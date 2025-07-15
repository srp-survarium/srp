vostok::animation::callback_return_type_enum __thiscall survarium::jump_logic_state_prepare::on_interval_end(
        survarium::jump_logic_state_prepare *this,
        vostok::animation::animation_callback_params *params)
{
  if ( params->animation->m_object == this->m_animation.first.m_object )
  {
    this->m_prepare_interval_ended = 1;
    params->interrupt_animation_player_tick = 1;
  }
  return 0;
}
