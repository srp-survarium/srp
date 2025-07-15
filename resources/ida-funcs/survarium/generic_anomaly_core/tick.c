void __userpurge survarium::generic_anomaly_core::tick(
        survarium::generic_anomaly_core *this@<ecx>,
        BOOL a2@<edi>,
        unsigned int time_delta_ms,
        unsigned int current_time_ms)
{
  float *p_grm_satisfaction_tree_hook; // ebx
  float v6; // xmm0_4
  float v7; // xmm1_4
  survarium::anomaly_state *v8; // eax
  survarium::anomaly_state *v9; // ecx
  unsigned int m_quality_levels_count; // edi
  unsigned int m_uid; // eax
  unsigned int i; // edi
  int v13; // ecx
  bool v14; // [esp-Ch] [ebp-10h]
  survarium::anomaly_state *v15; // [esp+0h] [ebp-4h]

  v14 = a2;
  p_grm_satisfaction_tree_hook = (float *)&this[-1].grm_satisfaction_tree_hook;
  if ( *((_BYTE *)&this[-1].grm_satisfaction_tree_hook + 328) )
  {
    v6 = p_grm_satisfaction_tree_hook[83];
    v7 = (double)time_delta_ms * 0.001 * (double)(unsigned int)this->m_children_resources.m_last;
    if ( v7 > v6 )
      v7 = p_grm_satisfaction_tree_hook[83];
    p_grm_satisfaction_tree_hook[83] = v6 - v7;
  }
  v8 = survarium::generic_anomaly_core::select_state(this, (int)&this[-1].grm_satisfaction_tree_hook);
  m_quality_levels_count = this->m_quality_levels_count;
  v15 = v8;
  if ( v8 != (survarium::anomaly_state *)m_quality_levels_count )
  {
    if ( m_quality_levels_count )
      survarium::anomaly_state::finalize(v9, m_quality_levels_count, 0);
    this->m_quality_levels_count = (unsigned int)v15;
    survarium::anomaly_state::initialize(v9, v15, current_time_ms, v14);
  }
  survarium::anomaly_state::execute(v9, (unsigned int *)this->m_quality_levels_count, time_delta_ms, current_time_ms);
  if ( LOBYTE(this->m_reconstruction_info_actuality_tick) && *((_BYTE *)&this->m_reconstruction_size + 4) )
  {
    m_uid = this->m_uid;
    if ( m_uid == -1 )
    {
      this->m_uid = current_time_ms + 1000 * HIDWORD(this->m_reconstruction_info_actuality_tick);
    }
    else if ( m_uid <= current_time_ms )
    {
      (*(void (__thiscall **)(boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none> *, unsigned int))(*(_DWORD *)p_grm_satisfaction_tree_hook + 36))(
        &this[-1].grm_satisfaction_tree_hook,
        current_time_ms);
    }
  }
  for ( i = 0; i < this->m_current_quality_level; ++i )
  {
    v13 = *(_DWORD *)(LODWORD(this->m_last_fail_of_increasing_quality) + 4 * i);
    (*(void (__thiscall **)(int, unsigned int, unsigned int))(*(_DWORD *)v13 + 96))(v13, time_delta_ms, current_time_ms);
  }
}
