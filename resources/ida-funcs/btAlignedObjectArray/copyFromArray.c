void __userpurge btAlignedObjectArray<btSoftBody *>::copyFromArray(
        btAlignedObjectArray<btSoftBody *> *this@<ecx>,
        int a2@<esi>,
        const btAlignedObjectArray<btSoftBody *> *otherArray)
{
  int v3; // ebx
  int m_size; // edi
  int v5; // edx
  int v6; // eax
  _DWORD *v7; // ecx
  int i; // ecx
  _DWORD *v9; // eax
  _DWORD *v10; // ecx
  int v11; // eax
  int v12; // [esp+8h] [ebp-8h]
  _DWORD *v13; // [esp+Ch] [ebp-4h]

  v3 = *(_DWORD *)(a2 + 4);
  m_size = otherArray->m_size;
  v12 = v3;
  if ( m_size >= v3 )
  {
    if ( m_size > v3 && *(_DWORD *)(a2 + 8) < m_size )
    {
      if ( m_size )
        v13 = btAlignedAllocInternal(4 * m_size);
      else
        v13 = 0;
      v5 = *(_DWORD *)(a2 + 4);
      v6 = 0;
      if ( v5 > 0 )
      {
        v7 = v13;
        do
        {
          if ( v7 )
          {
            *v7 = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v6);
            v3 = v12;
          }
          ++v6;
          ++v7;
        }
        while ( v6 < v5 );
      }
      if ( *(_DWORD *)(a2 + 12) )
      {
        if ( *(_BYTE *)(a2 + 16) )
          btAlignedFreeInternal(*(void **)(a2 + 12));
        *(_DWORD *)(a2 + 12) = 0;
      }
      *(_BYTE *)(a2 + 16) = 1;
      *(_DWORD *)(a2 + 12) = v13;
      *(_DWORD *)(a2 + 8) = m_size;
    }
    for ( i = v3; i < m_size; ++i )
    {
      v9 = (_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * i);
      if ( v9 )
        *v9 = 0;
    }
  }
  v10 = *(_DWORD **)(a2 + 12);
  v11 = 0;
  for ( *(_DWORD *)(a2 + 4) = m_size; v11 < m_size; ++v10 )
  {
    if ( v10 )
      *v10 = otherArray->m_data[v11];
    ++v11;
  }
}
