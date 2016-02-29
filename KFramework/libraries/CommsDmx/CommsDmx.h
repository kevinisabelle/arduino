/**
 * CommsDmx - A simple interface to DMX.
 *
 * Copyright (c) 2008-2009 Peter Knight, Tinker.it! All rights reserved.
 */

#ifndef CommsDmx_h
#define CommsDmx_h

#include <inttypes.h>

#if RAMEND <= 0x4FF
#define DMX_SIZE 128
#else
#define DMX_SIZE 512
#endif

class CommsDmx {
  public:
    void setup(uint8_t pin, int maxChannels);
    void maxChannel(int);
    void write(int, uint8_t);
    void usePin(uint8_t);
};

#endif
