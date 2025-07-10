void __thiscall survarium::legs_ik_processor::leg_params::tick(
        survarium::legs_ik_processor::leg_params *this,
        float dt)
{
  float v2; // xmm0_4
  float v3; // xmm0_4

  v2 = this->heel_transition_time - dt;
  vostok::math::max();
  this->heel_transition_time = v2;
  v3 = this->toe_transition_time - dt;
  vostok::math::max();
  this->toe_transition_time = v3;
  this->m_time_since_stance = this->m_time_since_stance + dt;
}
