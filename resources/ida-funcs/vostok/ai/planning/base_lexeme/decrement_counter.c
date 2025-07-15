void __thiscall vostok::ai::planning::base_lexeme::decrement_counter(vostok::ai::planning::base_lexeme *this)
{
  survarium::game_camera *m_destroy_manually; // ecx

  m_destroy_manually = (survarium::game_camera *)this->m_destroy_manually;
  if ( m_destroy_manually )
  {
    survarium::weapon_user_dead_state::finalize(m_destroy_manually);
    if ( !--this->m_counter )
      ((void (__thiscall *)(vostok::ai::planning::base_lexeme *, _DWORD))this->~vostok::ai::planning::base_lexeme)(
        this,
        0);
  }
}
