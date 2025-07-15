void __userpurge boost::asio::detail::win_iocp_io_service::win_iocp_io_service(
        boost::asio::detail::win_iocp_io_service *this@<esi>,
        boost::asio::io_service *io_service@<eax>,
        boost::asio::detail::win_mutex *a3@<ecx>,
        DWORD concurrency_hint)
{
  HANDLE IoCompletionPort; // eax
  boost::system::error_code err; // [esp+8h] [ebp-Ch] BYREF

  this->key_.type_info_ = 0;
  this->key_.id_ = 0;
  this->owner_ = io_service;
  this->next_ = 0;
  this->__vftable = (boost::asio::detail::win_iocp_io_service_vtbl *)&boost::asio::detail::win_iocp_io_service::`vftable';
  this->iocp_.handle = 0;
  this->outstanding_work_ = 0;
  this->stopped_ = 0;
  this->shutdown_ = 0;
  this->timer_thread_.p_ = 0;
  this->waitable_timer_.handle = 0;
  this->dispatch_required_ = 0;
  boost::asio::detail::win_mutex::win_mutex(a3, &this->dispatch_mutex_);
  err.m_cat = (const boost::system::error_category *)-1;
  this->timer_queues_.first_ = 0;
  this->completed_ops_.front_ = 0;
  this->completed_ops_.back_ = 0;
  IoCompletionPort = CreateIoCompletionPort((HANDLE)0xFFFFFFFF, 0, 0, concurrency_hint);
  this->iocp_.handle = IoCompletionPort;
  if ( !IoCompletionPort )
  {
    err.m_val = GetLastError();
    err.m_cat = boost::system::system_category();
    if ( (err.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
      boost::asio::detail::do_throw_error(&err, "iocp");
  }
}
