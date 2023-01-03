cmake_minimum_required(VERSION 3.24)

project(wlan_scanner2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")
set(LIBRARIES "")

option(ENABLE_NETWORK "Enable network support" ON)

list(APPEND LIBRARIES -lstdc++)

add_executable(wlan_scanner2
        src/main.cpp

        src/core/get_ifname.cpp src/core/get_ifname.h
        src/core/scan_wireless_network.cpp src/core/scan_wireless_network.h

        src/helpers/wifi_access_point.cpp src/helpers/wifi_access_point.h

        src/utils/exists_in_arg.cpp src/utils/exists_in_arg.h)

find_package("Libiw")

target_link_libraries(wlan_scanner2 ${LIBRARIES})
