void __thiscall survarium::generic_anomaly_core::resolve_links(
        survarium::generic_anomaly_core *this,
        survarium::anomaly_state **p,
        vostok::configs::binary_config_value config)
{
  unsigned int v4; // esi
  const vostok::configs::binary_config_value *v5; // eax
  int v6; // eax
  void *v7; // eax
  unsigned int v8; // ecx
  unsigned int v9; // ecx
  _DWORD *v10; // eax
  int v11; // esi
  const vostok::configs::binary_config_value *v12; // eax
  const vostok::configs::binary_config_value *v13; // eax
  const vostok::configs::binary_config_value *v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // ecx
  void **M_finish; // esi
  survarium::anomaly_state **M_start; // ebx
  int v20; // ecx
  int v21; // eax
  survarium::anomaly_state **i; // edi
  unsigned int v23; // [esp+Ch] [ebp-20h]
  _DWORD *v24; // [esp+10h] [ebp-1Ch]
  int v25; // [esp+14h] [ebp-18h]
  int v26; // [esp+18h] [ebp-14h]
  int v27; // [esp+1Ch] [ebp-10h]
  int v28; // [esp+20h] [ebp-Ch]
  unsigned int v29; // [esp+20h] [ebp-Ch]
  unsigned int v30; // [esp+24h] [ebp-8h]
  unsigned int v31; // [esp+28h] [ebp-4h]
  unsigned int v32; // [esp+28h] [ebp-4h]

  v4 = this->m_artefact_containers._M_impl._M_finish - this->m_artefact_containers._M_impl._M_start;
  v31 = 0;
  if ( v4 )
  {
    v28 = 0;
    do
    {
      v5 = vostok::configs::binary_config_value::operator[](&config, "artefact_containers");
      v6 = ((int (__thiscall *)(survarium::anomaly_state **, _DWORD))(*p)->debug_idx)(
             p,
             *(_DWORD *)((char *)v5->data.pointer + v28));
      if ( v6 )
        v7 = (void *)(v6 - 4);
      else
        v7 = 0;
      v28 += 24;
      v8 = v31++;
      this->m_artefact_containers._M_impl._M_start[v8] = v7;
      *((_DWORD *)this->m_artefact_containers._M_impl._M_start[v8] + 21) = this;
    }
    while ( v31 < v4 );
  }
  v29 = 0;
  v9 = this->m_states._M_impl._M_finish - this->m_states._M_impl._M_start;
  v23 = v9;
  if ( v9 )
  {
    v25 = 0;
    do
    {
      v10 = this->m_states._M_impl._M_start[v29];
      v24 = v10;
      v30 = 0;
      if ( (v10[8] - v10[7]) >> 2 )
      {
        v26 = 0;
        do
        {
          v11 = *(_DWORD *)(v10[7] + 4 * v30);
          v32 = 0;
          if ( (*(_DWORD *)(v11 + 24) - *(_DWORD *)(v11 + 20)) >> 2 )
          {
            v27 = 0;
            do
            {
              v12 = vostok::configs::binary_config_value::operator[](&config, "states");
              v13 = vostok::configs::binary_config_value::operator[](
                      (vostok::configs::binary_config_value *)((char *)v12->data.pointer + v25),
                      "groups");
              v14 = vostok::configs::binary_config_value::operator[](
                      (vostok::configs::binary_config_value *)((char *)v13->data.pointer + v26),
                      "zones");
              v15 = ((int (__thiscall *)(survarium::anomaly_state **, _DWORD))(*p)->debug_idx)(
                      p,
                      *(_DWORD *)((char *)v14->data.pointer + v27));
              if ( v15 )
                v16 = v15 - 268;
              else
                v16 = 0;
              v27 += 24;
              v17 = 4 * v32++;
              *(_DWORD *)(v17 + *(_DWORD *)(v11 + 20)) = v16;
              *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v11 + 20) + v17) + 428) = v11;
            }
            while ( v32 < (*(_DWORD *)(v11 + 24) - *(_DWORD *)(v11 + 20)) >> 2 );
            v10 = v24;
            v9 = v23;
          }
          ++v30;
          v26 += 24;
        }
        while ( v30 < (v10[8] - v10[7]) >> 2 );
      }
      ++v29;
      v25 += 24;
    }
    while ( v29 < v9 );
  }
  M_finish = this->m_states._M_impl._M_finish;
  M_start = (survarium::anomaly_state **)this->m_states._M_impl._M_start;
  if ( M_start != (survarium::anomaly_state **)M_finish )
  {
    v20 = ((char *)M_finish - (char *)M_start) >> 2;
    v21 = 0;
    while ( v20 != 1 )
    {
      ++v21;
      v20 >>= 1;
    }
    stlp_std::priv::__introsort_loop<char const * *,char const *,int,bool (__cdecl *)(char const *,char const *)>(
      M_start,
      (survarium::anomaly_state **)M_finish,
      0,
      2 * v21,
      (survarium::anomaly_state **)survarium::state_prio);
    if ( ((char *)M_finish - (char *)M_start) >> 2 <= 16 )
    {
      stlp_std::priv::__insertion_sort<survarium::anomaly_state * *,survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
        M_start,
        (bool (__cdecl *)(survarium::anomaly_state *, survarium::anomaly_state *))M_start,
        (survarium::anomaly_state **)M_finish);
    }
    else
    {
      stlp_std::priv::__insertion_sort<survarium::anomaly_state * *,survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
        M_start,
        (bool (__cdecl *)(survarium::anomaly_state *, survarium::anomaly_state *))M_start,
        M_start + 16);
      for ( i = M_start + 16; i != (survarium::anomaly_state **)M_finish; ++i )
        stlp_std::priv::__unguarded_linear_insert<survarium::anomaly_state * *,survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
          i,
          *i);
    }
  }
}
