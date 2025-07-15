void __thiscall btQuantizedBvh::walkRecursiveQuantizedTreeAgainstQueryAabb(
        btQuantizedBvh *this,
        const btQuantizedBvhNode *currentNode,
        btNodeOverlapCallback *nodeCallback,
        unsigned __int16 *quantizedQueryAabbMin,
        unsigned __int16 *quantizedQueryAabbMax)
{
  const btQuantizedBvhNode *v6; // ebx
  int m_escapeIndexOrTriangleIndex; // eax
  int v8; // ecx

  while ( 1 )
  {
    v8 = *quantizedQueryAabbMax >= currentNode->m_quantizedAabbMin[0]
      && currentNode->m_quantizedAabbMax[0] >= *quantizedQueryAabbMin
      && quantizedQueryAabbMax[1] >= currentNode->m_quantizedAabbMin[1]
      && quantizedQueryAabbMax[2] >= currentNode->m_quantizedAabbMin[2]
      && currentNode->m_quantizedAabbMax[1] >= quantizedQueryAabbMin[1]
      && currentNode->m_quantizedAabbMax[2] >= quantizedQueryAabbMin[2];
    if ( (v8 | -v8) >= 0 )
      break;
    if ( currentNode->m_escapeIndexOrTriangleIndex >= 0 )
    {
      nodeCallback->processNode(
        nodeCallback,
        currentNode->m_escapeIndexOrTriangleIndex >> 21,
        ((unsigned int)&loc_1FFFFE + 1) & currentNode->m_escapeIndexOrTriangleIndex);
      return;
    }
    v6 = currentNode + 1;
    btQuantizedBvh::walkRecursiveQuantizedTreeAgainstQueryAabb(
      this,
      currentNode + 1,
      nodeCallback,
      quantizedQueryAabbMin,
      quantizedQueryAabbMax);
    m_escapeIndexOrTriangleIndex = v6->m_escapeIndexOrTriangleIndex;
    if ( m_escapeIndexOrTriangleIndex < 0 )
      currentNode = &v6[-m_escapeIndexOrTriangleIndex];
    else
      currentNode = v6 + 1;
  }
}
