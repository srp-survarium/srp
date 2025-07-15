vostok::animation::callback_return_type_enum __thiscall survarium::weapon_core_throw_grenade_base_substate::on_animation_end(
        survarium::weapon_core_throw_grenade_base_substate *this,
        vostok::animation::animation_callback_params *params)
{
  if ( params->animated_object == this->m_weapon->m_user
    && params->animation->m_object == this->m_user_animations[0][this->m_index_of_animation_to_wait].m_object )
  {
    this->m_animation_has_been_ended = 1;
    params->interrupt_animation_player_tick = 1;
  }
  return 0;
}
