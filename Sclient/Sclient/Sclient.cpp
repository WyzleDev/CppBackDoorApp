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
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int size_of_addr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(11111);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr))) {
		std::cout << "Error: Failed connection to the server.\n";
		return 1;
	}
	std::cout << "Connected" << std::endl;
	system("pause");
	return 0;
}