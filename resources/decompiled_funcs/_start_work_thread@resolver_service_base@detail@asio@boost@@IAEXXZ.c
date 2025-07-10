void __thiscall boost::asio::detail::resolver_service_base::start_work_thread(
        boost::asio::detail::resolver_service_base *this)
{
  boost::asio::detail::win_thread *v1; // eax
  boost::asio::detail::win_thread *v3; // [esp+28h] [ebp-Ch]
  boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex> lock; // [esp+2Ch] [ebp-8h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&lock);
  lock.mutex_ = &this->mutex_;
  EnterCriticalSection(&this->mutex_.crit_section_);
  lock.locked_ = 1;
  if ( !this->work_thread_.p_ )
  {
    v3 = (boost::asio::detail::win_thread *)operator new(0xCu);
    if ( v3 )
    {
      boost::asio::detail::win_thread::win_thread(
        v3,
        (boost::asio::detail::resolver_service_base::work_io_service_runner)this->work_io_service_.p_,
        0);
      boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::reset(&this->work_thread_, v1);
    }
    else
    {
      boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::reset(&this->work_thread_, 0);
    }
  }
  if ( lock.locked_ )
    LeaveCriticalSection(&lock.mutex_->crit_section_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&lock);
}
