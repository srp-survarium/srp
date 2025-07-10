void __thiscall boost::asio::detail::select_reactor::shutdown_service(boost::asio::detail::select_reactor *this)
{
  boost::asio::detail::timer_queue_base *j; // [esp+34h] [ebp-64h]
  boost::asio::detail::win_thread *thread; // [esp+80h] [ebp-18h]
  int i; // [esp+84h] [ebp-14h]
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> ops; // [esp+88h] [ebp-10h] BYREF
  boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex> lock; // [esp+90h] [ebp-8h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&lock);
  lock.mutex_ = &this->mutex_;
  EnterCriticalSection(&this->mutex_.crit_section_);
  lock.locked_ = 1;
  this->shutdown_ = 1;
  this->stop_thread_ = 1;
  if ( lock.locked_ )
  {
    LeaveCriticalSection(&lock.mutex_->crit_section_);
    lock.locked_ = 0;
  }
  if ( this->thread_ )
  {
    boost::asio::detail::socket_select_interrupter::interrupt(&this->interrupter_);
    boost::asio::detail::win_thread::join(this->thread_);
    thread = this->thread_;
    if ( thread )
    {
      CloseHandle(thread->thread_);
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)thread);
      operator delete(thread);
    }
    this->thread_ = 0;
  }
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&ops);
  ops.front_ = 0;
  ops.back_ = 0;
  for ( i = 0; i < 4; ++i )
    boost::asio::detail::reactor_op_queue<unsigned int>::get_all_operations(&this->op_queue_[i], &ops);
  for ( j = this->timer_queues_.first_; j; j = j->next_ )
    j->get_all_timers(j, &ops);
  boost::asio::detail::win_iocp_io_service::abandon_operations(this->io_service_, &ops);
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::~op_queue<boost::asio::detail::win_iocp_operation>((boost::asio::detail::op_queue<boost::asio::detail::timer_op> *)&ops);
  if ( lock.locked_ )
    LeaveCriticalSection(&lock.mutex_->crit_section_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&lock);
}
