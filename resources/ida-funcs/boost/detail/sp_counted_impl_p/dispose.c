void __thiscall boost::detail::sp_counted_impl_p<boost::asio::ssl::detail::openssl_init_base::do_init>::dispose(
        boost::detail::sp_counted_impl_p<boost::asio::ssl::detail::openssl_init_base::do_init> *this,
        unsigned int a2)
{
  if ( this->px_ )
    boost::asio::ssl::detail::openssl_init_base::do_init::`scalar deleting destructor'(
      (boost::asio::ssl::detail::openssl_init_base::do_init *)this,
      a2);
}


void __thiscall boost::detail::sp_counted_impl_p<boost::asio::detail::win_mutex>::dispose(
        boost::detail::sp_counted_impl_p<boost::asio::detail::win_mutex> *this)
{
  boost::asio::detail::win_mutex *px; // esi

  px = this->px_;
  if ( px )
  {
    DeleteCriticalSection(&this->px_->crit_section_);
    operator delete(px);
  }
}
