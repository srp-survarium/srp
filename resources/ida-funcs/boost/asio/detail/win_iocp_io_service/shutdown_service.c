void __thiscall boost::asio::detail::win_iocp_io_service::shutdown_service(
        boost::asio::detail::win_iocp_io_service *this)
{
  LONG i; // eax
  boost::asio::detail::win_thread *v3; // ecx
  boost::asio::detail::timer_queue_base *first; // esi
  unsigned int LowPart; // eax
  unsigned int v6; // esi
  unsigned int *v7; // eax
  boost::asio::detail::win_iocp_operation *v8; // ecx
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *v9; // ecx
  boost::asio::detail::win_iocp_operation *v10; // ecx
  boost::asio::detail::win_thread *p; // ebx
  void *handle; // [esp-18h] [ebp-38h]
  void *v13; // [esp-14h] [ebp-34h]
  LPOVERLAPPED Overlapped; // [esp+Ch] [ebp-14h] BYREF
  unsigned int CompletionKey; // [esp+10h] [ebp-10h] BYREF
  unsigned int NumberOfBytesTransferred; // [esp+14h] [ebp-Ch] BYREF
  LARGE_INTEGER DueTime; // [esp+18h] [ebp-8h] BYREF

  InterlockedExchange(&this->shutdown_, 1);
  if ( this->timer_thread_.p_ )
  {
    handle = this->waitable_timer_.handle;
    DueTime.QuadPart = 1;
    SetWaitableTimer(handle, &DueTime, 1, 0, 0, 0);
  }
  for ( i = InterlockedExchangeAdd(&this->outstanding_work_, 0);
        i > 0;
        i = InterlockedExchangeAdd(&this->outstanding_work_, 0) )
  {
    first = this->timer_queues_.first_;
    DueTime.QuadPart = 0;
    while ( first )
    {
      first->get_all_timers(first, (boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *)&DueTime);
      first = first->next_;
    }
    boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::push<boost::asio::detail::win_iocp_operation>(
      (boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *)&DueTime,
      &this->completed_ops_);
    LowPart = DueTime.LowPart;
    if ( DueTime.LowPart )
    {
      v6 = DueTime.LowPart;
      do
      {
        v7 = (unsigned int *)(LowPart + 20);
        DueTime.LowPart = *v7;
        if ( !DueTime.LowPart )
          DueTime.QuadPart = 0;
        *v7 = 0;
        InterlockedDecrement(&this->outstanding_work_);
        boost::asio::detail::win_iocp_operation::destroy(v8, v6);
        LowPart = DueTime.LowPart;
        v6 = DueTime.LowPart;
      }
      while ( DueTime.LowPart );
    }
    else
    {
      v13 = this->iocp_.handle;
      NumberOfBytesTransferred = 0;
      CompletionKey = 0;
      Overlapped = 0;
      GetQueuedCompletionStatus(v13, &NumberOfBytesTransferred, &CompletionKey, &Overlapped, 0x1F4u);
      if ( Overlapped )
      {
        InterlockedDecrement(&this->outstanding_work_);
        boost::asio::detail::win_iocp_operation::destroy(v10, (int)Overlapped);
      }
    }
    boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::~op_queue<boost::asio::detail::win_iocp_operation>(
      v9,
      (int *)&DueTime);
  }
  p = this->timer_thread_.p_;
  if ( p )
    boost::asio::detail::win_thread::join(v3, (int)p);
}
