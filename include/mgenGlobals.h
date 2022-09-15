/*********************************************************************
 *
 * AUTHORIZATION TO USE AND DISTRIBUTE
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that: 
 *
 * (1) source code distributions retain this paragraph in its entirety, 
 *  
 * (2) distributions including binary code include this paragraph in
 *     its entirety in the documentation or other materials provided 
 *     with the distribution, and 
 *
 * (3) all advertising materials mentioning features or use of this 
 *     software display the following acknowledgment:
 * 
 *      "This product includes software written and developed 
 *       by Brian Adamson and Joe Macker of the Naval Research 
 *       Laboratory (NRL)." 
 *         
 *  The name of NRL, the name(s) of NRL  employee(s), or any entity
 *  of the United States Government may not be used to endorse or
 *  promote  products derived from this software, nor does the 
 *  inclusion of the NRL written and developed software  directly or
 *  indirectly suggest NRL or United States  Government endorsement
 *  of this product.
 * 
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 ********************************************************************/

#ifndef _MGEN_GLOBALS
#define _MGEN_GLOBALS
enum LogEventType
  {
    INVALID_EVENT = 0,
    RECV_EVENT,
    RERR_EVENT,
    SEND_EVENT,
    LISTEN_EVENT,
    IGNORE_EVENT,
    JOIN_EVENT,
    LEAVE_EVENT,
    START_EVENT,
    STOP_EVENT,
    ON_EVENT,
    ACCEPT_EVENT,
    DISCONNECT_EVENT,
    CONNECT_EVENT,
    OFF_EVENT,
    SHUTDOWN_EVENT

  };

/**
 * Possible protocol types 
 */
enum Protocol
  {
    INVALID_PROTOCOL,
    UDP,
    TCP,
    SINK,
    SOURCE  // pseudo transport type so an mgen can have distinct source/sink transports
  }; 

enum 
  {
    // For MIN_SIZE:
    // 56 is full header assuming 4-byte dst and host IPv4 addresses
    // 20 is HMAC-SHA1, 4 is CRC
    // So in IPv4, MIN_SIZE should be 56+20+4
    // For IPv6, addresses are 16 bytes, so MIN_SIZE should be 2*(16-4) bytes bigger,
    // or 80+20+4
    // Since MGEN supports both IPv4 and IPv6 concurrently, pick the bigger one
    MIN_SIZE = 80+20+4+1,
    MAX_SIZE = 8192,
    MSG_LEN_SIZE = 2,  // size of the length field that starts the on-wire message
    MAX_FRAG_SIZE = 65535, // TCP max fragment size
    MIN_FRAG_SIZE = MIN_SIZE, 
                          

    // TX_BUFFER_SIZE is the tcp tx buffer size
    TX_BUFFER_SIZE = MAX_FRAG_SIZE
    
  };

#endif // _MGEN_GLOBALS
