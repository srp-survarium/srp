void __thiscall boost::asio::detail::win_thread::func<boost::asio::detail::binder1<void (__cdecl *)(boost::asio::detail::select_reactor *),boost::asio::detail::select_reactor *>>::run(
        boost::asio::detail::win_thread::func<boost::asio::detail::binder1<void (__cdecl*)(boost::asio::detail::select_reactor *),boost::asio::detail::select_reactor *> > *this)
{
  this->f_.handler_(this->f_.arg1_);
}
