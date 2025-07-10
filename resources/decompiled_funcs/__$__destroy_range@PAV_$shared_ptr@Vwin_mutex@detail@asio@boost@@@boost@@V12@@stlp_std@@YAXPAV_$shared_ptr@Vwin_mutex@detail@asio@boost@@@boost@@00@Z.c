void __cdecl stlp_std::__destroy_range<boost::shared_ptr<boost::asio::detail::win_mutex> *,boost::shared_ptr<boost::asio::detail::win_mutex>>(
        boost::shared_ptr<boost::asio::detail::win_mutex> *__first,
        boost::shared_ptr<boost::asio::detail::win_mutex> *__last)
{
  while ( __first != __last )
  {
    if ( __first->pn.pi_ )
      boost::detail::sp_counted_base::release(__first->pn.pi_);
    ++__first;
  }
}
