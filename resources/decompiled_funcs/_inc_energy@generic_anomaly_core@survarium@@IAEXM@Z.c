void __thiscall survarium::generic_anomaly_core::inc_energy(survarium::generic_anomaly_core *this, float amount)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( this->energy_enabled )
  {
    this->m_energy_current = this->m_energy_current + amount;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  }
}
