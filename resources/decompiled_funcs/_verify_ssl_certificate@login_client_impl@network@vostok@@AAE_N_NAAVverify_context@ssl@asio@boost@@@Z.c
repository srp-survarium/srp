bool __thiscall vostok::network::login_client_impl::verify_ssl_certificate(
        vostok::network::login_client_impl *this,
        bool preverified,
        boost::asio::ssl::verify_context *verify_context)
{
  return preverified;
}
