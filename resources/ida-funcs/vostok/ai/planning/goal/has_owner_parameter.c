char __thiscall vostok::ai::planning::goal::has_owner_parameter(vostok::ai::planning::goal *this)
{
  survarium::game_camera *v1; // ecx
  unsigned int i; // [esp+18h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    v1 = (survarium::game_camera *)(this->m_parameters.m_end - this->m_parameters.m_begin);
    if ( i >= (unsigned int)v1 )
      break;
    survarium::weapon_user_dead_state::finalize(v1);
    if ( !this->m_parameters.m_begin[i]->m_type )
      return 1;
  }
  return 0;
}
