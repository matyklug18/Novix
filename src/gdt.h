#pragma once

#include "stdint.h"

extern "C" {

struct __attribute__((packed)) IDTEntry
{
    uint16_t base_lower;
    uint16_t sel;
    uint8_t  always0;
    uint8_t  flags;
    uint16_t base_upper;
};

struct __attribute__((packed)) IDTPointer
{
    uint16_t limit;
    uint32_t base;
};

struct __attribute__((packed)) GDTEntry
{
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t  base_middle;
    uint8_t  access;
    uint8_t  granularity;
    uint8_t  base_high;
};

struct __attribute__((packed)) GDTPointer
{
    uint16_t limit;
    uint32_t base;
};

void loadTables();

}