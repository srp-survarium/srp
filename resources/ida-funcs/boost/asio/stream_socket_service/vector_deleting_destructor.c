boost::asio::datagram_socket_service<boost::asio::ip::udp> *__thiscall boost::asio::stream_socket_service<boost::asio::ip::tcp>::`vector deleting destructor'(
        boost::asio::datagram_socket_service<boost::asio::ip::udp> *this,
        char a2)
{
  boost::asio::datagram_socket_service<boost::asio::ip::udp>::~datagram_socket_service<boost::asio::ip::udp>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
