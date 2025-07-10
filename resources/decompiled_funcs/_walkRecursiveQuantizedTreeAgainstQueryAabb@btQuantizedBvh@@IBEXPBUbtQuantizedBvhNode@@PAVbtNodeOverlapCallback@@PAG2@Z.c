void __thiscall btQuantizedBvh::walkRecursiveQuantizedTreeAgainstQueryAabb(
        btQuantizedBvh *this,
        const btQuantizedBvhNode *currentNode,
        btNodeOverlapCallback *nodeCallback,
        unsigned __int16 *quantizedQueryAabbMin,
        unsigned __int16 *quantizedQueryAabbMax)
{
  const btQuantizedBvhNode *v6; // ecx
  int v7; // ebx
  bool v8; // dl
  const btQuantizedBvhNode *v9; // ebx
  int m_escapeIndexOrTriangleIndex; // eax
  int v11; // ebx

  v6 = currentNode;
  v7 = *quantizedQueryAabbMax >= currentNode->m_quantizedAabbMin[0]
    && currentNode->m_quantizedAabbMax[0] >= *quantizedQueryAabbMin
    && quantizedQueryAabbMax[1] >= currentNode->m_quantizedAabbMin[1]
    && quantizedQueryAabbMax[2] >= currentNode->m_quantizedAabbMin[2]
    && currentNode->m_quantizedAabbMax[1] >= quantizedQueryAabbMin[1]
    && currentNode->m_quantizedAabbMax[2] >= quantizedQueryAabbMin[2];
  v8 = currentNode->m_escapeIndexOrTriangleIndex >= 0;
  if ( (v7 | -((v7 | -v7) >> 31)) < 0 )
  {
    while ( !v8 )
    {
      v9 = v6 + 1;
      btQuantizedBvh::walkRecursiveQuantizedTreeAgainstQueryAabb(
        this,
        v6 + 1,
        nodeCallback,
        quantizedQueryAabbMin,
        quantizedQueryAabbMax);
      m_escapeIndexOrTriangleIndex = v9->m_escapeIndexOrTriangleIndex;
      if ( m_escapeIndexOrTriangleIndex < 0 )
        v6 = &v9[-m_escapeIndexOrTriangleIndex];
      else
        v6 = v9 + 1;
      v11 = *quantizedQueryAabbMax >= v6->m_quantizedAabbMin[0]
         && v6->m_quantizedAabbMax[0] >= *quantizedQueryAabbMin
         && quantizedQueryAabbMax[1] >= v6->m_quantizedAabbMin[1]
         && quantizedQueryAabbMax[2] >= v6->m_quantizedAabbMin[2]
         && v6->m_quantizedAabbMax[1] >= quantizedQueryAabbMin[1]
         && v6->m_quantizedAabbMax[2] >= quantizedQueryAabbMin[2];
      v8 = v6->m_escapeIndexOrTriangleIndex >= 0;
      if ( (v11 | -((v11 | -v11) >> 31)) >= 0 )
        return;
    }
    nodeCallback->processNode(
      nodeCallback,
      v6->m_escapeIndexOrTriangleIndex >> 21,
      ((unsigned int)&loc_1FFFFE + 1) & v6->m_escapeIndexOrTriangleIndex);
  }
}
