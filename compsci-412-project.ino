/**
 * @brief This program uses an ESP32-based development board to scan for Wi-Fi
 *        access points and devices. It periodically switches the Wi-Fi channel
 *        and logs any MAC addresses that it sees. It also periodically cleans up
 *        the logs to remove stale MAC addresses that have not been seen in a while.
 *
 * This program requires an ESP32-based development board, the Arduino IDE,
 * and the following libraries:
 * - Arduino.h
 * - freertos/FreeRTOS.h
 * - esp_wifi.h
 * - esp_wifi_types.h
 *
 * The only library you'll need to explicitly install using the Arduino Library Manager
 * is the FreeRTOS.h provider.
 *
 * Make sure you also have the following header files that are bundled with the main
 * .ino project file too:
 * - ieee_802_11_mac_header.h
 * - mac_address.h
 * - wifi_sniffer.h
 *
 * Once uploaded, open the Serial Monitor at a baud rate of 115200 to view the
 * results. The program will periodically print the MAC addresses of any
 * access points and devices it detects, along with how long ago they were seen.
 *
 * @file
 */

#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <esp_wifi.h>
#include <esp_wifi_types.h>
#include <map>
#include <LiquidCrystal.h>
#include "ieee_802_11_mac_header.h"
#include "mac_address.h"
#include "wifi_sniffer.h"

auto mac_address_last_seen = std::map<mac_address, long>();
auto lcd = LiquidCrystal(19, 23, 18, 17, 16, 15);

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  setup_wifi_sniffer();
}

void handle_packet(void* buffer, wifi_promiscuous_pkt_type_t type) {
  if (type != WIFI_PKT_MGMT) {
    return;
  }

  // Interpret raw bytes as a specific type. Then use the special ->payload
  // offset to access more raw bytes. Then, interpret those raw bytes as the
  // WiFi header.
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
  set_channel(channel);
  Serial.printf("Scanning channel %d...", channel);
  Serial.println();
  lcd.setCursor(0, 0);
  lcd.print("Scan chan ");
  lcd.print(channel);

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
    Serial.print("mac_address=");
    print_mac_address(mac_address);
    Serial.print(", ");
    Serial.printf("last_seen %dms ago", last_seen_ago);
    Serial.println();
  }
  Serial.printf("There are %d MAC addresses", n);
  Serial.println();
  lcd.setCursor(0, 1);
  lcd.print(n);
  lcd.print(" MAC addrs");
}
