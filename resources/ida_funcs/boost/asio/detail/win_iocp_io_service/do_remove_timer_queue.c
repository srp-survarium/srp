void __thiscall boost::asio::detail::win_iocp_io_service::do_remove_timer_queue(
        boost::asio::detail::win_iocp_io_service *this,
        boost::asio::detail::timer_queue_base *queue)
{
  boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex> lock; // [esp+10h] [ebp-8h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&lock);
  lock.mutex_ = &this->dispatch_mutex_;
  EnterCriticalSection(&this->dispatch_mutex_.crit_section_);
  lock.locked_ = 1;
  boost::asio::detail::timer_queue_set::erase(&this->timer_queues_, queue);
  if ( lock.locked_ )
    LeaveCriticalSection(&lock.mutex_->crit_section_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&lock);
}
