#include "core.h"

string get_data(bool dev_mode, bool json_mode) {
  stringstream buffer;
  string ifname = get_ifname();
  WifiAccessPoints *wifi_access_points = scan_wireless_network(ifname);

  if (dev_mode) {
    buffer << "Scan completed:" << std::endl << "Found " << wifi_access_points->size << " access point"
              << (wifi_access_points->size == 1 ? "" : "s") << std::endl;

    for (int i = 0; i < wifi_access_points->size; ++i) {
      buffer << wifi_access_points->wifi_access_points[i]->to_string() << endl;
    }
  } else if (json_mode) {
    buffer << "[";
    for (int i = 0; i < wifi_access_points->size; ++i) {
      buffer << wifi_access_points->wifi_access_points[i]->to_json();
      buffer << (i == wifi_access_points->size - 1 ? "" : ",");
    }
    buffer << "]";
  }

  return buffer.str();
}