#!/bin/bash


make -f Makefile.linux clean
make -f Makefile.linux
mkdir -p ../bin
mv mgen ../bin
mv mpmgr ../bin
