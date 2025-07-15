void __thiscall survarium::generic_anomaly_core::deserialize(
        survarium::generic_anomaly_core *this,
        vostok::network_core::buffer_reader *reader,
        survarium::generic_anomaly_core *time_offset)
{
  survarium::generic_anomaly_core *v3; // ebx
  bool v4; // al
  const unsigned __int8 *m_pointer; // esi
  int v6; // eax
  vostok::network_core::buffer_reader *v7; // edx
  const unsigned __int8 *v8; // esi
  unsigned int v9; // xmm0_4
  _DWORD *v10; // esi
  int m_current_satisfaction_update_tick; // edi
  _DWORD *v12; // eax
  const unsigned __int8 *v13; // esi
  const unsigned __int8 *v14; // esi
  unsigned int m_reconstruction_size; // esi
  int v16; // edi
  int v17; // esi
  int v18; // ecx
  bool v19; // [esp+0h] [ebp-14h]
  int v20; // [esp+Ch] [ebp-8h]
  float v21; // [esp+Ch] [ebp-8h]
  unsigned __int8 v22; // [esp+13h] [ebp-1h]
  unsigned __int8 v23; // [esp+13h] [ebp-1h]

  v3 = this;
  if ( LOBYTE(this->type) )
  {
    v4 = vostok::network_core::buffer_reader::r<bool>(reader);
    LOBYTE(v3->m_reconstruction_info_actuality_tick) = v4;
    if ( v4 )
    {
      this = (survarium::generic_anomaly_core *)reader;
      m_pointer = reader->m_pointer;
      v20 = *(_DWORD *)m_pointer;
      reader->m_pointer = m_pointer + 4;
      if ( v20 == -1 )
      {
        v6 = -1;
      }
      else
      {
        this = time_offset;
        v6 = (int)time_offset + v20;
      }
      HIDWORD(v3->m_reconstruction_info_actuality_tick) = v6;
    }
  }
  v7 = reader;
  v8 = reader->m_pointer;
  v9 = *(_DWORD *)v8;
  reader->m_pointer = v8 + 4;
  v3->m_children_resources.m_lock = v9;
  v22 = *reader->m_pointer++;
  if ( v22 == 0xFF )
  {
    v10 = 0;
  }
  else
  {
    this = (survarium::generic_anomaly_core *)*((_DWORD *)&v3->m_parent_resources + 6);
    v10 = (_DWORD *)*((_DWORD *)&this->survarium::link_resolver::__vftable + v22);
  }
  m_current_satisfaction_update_tick = v3->m_current_satisfaction_update_tick;
  if ( (_DWORD *)m_current_satisfaction_update_tick != v10 )
  {
    if ( m_current_satisfaction_update_tick )
    {
      survarium::anomaly_state::finalize((survarium::anomaly_state *)this, m_current_satisfaction_update_tick, 1);
      v7 = reader;
    }
    LODWORD(v3->m_current_satisfaction_update_tick) = v10;
    if ( v10 )
    {
      survarium::anomaly_state::initialize((survarium::anomaly_state *)this, v10, 1u, v19);
      v7 = reader;
    }
  }
  v12 = (_DWORD *)v3->m_current_satisfaction_update_tick;
  if ( v12 )
  {
    survarium::anomaly_state::deserialize((survarium::anomaly_state *)this, v12, v7, (unsigned int)time_offset);
    v7 = reader;
  }
  v13 = v7->m_pointer;
  v23 = *v13;
  v7->m_pointer = v13 + 1;
  BYTE5(v3->m_current_satisfaction_update_tick) = (v23 & 2) != 0;
  BYTE4(v3->m_current_satisfaction_update_tick) = v23 & 1;
  v14 = v7->m_pointer;
  v21 = *(float *)v14;
  v7->m_pointer = v14 + 4;
  m_reconstruction_size = v3->m_reconstruction_size;
  v16 = *(&v3->m_reconstruction_size + 1);
  v3->m_target_satisfaction = v21;
  while ( m_reconstruction_size != v16 )
  {
    (*(void (__thiscall **)(int, vostok::network_core::buffer_reader *, survarium::generic_anomaly_core *))(*(_DWORD *)(*(_DWORD *)m_reconstruction_size + 68) + 4))(
      *(_DWORD *)m_reconstruction_size + 68,
      v7,
      time_offset);
    v7 = reader;
    m_reconstruction_size += 4;
  }
  v17 = 0;
  if ( LODWORD(v3->m_current_satisfaction) )
  {
    while ( 1 )
    {
      v18 = *(_DWORD *)(v3->m_quality_levels_count + 4 * v17);
      (*(void (__thiscall **)(int, vostok::network_core::buffer_reader *, _DWORD, survarium::generic_anomaly_core *))(*(_DWORD *)v18 + 88))(
        v18,
        v7,
        0,
        time_offset);
      if ( (unsigned int)++v17 >= LODWORD(v3->m_current_satisfaction) )
        break;
      v7 = reader;
    }
  }
}
