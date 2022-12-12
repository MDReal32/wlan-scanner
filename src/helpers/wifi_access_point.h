#include <cstdio>

class WifiAccessPoint {
private:
    char *access_point_name{};
    char *mac_address{};

public:
    WifiAccessPoint();

    void print_access_point();

    char *get_access_point_name();
    void set_access_point_name(char *access_point_name);

    char *get_mac_address();
    void set_mac_address(char *mac_address);
};
