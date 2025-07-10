void __thiscall survarium::legs_ik_processor::set_left_heel_on_ground(survarium::legs_ik_processor *this, bool value)
{
  survarium::legs_ik_processor::set_heel_on_ground(this, &this->m_left_leg_params, value);
}
