void __thiscall boost::asio::detail::win_iocp_socket_service_base::shutdown_service(
        boost::asio::detail::win_iocp_socket_service_base *this)
{
  boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl; // [esp+CCh] [ebp-Ch]
  boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex> lock; // [esp+D0h] [ebp-8h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&lock);
  lock.mutex_ = &this->mutex_;
  EnterCriticalSection(&this->mutex_.crit_section_);
  lock.locked_ = 1;
  for ( impl = this->impl_list_; impl; impl = impl->next_ )
  {
    boost::system::system_category();
    boost::asio::detail::win_iocp_socket_service_base::close_for_destruction(this, impl);
  }
  if ( lock.locked_ )
    LeaveCriticalSection(&lock.mutex_->crit_section_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&lock);
}
