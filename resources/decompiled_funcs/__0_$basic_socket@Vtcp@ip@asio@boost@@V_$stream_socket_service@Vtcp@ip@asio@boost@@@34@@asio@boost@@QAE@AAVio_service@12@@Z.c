void __thiscall boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>(
        boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > *this,
        boost::asio::io_service *io_service)
{
  boost::asio::basic_io_object<boost::asio::stream_socket_service<boost::asio::ip::tcp>>::basic_io_object<boost::asio::stream_socket_service<boost::asio::ip::tcp>>(
    this,
    io_service);
}
