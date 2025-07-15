void __thiscall btTriangleIndexVertexArray::addIndexedMesh(
        btTriangleIndexVertexArray *this,
        const btIndexedMesh *mesh,
        PHY_ScalarType indexType)
{
  int m_triangleIndexStride; // ecx
  const unsigned __int8 *m_triangleIndexBase; // eax
  const unsigned __int8 *v6; // eax
  char *v7; // edx
  void *v8; // edi
  char *v9; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]
  int v11; // [esp+1Ch] [ebp+8h]

  m_triangleIndexStride = mesh[1].m_triangleIndexStride;
  m_triangleIndexBase = mesh[1].m_triangleIndexBase;
  if ( m_triangleIndexBase == (const unsigned __int8 *)m_triangleIndexStride )
  {
    v11 = m_triangleIndexBase ? 2 * (_DWORD)m_triangleIndexBase : 1;
    if ( m_triangleIndexStride < v11 )
    {
      if ( v11 )
        v9 = (char *)btAlignedAllocInternal(32 * v11);
      else
        v9 = 0;
      v6 = mesh[1].m_triangleIndexBase;
      if ( (int)v6 > 0 )
      {
        v7 = v9;
        v10 = 0;
        do
        {
          if ( v7 )
            qmemcpy(v7, (const void *)(v10 + mesh[1].m_numVertices), 0x20u);
          v10 += 32;
          v7 += 32;
          --v6;
        }
        while ( v6 );
      }
      if ( mesh[1].m_numVertices )
      {
        if ( LOBYTE(mesh[1].m_vertexBase) )
          btAlignedFreeInternal((void *)mesh[1].m_numVertices);
        mesh[1].m_numVertices = 0;
      }
      mesh[1].m_numVertices = (int)v9;
      LOBYTE(mesh[1].m_vertexBase) = 1;
      mesh[1].m_triangleIndexStride = v11;
    }
  }
  v8 = (void *)(mesh[1].m_numVertices + 32 * (int)mesh[1].m_triangleIndexBase);
  if ( v8 )
    qmemcpy(v8, (const void *)indexType, 0x20u);
  *(_DWORD *)(32 * (int)++mesh[1].m_triangleIndexBase + mesh[1].m_numVertices - 8) = 2;
}
