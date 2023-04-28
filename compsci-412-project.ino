#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <esp_wifi.h>
#include <esp_wifi_types.h>
#include <map>
#include "ieee_802_11_mac_header.h"
#include "mac_address.h"
#include "wifi_sniffer.h"

auto mac_address_last_seen = std::map<mac_address, long>();

void setup() {
  Serial.begin(115200);
  setup_wifi_sniffer();
}

void handle_packet(void* buffer, wifi_promiscuous_pkt_type_t type) {
  if (type != WIFI_PKT_MGMT) {
    return;
  }

  const auto packet = (wifi_promiscuous_pkt_t*) buffer;
  const auto header = (ieee_802_11_mac_header*) packet->payload;

  // Serial.print("Here's the header: ")
  // print_ieee_802_11_mac_header(header);
  // Serial.println();

  mac_address_last_seen[header->address_1] = millis();
  mac_address_last_seen[header->address_2] = millis();
  mac_address_last_seen[header->address_3] = millis();
  mac_address_last_seen[header->address_4] = millis();
}

uint8_t channel = 1;
void loop() {
  for (int i = 0; i < 13; i++) {
    set_channel(channel);
    Serial.printf("Scanning channel %d...", channel);
    Serial.println();

    // We use vTaskDelay() instead of delay() so that the handle_packet() and the
    // ESP32 event loop still runs IN PARALLEL to this delay.
    vTaskDelay(6000);

    // 1-13 inclusive both ends, not 0-13 exclusive end.
    channel = (channel % 13) + 1;

    int n = 0;
    for (auto [mac_address, last_seen] : mac_address_last_seen) {
      auto last_seen_ago = millis() - last_seen;
      if (last_seen_ago > 13 * 7000) {
        mac_address_last_seen.erase(mac_address);
      }

      n++;
      // Serial.print("mac_address=");
      // print_mac_address(mac_address);
      // Serial.print(", ");
      // Serial.printf("last_seen %dms ago", last_seen_ago);
      // Serial.println();
    }
    Serial.printf("There are %d MAC addresses", n);
    Serial.println();
  }
}
