#include "./wifi_access_point.h"

WifiAccessPoint::WifiAccessPoint() = default;

void WifiAccessPoint::print_access_point() {
  printf("Access point name: %s\n", WifiAccessPoint::access_point_name);
}

char *WifiAccessPoint::get_access_point_name() {
  return WifiAccessPoint::access_point_name;
}

void WifiAccessPoint::set_access_point_name(char *apn) {
  WifiAccessPoint::access_point_name = apn;
}

char *WifiAccessPoint::get_mac_address() {
  return WifiAccessPoint::mac_address;
}

void WifiAccessPoint::set_mac_address(char *mac) {
  WifiAccessPoint::mac_address = mac;
}
