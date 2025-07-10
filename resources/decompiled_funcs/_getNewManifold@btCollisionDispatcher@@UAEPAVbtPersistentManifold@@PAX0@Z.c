btPersistentManifold *__thiscall btCollisionDispatcher::getNewManifold(btCollisionDispatcher *this, float b0, float b1)
{
  float v3; // ebp
  float *v4; // esi
  double v6; // st7
  int v7; // ecx
  double v8; // st7
  float *p_b0; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float *v12; // eax
  float v13; // xmm0_4
  btPoolAllocator *m_persistentManifoldPoolAllocator; // eax
  bool v15; // zf
  btPersistentManifold *m_firstFree; // ecx
  void *m_objectType; // edx
  btPersistentManifold *v18; // eax
  btPersistentManifold *v19; // ebx
  int m_capacity; // ecx
  int m_size; // eax
  int v22; // esi
  btPersistentManifold **v23; // ebp
  int v24; // edx
  int v25; // eax
  btPersistentManifold **v26; // ecx
  btPersistentManifold **m_data; // eax
  btPersistentManifold **v28; // eax
  float v30; // [esp+8h] [ebp-14h]
  float v31; // [esp+18h] [ebp-4h] BYREF

  v3 = b0;
  v4 = (float *)LODWORD(b1);
  ++gNumManifold;
  if ( (this->m_dispatcherFlags & 2) != 0 )
  {
    v6 = ((double (__stdcall *)(_DWORD))*(_DWORD *)(**(_DWORD **)(LODWORD(b1) + 204) + 16))(LODWORD(gContactBreakingThreshold));
    v7 = *(_DWORD *)(LODWORD(v3) + 204);
    b1 = v6;
    v8 = ((double (__stdcall *)(_DWORD))*(_DWORD *)(*(_DWORD *)v7 + 16))(LODWORD(gContactBreakingThreshold));
    b0 = v8;
    p_b0 = &b0;
    if ( b1 <= v8 )
      p_b0 = &b1;
    v10 = *p_b0;
  }
  else
  {
    v10 = gContactBreakingThreshold;
  }
  v11 = *(float *)(LODWORD(v3) + 196);
  b1 = v10;
  v31 = v4[49];
  b0 = v11;
  v12 = &b0;
  if ( v31 <= v11 )
    v12 = &v31;
  v13 = *v12;
  m_persistentManifoldPoolAllocator = this->m_persistentManifoldPoolAllocator;
  v15 = m_persistentManifoldPoolAllocator->m_freeCount == 0;
  b0 = v13;
  if ( v15 )
  {
    if ( (this->m_dispatcherFlags & 4) != 0 )
      return 0;
    ++gNumAlignedAllocs;
    v18 = (btPersistentManifold *)sAlignedAllocFunc(0x500u, 16);
  }
  else
  {
    m_firstFree = (btPersistentManifold *)m_persistentManifoldPoolAllocator->m_firstFree;
    m_objectType = (void *)m_firstFree->m_objectType;
    --m_persistentManifoldPoolAllocator->m_freeCount;
    m_persistentManifoldPoolAllocator->m_firstFree = m_objectType;
    v18 = m_firstFree;
  }
  if ( v18 )
  {
    *(float *)&v19 = COERCE_FLOAT(
                       btPersistentManifold::btPersistentManifold(
                         m_firstFree,
                         (int)v18,
                         (void *)LODWORD(v3),
                         v4,
                         SLODWORD(b1),
                         b0,
                         v30));
    b1 = *(float *)&v19;
  }
  else
  {
    *(float *)&v19 = 0.0;
    b1 = 0.0;
  }
  v19->m_index1a = this->m_manifoldsPtr.m_size;
  m_capacity = this->m_manifoldsPtr.m_capacity;
  m_size = this->m_manifoldsPtr.m_size;
  if ( m_size == m_capacity )
  {
    v22 = 2 * m_size;
    if ( !m_size )
      v22 = 1;
    if ( m_capacity < v22 )
    {
      if ( v22 )
      {
        ++gNumAlignedAllocs;
        v23 = (btPersistentManifold **)sAlignedAllocFunc(4 * v22, 16);
      }
      else
      {
        v23 = 0;
      }
      v24 = this->m_manifoldsPtr.m_size;
      v25 = 0;
      if ( v24 > 0 )
      {
        v26 = v23;
        do
        {
          if ( v26 )
          {
            *v26 = this->m_manifoldsPtr.m_data[v25];
            *(float *)&v19 = b1;
          }
          ++v25;
          ++v26;
        }
        while ( v25 < v24 );
      }
      m_data = this->m_manifoldsPtr.m_data;
      if ( m_data )
      {
        if ( this->m_manifoldsPtr.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(m_data);
        }
        this->m_manifoldsPtr.m_data = 0;
      }
      this->m_manifoldsPtr.m_ownsMemory = 1;
      this->m_manifoldsPtr.m_data = v23;
      this->m_manifoldsPtr.m_capacity = v22;
    }
  }
  v28 = &this->m_manifoldsPtr.m_data[this->m_manifoldsPtr.m_size];
  if ( v28 )
    *v28 = v19;
  ++this->m_manifoldsPtr.m_size;
  return v19;
}
