void __thiscall btDefaultSoftBodySolver::copySoftBodyToVertexBuffer(
        btDefaultSoftBodySolver *this,
        const btSoftBody *const softBody,
        btVertexBufferDescriptor *vertexBuffer)
{
  int m_size; // edi
  int v4; // esi
  int v5; // eax
  _DWORD *v6; // ecx
  int v7; // edx
  int v8; // eax
  int v9; // eax
  _DWORD *v10; // ecx
  int v11; // edx
  int v12; // eax
  int v13; // ebx
  int v14; // [esp+14h] [ebp-1Ch]
  int v15; // [esp+14h] [ebp-1Ch]
  int v16; // [esp+1Ch] [ebp-14h]
  int v17; // [esp+24h] [ebp-Ch]
  int v18; // [esp+24h] [ebp-Ch]
  int v19; // [esp+28h] [ebp-8h]
  int v20; // [esp+28h] [ebp-8h]

  if ( vertexBuffer->getBufferType(vertexBuffer) == CPU_BUFFER )
  {
    m_size = softBody->m_nodes.m_size;
    v4 = ((int (__thiscall *)(btVertexBufferDescriptor *))vertexBuffer->__vftable[1].~btVertexBufferDescriptor)(vertexBuffer);
    if ( vertexBuffer->hasVertexPositions(vertexBuffer) )
    {
      v14 = vertexBuffer->getVertexOffset(vertexBuffer);
      v5 = vertexBuffer->getVertexStride(vertexBuffer);
      v6 = (_DWORD *)(v4 + 4 * v14);
      if ( m_size > 0 )
      {
        v7 = 4 * v5;
        v8 = 0;
        v15 = m_size;
        do
        {
          v17 = softBody->m_nodes.m_data[v8].m_x.mVec128.m128_i32[1];
          v19 = softBody->m_nodes.m_data[v8].m_x.mVec128.m128_i32[2];
          *v6 = softBody->m_nodes.m_data[v8].m_x.mVec128.m128_i32[0];
          v6[1] = v17;
          v6[2] = v19;
          v6 = (_DWORD *)((char *)v6 + v7);
          ++v8;
          --v15;
        }
        while ( v15 );
      }
    }
    if ( vertexBuffer->hasNormals(vertexBuffer) )
    {
      v16 = vertexBuffer->getNormalOffset(vertexBuffer);
      v9 = vertexBuffer->getNormalStride(vertexBuffer);
      v10 = (_DWORD *)(v4 + 4 * v16);
      if ( m_size > 0 )
      {
        v11 = 4 * v9;
        v12 = 0;
        v13 = m_size;
        do
        {
          v18 = softBody->m_nodes.m_data[v12].m_n.mVec128.m128_i32[1];
          v20 = softBody->m_nodes.m_data[v12].m_n.mVec128.m128_i32[2];
          *v10 = softBody->m_nodes.m_data[v12].m_n.mVec128.m128_i32[0];
          v10[1] = v18;
          v10[2] = v20;
          v10 = (_DWORD *)((char *)v10 + v11);
          ++v12;
          --v13;
        }
        while ( v13 );
      }
    }
  }
}
