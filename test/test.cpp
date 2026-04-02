#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>
#include <cstring>
#include <cstdint>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

class Client
{
public:
    Client(const string& ip, uint16_t port)
        : _socketfd(INVALID_SOCKET)
        , _serverip(ip)
        , _serverport(port)
    {
        // 1. 初始化 Winsock
        WSADATA wsaData;
        int ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (ret != 0)
        {
            cerr << "WSAStartup failed, error: " << ret << endl;
            exit(1);
        }
    }

    void init()
    {
        // 2. 创建 UDP 套接字
        _socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (_socketfd == INVALID_SOCKET)
        {
            cerr << "socket failed, error: " << WSAGetLastError() << endl;
            WSACleanup();
            exit(1);
        }

        // 3. 填充服务器地址
        memset(&_server, 0, sizeof(_server));
        _server.sin_family = AF_INET;
        _server.sin_port = htons(_serverport);

        int ret = inet_pton(AF_INET, _serverip.c_str(), &_server.sin_addr);
        if (ret != 1)
        {
            cerr << "inet_pton failed, invalid ip: " << _serverip << endl;
            closesocket(_socketfd);
            _socketfd = INVALID_SOCKET;
            WSACleanup();
            exit(1);
        }
    }

    void run()
    {
        string message;

        while (true)
        {
            cout << "请输入数据(输入 quit 退出): ";
            getline(cin, message);

            if (message == "quit")
            {
                break;
            }

            int ret = sendto(
                _socketfd,
                message.c_str(),
                static_cast<int>(message.size()),
                0,
                reinterpret_cast<sockaddr*>(&_server),
                sizeof(_server)
            );

            if (ret == SOCKET_ERROR)
            {
                cerr << "sendto failed, error: " << WSAGetLastError() << endl;
                break;
            }

            cout << "发送成功, 字节数: " << ret << endl;
        }
    }

    ~Client()
    {
        if (_socketfd != INVALID_SOCKET)
        {
            closesocket(_socketfd);
            _socketfd = INVALID_SOCKET;
        }

        WSACleanup();
    }

private:
    SOCKET _socketfd;
    string _serverip;
    uint16_t _serverport;
    sockaddr_in _server;
};



//// 运行方式：client.exe 127.0.0.1 8080
//int main()
//{
//
//
//    string serverip = "8.140.211.98";
//    uint16_t serverport = 8080;
//
//    unique_ptr<Client> ucli(new Client(serverip, serverport));
//    ucli->init();
//
//    // 如果前面用过 cin >> ，这里通常需要清理缓冲区
//    // 但当前 main 中没有用到 cin，所以这里可以不写
//    ucli->run();
//
//    return 0;
//}