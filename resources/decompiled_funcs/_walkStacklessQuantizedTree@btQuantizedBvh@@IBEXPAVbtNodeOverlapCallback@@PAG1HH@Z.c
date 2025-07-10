void __userpurge btQuantizedBvh::walkStacklessQuantizedTree(
        btQuantizedBvh *this@<edx>,
        int startNodeIndex@<eax>,
        btNodeOverlapCallback *nodeCallback,
        unsigned __int16 *quantizedQueryAabbMin,
        unsigned __int16 *quantizedQueryAabbMax,
        int endNodeIndex)
{
  btQuantizedBvhNode *v8; // esi
  int v9; // ecx
  int v10; // eax
  int v11; // edi
  bool v12; // al
  int v13; // eax
  int walkIterations; // [esp+Ch] [ebp-4h]
  int curIndex; // [esp+18h] [ebp+8h]
  bool isLeafNode; // [esp+1Ch] [ebp+Ch]

  v8 = &this->m_quantizedContiguousNodes.m_data[startNodeIndex];
  v9 = 0;
  curIndex = startNodeIndex;
  while ( curIndex < endNodeIndex )
  {
    walkIterations = ++v9;
    v10 = *quantizedQueryAabbMax >= v8->m_quantizedAabbMin[0]
       && v8->m_quantizedAabbMax[0] >= *quantizedQueryAabbMin
       && quantizedQueryAabbMax[1] >= v8->m_quantizedAabbMin[1]
       && quantizedQueryAabbMax[2] >= v8->m_quantizedAabbMin[2]
       && v8->m_quantizedAabbMax[1] >= quantizedQueryAabbMin[1]
       && v8->m_quantizedAabbMax[2] >= quantizedQueryAabbMin[2];
    v11 = ((v10 | -v10) >> 31) & 1;
    v12 = v8->m_escapeIndexOrTriangleIndex >= 0;
    isLeafNode = v12;
    if ( v8->m_escapeIndexOrTriangleIndex >= 0 )
    {
      if ( !v11 )
        goto LABEL_6;
      nodeCallback->processNode(
        nodeCallback,
        v8->m_escapeIndexOrTriangleIndex >> 21,
        ((unsigned int)&loc_1FFFFE + 1) & v8->m_escapeIndexOrTriangleIndex);
      v12 = isLeafNode;
      v9 = walkIterations;
    }
    if ( v11 )
      goto LABEL_8;
LABEL_6:
    if ( v12 )
    {
LABEL_8:
      ++v8;
      ++curIndex;
      continue;
    }
    v13 = -v8->m_escapeIndexOrTriangleIndex;
    v8 -= v8->m_escapeIndexOrTriangleIndex;
    curIndex += v13;
  }
  if ( maxIterations < v9 )
    maxIterations = v9;
}
