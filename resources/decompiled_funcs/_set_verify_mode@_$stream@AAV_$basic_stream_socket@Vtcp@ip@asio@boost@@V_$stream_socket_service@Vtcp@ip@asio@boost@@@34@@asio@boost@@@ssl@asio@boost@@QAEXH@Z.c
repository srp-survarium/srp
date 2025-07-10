void __thiscall boost::asio::ssl::stream<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>> &>::set_verify_mode(
        boost::asio::ssl::stream<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > &> *this,
        int v)
{
  int (__cdecl *verify_callback)(int, x509_store_ctx_st *); // eax

  boost::system::system_category();
  verify_callback = SSL_get_verify_callback(this->core_.engine_.ssl_);
  SSL_set_verify(this->core_.engine_.ssl_, v, verify_callback);
  boost::system::system_category();
}
