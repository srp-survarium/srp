void __userpurge btAlignedObjectArray<btSoftBody *>::copyFromArray(
        btAlignedObjectArray<btSoftBody *> *this@<ecx>,
        int a2@<eax>,
        const btAlignedObjectArray<btSoftBody *> *otherArray)
{
  const btAlignedObjectArray<btSoftBody *> *v3; // edx
  int v5; // ebx
  int m_size; // edi
  _DWORD *v7; // ebp
  int v8; // edx
  int v9; // eax
  _DWORD *v10; // ecx
  void *v11; // eax
  int i; // eax
  _DWORD *v13; // ecx
  _DWORD *v14; // ecx
  int v15; // eax
  _DWORD *v16; // [esp+Ch] [ebp-4h]

  v3 = otherArray;
  v5 = *(_DWORD *)(a2 + 4);
  m_size = otherArray->m_size;
  if ( m_size >= v5 )
  {
    if ( m_size > v5 && *(_DWORD *)(a2 + 8) < m_size )
    {
      if ( m_size )
      {
        ++gNumAlignedAllocs;
        v7 = sAlignedAllocFunc(4 * m_size, 16);
        v16 = v7;
      }
      else
      {
        v7 = 0;
        v16 = 0;
      }
      v8 = *(_DWORD *)(a2 + 4);
      v9 = 0;
      if ( v8 > 0 )
      {
        v10 = v7;
        do
        {
          if ( v10 )
            *v10 = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v9);
          ++v9;
          ++v10;
        }
        while ( v9 < v8 );
        v7 = v16;
      }
      v11 = *(void **)(a2 + 12);
      if ( v11 )
      {
        if ( *(_BYTE *)(a2 + 16) )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v11);
        }
        *(_DWORD *)(a2 + 12) = 0;
      }
      v3 = otherArray;
      *(_DWORD *)(a2 + 12) = v7;
      *(_BYTE *)(a2 + 16) = 1;
      *(_DWORD *)(a2 + 8) = m_size;
    }
    for ( i = v5; i < m_size; ++i )
    {
      v13 = (_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * i);
      if ( v13 )
        *v13 = 0;
    }
  }
  v14 = *(_DWORD **)(a2 + 12);
  v15 = 0;
  for ( *(_DWORD *)(a2 + 4) = m_size; v15 < m_size; ++v14 )
  {
    if ( v14 )
      *v14 = v3->m_data[v15];
    ++v15;
  }
}
