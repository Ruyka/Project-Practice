#include<winsock.h>
#include<iostream>

#pragma comment(lib, "Ws2_32.lib")

#define SCK_VERSION2 0x0202

SOCKET s;
WSADATA w;

bool ConnectToHost(int port, char* IPAddress);
void CloseConnection();
int ListenOnPort(int port);

int main(int ac, char* av)
{
	ListenOnPort(10000);
	CloseConnection();
	return 0;
}

bool ConnectToHost(int port, char * IPAddress)
{
	WSADATA wsadata;

	int error = WSAStartup(SCK_VERSION2, &wsadata);

	if (error) return false;

	if (wsadata.wVersion != SCK_VERSION2)
	{
		WSACleanup();
		return false;
	}

	SOCKADDR_IN target;

	target.sin_family = AF_INET;
	target.sin_port = htons(port);
	target.sin_addr.s_addr = inet_addr(IPAddress);
	//target.sin_addr.s_addr = htonl(INADDR_ANY);

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (s == INVALID_SOCKET) return false;

	if (connect(s, (SOCKADDR *)&target, sizeof(target)) == SOCKET_ERROR)
		return false;

	return true;
}

void CloseConnection()
{
	if (s)
		closesocket(s);
	WSACleanup();
}

int ListenOnPort(int port)
{
	int error = WSAStartup(SCK_VERSION2, &w);
	
	if (error) return false;

	if (w.wVersion != SCK_VERSION2)
	{
		WSACleanup();
		return false;
	}

	SOCKADDR_IN addr;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (s == INVALID_SOCKET) return false;

	if (bind(s, (LPSOCKADDR)&addr, sizeof(addr)) == SOCKET_ERROR) return false;

	listen(s, SOMAXCONN);

	return 0;
}
