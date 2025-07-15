btPairSet *__usercall btPairSet::btPairSet@<eax>(btPairSet *this@<ecx>, btPairSet *a2@<esi>)
{
  GIM_PAIR *v2; // eax
  int m_size; // edi
  int *p_m_index1; // ecx
  int v5; // edx
  GIM_PAIR *v6; // eax
  GIM_PAIR *i; // [esp+8h] [ebp-4h]

  a2->m_ownsMemory = 1;
  a2->m_data = 0;
  a2->m_size = 0;
  a2->m_capacity = 0;
  v2 = (GIM_PAIR *)btAlignedAllocInternal(0x100u);
  m_size = a2->m_size;
  p_m_index1 = &v2->m_index1;
  v5 = 0;
  for ( i = v2; v5 < m_size; p_m_index1 += 2 )
  {
    if ( p_m_index1 )
    {
      v6 = &a2->m_data[v5];
      *p_m_index1 = v6->m_index1;
      p_m_index1[1] = v6->m_index2;
    }
    ++v5;
  }
  if ( a2->m_data )
  {
    if ( a2->m_ownsMemory )
      btAlignedFreeInternal(a2->m_data);
    a2->m_data = 0;
  }
  a2->m_data = i;
  a2->m_ownsMemory = 1;
  a2->m_capacity = 32;
  return a2;
}
