void __thiscall survarium::legs_ik_processor::legs_ik_processor(survarium::legs_ik_processor *this)
{
  vostok::animation::fermi_interpolator *v1; // ecx
  vostok::animation::fermi_interpolator *v2; // ecx
  survarium::legs_ik_processor *thisb; // [esp+4h] [ebp-Ch]
  survarium::legs_ik_processor *thisc; // [esp+4h] [ebp-Ch]

  survarium::ik_processor::ik_processor(this);
  this->m_drawer = 0;
  this->m_character_controller = 0;
  survarium::legs_ik_processor::leg_params::leg_params(&this->m_left_leg_params);
  survarium::legs_ik_processor::leg_params::leg_params(&this->m_right_leg_params);
  vostok::animation::fermi_interpolator::fermi_interpolator(
    v1,
    (int)&this->m_heel_interpolator,
    SLODWORD(FLOAT_0_1),
    0.0049999999,
    *(float *)&this);
  vostok::animation::fermi_interpolator::fermi_interpolator(
    v2,
    (int)&thisb->m_toe_interpolator,
    SLODWORD(FLOAT_0_1),
    0.0049999999,
    *(float *)&thisb);
  thisc->m_heel_transition_time_calculator.m_value = *(float *)&FLOAT_0_0;
  thisc->m_toe_transition_time_calculator.m_value = *(float *)&FLOAT_0_0;
  thisc->m_heel_transition_time = thisc->m_heel_interpolator.transition_time(&thisc->m_heel_interpolator);
  thisc->m_toe_transition_time = thisc->m_toe_interpolator.transition_time(&thisc->m_toe_interpolator);
}
