void __thiscall boost::detail::sp_counted_impl_p<boost::asio::detail::win_mutex>::dispose(
        boost::detail::sp_counted_impl_p<boost::asio::detail::win_mutex> *this)
{
  boost::checked_delete<boost::asio::detail::win_mutex>(this->px_);
}
