void __thiscall btQuantizedBvh::walkStacklessTree(
        btQuantizedBvh *this,
        const btQuantizedBvh *nodeCallback,
        btNodeOverlapCallback *aabbMin,
        const btVector3 *aabbMax,
        const btVector3 *aabbMaxa)
{
  int v5; // edx
  int v6; // ebp
  btNodeOverlapCallback_vtbl *m_data; // esi
  unsigned __int8 v8; // al
  int v9; // edi
  bool v10; // bl
  void (__thiscall *v11)(btNodeOverlapCallback *); // eax
  int walkIterations; // [esp+8h] [ebp-4h]

  v5 = 0;
  v6 = 0;
  m_data = (btNodeOverlapCallback_vtbl *)nodeCallback->m_contiguousNodes.m_data;
  while ( v6 < nodeCallback->m_curNodeIndex )
  {
    walkIterations = ++v5;
    v8 = 1;
    if ( aabbMax->mVec128.m128_f32[0] > *(float *)&m_data[2].~btNodeOverlapCallback
      || *(float *)&m_data->~btNodeOverlapCallback > aabbMaxa->mVec128.m128_f32[0] )
    {
      v8 = 0;
    }
    if ( aabbMax->mVec128.m128_f32[2] > *(float *)&m_data[3].~btNodeOverlapCallback
      || *(float *)&m_data[1].~btNodeOverlapCallback > aabbMaxa->mVec128.m128_f32[2] )
    {
      v8 = 0;
    }
    if ( aabbMax->mVec128.m128_f32[1] > *(float *)&m_data[2].processNode
      || *(float *)&m_data->processNode > aabbMaxa->mVec128.m128_f32[1] )
    {
      v8 = 0;
    }
    v9 = v8;
    v10 = m_data[4].~btNodeOverlapCallback == (void (__thiscall *)(btNodeOverlapCallback *))-1;
    if ( m_data[4].~btNodeOverlapCallback == (void (__thiscall *)(btNodeOverlapCallback *))-1 )
    {
      if ( !v8 )
        goto LABEL_15;
      aabbMin->processNode(aabbMin, (int)m_data[4].processNode, (int)m_data[5].~btNodeOverlapCallback);
      v5 = walkIterations;
    }
    if ( v9 )
      goto LABEL_17;
LABEL_15:
    if ( v10 )
    {
LABEL_17:
      m_data += 8;
      ++v6;
      continue;
    }
    v11 = m_data[4].~btNodeOverlapCallback;
    m_data += 8 * (_DWORD)v11;
    v6 += (int)v11;
  }
  if ( maxIterations < v5 )
    maxIterations = v5;
}
