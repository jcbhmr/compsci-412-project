#pragma once
#include <cstdint>
#include <Arduino.h>

inline void print_mac_address(uint8_t* address) {
  Serial.printf(
    "%02x:%02x:%02x:%02x:%02x:%02x",
    address[0],
    address[1],
    address[2],
    address[3],
    address[4],
    address[5]
  );
}
