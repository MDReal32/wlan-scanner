#include "./wifi_access_point.h"

WifiAccessPoint::WifiAccessPoint() = default;

void WifiAccessPoint::print_access_point() {
  printf("Access point name: %s\n", WifiAccessPoint::access_point_name);
}

char *WifiAccessPoint::get_access_point_name() {
  return WifiAccessPoint::access_point_name;
}

void WifiAccessPoint::set_access_point_name(char *accessPointName) {
  WifiAccessPoint::access_point_name = accessPointName;
}

char *WifiAccessPoint::get_mac_address() {
  return WifiAccessPoint::mac_address;
}

void WifiAccessPoint::set_mac_address(char *macAddress) {
  WifiAccessPoint::mac_address = macAddress;
}

bool WifiAccessPoint::get_is_hidden() {
  return WifiAccessPoint::is_hidden;
}

void WifiAccessPoint::set_is_hidden(bool isHidden) {
  WifiAccessPoint::is_hidden = isHidden;
}
