void __thiscall boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex>::~scoped_lock<boost::asio::detail::win_mutex>(
        boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex> *this)
{
  if ( this->locked_ )
    LeaveCriticalSection(&this->mutex_->crit_section_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
