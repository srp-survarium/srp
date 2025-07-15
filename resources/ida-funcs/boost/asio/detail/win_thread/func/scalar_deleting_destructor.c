boost::asio::detail::win_thread::func<boost::asio::detail::resolver_service_base::work_io_service_runner> *__thiscall boost::asio::detail::win_thread::func<boost::asio::detail::binder1<void (__cdecl *)(boost::asio::detail::select_reactor *),boost::asio::detail::select_reactor *>>::`scalar deleting destructor'(
        boost::asio::detail::win_thread::func<boost::asio::detail::resolver_service_base::work_io_service_runner> *this,
        char a2)
{
  this->__vftable = (boost::asio::detail::win_thread::func<boost::asio::detail::resolver_service_base::work_io_service_runner>_vtbl *)&boost::asio::detail::win_thread::func_base::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
