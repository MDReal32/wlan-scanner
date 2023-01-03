#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class WifiAccessPoint {
private:
    string access_point_name{};
    string mac_address{};
    bool is_hidden{};

public:
    WifiAccessPoint();

    string to_string();
    string to_json();

    string get_access_point_name();
    void set_access_point_name(string &apn);

    string get_mac_address();
    void set_mac_address(string &mac);

    bool get_is_hidden();
    void set_is_hidden(bool isHidden);
};