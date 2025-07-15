void __thiscall survarium::breath_state_holding::tick(survarium::breath_state_holding *this, float dt)
{
  float v2; // xmm0_4

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v2 = *this->m_breath_holding_reserve - dt;
  vostok::math::max();
  *this->m_breath_holding_reserve = v2;
}
