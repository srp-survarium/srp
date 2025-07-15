vostok::animation::callback_return_type_enum __thiscall survarium::weapon_core_shotgun_reload_start_substate::on_animation_end(
        survarium::weapon_core_shotgun_reload_start_substate *this,
        vostok::animation::animation_callback_params *params)
{
  survarium::weapon_core *animated_object; // edx

  animated_object = (survarium::weapon_core *)params->animated_object;
  params->interrupt_animation_player_tick = 0;
  if ( animated_object == this->m_weapon && params->animation->m_object == this->m_weapon_animation.m_object )
  {
    this->m_animation_ended = 1;
    params->interrupt_animation_player_tick = 1;
  }
  return 0;
}
