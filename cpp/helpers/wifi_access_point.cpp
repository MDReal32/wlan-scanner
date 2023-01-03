#include "./wifi_access_point.h"

WifiAccessPoint::WifiAccessPoint() = default;

string WifiAccessPoint::to_string() {
  return "Access point name: " + WifiAccessPoint::access_point_name
         + "; MAC address: " + WifiAccessPoint::mac_address
         + "; Is hidden: " + (WifiAccessPoint::is_hidden ? "true" : "false") + "\n";
}

string WifiAccessPoint::to_json() {
  return R"({"accessPointName": ")" + WifiAccessPoint::access_point_name + R"(",)"
         R"("macAddress": ")" + WifiAccessPoint::mac_address + R"(",)"
         R"("isHidden": ")" + (WifiAccessPoint::is_hidden ? "true" : "false") + R"("})";
}

string WifiAccessPoint::get_access_point_name() {
  return WifiAccessPoint::access_point_name;
}

void WifiAccessPoint::set_access_point_name(string &accessPointName) {
  WifiAccessPoint::access_point_name = accessPointName;
}

string WifiAccessPoint::get_mac_address() {
  return WifiAccessPoint::mac_address;
}

void WifiAccessPoint::set_mac_address(string &macAddress) {
  WifiAccessPoint::mac_address = macAddress;
}

bool WifiAccessPoint::get_is_hidden() {
  return WifiAccessPoint::is_hidden;
}

void WifiAccessPoint::set_is_hidden(bool isHidden) {
  WifiAccessPoint::is_hidden = isHidden;
}
