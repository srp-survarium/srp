void __userpurge btQuantizedBvh::walkStacklessQuantizedTree(
        btQuantizedBvh *this@<ecx>,
        int startNodeIndex@<eax>,
        btNodeOverlapCallback *nodeCallback,
        unsigned __int16 *quantizedQueryAabbMin,
        unsigned __int16 *quantizedQueryAabbMax,
        int endNodeIndex)
{
  btQuantizedBvhNode *v7; // esi
  int v8; // edx
  int v9; // eax
  int v10; // edi
  int v11; // eax
  int v12; // [esp+8h] [ebp-8h]
  int v13; // [esp+Ch] [ebp-4h]
  bool v14; // [esp+23h] [ebp+13h]

  v7 = &this->m_quantizedContiguousNodes.m_data[startNodeIndex];
  v8 = 0;
  v13 = startNodeIndex;
  while ( v13 < endNodeIndex )
  {
    v12 = ++v8;
    v9 = *quantizedQueryAabbMax >= v7->m_quantizedAabbMin[0]
      && v7->m_quantizedAabbMax[0] >= *quantizedQueryAabbMin
      && quantizedQueryAabbMax[1] >= v7->m_quantizedAabbMin[1]
      && quantizedQueryAabbMax[2] >= v7->m_quantizedAabbMin[2]
      && v7->m_quantizedAabbMax[1] >= quantizedQueryAabbMin[1]
      && v7->m_quantizedAabbMax[2] >= quantizedQueryAabbMin[2];
    v10 = ((v9 | -v9) >> 31) & 1;
    v14 = v7->m_escapeIndexOrTriangleIndex >= 0;
    if ( v7->m_escapeIndexOrTriangleIndex >= 0 )
    {
      if ( (v9 | -v9) >= 0 )
        goto LABEL_6;
      nodeCallback->processNode(
        nodeCallback,
        v7->m_escapeIndexOrTriangleIndex >> 21,
        ((unsigned int)&loc_1FFFFE + 1) & v7->m_escapeIndexOrTriangleIndex);
      v8 = v12;
    }
    if ( v10 )
      goto LABEL_8;
LABEL_6:
    if ( v14 )
    {
LABEL_8:
      ++v7;
      ++v13;
      continue;
    }
    v11 = -v7->m_escapeIndexOrTriangleIndex;
    v7 -= v7->m_escapeIndexOrTriangleIndex;
    v13 += v11;
  }
  if ( maxIterations < v8 )
    maxIterations = v8;
}
