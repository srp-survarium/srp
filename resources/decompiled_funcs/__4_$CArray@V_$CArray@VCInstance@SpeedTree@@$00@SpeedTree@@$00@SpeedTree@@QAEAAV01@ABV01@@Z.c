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
