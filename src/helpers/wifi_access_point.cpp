#include "./wifi_access_point.h"

WifiAccessPoint::WifiAccessPoint() = default;

void WifiAccessPoint::print_access_point() {
  printf("Access point name: %s\n", WifiAccessPoint::access_point_name);
}

int WifiAccessPoint::get_access_point_json_length() {
  return 57 + strlen(WifiAccessPoint::access_point_name) + strlen(WifiAccessPoint::mac_address) +
         (WifiAccessPoint::is_hidden ? 4 : 5);
}

const char *WifiAccessPoint::get_access_point_json() {
//  int json_length = WifiAccessPoint::get_access_point_json_length();
//  char *json = new char[json_length];


//  sprintf(json, R"({ "accessPointName": "%s", "macAddress": "%s", "isHidden": %s })",
//          WifiAccessPoint::access_point_name, WifiAccessPoint::mac_address,
//          WifiAccessPoint::is_hidden ? "true" : "false");
//  return json;
return "";
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
