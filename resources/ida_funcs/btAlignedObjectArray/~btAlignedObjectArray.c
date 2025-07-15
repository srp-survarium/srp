void __thiscall btAlignedObjectArray<btFace>::~btAlignedObjectArray<btFace>(
        btAlignedObjectArray<btFace> *this,
        btAlignedObjectArray<btFace> *thisa)
{
  int v3; // edi
  btFace *m_data; // esi
  int *v5; // eax
  btFace *v6; // esi
  bool v7; // zf
  btFace *v8; // eax
  btAlignedObjectArray<btFace> *thisb; // [esp+Ch] [ebp+4h]

  if ( thisa->m_size > 0 )
  {
    v3 = 0;
    thisb = (btAlignedObjectArray<btFace> *)thisa->m_size;
    do
    {
      m_data = thisa->m_data;
      v5 = m_data[v3].m_indices.m_data;
      v6 = &m_data[v3];
      if ( v5 )
      {
        if ( v6->m_indices.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v5);
        }
        v6->m_indices.m_data = 0;
      }
      ++v3;
      v7 = thisb == (btAlignedObjectArray<btFace> *)1;
      thisb = (btAlignedObjectArray<btFace> *)((char *)thisb - 1);
      v6->m_indices.m_ownsMemory = 1;
      v6->m_indices.m_data = 0;
      v6->m_indices.m_size = 0;
      v6->m_indices.m_capacity = 0;
    }
    while ( !v7 );
  }
  v8 = thisa->m_data;
  if ( v8 )
  {
    if ( thisa->m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v8);
    }
    thisa->m_data = 0;
  }
  thisa->m_data = 0;
  thisa->m_size = 0;
  thisa->m_capacity = 0;
  thisa->m_ownsMemory = 1;
}
