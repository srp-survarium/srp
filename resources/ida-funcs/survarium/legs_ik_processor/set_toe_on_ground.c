void __thiscall survarium::legs_ik_processor::set_toe_on_ground(
        survarium::legs_ik_processor *this,
        survarium::legs_ik_processor::leg_params *params,
        bool value)
{
  survarium::legs_ik_processor *thisb; // [esp+4h] [ebp-24h]
  int v5; // [esp+8h] [ebp-20h]
  _BYTE v6[12]; // [esp+1Ch] [ebp-Ch] BYREF

  if ( params->m_toe_on_ground != value )
  {
    survarium::legs_ik_processor::leg_params::set_toe_on_ground(params, value);
    if ( !value )
    {
      this->m_toe_transition_time = this->m_toe_transition_time_calculator.m_value;
      vostok::math::clamp<float>(&this->m_toe_transition_time, 0.001, 0.5);
      survarium::legs_ik_processor::leg_params::set_toe_transition_time(
        &this->m_left_leg_params,
        this->m_toe_transition_time);
      survarium::legs_ik_processor::leg_params::set_toe_transition_time(
        &this->m_right_leg_params,
        this->m_toe_transition_time);
      v5 = vostok::animation::fermi_interpolator::fermi_interpolator(
             (vostok::animation::fermi_interpolator *)this,
             (int)v6,
             LODWORD(this->m_toe_transition_time),
             0.0049999999,
             *(float *)&this);
      thisb->m_toe_interpolator.m_total_transition_time = *(float *)(v5 + 4);
      thisb->m_toe_interpolator.m_epsilon = *(float *)(v5 + 8);
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v6);
    }
  }
}
