vostok::animation::callback_return_type_enum __thiscall survarium::weapon_core_melee_state::on_animation_end(
        survarium::weapon_core_melee_state *this,
        vostok::animation::animation_callback_params *params)
{
  vostok::resources::managed_resource *m_object; // eax

  if ( params->animated_object == this->m_weapon->m_user )
  {
    m_object = params->animation->m_object;
    if ( m_object == this->m_animations[0][0].m_object || m_object == this->m_animations[0][1].m_object )
    {
      this->m_animation_has_been_ended = 1;
      params->interrupt_animation_player_tick = 1;
    }
  }
  return 0;
}
