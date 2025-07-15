void __thiscall boost::detail::sp_counted_impl_p<boost::asio::ssl::detail::openssl_init_base::do_init>::dispose(
        boost::detail::sp_counted_impl_p<boost::asio::ssl::detail::openssl_init_base::do_init> *this)
{
  boost::checked_delete<boost::asio::ssl::detail::openssl_init_base::do_init>(this->px_);
}


void __thiscall boost::detail::sp_counted_impl_p<boost::asio::detail::win_mutex>::dispose(
        boost::detail::sp_counted_impl_p<boost::asio::detail::win_mutex> *this)
{
  boost::checked_delete<boost::asio::detail::win_mutex>(this->px_);
}
