# This module defines
#  LIBIW_FOUND - whether the libiw library was found
#  LIBIW_LIBRARIES - the libiw library
#  LIBIW_INCLUDE_DIR - the include path of the libiw library

find_library(LIBIW_LIBRARY iw)

if (LIBIW_LIBRARY)
    set(LIBIW_LIBRARIES ${LIBIW_LIBRARY})
    set(LIBIW_FOUND TRUE)
endif (LIBIW_LIBRARY)

find_path(LIBIW_INCLUDE_DIR NAMES iwlib.h)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Libiw DEFAULT_MSG LIBIW_LIBRARY LIBIW_INCLUDE_DIR)

mark_as_advanced(LIBIW_INCLUDE_DIR LIBIW_LIBRARY)

if (ENABLE_NETWORK)
    message(STATUS "Libiw found: ${LIBIW_FOUND}")
    if (LIBIW_FOUND)
        include_directories(${LIBIW_INCLUDE_DIR})
        list(APPEND LIBRARIES ${LIBIW_LIBRARY})
    else (LIBIW_FOUND)
        message(WARNING "${ANSI}[41;1mDisabling \"network module\" support (prerequisites failed)${ANSI}[0m")
        set(ENABLE_NETWORK OFF)
    endif ()
endif ()
