#pragma once
#include <cstdint>
#include <Arduino.h>

struct mac_address {
  uint8_t value[6];

  inline bool operator < (const mac_address& rhs) const {
    // Stack the 6 bytes into a 64-bit (8-byte) int for comparison. This op
    // is required by std::map to be able to sort the objects. We can't use
    // std::unordered_map for some reason. Likely cause: old C++ STL.
    uint64_t x =
      (this->value[0] << (5 * 8))
      + (this->value[1] << (4 * 8))
      + (this->value[2] << (3 * 8))
      + (this->value[3] << (2 * 8))
      + (this->value[4] << (1 * 8))
      + (this->value[5] << 0);
    uint64_t y =
      (rhs.value[0] << (5 * 8))
      + (rhs.value[1] << (4 * 8))
      + (rhs.value[2] << (3 * 8))
      + (rhs.value[3] << (2 * 8))
      + (rhs.value[4] << (1 * 8))
      + (rhs.value[5] << 0);
    return x < y;
  }
};

inline void print_mac_address(mac_address address) {
  Serial.printf(
    "%02x:%02x:%02x:%02x:%02x:%02x",
    address.value[0],
    address.value[1],
    address.value[2],
    address.value[3],
    address.value[4],
    address.value[5]
  );
}
