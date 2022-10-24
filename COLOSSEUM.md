This project is forked from upstream mgen, with patches applied by Kudu Dynamics during SC2.

# Upgrading to Ubuntu 20.04
The goal is to retain functionality from the Kudu release. We also need to
upgrade the underlying OS.

### Patch
We only want to apply minimal patches to get mgen to build. Thus we have
applied the following patches:
* https://sources.debian.org/data/main/m/mgen/5.02.b%2Bdfsg1-2.2/debian/patches/100-ld-as-needed.patch
* https://sources.debian.org/data/main/m/mgen/5.02.b%2Bdfsg1-2.2/debian/patches/400-nolibpcap.patch
* https://sources.debian.org/data/main/m/mgen/5.02.b%2Bdfsg1-2.2/debian/patches/gcc7.patch

### Add protolib
Download from here:
https://sources.debian.org/data/main/m/mgen/5.02.b%2Bdfsg1-2.2/protolib/

In theory, it would be better to download this from source, e.g. from NRL. That
said, The Debian build has this included, so we also include it manually here.

### Build
For actual build commands, see [Colosseum mgen
repo](https://github.com/colosseum-wiot/armory-traffic-generation) colosseum
branches, specifically `containers/mgen/Dockerfile`.

# Release notes for Kudu MGEN enhancements

2018_06_28:
 * Removed bad casts of the timeval.tv_usec field in Mgen::Log function to prevent bad data from being printed to the
   microseconds field 

2018_05_21:
 * Added the TOS field to MGEN messages
 * Update MGEN text logging to include the TOS field
 * To generate send logs specify the txlog option on the command line
    - Ex. mgen input send.mgn txlog

2017_11_16:
 * Update MGEN text logging to include date in printed timestamps, to eliminate ambiguity.
 * Datetime format: YYYY-mm-dd_HH:MM:SS.ssssss

2017_11_15:
 * Remove HAVE_PCAP from build flags due to issues encountered by APL running with this flag.
 * Side effect of this change is that CLONE command is disabled.

2017_10_27:
 * Backport the global SEED command from NRL's mainline MGEN

2017_10_16:
 * Enable CLONE command. Fix bug in CLONE code related to using magic number rather than MIN_SIZE.

2017_10_03:
* Update default TTL of MGEN-created packets to 255 (previously was 3)
* Add Kudu version identifier to version string (version now looks like "5.02b-Kudu-2017_10_03")

2017_08_07:
* Add convenience script (build.sh) to build MGEN
* Remove -fstack-protector-strong from compiler flags because it isn't supported by Ubuntu 14.04's gcc

2017_05_25:
* Fix unpacking bugs that allowed incomplete packets / bad payload lengths to be considered successfully receieved
* Add compiler flags for hardening and optimization

2017_05_10:
* Add HMAC integrity checking, enabled via  "integrity" commandline option
* Hardcode RANDOM_FILL to ensure it's always on; fixed randomization so it is no longer trivially predictable
* Fix buffer-sizing bug that caused packet random padding to get clobbered by determiniistic header contents
* MGEN network protocol changed, protocol version bumped from 2 to 3
* MGEN network protocol and logs now include MGEN fragment identifiers
