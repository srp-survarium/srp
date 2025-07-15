void __thiscall survarium::weapon_core::tick(survarium::weapon_core *this, unsigned int current_time_in_ms)
{
  survarium::base_player *m_user; // esi
  survarium::weapon_core *v4; // ecx
  bool v5; // al

  m_user = this->m_user;
  this->m_last_tick_time_in_ms = current_time_in_ms;
  if ( m_user->m_is_alive )
  {
    v5 = survarium::player_input::is_moving(&m_user->m_input)
      && m_user->damage_model(&m_user->survarium::inventory_holder)->m_object->m_broken_legs_count < 2u;
    survarium::weapon_core::update_dispersion(v4, (int)this, (int)m_user, v5, current_time_in_ms);
  }
  survarium::transition_helper::tick(&this->m_aim_progress, current_time_in_ms);
}
