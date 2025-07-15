void __thiscall survarium::game_world::clear_enemies_positions_for_team(
        survarium::game_world *this,
        const char *team_name)
{
  vostok::math::float3 *M_start; // eax
  vostok::math::float3 *v4; // eax

  if ( !strcmp(team_name, (const char *)stru_95AF78.m_key_bindings[5].m_keyboard) )
  {
    M_start = this->m_enemies_for_team_1._M_impl._M_start;
    if ( M_start != this->m_enemies_for_team_1._M_impl._M_finish )
      this->m_enemies_for_team_1._M_impl._M_finish = M_start;
  }
  else if ( !strcmp(team_name, "2") )
  {
    v4 = this->m_enemies_for_team_2._M_impl._M_start;
    if ( v4 != this->m_enemies_for_team_2._M_impl._M_finish )
      this->m_enemies_for_team_2._M_impl._M_finish = v4;
  }
}
