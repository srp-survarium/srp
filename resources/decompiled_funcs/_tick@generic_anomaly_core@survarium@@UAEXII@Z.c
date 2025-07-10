void __thiscall survarium::generic_anomaly_core::tick(
        survarium::generic_anomaly_core *this,
        unsigned int time_delta_ms,
        unsigned int current_time_ms)
{
  survarium::game_camera *v3; // ecx
  float amount; // [esp+0h] [ebp-20h]
  survarium::anomaly_state *state; // [esp+1Ch] [ebp-4h]

  this->m_current_time = current_time_ms;
  amount = (double)this->energy_decrease_speed * ((double)time_delta_ms / 1000.0);
  survarium::generic_anomaly_core::dec_energy(this, amount);
  state = survarium::generic_anomaly_core::select_state(this);
  survarium::weapon_user_dead_state::finalize(v3);
  if ( state != this->m_current_state )
  {
    if ( this->m_current_state )
      survarium::anomaly_state::finalize(this->m_current_state);
    this->m_current_state = state;
    survarium::anomaly_state::initialize(this->m_current_state);
  }
  survarium::anomaly_state::execute(this->m_current_state, time_delta_ms, current_time_ms);
  if ( this->m_artefact_grab_time_ms )
  {
    if ( this->m_artefact_grab_time_ms + 1000 * this->artefacts_respawn_time_sec < current_time_ms )
      survarium::generic_anomaly_core::spawn_artefacts(this);
  }
}
