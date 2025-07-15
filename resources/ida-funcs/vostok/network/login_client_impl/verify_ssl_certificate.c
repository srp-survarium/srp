bool __thiscall vostok::network::login_client_impl::verify_ssl_certificate(
        vostok::network::login_client_impl *this,
        const bool preverified,
        boost::asio::ssl::verify_context *verify_context)
{
  return preverified;
}
