#include <iostream>

#include "core/get_ifname.h"
#include "core/scan_wireless_network.h"
#include "utils/exists_in_arg.h"

using namespace std;

int main(int argc, char *argv[]) {
  bool is_dev_mode = exists_in_arg(argc, argv, "--dev");
  bool is_json_mode = exists_in_arg(argc, argv, "--json");

  string ifname = get_ifname();
  WifiAccessPoints* wifiAccessPoints = scan_wireless_network(ifname);

  if (is_dev_mode) {
    std::cout << "Scan completed:" << std::endl << "Found " << wifiAccessPoints->size << " access point" << (wifiAccessPoints->size == 1 ? "" : "s") << std::endl;

    for (int i = 0; i < wifiAccessPoints->size; ++i) {
      cout << wifiAccessPoints->wifi_access_points[i]->to_string() << endl;
    }
  }

  if (is_json_mode && !is_dev_mode) {
    cout << "[";
    for (int i = 0; i < wifiAccessPoints->size; ++i) {
      cout << wifiAccessPoints->wifi_access_points[i]->to_json();
    }
    cout << "]";
  }

  return 0;
}
