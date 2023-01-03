cmake_minimum_required(VERSION 3.24)

project(wlan_scanner2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")
set(LIBRARIES "")

option(ENABLE_NETWORK "Enable network support" ON)

list(APPEND LIBRARIES -lstdc++)

add_executable(wlan_scanner
        cpp/main.cpp

        cpp/core/get_ifname.cpp cpp/core/get_ifname.h
        cpp/core/scan_wireless_network.cpp cpp/core/scan_wireless_network.h

        cpp/helpers/wifi_access_point.cpp cpp/helpers/wifi_access_point.h

        cpp/utils/exists_in_arg.cpp cpp/utils/exists_in_arg.h)

find_package("Libiw")

target_link_libraries(wlan_scanner ${LIBRARIES})
