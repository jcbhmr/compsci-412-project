#pragma once
#include <cstdint>
#include "mac_address.h"

/**
 * @see https://witestlab.poly.edu/blog/802-11-wireless-lan-2/
 */
struct ieee_802_11_mac_header {
  /**
   * Frame Control: Indicates the type of frame (control, management, or data)
   * and provides control information. Control information includes whether the
   * frame is to or from a DS, fragmentation information, and privacy
   * information.
   */
  uint16_t frame_control;

  /**
   * Duration/Connection ID: If used as a duration field, indicates the time
   * (in microseconds) the channel will be allocated for successful transmission
   * of a MAC frame. In some control frames, this field contains an association,
   * or connection, identifier.
   */
  uint16_t duration_id;

  /**
   * Addresses: The number and meaning of the 48-bit address fields depend on
   * context. The transmitter address and receiver address are the MAC addresses
   * of stations joined to the BSS that are transmitting and receiving frames
   * over the wireless LAN. The service set ID (SSID) identifies the wireless
   * LAN over which a frame is transmitted. For an IBSS, the SSID is a random
   * number generated at the time the network is formed. For a wireless LAN that
   * is part of a larger configuration the SSID identifies the BSS over which
   * the frame is transmitted; specifically, the SSID is the MAC-level address
   * of the AP for this BSS (Figure 17.4). Finally the source address and
   * destination address are the MAC addresses of stations, wireless or
   * otherwise, that are the ultimate source and destination of this frame. The
   * source address may be identical to the transmitter address and the
   * destination address may be identical to the receiver address.
   */
  mac_address address_1;
  mac_address address_2;
  mac_address address_3;

  /**
   * Sequence Control: Contains a 4-bit fragment number subfield, used for
   * fragmentation and reassembly, and a 12-bit sequence number used to number
   * frames sent between a given transmitter and receiver.
   */
  uint16_t sequence_control[2];

  mac_address address_4;

  // There's the data and CRC parts that aren't included in the header.
};

inline void print_ieee_802_11_mac_header(ieee_802_11_mac_header* header) {
  Serial.print("address_1=");
  print_mac_address(header->address_1);
  Serial.print(", address_2=");
  print_mac_address(header->address_2);
  Serial.print(", address_3=");
  print_mac_address(header->address_3);
  Serial.print(", address_4=");
  print_mac_address(header->address_4);
}
