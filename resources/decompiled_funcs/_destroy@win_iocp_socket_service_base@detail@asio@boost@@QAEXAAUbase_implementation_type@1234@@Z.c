void __thiscall boost::asio::detail::win_iocp_socket_service_base::destroy(
        boost::asio::detail::win_iocp_socket_service_base *this,
        boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl)
{
  boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex> lock; // [esp+C4h] [ebp-8h] BYREF

  boost::asio::detail::win_iocp_socket_service_base::close_for_destruction(this, impl);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&lock);
  lock.mutex_ = &this->mutex_;
  EnterCriticalSection(&this->mutex_.crit_section_);
  lock.locked_ = 1;
  if ( this->impl_list_ == impl )
    this->impl_list_ = impl->next_;
  if ( impl->prev_ )
    impl->prev_->next_ = impl->next_;
  if ( impl->next_ )
    impl->next_->prev_ = impl->prev_;
  impl->next_ = 0;
  impl->prev_ = 0;
  if ( lock.locked_ )
    LeaveCriticalSection(&lock.mutex_->crit_section_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&lock);
}
