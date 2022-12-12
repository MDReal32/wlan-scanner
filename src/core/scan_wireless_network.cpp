#include "./scan_wireless_network.h"


WifiAccessPoints* scan_wireless_network(char *ifname) {
  printf("Scanning wireless network on interface %s\n\n", ifname);

  wireless_scan_head head;
  wireless_scan *result;
  iwrange range;
  struct ifreq s;
  int sock;

  WifiAccessPoints* wifi_access_points;
  int idx = 0;

  sock = iw_sockets_open();

  if (iw_get_range_info(sock, ifname, &range) < 0) {
    printf("Error during iw_get_range_info. Aborting.\n");
    exit(2);
  }

  if (iw_scan(sock, ifname, range.we_version_compiled, &head) < 0) {
    printf("Error during iw_scan. Aborting.\n");
    exit(2);
  }

  strcpy(s.ifr_name, "wlp3s0");
  if (0 == ioctl(sock, SIOCGIFHWADDR, &s)) {
    int i;
    for (i = 0; i < 6; ++i) {
      printf("%02x", (unsigned char) s.ifr_addr.sa_data[i]);
    }
    puts("\n");
  }


//  wifi_access_points = new WifiAccessPoints();
  result = head.result;
  while (NULL != result) {
//    auto* wifi_access_point = new WifiAccessPoint();
//    wifi_access_point->set_access_point_name(result->b.essid);
//    wifi_access_points->wifi_access_points[idx] = wifi_access_point;

    printf("Access point name: %s, ", result->b.essid);
    char mac[17];

    for (int i = 0; i < 6; i++) {
      sprintf(mac + i * 3, "%02x%s", (unsigned char) result->ap_addr.sa_data[i], i < 5 ? ":" : "");
    }

    printf("mac address: %s\n", mac);

    idx++;
    result = result->next;
  }
  wifi_access_points->size = idx;

  return wifi_access_points;
}