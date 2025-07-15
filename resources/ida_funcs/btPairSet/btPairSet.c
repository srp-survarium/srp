btPairSet *__usercall btPairSet::btPairSet@<eax>(btPairSet *this@<ecx>, btPairSet *a2@<esi>)
{
  GIM_PAIR *v2; // eax
  int m_size; // edi
  GIM_PAIR *v4; // ebp
  int v5; // eax
  GIM_PAIR *v6; // ecx
  GIM_PAIR *m_data; // edx
  GIM_PAIR *v8; // eax

  ++gNumAlignedAllocs;
  a2->m_ownsMemory = 1;
  a2->m_data = 0;
  a2->m_size = 0;
  a2->m_capacity = 0;
  v2 = (GIM_PAIR *)sAlignedAllocFunc(0x100u, 16);
  m_size = a2->m_size;
  v4 = v2;
  v5 = 0;
  if ( m_size > 0 )
  {
    v6 = v4;
    do
    {
      if ( v6 )
      {
        m_data = a2->m_data;
        v6->m_index1 = m_data[v5].m_index1;
        v6->m_index2 = m_data[v5].m_index2;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < m_size );
  }
  v8 = a2->m_data;
  if ( v8 )
  {
    if ( a2->m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v8);
    }
    a2->m_data = 0;
  }
  a2->m_data = v4;
  a2->m_ownsMemory = 1;
  a2->m_capacity = 32;
  return a2;
}
