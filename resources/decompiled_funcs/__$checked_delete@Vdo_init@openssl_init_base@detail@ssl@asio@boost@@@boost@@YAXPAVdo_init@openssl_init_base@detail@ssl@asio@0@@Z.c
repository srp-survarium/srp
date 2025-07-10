void __cdecl boost::checked_delete<boost::asio::ssl::detail::openssl_init_base::do_init>(
        boost::asio::ssl::detail::openssl_init_base::do_init *x)
{
  if ( x )
  {
    boost::asio::ssl::detail::openssl_init_base::do_init::~do_init(x);
    operator delete(x);
  }
}
