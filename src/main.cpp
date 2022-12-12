#include "core/get_ifname.h"
#include "core/scan_wireless_network.h"

bool exists_in_arg(int argc, char *argv[], char *arg) {
  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], arg) == 0) {
      return true;
    }
  }

  return false;
}

int main(int argc, char *argv[]) {
  bool is_dev_mode = exists_in_arg(argc, argv, "--dev");

  char *ifname = get_ifname();
  WifiAccessPoints* wifiAccessPoints = scan_wireless_network(ifname);

  if (is_dev_mode) {
    printf("Scan completed:\n");
    printf("Found %d access point%s\n", wifiAccessPoints->size, wifiAccessPoints->size == 1 ? "" : "s");
  }


//  for (int i = 0; i < wifiAccessPoints.size; i++) {
//    wifiAccessPoints.wifi_access_points[i]->print_access_point();
//  }

//  printf("Access point name: %s\n", wifiAccessPoints->wifi_access_points);
//  for (int i = 0; i < WifiAccessPoints->size; i++) {
//    WifiAccessPoints->wifi_access_points[i]->print_access_point();
//  }

  return 0;
}
