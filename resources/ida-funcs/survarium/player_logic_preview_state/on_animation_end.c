vostok::animation::callback_return_type_enum __thiscall survarium::player_logic_preview_state::on_animation_end(
        survarium::player_logic_preview_state *this,
        vostok::animation::animation_callback_params *params)
{
  bool v2; // cl

  v2 = params->animated_object == this->m_user && params->animation->m_object == this->m_animation_to_wait.m_object;
  params->interrupt_animation_player_tick = v2;
  return 0;
}
