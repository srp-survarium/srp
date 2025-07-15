void __thiscall survarium::generic_anomaly_core::serialize(
        survarium::generic_anomaly_core *this,
        vostok::network_core::buffer_writer *writer,
        survarium::generic_anomaly_core *time_offset)
{
  survarium::generic_anomaly_core *v3; // esi
  int m_reconstruction_info_actuality_tick_high; // eax
  vostok::network_core::buffer_writer *p_m_current_satisfaction_update_tick; // ecx
  char *v6; // eax
  survarium::anomaly_state *v7; // ecx
  _DWORD *m_current_satisfaction_update_tick; // eax
  vostok::network_core::buffer_writer *v9; // ecx
  unsigned int m_reconstruction_size; // edi
  int v11; // ebx
  unsigned int i; // edi
  int v13; // ecx
  vostok::network_core::buffer_writer *v14; // [esp-4h] [ebp-1Ch]
  unsigned __int8 v15; // [esp+13h] [ebp-5h] BYREF
  int m_target_satisfaction_low; // [esp+14h] [ebp-4h] BYREF

  v3 = this;
  if ( LOBYTE(this->type) )
  {
    vostok::network_core::buffer_writer::w<bool>(
      (const bool *)&this->vostok::resources::resource_reconstruction_info,
      (vostok::network_core::buffer_writer *)this,
      writer,
      ".\\generic_anomaly_core.cpp",
      (const char *)0x22,
      "survarium::generic_anomaly_core::serialize",
      "m_need_to_spawn_artefacts");
    if ( LOBYTE(v3->m_reconstruction_info_actuality_tick) )
    {
      m_reconstruction_info_actuality_tick_high = HIDWORD(v3->m_reconstruction_info_actuality_tick);
      if ( m_reconstruction_info_actuality_tick_high == -1 )
      {
        m_target_satisfaction_low = -1;
      }
      else
      {
        this = time_offset;
        m_target_satisfaction_low = (int)time_offset + m_reconstruction_info_actuality_tick_high;
      }
      vostok::network_core::buffer_writer::w<unsigned int>(
        (unsigned __int8 *)&m_target_satisfaction_low,
        (vostok::network_core::buffer_writer *)this,
        writer,
        ".\\generic_anomaly_core.cpp",
        (const char *)0x24,
        "survarium::generic_anomaly_core::serialize",
        "m_next_artefact_spawn_time_ms != u32( -1 ) ? m_next_artefact_spawn_time_ms + time_offset : u32( -1 )");
    }
  }
  vostok::network_core::buffer_writer::w<float>(
    (float *)&v3->m_children_resources.m_lock,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\generic_anomaly_core.cpp",
    (const char *)0x27,
    "survarium::generic_anomaly_core::serialize",
    "m_energy_current");
  p_m_current_satisfaction_update_tick = (vostok::network_core::buffer_writer *)&v3->m_current_satisfaction_update_tick;
  if ( LODWORD(v3->m_current_satisfaction_update_tick) )
  {
    v6 = stlp_std::find<vostok::render::render_output_window * *,vostok::render::render_output_window *>(
           *((char **)&v3->m_parent_resources + 6),
           (int *)&v3->m_current_satisfaction_update_tick,
           (char *)v3->m_memory_usage_self.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type);
    p_m_current_satisfaction_update_tick = v14;
    v15 = (int)&v6[-*((_DWORD *)&v3->m_parent_resources + 6)] >> 2;
  }
  else
  {
    v15 = -1;
  }
  vostok::network_core::buffer_writer::w<unsigned char>(
    &v15,
    p_m_current_satisfaction_update_tick,
    writer,
    ".\\generic_anomaly_core.cpp",
    (const char *)0x3C,
    "survarium::generic_anomaly_core::serialize",
    "current_state_index");
  m_current_satisfaction_update_tick = (_DWORD *)v3->m_current_satisfaction_update_tick;
  if ( m_current_satisfaction_update_tick )
    survarium::anomaly_state::serialize(v7, m_current_satisfaction_update_tick, writer, (unsigned int)time_offset);
  v15 = BYTE4(v3->m_current_satisfaction_update_tick) != 0;
  if ( BYTE5(v3->m_current_satisfaction_update_tick) )
    v15 |= 2u;
  vostok::network_core::buffer_writer::w<unsigned char>(
    &v15,
    (vostok::network_core::buffer_writer *)v7,
    writer,
    ".\\generic_anomaly_core.cpp",
    (const char *)0x49,
    "survarium::generic_anomaly_core::serialize",
    "events_mask");
  m_target_satisfaction_low = LODWORD(v3->m_target_satisfaction);
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&m_target_satisfaction_low,
    v9,
    writer,
    ".\\generic_anomaly_core.cpp",
    (const char *)0x4C,
    "survarium::generic_anomaly_core::serialize",
    "m_random.seed()");
  m_reconstruction_size = v3->m_reconstruction_size;
  v11 = *(&v3->m_reconstruction_size + 1);
  while ( m_reconstruction_size != v11 )
  {
    (**(void (__thiscall ***)(int, vostok::network_core::buffer_writer *, survarium::generic_anomaly_core *))(*(_DWORD *)m_reconstruction_size + 68))(
      *(_DWORD *)m_reconstruction_size + 68,
      writer,
      time_offset);
    m_reconstruction_size += 4;
  }
  for ( i = 0; i < LODWORD(v3->m_current_satisfaction); ++i )
  {
    v13 = *(_DWORD *)(v3->m_quality_levels_count + 4 * i);
    (*(void (__thiscall **)(int, vostok::network_core::buffer_writer *, _DWORD, survarium::generic_anomaly_core *))(*(_DWORD *)v13 + 84))(
      v13,
      writer,
      0,
      time_offset);
  }
}
