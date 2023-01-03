#include "./scan_wireless_network.h"


WifiAccessPoints *scan_wireless_network(string &ifname) {
  wireless_scan_head head;
  wireless_scan *result;
  iwrange range;
  struct ifreq s{};
  int sock;

  auto *wifi_access_points = new WifiAccessPoints();
  int idx = 0;

  sock = iw_sockets_open();

  if (iw_get_range_info(sock, ifname.c_str(), &range) < 0) {
    cout << "Error during iw_get_range_info. Aborting." << endl;
    exit(2);
  }

  if (iw_scan(sock, (char*) ifname.c_str(), range.we_version_compiled, &head) < 0) {
    cout << "Error during iw_scan. Aborting." << endl;
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

  result = head.result;
  while (nullptr != result) {
    string access_point_name = result->b.essid;
    string mac_address;

    for (int i = 0; i < 6; i++) {
      char buf[3];
      sprintf(buf, "%02x", (unsigned char) result->ap_addr.sa_data[i]);
      mac_address += buf;
      if (i < 5) mac_address += ":";
    }

    auto *wifi_access_point = new WifiAccessPoint();
    wifi_access_point->set_access_point_name(access_point_name);
    wifi_access_point->set_mac_address(mac_address);
    wifi_access_points->wifi_access_points[idx] = wifi_access_point;

    result = result->next;
    idx++;
  }
  wifi_access_points->size = idx;

  return wifi_access_points;
}