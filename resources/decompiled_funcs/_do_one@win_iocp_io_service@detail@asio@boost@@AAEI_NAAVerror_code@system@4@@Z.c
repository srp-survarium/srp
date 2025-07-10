unsigned int __thiscall boost::asio::detail::win_iocp_io_service::do_one(
        boost::asio::detail::win_iocp_io_service *this,
        bool block,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v5; // [esp+4h] [ebp-C4h]
  const boost::system::error_category *v6; // [esp+8h] [ebp-C0h]
  const boost::system::error_category *v7; // [esp+20h] [ebp-A8h]
  boost::asio::detail::timer_queue_base *i; // [esp+50h] [ebp-78h]
  const boost::system::error_category *v9; // [esp+64h] [ebp-64h]
  const boost::system::error_category *v10; // [esp+74h] [ebp-54h]
  const boost::system::error_category *v11; // [esp+88h] [ebp-40h]
  const boost::system::error_category *Internal; // [esp+90h] [ebp-38h]
  boost::asio::detail::win_iocp_operation *op; // [esp+98h] [ebp-30h]
  boost::system::error_code result_ec; // [esp+9Ch] [ebp-2Ch] BYREF
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> ops; // [esp+A4h] [ebp-24h] BYREF
  boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex> lock; // [esp+ACh] [ebp-1Ch] BYREF
  _OVERLAPPED *overlapped; // [esp+B4h] [ebp-14h] BYREF
  unsigned int completion_key; // [esp+B8h] [ebp-10h] BYREF
  unsigned int last_error; // [esp+BCh] [ebp-Ch]
  unsigned int bytes_transferred; // [esp+C0h] [ebp-8h] BYREF
  int ok; // [esp+C4h] [ebp-4h]

  do
  {
    while ( 1 )
    {
      while ( 1 )
      {
        if ( InterlockedCompareExchange(&this->dispatch_required_, 0, 1) == 1 )
        {
          survarium::weapon_core::cast_weapon_core((survarium::game_options *)&lock);
          lock.mutex_ = &this->dispatch_mutex_;
          EnterCriticalSection(&this->dispatch_mutex_.crit_section_);
          lock.locked_ = 1;
          survarium::weapon_core::cast_weapon_core((survarium::game_options *)&ops);
          ops.front_ = 0;
          ops.back_ = 0;
          if ( this->completed_ops_.front_ )
          {
            ops = this->completed_ops_;
            this->completed_ops_.front_ = 0;
            this->completed_ops_.back_ = 0;
          }
          for ( i = this->timer_queues_.first_; i; i = i->next_ )
            i->get_ready_timers(i, &ops);
          boost::asio::detail::win_iocp_io_service::post_deferred_completions(this, &ops);
          boost::asio::detail::win_iocp_io_service::update_timeout(this);
          boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::~op_queue<boost::asio::detail::win_iocp_operation>((boost::asio::detail::op_queue<boost::asio::detail::timer_op> *)&ops);
          if ( lock.locked_ )
            LeaveCriticalSection(&lock.mutex_->crit_section_);
          survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&lock);
        }
        bytes_transferred = 0;
        completion_key = 0;
        overlapped = 0;
        SetLastError(0);
        ok = GetQueuedCompletionStatus(
               this->iocp_.handle,
               &bytes_transferred,
               &completion_key,
               &overlapped,
               block ? 0x1F4 : 0);
        last_error = GetLastError();
        if ( !overlapped )
          break;
        op = (boost::asio::detail::win_iocp_operation *)overlapped;
        v7 = boost::system::system_category();
        result_ec.m_val = last_error;
        result_ec.m_cat = v7;
        if ( completion_key == 2 )
        {
          Internal = (const boost::system::error_category *)op->Internal;
          result_ec.m_val = op->Offset;
          result_ec.m_cat = Internal;
          bytes_transferred = op->OffsetHigh;
        }
        else
        {
          op->Internal = (unsigned int)result_ec.m_cat;
          op->Offset = result_ec.m_val;
          op->OffsetHigh = bytes_transferred;
        }
        if ( InterlockedCompareExchange(&op->ready_, 1, 0) == 1 )
        {
          op->func_(this, op, &result_ec, bytes_transferred);
          v11 = boost::system::system_category();
          ec->m_val = 0;
          ec->m_cat = v11;
          if ( !InterlockedDecrement(&this->outstanding_work_) )
            boost::asio::detail::win_iocp_io_service::stop(this);
          return 1;
        }
      }
      if ( ok )
        break;
      if ( last_error != 258 )
      {
        v6 = boost::system::system_category();
        ec->m_val = last_error;
        ec->m_cat = v6;
        return 0;
      }
      if ( !block )
      {
        v10 = boost::system::system_category();
        ec->m_val = 0;
        ec->m_cat = v10;
        return 0;
      }
    }
  }
  while ( completion_key == 1 || !InterlockedExchangeAdd(&this->stopped_, 0) );
  if ( PostQueuedCompletionStatus(this->iocp_.handle, 0, 0, 0) )
  {
    v9 = boost::system::system_category();
    ec->m_val = 0;
    ec->m_cat = v9;
  }
  else
  {
    last_error = GetLastError();
    v5 = boost::system::system_category();
    ec->m_val = last_error;
    ec->m_cat = v5;
  }
  return 0;
}
