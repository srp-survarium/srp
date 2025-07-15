void __userpurge vostok::network_core::http_client::http_client(
        vostok::network_core::http_client *this@<ecx>,
        int a2@<edi>,
        boost::asio::io_service *io_service)
{
  boost::asio::basic_streambuf<stlp_std::allocator<char> > *v3; // ecx
  boost::asio::basic_streambuf<stlp_std::allocator<char> > *v4; // ecx
  const stlp_std::allocator<char> *v5; // [esp+0h] [ebp-8h]
  const stlp_std::allocator<char> *v6; // [esp+0h] [ebp-8h]

  boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp>>::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp>>(
    io_service,
    (boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp> > *)a2);
  boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>(
    io_service,
    (boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > *)(a2 + 12));
  boost::asio::basic_streambuf<stlp_std::allocator<char>>::basic_streambuf<stlp_std::allocator<char>>(
    v3,
    a2 + 80,
    0xFFFFFFFF,
    v5);
  boost::asio::basic_streambuf<stlp_std::allocator<char>>::basic_streambuf<stlp_std::allocator<char>>(
    v4,
    a2 + 128,
    0xFFFFFFFF,
    v6);
  *(_DWORD *)(a2 + 192) = a2 + 176;
  *(_DWORD *)(a2 + 196) = a2 + 176;
  **(_BYTE **)(a2 + 192) = 0;
  *(_DWORD *)(a2 + 200) = 0;
  *(_DWORD *)(a2 + 232) = 0;
}
