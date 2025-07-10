void __thiscall boost::asio::detail::win_iocp_io_service::on_pending(
        boost::asio::detail::win_iocp_io_service *this,
        boost::asio::detail::win_iocp_operation *op)
{
  boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex> lock; // [esp+18h] [ebp-8h] BYREF

  if ( InterlockedCompareExchange(&op->ready_, 1, 0) == 1 && !PostQueuedCompletionStatus(this->iocp_.handle, 0, 2u, op) )
  {
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&lock);
    lock.mutex_ = &this->dispatch_mutex_;
    EnterCriticalSection(&this->dispatch_mutex_.crit_section_);
    lock.locked_ = 1;
    op->next_ = 0;
    if ( this->completed_ops_.back_ )
    {
      this->completed_ops_.back_->next_ = op;
      this->completed_ops_.back_ = op;
    }
    else
    {
      this->completed_ops_.back_ = op;
      this->completed_ops_.front_ = op;
    }
    InterlockedExchange(&this->dispatch_required_, 1);
    if ( lock.locked_ )
      LeaveCriticalSection(&lock.mutex_->crit_section_);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&lock);
  }
}
