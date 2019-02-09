namespace network
{
#ifdef _WIN32
    template <>
    SOCKET Socket::getUnderlyingSocket();
#endif
#ifdef __linux__
    template <>
    int Socket::getUnderlyingSocket();
#endif
}