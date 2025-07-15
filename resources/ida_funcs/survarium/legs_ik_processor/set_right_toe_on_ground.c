void __thiscall survarium::legs_ik_processor::set_right_toe_on_ground(survarium::legs_ik_processor *this, bool value)
{
  survarium::legs_ik_processor::set_toe_on_ground(this, &this->m_right_leg_params, value);
}
