void __thiscall boost::asio::detail::select_reactor::deregister_descriptor(
        boost::asio::detail::select_reactor *this,
        unsigned int descriptor,
        boost::asio::detail::select_reactor::per_descriptor_data *__formal,
        bool a4)
{
  boost::system::error_code ec; // [esp+50h] [ebp-10h] BYREF
  boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex> lock; // [esp+58h] [ebp-8h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&lock);
  lock.mutex_ = &this->mutex_;
  EnterCriticalSection(&this->mutex_.crit_section_);
  lock.locked_ = 1;
  ec.m_val = 995;
  ec.m_cat = boost::system::system_category();
  boost::asio::detail::select_reactor::cancel_ops_unlocked(this, descriptor, &ec);
  if ( lock.locked_ )
    LeaveCriticalSection(&lock.mutex_->crit_section_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&lock);
}
