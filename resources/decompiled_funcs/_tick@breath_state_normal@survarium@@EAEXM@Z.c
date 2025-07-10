void __thiscall survarium::breath_state_normal::tick(survarium::breath_state_normal *this, float dt)
{
  float max_breath_holding_time; // xmm0_4

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  max_breath_holding_time = this->m_params->max_breath_holding_time;
  vostok::math::min();
  *this->m_breath_holding_reserve = max_breath_holding_time;
}
