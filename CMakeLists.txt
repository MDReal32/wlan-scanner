cmake_minimum_required(VERSION 3.24)

project(wlan_scanner2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

option(ENABLE_NETWORK "Enable network support" ON)

add_executable(wlan_scanner2
        src/main.cpp

        src/core/get_ifname.cpp src/core/get_ifname.h
        src/core/scan_wireless_network.cpp src/core/scan_wireless_network.h

        src/helpers/wifi_access_point.cpp src/helpers/wifi_access_point.h
        src/helpers/get_access_points_json.cpp src/helpers/get_access_points_json.h

        src/utils/string_starts_with.cpp src/utils/string_starts_with.h
        src/utils/exists_in_arg.cpp src/utils/exists_in_arg.h)

find_package("Libiw")
