void __thiscall boost::asio::detail::select_reactor::run_thread(boost::asio::detail::select_reactor *this)
{
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> ops; // [esp+8Ch] [ebp-10h] BYREF
  boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex> lock; // [esp+94h] [ebp-8h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&lock);
  lock.mutex_ = &this->mutex_;
  EnterCriticalSection(&this->mutex_.crit_section_);
  lock.locked_ = 1;
  while ( !this->stop_thread_ )
  {
    if ( lock.locked_ )
    {
      LeaveCriticalSection(&lock.mutex_->crit_section_);
      lock.locked_ = 0;
    }
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&ops);
    ops.front_ = 0;
    ops.back_ = 0;
    boost::asio::detail::select_reactor::run(this, 1, &ops);
    boost::asio::detail::win_iocp_io_service::post_deferred_completions(this->io_service_, &ops);
    if ( !lock.locked_ )
    {
      EnterCriticalSection(&lock.mutex_->crit_section_);
      lock.locked_ = 1;
    }
    boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::~op_queue<boost::asio::detail::win_iocp_operation>((boost::asio::detail::op_queue<boost::asio::detail::timer_op> *)&ops);
  }
  boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex>::~scoped_lock<boost::asio::detail::win_mutex>(&lock);
}
