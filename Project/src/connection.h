#ifndef _CONNECTION_
#define _CONNECTION_

#define WIN32_LEAN_AND_MEAN

#include <cstdio>
#include <cstdlib>
#include <cstring>

#ifdef linux
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#else
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#endif

#include <string>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

class Connection {
 public:
  Connection(short port);

  bool sendMsg(string msg);
  string readLine();
 private: 
#ifdef linux
  int sock;
#else
  SOCKET sock;
#endif
};

#endif
