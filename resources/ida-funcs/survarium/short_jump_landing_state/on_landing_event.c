vostok::animation::callback_return_type_enum __thiscall survarium::short_jump_landing_state::on_landing_event(
        survarium::short_jump_landing_state *this,
        vostok::animation::animation_callback_params *params)
{
  vostok::resources::managed_resource *m_object; // ecx
  const void *v5; // [esp+0h] [ebp-8h]

  if ( params->animation_interval_id == this->m_interval_id_to_wait_for
    && params->animated_object == this->m_jump_logic->m_owner->m_user )
  {
    m_object = params->animation->m_object;
    if ( m_object == this->m_animation.first.m_object )
    {
      params->interrupt_animation_player_tick = 1;
      survarium::weapon_user_animations_selector::remove_animation_callback(
        (survarium::weapon_user_animations_selector *)m_object,
        (int)this->m_jump_logic->m_owner,
        (const char *)this,
        v5);
      this->m_is_jump_finished = 1;
    }
  }
  return 0;
}
