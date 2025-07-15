void __thiscall boost::asio::detail::win_thread::func<boost::asio::detail::win_iocp_io_service::timer_thread_function>::run(
        boost::asio::detail::win_thread::func<boost::asio::detail::win_iocp_io_service::timer_thread_function> *this)
{
  while ( !InterlockedExchangeAdd(&this->f_.io_service_->shutdown_, 0) )
  {
    if ( !WaitForSingleObject(this->f_.io_service_->waitable_timer_.handle, 0xFFFFFFFF) )
    {
      InterlockedExchange(&this->f_.io_service_->dispatch_required_, 1);
      PostQueuedCompletionStatus(this->f_.io_service_->iocp_.handle, 0, 1u, 0);
    }
  }
}


void __thiscall boost::asio::detail::win_thread::func<boost::asio::detail::resolver_service_base::work_io_service_runner>::run(
        boost::asio::detail::win_thread::func<boost::asio::detail::resolver_service_base::work_io_service_runner> *this)
{
  boost::asio::io_service::run((boost::asio::io_service *)this, (int)this->f_.io_service_);
}


void __thiscall boost::asio::detail::win_thread::func<boost::asio::detail::binder1<void (__cdecl *)(boost::asio::detail::select_reactor *),boost::asio::detail::select_reactor *>>::run(
        boost::asio::detail::win_thread::func<boost::asio::detail::binder1<void (__cdecl*)(boost::asio::detail::select_reactor *),boost::asio::detail::select_reactor *> > *this)
{
  this->f_.handler_(this->f_.arg1_);
}
