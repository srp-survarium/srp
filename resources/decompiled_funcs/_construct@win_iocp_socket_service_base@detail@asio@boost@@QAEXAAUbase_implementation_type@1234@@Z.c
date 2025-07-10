void __thiscall boost::asio::detail::win_iocp_socket_service_base::construct(
        boost::asio::detail::win_iocp_socket_service_base *this,
        boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl)
{
  boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex> lock; // [esp+2Ch] [ebp-8h] BYREF

  impl->socket_ = -1;
  impl->state_ = 0;
  boost::shared_ptr<void>::reset(&impl->cancel_token_);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&lock);
  lock.mutex_ = &this->mutex_;
  EnterCriticalSection(&this->mutex_.crit_section_);
  lock.locked_ = 1;
  impl->next_ = this->impl_list_;
  impl->prev_ = 0;
  if ( this->impl_list_ )
    this->impl_list_->prev_ = impl;
  this->impl_list_ = impl;
  if ( lock.locked_ )
    LeaveCriticalSection(&lock.mutex_->crit_section_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&lock);
}
