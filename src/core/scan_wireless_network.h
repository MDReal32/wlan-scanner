#include <iostream>
#include <iwlib.h>

#include "../helpers/wifi_access_point.h"

using namespace std;

struct WifiAccessPoints {
    int size;
    WifiAccessPoint* wifi_access_points[];
};

WifiAccessPoints* scan_wireless_network(string &ifname);
