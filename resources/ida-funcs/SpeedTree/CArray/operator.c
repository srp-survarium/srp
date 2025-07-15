SpeedTree::CArray<SpeedTree::CCore *,1> *__userpurge SpeedTree::CArray<SpeedTree::CCore *,1>::operator=@<eax>(
        SpeedTree::CArray<SpeedTree::CCore *,1> *this@<ecx>,
        SpeedTree::CArray<SpeedTree::CCore *,1> *a2@<esi>,
        const SpeedTree::CArray<SpeedTree::CCore *,1> *cRight)
{
  unsigned int m_uiSize; // eax
  unsigned int m_uiDataSize; // ecx
  SpeedTree::CCore **v5; // edi
  SpeedTree::CCore **m_pData; // eax
  _DWORD *v7; // eax
  SpeedTree::CCore **v8; // eax
  SpeedTree::CCore **v9; // ecx
  unsigned int v10; // edx

  m_uiSize = cRight->m_uiSize;
  if ( a2->m_bExternalMemory )
  {
    m_uiDataSize = a2->m_uiDataSize;
    a2->m_uiSize = m_uiSize;
    if ( m_uiSize > m_uiDataSize )
      a2->m_uiSize = m_uiDataSize;
  }
  else
  {
    if ( m_uiSize > a2->m_uiDataSize )
    {
      v5 = SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::Allocate(a2, cRight->m_uiSize);
      m_pData = a2->m_pData;
      if ( m_pData )
      {
        v7 = m_pData - 1;
        if ( v7 )
        {
          SpeedTree::g_siHeapMemoryUsed += -4 - 4 * *v7;
          if ( SpeedTree::g_pAllocator )
            SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, v7);
        }
      }
      a2->m_pData = v5;
      a2->m_uiDataSize = cRight->m_uiSize;
    }
    a2->m_uiSize = cRight->m_uiSize;
  }
  if ( a2->m_uiSize )
  {
    v8 = a2->m_pData;
    v9 = cRight->m_pData;
    v10 = 0;
    do
    {
      *v8 = *v9;
      ++v10;
      ++v8;
      ++v9;
    }
    while ( v10 < a2->m_uiSize );
  }
  return a2;
}


SpeedTree::CArray<SpeedTree::CInstance,1> *__usercall SpeedTree::CArray<SpeedTree::CInstance,1>::operator=@<eax>(
        SpeedTree::CArray<SpeedTree::CInstance,1> *this@<esi>,
        const SpeedTree::CArray<SpeedTree::CInstance,1> *cRight@<eax>)
{
  unsigned int m_uiSize; // eax
  unsigned int m_uiDataSize; // ecx
  SpeedTree::CInstance *v5; // ebx
  SpeedTree::CInstance *m_pData; // eax
  SpeedTree::CInstance *v7; // ecx
  unsigned int v8; // edx
  SpeedTree::CInstance *pRawBlock; // [esp+8h] [ebp-4h] BYREF

  m_uiSize = cRight->m_uiSize;
  if ( this->m_bExternalMemory )
  {
    m_uiDataSize = this->m_uiDataSize;
    this->m_uiSize = m_uiSize;
    if ( m_uiSize > m_uiDataSize )
      this->m_uiSize = m_uiDataSize;
  }
  else
  {
    if ( m_uiSize > this->m_uiDataSize )
    {
      v5 = SpeedTree::st_new_array<SpeedTree::CInstance>(m_uiSize);
      pRawBlock = this->m_pData;
      SpeedTree::st_delete_array<SpeedTree::CInstance>(&pRawBlock);
      this->m_pData = v5;
      this->m_uiDataSize = cRight->m_uiSize;
    }
    this->m_uiSize = cRight->m_uiSize;
  }
  if ( this->m_uiSize )
  {
    m_pData = this->m_pData;
    v7 = cRight->m_pData;
    v8 = 0;
    do
    {
      *(_QWORD *)&m_pData->m_vPos.x = *(_QWORD *)&v7->m_vPos.x;
      *(_QWORD *)&m_pData->m_vPos.z = *(_QWORD *)&v7->m_vPos.z;
      *(_QWORD *)&m_pData->m_vGeometricCenter.x = *(_QWORD *)&v7->m_vGeometricCenter.x;
      *(_QWORD *)&m_pData->m_vGeometricCenter.z = *(_QWORD *)&v7->m_vGeometricCenter.z;
      *(_DWORD *)m_pData->m_anRotationVector = *(_DWORD *)v7->m_anRotationVector;
      ++v8;
      ++m_pData;
      ++v7;
    }
    while ( v8 < this->m_uiSize );
  }
  return this;
}


SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *__userpurge SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::operator=@<eax>(
        SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *this@<ecx>,
        int a2@<edi>,
        const SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *cRight)
{
  const SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *v3; // ebx
  unsigned int m_uiSize; // eax
  unsigned int v5; // ecx
  SpeedTree::CArray<SpeedTree::CInstance,1> *v6; // esi
  SpeedTree::CArray<SpeedTree::CInstance,1> *v7; // esi
  const SpeedTree::CArray<SpeedTree::CInstance,1> *m_pData; // ebx
  unsigned int v9; // ebp
  const char *v11; // [esp+0h] [ebp-8h]

  v3 = cRight;
  m_uiSize = cRight->m_uiSize;
  if ( *(_BYTE *)(a2 + 16) )
  {
    v5 = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(a2 + 8) = m_uiSize;
    if ( m_uiSize > v5 )
      *(_DWORD *)(a2 + 8) = v5;
  }
  else
  {
    if ( m_uiSize > *(_DWORD *)(a2 + 12) )
    {
      v6 = SpeedTree::st_new_array<SpeedTree::CArray<SpeedTree::CInstance,1>>(m_uiSize, v11);
      cRight = *(const SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> **)(a2 + 4);
      SpeedTree::st_delete_array<SpeedTree::CArray<SpeedTree::CInstance,1>>((SpeedTree::CArray<SpeedTree::CInstance,1> **)&cRight);
      *(_DWORD *)(a2 + 4) = v6;
      *(_DWORD *)(a2 + 12) = v3->m_uiSize;
    }
    *(_DWORD *)(a2 + 8) = v3->m_uiSize;
  }
  if ( !*(_DWORD *)(a2 + 8) )
    return (SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *)a2;
  v7 = *(SpeedTree::CArray<SpeedTree::CInstance,1> **)(a2 + 4);
  m_pData = v3->m_pData;
  v9 = 0;
  do
  {
    SpeedTree::CArray<SpeedTree::CInstance,1>::operator=(v7, m_pData);
    ++v9;
    ++v7;
    ++m_pData;
  }
  while ( v9 < *(_DWORD *)(a2 + 8) );
  return (SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *)a2;
}
