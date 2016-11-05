#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "Ws2_32.lib")

#include<iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<string>
using namespace std;

int main() {
	WSAData version;
	WORD mkword = MAKEWORD(2, 2);
	int checkVer = WSAStartup(mkword, &version);
	if (checkVer) {
		cout << "Not supported version.\n" << WSAGetLastError() << endl;
		return 0;
	}
	else {
		cout << "Supported version.\n" << endl;
	}

	SOCKET u_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (u_sock == INVALID_SOCKET) {
		cout << "Create socket failed.\n";
		return 0;
	}
	else {
		cout << "Socket created.\n\n";
	}

	string in_address;
	string out_address;

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("192.168.43.240");
	//inet_pton(AF_INET, "192.168.43.240", &(addr.sin_addr));
	addr.sin_port = htons(80);

	int conn = connect(u_sock, (SOCKADDR*)&addr, sizeof(addr));
	if (conn == SOCKET_ERROR) {
		cout << "Error when connecting - " << WSAGetLastError() << endl;
		closesocket(u_sock);
		WSACleanup();
		return 0;
	}
	else {
		cout << "Connected.\n\n";
	}

	char* mymsg = "Hello";
	char vect[512] = { 0 };

	int smsg = send(u_sock, mymsg, sizeof(mymsg), 0);
	if (smsg == SOCKET_ERROR) {
		cout << "Error - " << WSAGetLastError() << endl;
		WSACleanup();
	}
	else {
		cout << "Sent.\n\n";
	}

	int get = recv(u_sock, vect, 512, 0);
	if (get == SOCKET_ERROR) {
		cout << "Error receiving - " << WSAGetLastError() << endl;
	}
	else {
		cout << "Received.\n\n";
	}
	cout << vect << endl;
	closesocket(u_sock);
	
	return 0;
}