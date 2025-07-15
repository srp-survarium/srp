vostok::animation::callback_return_type_enum __thiscall survarium::player_logic_dead_state::on_animation_end(
        survarium::player_logic_dead_state *this,
        vostok::animation::animation_callback_params *params)
{
  if ( params->animation->m_object == this->m_animation.first.m_object )
  {
    this->m_is_ready_to_be_deactivated = 1;
    params->interrupt_animation_player_tick = 1;
  }
  return 0;
}
