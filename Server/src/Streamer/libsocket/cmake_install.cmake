# Install script for directory: /home/ubuntu/Downloads/libsocket-master/headers

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/libsocket/unixdgram.hpp;/usr/include/libsocket/exception.hpp;/usr/include/libsocket/inetclientdgram.hpp;/usr/include/libsocket/libinetsocket.h;/usr/include/libsocket/unixserverstream.hpp;/usr/include/libsocket/dgramclient.hpp;/usr/include/libsocket/streamclient.hpp;/usr/include/libsocket/inetserverstream.hpp;/usr/include/libsocket/unixclientdgram.hpp;/usr/include/libsocket/socket.hpp;/usr/include/libsocket/inetbase.hpp;/usr/include/libsocket/inetserverdgram.hpp;/usr/include/libsocket/unixclientstream.hpp;/usr/include/libsocket/libunixsocket.h;/usr/include/libsocket/select.hpp;/usr/include/libsocket/inetclientstream.hpp;/usr/include/libsocket/unixbase.hpp;/usr/include/libsocket/unixserverdgram.hpp;/usr/include/libsocket/inetdgram.hpp;/usr/include/libsocket/epoll.hpp")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/usr/include/libsocket" TYPE FILE FILES
    "/home/ubuntu/Downloads/libsocket-master/headers/./unixdgram.hpp"
    "/home/ubuntu/Downloads/libsocket-master/headers/./exception.hpp"
    "/home/ubuntu/Downloads/libsocket-master/headers/./inetclientdgram.hpp"
    "/home/ubuntu/Downloads/libsocket-master/headers/./libinetsocket.h"
    "/home/ubuntu/Downloads/libsocket-master/headers/./unixserverstream.hpp"
    "/home/ubuntu/Downloads/libsocket-master/headers/./dgramclient.hpp"
    "/home/ubuntu/Downloads/libsocket-master/headers/./streamclient.hpp"
    "/home/ubuntu/Downloads/libsocket-master/headers/./inetserverstream.hpp"
    "/home/ubuntu/Downloads/libsocket-master/headers/./unixclientdgram.hpp"
    "/home/ubuntu/Downloads/libsocket-master/headers/./socket.hpp"
    "/home/ubuntu/Downloads/libsocket-master/headers/./inetbase.hpp"
    "/home/ubuntu/Downloads/libsocket-master/headers/./inetserverdgram.hpp"
    "/home/ubuntu/Downloads/libsocket-master/headers/./unixclientstream.hpp"
    "/home/ubuntu/Downloads/libsocket-master/headers/./libunixsocket.h"
    "/home/ubuntu/Downloads/libsocket-master/headers/./select.hpp"
    "/home/ubuntu/Downloads/libsocket-master/headers/./inetclientstream.hpp"
    "/home/ubuntu/Downloads/libsocket-master/headers/./unixbase.hpp"
    "/home/ubuntu/Downloads/libsocket-master/headers/./unixserverdgram.hpp"
    "/home/ubuntu/Downloads/libsocket-master/headers/./inetdgram.hpp"
    "/home/ubuntu/Downloads/libsocket-master/headers/./epoll.hpp"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

