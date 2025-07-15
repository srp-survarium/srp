void __fastcall vostok::animation::legs_ik_solver::leg_params::tick(
        vostok::animation::legs_ik_solver::leg_params *this,
        const unsigned int time_delta_in_ms)
{
  unsigned int heel_transition_time_in_ms; // eax
  unsigned int v3; // eax
  unsigned int toe_transition_time_in_ms; // eax
  unsigned int v5; // eax

  heel_transition_time_in_ms = this->heel_transition_time_in_ms;
  if ( heel_transition_time_in_ms <= time_delta_in_ms )
    v3 = 0;
  else
    v3 = heel_transition_time_in_ms - time_delta_in_ms;
  this->heel_transition_time_in_ms = v3;
  toe_transition_time_in_ms = this->toe_transition_time_in_ms;
  if ( toe_transition_time_in_ms <= time_delta_in_ms )
    v5 = 0;
  else
    v5 = toe_transition_time_in_ms - time_delta_in_ms;
  this->toe_transition_time_in_ms = v5;
}
