#include <cstdio>
#include <iwlib.h>

#include "../helpers/wifi_access_point.h"

struct WifiAccessPoints {
    int size;
    WifiAccessPoint* wifi_access_points[];
};

WifiAccessPoints* scan_wireless_network(char *ifname);
