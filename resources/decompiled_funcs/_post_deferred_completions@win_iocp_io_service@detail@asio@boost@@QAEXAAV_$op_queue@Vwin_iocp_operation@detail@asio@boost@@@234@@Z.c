void __thiscall boost::asio::detail::win_iocp_io_service::post_deferred_completions(
        boost::asio::detail::win_iocp_io_service *this,
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *ops)
{
  boost::asio::detail::win_iocp_operation *v3; // [esp+Ch] [ebp-28h]
  boost::asio::detail::win_iocp_operation *v4; // [esp+10h] [ebp-24h]
  boost::asio::detail::win_iocp_operation *front; // [esp+24h] [ebp-10h]
  boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex> lock; // [esp+28h] [ebp-Ch] BYREF
  boost::asio::detail::win_iocp_operation *op; // [esp+30h] [ebp-4h]

  while ( 1 )
  {
    op = ops->front_;
    if ( !op )
      break;
    if ( ops->front_ )
    {
      front = ops->front_;
      ops->front_ = ops->front_->next_;
      if ( !ops->front_ )
        ops->back_ = 0;
      front->next_ = 0;
    }
    op->ready_ = 1;
    if ( !PostQueuedCompletionStatus(this->iocp_.handle, 0, 2u, op) )
    {
      survarium::weapon_core::cast_weapon_core((survarium::game_options *)&lock);
      lock.mutex_ = &this->dispatch_mutex_;
      EnterCriticalSection(&this->dispatch_mutex_.crit_section_);
      lock.locked_ = 1;
      v4 = op;
      op->next_ = 0;
      if ( this->completed_ops_.back_ )
      {
        this->completed_ops_.back_->next_ = v4;
        this->completed_ops_.back_ = v4;
      }
      else
      {
        this->completed_ops_.back_ = v4;
        this->completed_ops_.front_ = v4;
      }
      v3 = ops->front_;
      if ( ops->front_ )
      {
        if ( this->completed_ops_.back_ )
          this->completed_ops_.back_->next_ = v3;
        else
          this->completed_ops_.front_ = v3;
        this->completed_ops_.back_ = ops->back_;
        ops->front_ = 0;
        ops->back_ = 0;
      }
      InterlockedExchange(&this->dispatch_required_, 1);
      if ( lock.locked_ )
        LeaveCriticalSection(&lock.mutex_->crit_section_);
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&lock);
    }
  }
}
