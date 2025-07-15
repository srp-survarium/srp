vostok::animation::callback_return_type_enum __thiscall survarium::jump_logic_state_start::on_jump_event(
        survarium::jump_logic_state_start *this,
        vostok::animation::animation_callback_params *params)
{
  survarium::player_stamina *v2; // eax
  float amount; // [esp+8h] [ebp-18h]
  survarium::player_stamina *v6; // [esp+Ch] [ebp-14h]
  survarium::game_camera *m_owner; // [esp+18h] [ebp-8h]

  if ( params->animation_interval_id == this->m_interval_id_to_wait_for )
  {
    m_owner = (survarium::game_camera *)this->m_jump_logic->m_owner;
    survarium::weapon_user_dead_state::finalize(m_owner);
    if ( params->animated_object == m_owner->m_game_scene )
    {
      params->interrupt_animation_player_tick = 0;
      v6 = this->m_user->stamina(this->m_user);
      amount = (float)(v6->m_max_value * v6->m_max_value_factor) / 5.0;
      v2 = this->m_user->stamina(this->m_user);
      survarium::player_stamina::spend(v2, amount);
      this->m_user->jump(this->m_user);
    }
  }
  return 0;
}
