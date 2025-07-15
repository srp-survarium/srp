void __thiscall survarium::generic_anomaly_core::on_artefact_container_use(
        survarium::generic_anomaly_core *this,
        survarium::artefact_container_core *container)
{
  float amount; // [esp+0h] [ebp-10h]

  amount = (float)this->energy_af_container_use;
  survarium::generic_anomaly_core::inc_energy(this, amount);
  if ( !this->m_artefact_grab_time_ms )
    this->m_artefact_grab_time_ms = this->m_current_time;
}
