void __thiscall survarium::generic_anomaly_core::post_deserialize_resolve(
        survarium::generic_anomaly_core *this,
        survarium::game_world_core *game_world_core)
{
  int m_current_satisfaction_update_tick; // esi
  unsigned int m_reconstruction_size; // esi
  int v5; // edi

  m_current_satisfaction_update_tick = this->m_current_satisfaction_update_tick;
  if ( m_current_satisfaction_update_tick )
    survarium::anomaly_state::post_deserialize_resolve(
      (survarium::anomaly_state *)this,
      m_current_satisfaction_update_tick,
      game_world_core);
  m_reconstruction_size = this->m_reconstruction_size;
  v5 = *(&this->m_reconstruction_size + 1);
  while ( m_reconstruction_size != v5 )
  {
    (*(void (__thiscall **)(int, survarium::game_world_core *))(*(_DWORD *)(*(_DWORD *)m_reconstruction_size + 68) + 8))(
      *(_DWORD *)m_reconstruction_size + 68,
      game_world_core);
    m_reconstruction_size += 4;
  }
}
