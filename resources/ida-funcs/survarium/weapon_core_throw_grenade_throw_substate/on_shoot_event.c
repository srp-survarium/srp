vostok::animation::callback_return_type_enum __thiscall survarium::weapon_core_throw_grenade_throw_substate::on_shoot_event(
        survarium::weapon_core_throw_grenade_throw_substate *this,
        vostok::animation::animation_callback_params *params)
{
  if ( params->animated_object == this->m_weapon->m_user
    && params->animation->m_object == this->m_user_animations[0][this->m_index_of_animation_to_wait].m_object )
  {
    survarium::weapon_core_throw_grenade_state::on_throw_event_fired(
      (survarium::weapon_core_throw_grenade_state *)this,
      (int)this->m_owner);
  }
  return 0;
}
