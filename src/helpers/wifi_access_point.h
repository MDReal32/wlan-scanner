#include <cstdio>
#include <cstring>

class WifiAccessPoint {
private:
    char *access_point_name{};
    char *mac_address{};
    bool is_hidden{};

public:
    WifiAccessPoint();

    void print_access_point();
    int get_access_point_json_length();
    const char *get_access_point_json();

    char *get_access_point_name();
    void set_access_point_name(char *apn);

    char *get_mac_address();
    void set_mac_address(char *mac);

    bool get_is_hidden();
    void set_is_hidden(bool isHidden);
};
