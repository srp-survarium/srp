void __thiscall boost::asio::detail::win_iocp_io_service::timer_thread_function::operator()(
        boost::asio::detail::win_iocp_io_service::timer_thread_function *this)
{
  while ( !InterlockedExchangeAdd(&this->io_service_->shutdown_, 0) )
  {
    if ( !WaitForSingleObject(this->io_service_->waitable_timer_.handle, 0xFFFFFFFF) )
    {
      InterlockedExchange(&this->io_service_->dispatch_required_, 1);
      PostQueuedCompletionStatus(this->io_service_->iocp_.handle, 0, 1u, 0);
    }
  }
}
