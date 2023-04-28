#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <esp_wifi.h>
#include <esp_wifi_types.h>
#include <unordered_map>
#include "ieee_802_11_mac_header.h"
#include "mac_address.h"

auto mac_address_last_seen = std::unordered_map<mac_address, long>();

uint8_t level = 0;
uint8_t channel = 1;
wifi_country_t wifi_country = {
  .cc = "CN",
  .schan = 1,
  .nchan = 13
};

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

// You'll get a report every seven-ish seconds.
void loop() {
  for (int i = 0; i < 13; i++) {
    // We use vTaskDelay() instead of delay() so that the handle_packet() and the
    // ESP32 event loop still runs IN PARALLEL to this delay.
    vTaskDelay(1000);

    wifi_sniffer_set_channel(channel);
    // 1-13 inclusive both ends, not 0-13 exclusive end.
    channel = (channel % 13) + 1;
  }

  // Clean any old addresses. We do this right before any reporting.
  std::erase_if(mac_address_last_seen, [](const auto& item) {
    auto const& [mac_address, last_seen] = item;

    auto ago = millis() - last_seen;
    return ago > 60 * 1000;
  });

  for (const auto [mac_address, last_seen] : mac_address_last_seen) {
    Serial.print("mac_address=");
    print_mac_address(mac_address);
    Serial.print(", ");
    auto last_seen_ago = millis() - last_seen;
    Serial.printf("last_seen %dms ago", last_seen_ago);
    Serial.println();
  }
}
