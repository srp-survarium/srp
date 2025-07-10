void __thiscall boost::asio::detail::win_iocp_io_service::shutdown_service(
        boost::asio::detail::win_iocp_io_service *this)
{
  _OVERLAPPED *v2; // [esp+28h] [ebp-4Ch]
  _DWORD v3[2]; // [esp+2Ch] [ebp-48h] BYREF
  _DWORD v4[2]; // [esp+34h] [ebp-40h] BYREF
  boost::asio::detail::win_iocp_operation *next; // [esp+3Ch] [ebp-38h]
  boost::asio::detail::win_iocp_operation *v6; // [esp+40h] [ebp-34h]
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *p_completed_ops; // [esp+44h] [ebp-30h]
  boost::asio::detail::win_iocp_operation *front; // [esp+48h] [ebp-2Ch]
  boost::asio::detail::timer_queue_base *i; // [esp+4Ch] [ebp-28h]
  _OVERLAPPED *overlapped; // [esp+54h] [ebp-20h] BYREF
  unsigned int completion_key; // [esp+58h] [ebp-1Ch] BYREF
  unsigned int bytes_transferred; // [esp+5Ch] [ebp-18h] BYREF
  boost::asio::detail::win_iocp_operation *op; // [esp+60h] [ebp-14h]
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> ops; // [esp+64h] [ebp-10h] BYREF
  _LARGE_INTEGER timeout; // [esp+6Ch] [ebp-8h] BYREF

  InterlockedExchange(&this->shutdown_, 1);
  if ( this->timer_thread_.p_ )
  {
    timeout.QuadPart = 1;
    SetWaitableTimer(this->waitable_timer_.handle, &timeout, 1, 0, 0, 0);
  }
  while ( InterlockedExchangeAdd(&this->outstanding_work_, 0) > 0 )
  {
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&ops);
    ops.front_ = 0;
    ops.back_ = 0;
    for ( i = this->timer_queues_.first_; i; i = i->next_ )
      i->get_all_timers(i, &ops);
    p_completed_ops = &this->completed_ops_;
    front = this->completed_ops_.front_;
    if ( front )
    {
      if ( ops.back_ )
        ops.back_->next_ = front;
      else
        ops.front_ = front;
      ops.back_ = p_completed_ops->back_;
      p_completed_ops->front_ = 0;
      p_completed_ops->back_ = 0;
    }
    if ( ops.front_ )
    {
      while ( 1 )
      {
        op = ops.front_;
        if ( !ops.front_ )
          break;
        v6 = ops.front_;
        next = ops.front_->next_;
        ops.front_ = next;
        if ( !next )
          ops.back_ = 0;
        v6->next_ = 0;
        InterlockedDecrement(&this->outstanding_work_);
        v4[0] = 0;
        v4[1] = boost::system::system_category();
        op->func_(0, op, (const boost::system::error_code *)v4, 0);
      }
    }
    else
    {
      bytes_transferred = 0;
      completion_key = 0;
      overlapped = 0;
      GetQueuedCompletionStatus(this->iocp_.handle, &bytes_transferred, &completion_key, &overlapped, 0x1F4u);
      if ( overlapped )
      {
        InterlockedDecrement(&this->outstanding_work_);
        v2 = overlapped;
        v3[0] = 0;
        v3[1] = boost::system::system_category();
        ((void (__cdecl *)(_DWORD, _OVERLAPPED *, _DWORD *, _DWORD))v2[1].InternalHigh)(0, v2, v3, 0);
      }
    }
    boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::~op_queue<boost::asio::detail::win_iocp_operation>((boost::asio::detail::op_queue<boost::asio::detail::timer_op> *)&ops);
  }
  if ( this->timer_thread_.p_ )
    boost::asio::detail::win_thread::join(this->timer_thread_.p_);
}
