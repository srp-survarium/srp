void __thiscall survarium::generic_anomaly_core::on_artefact_container_use(
        survarium::generic_anomaly_core *this,
        survarium::artefact_container_core *container,
        unsigned int current_time_in_ms)
{
  int v3; // ecx
  float energy_af_container_use; // [esp+0h] [ebp-4h]

  energy_af_container_use = (float)this->energy_af_container_use;
  survarium::generic_anomaly_core::inc_energy(this, (int)this, energy_af_container_use);
  if ( !*(_BYTE *)(v3 + 308) )
  {
    *(_BYTE *)(v3 + 308) = 1;
    *(_DWORD *)(v3 + 312) = current_time_in_ms + 1000 * *(_DWORD *)(v3 + 300);
  }
}
