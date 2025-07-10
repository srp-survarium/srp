void __thiscall survarium::legs_ik_processor::leg_params::set_heel_transition_time(
        survarium::legs_ik_processor::leg_params *this,
        float tr_time)
{
  vostok::math::min();
  this->heel_transition_time = tr_time;
}
