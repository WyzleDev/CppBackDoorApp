#include <iostream>
#pragma comment (lib, "ws2_32.lib")

#include <winsock2.h>
#include <iostream>
#pragma warning(disable: 4996)
int main(int argc, char* argv[]) 
{
	WSAData wsaData;
	WORD  DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error"<< std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int size_of_addr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(11111);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &size_of_addr);

	if (newConnection == 0) {
		std::cout << "error\n";
	}
	else {
		std::cout << "client connected!";
	}

	system("Pause");
	return 0;
}