# Install script for directory: /home/matteo/Desktop/libsocket-master/headers

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/libsocket/unixdgram.hpp;/usr/include/libsocket/exception.hpp;/usr/include/libsocket/inetclientdgram.hpp;/usr/include/libsocket/libinetsocket.h;/usr/include/libsocket/unixserverstream.hpp;/usr/include/libsocket/dgramclient.hpp;/usr/include/libsocket/streamclient.hpp;/usr/include/libsocket/inetserverstream.hpp;/usr/include/libsocket/unixclientdgram.hpp;/usr/include/libsocket/socket.hpp;/usr/include/libsocket/inetbase.hpp;/usr/include/libsocket/inetserverdgram.hpp;/usr/include/libsocket/unixclientstream.hpp;/usr/include/libsocket/libunixsocket.h;/usr/include/libsocket/select.hpp;/usr/include/libsocket/inetclientstream.hpp;/usr/include/libsocket/unixbase.hpp;/usr/include/libsocket/unixserverdgram.hpp;/usr/include/libsocket/inetdgram.hpp;/usr/include/libsocket/epoll.hpp")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/libsocket" TYPE FILE FILES
    "/home/matteo/Desktop/libsocket-master/headers/./unixdgram.hpp"
    "/home/matteo/Desktop/libsocket-master/headers/./exception.hpp"
    "/home/matteo/Desktop/libsocket-master/headers/./inetclientdgram.hpp"
    "/home/matteo/Desktop/libsocket-master/headers/./libinetsocket.h"
    "/home/matteo/Desktop/libsocket-master/headers/./unixserverstream.hpp"
    "/home/matteo/Desktop/libsocket-master/headers/./dgramclient.hpp"
    "/home/matteo/Desktop/libsocket-master/headers/./streamclient.hpp"
    "/home/matteo/Desktop/libsocket-master/headers/./inetserverstream.hpp"
    "/home/matteo/Desktop/libsocket-master/headers/./unixclientdgram.hpp"
    "/home/matteo/Desktop/libsocket-master/headers/./socket.hpp"
    "/home/matteo/Desktop/libsocket-master/headers/./inetbase.hpp"
    "/home/matteo/Desktop/libsocket-master/headers/./inetserverdgram.hpp"
    "/home/matteo/Desktop/libsocket-master/headers/./unixclientstream.hpp"
    "/home/matteo/Desktop/libsocket-master/headers/./libunixsocket.h"
    "/home/matteo/Desktop/libsocket-master/headers/./select.hpp"
    "/home/matteo/Desktop/libsocket-master/headers/./inetclientstream.hpp"
    "/home/matteo/Desktop/libsocket-master/headers/./unixbase.hpp"
    "/home/matteo/Desktop/libsocket-master/headers/./unixserverdgram.hpp"
    "/home/matteo/Desktop/libsocket-master/headers/./inetdgram.hpp"
    "/home/matteo/Desktop/libsocket-master/headers/./epoll.hpp"
    )
endif()

