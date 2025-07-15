void __thiscall survarium::legs_ik_processor::leg_params::leg_params(survarium::legs_ik_processor::leg_params *this)
{
  this->heel_transition_time = *(float *)&FLOAT_0_0;
  this->toe_transition_time = *(float *)&FLOAT_0_0;
  vostok::math::float3::float3(&this->rotation_axis, COERCE_UNSIGNED_INT(1.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  this->m_time_since_stance = *(float *)&FLOAT_0_0;
  this->m_heel_on_ground = 0;
  this->m_toe_on_ground = 0;
}
