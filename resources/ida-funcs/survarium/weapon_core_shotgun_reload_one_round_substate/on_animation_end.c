vostok::animation::callback_return_type_enum __thiscall survarium::weapon_core_shotgun_reload_one_round_substate::on_animation_end(
        survarium::weapon_core_shotgun_reload_one_round_substate *this,
        vostok::animation::animation_callback_params *params)
{
  survarium::weapon_core *m_weapon; // esi

  params->interrupt_animation_player_tick = 0;
  m_weapon = this->m_weapon;
  if ( params->animated_object == m_weapon && params->animation->m_object == this->m_weapon_animation.m_object )
  {
    survarium::weapon_core::reload_one_round((survarium::weapon_core *)this, (int)m_weapon);
    params->interrupt_animation_player_tick = 1;
  }
  return 0;
}
