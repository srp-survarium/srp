char __thiscall survarium::body_part_parameters::is_affect_applied(
        survarium::body_part_parameters *this,
        survarium::hit_affects_type_enum affect)
{
  survarium::game_camera *v2; // ecx
  unsigned int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    v2 = (survarium::game_camera *)(this->m_affects.m_end - this->m_affects.m_begin);
    if ( i >= (unsigned int)v2 )
      break;
    survarium::weapon_user_dead_state::finalize(v2);
    if ( this->m_affects.m_begin[i].first == affect )
      return 1;
  }
  return 0;
}
