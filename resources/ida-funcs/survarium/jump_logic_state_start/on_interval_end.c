vostok::animation::callback_return_type_enum __thiscall survarium::jump_logic_state_start::on_interval_end(
        survarium::jump_logic_state_start *this,
        vostok::animation::animation_callback_params *params)
{
  if ( params->animated_object == this->m_jump_logic->m_owner->m_user
    && params->animation->m_object == this->m_animation.first.m_object
    && params->animation_interval_id == this->m_interval_id_to_wait_for )
  {
    this->m_jump_interval_ended = 1;
    params->interrupt_animation_player_tick = 1;
  }
  return 0;
}
