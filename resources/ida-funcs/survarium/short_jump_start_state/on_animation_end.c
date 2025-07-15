vostok::animation::callback_return_type_enum __thiscall survarium::short_jump_start_state::on_animation_end(
        survarium::short_jump_start_state *this,
        vostok::animation::animation_callback_params *params)
{
  if ( params->animated_object == this->m_jump_logic->m_owner->m_user
    && params->animation->m_object == this->m_animation.first.m_object )
  {
    this->m_jump_animation_ended = 1;
    params->interrupt_animation_player_tick = 1;
  }
  return 0;
}
