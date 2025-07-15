void __thiscall btDefaultSoftBodySolver::copySoftBodyToVertexBuffer(
        btDefaultSoftBodySolver *this,
        const btSoftBody *const softBody,
        btVertexBufferDescriptor *vertexBuffer)
{
  int m_size; // edi
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // edi
  btSoftBody::Node *m_data; // eax
  btSoftBody::Node *v9; // eax
  btSoftBody::Node *v10; // eax
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // eax
  int v15; // eax
  int v16; // ecx
  int v17; // edx
  int v18; // edi
  unsigned int v19; // eax
  btSoftBody::Node *v20; // ebx
  btSoftBody::Node *v21; // ebx
  btSoftBody::Node *v22; // ebx
  int v23; // ecx
  int v24; // ecx
  int v25; // ecx
  int v26; // ebx
  int v27; // eax
  int v28; // edi
  int v29; // [esp+FCh] [ebp-24h]
  int v30; // [esp+100h] [ebp-20h]
  int v31; // [esp+104h] [ebp-1Ch]
  unsigned int v32; // [esp+104h] [ebp-1Ch]
  int v33; // [esp+104h] [ebp-1Ch]
  int v34; // [esp+104h] [ebp-1Ch]
  int v35; // [esp+108h] [ebp-18h]
  int v36; // [esp+10Ch] [ebp-14h]
  int v37; // [esp+10Ch] [ebp-14h]
  int v38; // [esp+10Ch] [ebp-14h]
  int v39; // [esp+10Ch] [ebp-14h]
  __int64 v40; // [esp+118h] [ebp-8h]
  __int64 v41; // [esp+118h] [ebp-8h]
  __int64 v42; // [esp+118h] [ebp-8h]
  __int64 v43; // [esp+118h] [ebp-8h]
  unsigned __int64 v44; // [esp+118h] [ebp-8h]
  __int64 v45; // [esp+118h] [ebp-8h]
  __int64 v46; // [esp+118h] [ebp-8h]
  __int64 v47; // [esp+118h] [ebp-8h]
  __int64 v48; // [esp+118h] [ebp-8h]
  unsigned __int64 v49; // [esp+118h] [ebp-8h]

  if ( vertexBuffer->getBufferType(vertexBuffer) == CPU_BUFFER )
  {
    m_size = softBody->m_nodes.m_size;
    v29 = m_size;
    v35 = ((int (__thiscall *)(btVertexBufferDescriptor *))vertexBuffer->__vftable[1].~btVertexBufferDescriptor)(vertexBuffer);
    if ( vertexBuffer->hasVertexPositions(vertexBuffer) )
    {
      v31 = vertexBuffer->getVertexOffset(vertexBuffer);
      v4 = vertexBuffer->getVertexStride(vertexBuffer);
      v5 = v35 + 4 * v31;
      v6 = 0;
      v36 = v4;
      v30 = 0;
      if ( m_size >= 4 )
      {
        v7 = 4 * v4;
        v32 = ((unsigned int)(v29 - 4) >> 2) + 1;
        v30 = 4 * v32;
        do
        {
          m_data = softBody->m_nodes.m_data;
          v40 = *(__int64 *)((char *)&m_data->m_x.mVec128.m128_i64[1] + v6);
          *(_QWORD *)v5 = *(unsigned __int64 *)((char *)m_data->m_x.mVec128.m128_u64 + v6);
          *(_DWORD *)(v5 + 8) = v40;
          v9 = softBody->m_nodes.m_data;
          v41 = *(__int64 *)((char *)&v9[1].m_x.mVec128.m128_i64[1] + v6);
          *(_QWORD *)(v5 + v7) = *(unsigned __int64 *)((char *)v9[1].m_x.mVec128.m128_u64 + v6);
          *(_DWORD *)(v5 + v7 + 8) = v41;
          v10 = softBody->m_nodes.m_data;
          v11 = v7 + v5;
          v42 = *(__int64 *)((char *)&v10[2].m_x.mVec128.m128_i64[1] + v6);
          *(_QWORD *)(v11 + v7) = *(unsigned __int64 *)((char *)v10[2].m_x.mVec128.m128_u64 + v6);
          v12 = v7 + v11;
          *(_DWORD *)(v12 + 8) = v42;
          v13 = v7 + v12;
          v43 = *(__int64 *)((char *)&softBody->m_nodes.m_data[3].m_x.mVec128.m128_i64[1] + v6);
          *(_QWORD *)v13 = *(unsigned __int64 *)((char *)softBody->m_nodes.m_data[3].m_x.mVec128.m128_u64 + v6);
          *(_DWORD *)(v13 + 8) = v43;
          v5 = v7 + v13;
          v6 += 448;
          --v32;
        }
        while ( v32 );
        m_size = v29;
        v4 = v36;
        v6 = v30;
      }
      if ( v6 < m_size )
      {
        v37 = 4 * v4;
        v14 = v6;
        v33 = m_size - v30;
        do
        {
          v44 = softBody->m_nodes.m_data[v14].m_x.mVec128.m128_u64[1];
          *(_QWORD *)v5 = softBody->m_nodes.m_data[v14].m_x.mVec128.m128_u64[0];
          *(_DWORD *)(v5 + 8) = v44;
          v5 += v37;
          ++v14;
          --v33;
        }
        while ( v33 );
      }
    }
    if ( vertexBuffer->hasNormals(vertexBuffer) )
    {
      v38 = vertexBuffer->getNormalOffset(vertexBuffer);
      v15 = vertexBuffer->getNormalStride(vertexBuffer);
      v16 = v35 + 4 * v38;
      v17 = 0;
      v34 = v15;
      if ( m_size >= 4 )
      {
        v18 = 4 * v15;
        v19 = ((unsigned int)(v29 - 4) >> 2) + 1;
        v39 = 4 * v19;
        do
        {
          v20 = softBody->m_nodes.m_data;
          v45 = *(__int64 *)((char *)&v20->m_n.mVec128.m128_i64[1] + v17);
          *(_QWORD *)v16 = *(unsigned __int64 *)((char *)v20->m_n.mVec128.m128_u64 + v17);
          *(_DWORD *)(v16 + 8) = v45;
          v21 = softBody->m_nodes.m_data;
          v46 = *(__int64 *)((char *)&v21[1].m_n.mVec128.m128_i64[1] + v17);
          *(_QWORD *)(v16 + v18) = *(unsigned __int64 *)((char *)v21[1].m_n.mVec128.m128_u64 + v17);
          *(_DWORD *)(v16 + v18 + 8) = v46;
          v22 = softBody->m_nodes.m_data;
          v23 = v18 + v16;
          v47 = *(__int64 *)((char *)&v22[2].m_n.mVec128.m128_i64[1] + v17);
          *(_QWORD *)(v23 + v18) = *(unsigned __int64 *)((char *)v22[2].m_n.mVec128.m128_u64 + v17);
          v24 = v18 + v23;
          *(_DWORD *)(v24 + 8) = v47;
          v25 = v18 + v24;
          v48 = *(__int64 *)((char *)&softBody->m_nodes.m_data[3].m_n.mVec128.m128_i64[1] + v17);
          *(_QWORD *)v25 = *(unsigned __int64 *)((char *)softBody->m_nodes.m_data[3].m_n.mVec128.m128_u64 + v17);
          *(_DWORD *)(v25 + 8) = v48;
          v16 = v18 + v25;
          v17 += 448;
          --v19;
        }
        while ( v19 );
        m_size = v29;
        v17 = v39;
        v15 = v34;
      }
      if ( v17 < m_size )
      {
        v26 = 4 * v15;
        v27 = v17;
        v28 = m_size - v17;
        do
        {
          v49 = softBody->m_nodes.m_data[v27].m_n.mVec128.m128_u64[1];
          *(_QWORD *)v16 = softBody->m_nodes.m_data[v27].m_n.mVec128.m128_u64[0];
          *(_DWORD *)(v16 + 8) = v49;
          v16 += v26;
          ++v27;
          --v28;
        }
        while ( v28 );
      }
    }
  }
}
