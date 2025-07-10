void __thiscall boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::~scoped_ptr<boost::asio::detail::win_thread>(
        boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread> *this)
{
  boost::asio::detail::win_thread *p; // [esp+Ch] [ebp-4h]

  p = this->p_;
  if ( this->p_ )
  {
    CloseHandle(p->thread_);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)p);
    operator delete(p);
  }
}
