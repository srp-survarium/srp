vostok::animation::callback_return_type_enum __thiscall survarium::weapon_core_shotgun_reload_finish_substate::on_animation_end(
        survarium::weapon_core_shotgun_reload_finish_substate *this,
        vostok::animation::animation_callback_params *params)
{
  survarium::weapon_core *animated_object; // esi
  survarium::weapon_core *m_weapon; // ecx

  animated_object = (survarium::weapon_core *)params->animated_object;
  params->interrupt_animation_player_tick = 0;
  if ( animated_object == this->m_weapon && params->animation->m_object == this->m_weapon_animation.m_object )
  {
    *this->m_owner_ready_for_transition = 1;
    params->interrupt_animation_player_tick = 1;
    m_weapon = this->m_weapon;
    if ( m_weapon->m_chamber_a_round_on_reload )
    {
      if ( m_weapon->m_ammo_in_magazine )
        survarium::weapon_core::instant_chamber_a_round(m_weapon, (int *)m_weapon);
    }
  }
  return 0;
}
