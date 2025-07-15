btPersistentManifold *__thiscall btCollisionDispatcher::getNewManifold(btCollisionDispatcher *this, float b0, float b1)
{
  float v3; // ebx
  float *v4; // esi
  double v6; // st7
  int v7; // ecx
  float *p_b1; // eax
  float v9; // xmm0_4
  float v10; // xmm1_4
  float *p_b0; // eax
  float v12; // xmm0_4
  btPoolAllocator *m_persistentManifoldPoolAllocator; // eax
  bool v14; // zf
  btPersistentManifold *m_firstFree; // ecx
  void *m_objectType; // edx
  void *v17; // eax
  btPersistentManifold *v18; // eax
  int m_capacity; // ecx
  int m_size; // eax
  int v21; // esi
  int v22; // edx
  int v23; // eax
  float v24; // ecx
  btPersistentManifold **v25; // eax
  float *v26; // eax
  btPersistentManifold *v28; // [esp+4h] [ebp-14h]
  float v29; // [esp+8h] [ebp-10h]
  float v30; // [esp+14h] [ebp-4h] BYREF

  ++gNumManifold;
  v3 = b0;
  v4 = (float *)LODWORD(b1);
  if ( (this->m_dispatcherFlags & 2) != 0 )
  {
    v6 = ((double (__stdcall *)(_DWORD))*(_DWORD *)(**(_DWORD **)(LODWORD(b1) + 204) + 16))(LODWORD(gContactBreakingThreshold));
    v7 = *(_DWORD *)(LODWORD(v3) + 204);
    b0 = v6;
    b1 = ((double (__stdcall *)(_DWORD))*(_DWORD *)(*(_DWORD *)v7 + 16))(LODWORD(gContactBreakingThreshold));
    p_b1 = &b1;
    if ( b0 <= (double)b1 )
      p_b1 = &b0;
    v9 = *p_b1;
  }
  else
  {
    v9 = gContactBreakingThreshold;
  }
  v10 = *(float *)(LODWORD(v3) + 196);
  b1 = v9;
  v30 = v4[49];
  b0 = v10;
  p_b0 = &b0;
  if ( v30 <= v10 )
    p_b0 = &v30;
  v12 = *p_b0;
  m_persistentManifoldPoolAllocator = this->m_persistentManifoldPoolAllocator;
  v14 = m_persistentManifoldPoolAllocator->m_freeCount == 0;
  b0 = v12;
  if ( v14 )
  {
    if ( (this->m_dispatcherFlags & 4) != 0 )
      return 0;
    v17 = btAlignedAllocInternal(0x500u);
    m_firstFree = v28;
  }
  else
  {
    m_firstFree = (btPersistentManifold *)m_persistentManifoldPoolAllocator->m_firstFree;
    m_objectType = (void *)m_firstFree->m_objectType;
    --m_persistentManifoldPoolAllocator->m_freeCount;
    m_persistentManifoldPoolAllocator->m_firstFree = m_objectType;
    v17 = m_firstFree;
  }
  if ( v17 )
    *(float *)&v18 = COERCE_FLOAT(
                       btPersistentManifold::btPersistentManifold(
                         m_firstFree,
                         (int)v17,
                         (void *)LODWORD(v3),
                         v4,
                         SLODWORD(b1),
                         b0,
                         v29));
  else
    *(float *)&v18 = 0.0;
  v18->m_index1a = this->m_manifoldsPtr.m_size;
  m_capacity = this->m_manifoldsPtr.m_capacity;
  b0 = *(float *)&v18;
  m_size = this->m_manifoldsPtr.m_size;
  if ( m_size == m_capacity )
  {
    v21 = m_size ? 2 * m_size : 1;
    if ( m_capacity < v21 )
    {
      if ( v21 )
        b1 = COERCE_FLOAT(btAlignedAllocInternal(4 * v21));
      else
        b1 = 0.0;
      v22 = this->m_manifoldsPtr.m_size;
      v23 = 0;
      if ( v22 > 0 )
      {
        v24 = b1;
        do
        {
          if ( v24 != 0.0 )
            *(_DWORD *)LODWORD(v24) = this->m_manifoldsPtr.m_data[v23];
          ++v23;
          LODWORD(v24) += 4;
        }
        while ( v23 < v22 );
      }
      if ( this->m_manifoldsPtr.m_data )
      {
        if ( this->m_manifoldsPtr.m_ownsMemory )
          btAlignedFreeInternal(this->m_manifoldsPtr.m_data);
        this->m_manifoldsPtr.m_data = 0;
      }
      v25 = (btPersistentManifold **)LODWORD(b1);
      this->m_manifoldsPtr.m_ownsMemory = 1;
      this->m_manifoldsPtr.m_data = v25;
      this->m_manifoldsPtr.m_capacity = v21;
    }
  }
  v26 = (float *)&this->m_manifoldsPtr.m_data[this->m_manifoldsPtr.m_size];
  if ( v26 )
    *v26 = b0;
  ++this->m_manifoldsPtr.m_size;
  return (btPersistentManifold *)LODWORD(b0);
}
