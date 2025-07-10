void __thiscall boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::reset(
        boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread> *this,
        boost::asio::detail::win_thread *p)
{
  boost::asio::detail::win_thread *v3; // [esp+Ch] [ebp-4h]

  v3 = this->p_;
  if ( this->p_ )
  {
    CloseHandle(v3->thread_);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v3);
    operator delete(v3);
  }
  this->p_ = p;
}
