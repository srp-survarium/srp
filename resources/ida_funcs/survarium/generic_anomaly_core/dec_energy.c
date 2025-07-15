void __thiscall survarium::generic_anomaly_core::dec_energy(survarium::generic_anomaly_core *this, float amount)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( this->energy_enabled )
  {
    vostok::math::min();
    this->m_energy_current = this->m_energy_current - amount;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  }
}
