void __userpurge survarium::stats_graph::add_value(
        survarium::stats_graph *this@<ecx>,
        float *a2@<esi>,
        float time,
        float value)
{
  float v4; // xmm0_4
  float *v5; // ecx
  float v6; // xmm2_4
  survarium::stats_graph *v7; // ecx
  survarium::stats_graph::stats_value *m_newest_value; // eax
  float *v9; // eax
  float v10; // xmm1_4
  survarium::stats_graph *v11; // ecx

  v4 = time;
  if ( *((_DWORD *)a2 + 8) <= 1u || (v5 = **(float ***)a2, (float)(time - *(float *)(*(_DWORD *)v5 + 8)) < a2[2]) )
  {
    v9 = (float *)*((_DWORD *)a2 + 1);
    if ( v9 )
    {
      a2[1] = *v9;
    }
    else
    {
      v9 = (float *)vostok::memory::doug_lea_allocator::malloc_impl(
                      (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                      0x10u);
      v4 = time;
    }
    v9[2] = v4;
    v9[3] = value;
    v10 = a2[6];
    v11 = *(survarium::stats_graph **)a2;
    ++*((_DWORD *)a2 + 8);
    a2[6] = v10 + value;
    if ( v11 )
    {
      *v9 = *(float *)&v11->m_newest_value;
      v9[1] = *a2;
      **(_DWORD **)a2 = v9;
      *(_DWORD *)(*(_DWORD *)v9 + 4) = v9;
    }
    else
    {
      *(_DWORD *)v9 = v9;
      *((_DWORD *)v9 + 1) = v9;
    }
    *(_DWORD *)a2 = v9;
  }
  else
  {
    v6 = a2[6] - v5[3];
    v7 = *(survarium::stats_graph **)a2;
    a2[6] = v6 + value;
    m_newest_value = v7->m_newest_value;
    *a2 = *(float *)&v7->m_newest_value;
    m_newest_value->time = time;
    *(float *)(*(_DWORD *)a2 + 12) = value;
    survarium::stats_graph::adjust_time_interval(v7, a2);
  }
}
