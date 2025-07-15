boost::asio::detail::win_thread::func<boost::asio::detail::win_iocp_io_service::timer_thread_function> *__thiscall boost::asio::detail::win_thread::func<boost::asio::detail::binder1<void (__cdecl *)(boost::asio::detail::select_reactor *),boost::asio::detail::select_reactor *>>::`scalar deleting destructor'(
        boost::asio::detail::win_thread::func<boost::asio::detail::win_iocp_io_service::timer_thread_function> *this,
        char a2)
{
  this->__vftable = (boost::asio::detail::win_thread::func<boost::asio::detail::win_iocp_io_service::timer_thread_function>_vtbl *)&boost::asio::detail::win_thread::func_base::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
