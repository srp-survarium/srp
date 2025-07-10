vostok::resources::resource_base *const *__usercall stlp_std::priv::__median<vostok::resources::resource_base *,vostok::resources::sorting_predicate>@<eax>(
        vostok::resources::resource_base *const *__b@<eax>,
        vostok::resources::resource_base *const *__c@<edi>,
        vostok::resources::resource_base *const *__a)
{
  int v3; // ecx
  float m_current_satisfaction; // xmm2_4
  int v5; // edx
  int v6; // esi
  float v7; // xmm2_4
  float v8; // xmm2_4
  int v9; // esi
  float v10; // xmm2_4
  float v11; // xmm2_4

  v3 = (int)*__b;
  m_current_satisfaction = (*__b)->m_current_satisfaction;
  v5 = (int)*__a;
  if ( fabs((*__a)->m_current_satisfaction - m_current_satisfaction) < 0.050000001 )
  {
    if ( *(_DWORD *)(v5 + 24) < *(_DWORD *)(v3 + 24) )
      goto LABEL_3;
LABEL_9:
    v9 = (int)*__c;
    v10 = (*__c)->m_current_satisfaction;
    if ( fabs(*(float *)(v5 + 112) - v10) >= 0.050000001 )
    {
      if ( *(float *)(v5 + 112) > v10 )
        return __a;
    }
    else if ( *(_DWORD *)(v5 + 24) < *(_DWORD *)(v9 + 24) )
    {
      return __a;
    }
    v11 = *(float *)(v9 + 112);
    if ( fabs(*(float *)(v3 + 112) - v11) >= 0.050000001 )
    {
      if ( *(float *)(v3 + 112) <= v11 )
        return __b;
    }
    else if ( *(_DWORD *)(v3 + 24) >= *(_DWORD *)(v9 + 24) )
    {
      return __b;
    }
    return __c;
  }
  if ( (*__a)->m_current_satisfaction <= m_current_satisfaction )
    goto LABEL_9;
LABEL_3:
  v6 = (int)*__c;
  v7 = (*__c)->m_current_satisfaction;
  if ( fabs(*(float *)(v3 + 112) - v7) < 0.050000001 )
  {
    if ( *(_DWORD *)(v3 + 24) < *(_DWORD *)(v6 + 24) )
      return __b;
    goto LABEL_5;
  }
  if ( *(float *)(v3 + 112) <= v7 )
  {
LABEL_5:
    v8 = *(float *)(v6 + 112);
    if ( fabs(*(float *)(v5 + 112) - v8) >= 0.050000001 )
    {
      if ( *(float *)(v5 + 112) <= v8 )
        return __a;
    }
    else if ( *(_DWORD *)(v5 + 24) >= *(_DWORD *)(v6 + 24) )
    {
      return __a;
    }
    return __c;
  }
  return __b;
}
