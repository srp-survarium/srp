void __thiscall survarium::legs_ik_processor::leg_params::set_heel_on_ground(
        survarium::legs_ik_processor::leg_params *this,
        bool value)
{
  this->m_heel_on_ground = value;
  if ( this->m_heel_on_ground && this->m_toe_on_ground )
    this->m_time_since_stance = *(float *)&FLOAT_0_0;
}
