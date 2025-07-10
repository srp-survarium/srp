void __cdecl boost::checked_delete<boost::asio::detail::win_mutex>(boost::asio::detail::win_mutex *x)
{
  if ( x )
  {
    DeleteCriticalSection(&x->crit_section_);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)x);
    operator delete(x);
  }
}
