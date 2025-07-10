void __userpurge btQuantizedBvh::walkStacklessQuantizedTreeCacheFriendly(
        unsigned __int16 *quantizedQueryAabbMin@<edi>,
        unsigned __int16 *quantizedQueryAabbMax@<esi>,
        btQuantizedBvh *this,
        btNodeOverlapCallback *nodeCallback)
{
  int v5; // ebx
  bool v6; // cc
  btBvhSubtreeInfo *v7; // ecx
  int i; // [esp+Ch] [ebp+4h]

  v5 = 0;
  v6 = this->m_SubtreeHeaders.m_size <= 0;
  i = 0;
  if ( !v6 )
  {
    do
    {
      v7 = &this->m_SubtreeHeaders.m_data[v5];
      if ( (*quantizedQueryAabbMax >= v7->m_quantizedAabbMin[0]
         && v7->m_quantizedAabbMax[0] >= *quantizedQueryAabbMin
         && quantizedQueryAabbMax[1] >= v7->m_quantizedAabbMin[1]
         && quantizedQueryAabbMax[2] >= v7->m_quantizedAabbMin[2]
         && v7->m_quantizedAabbMax[1] >= quantizedQueryAabbMin[1]
         && v7->m_quantizedAabbMax[2] >= quantizedQueryAabbMin[2]
          ? -1
          : *quantizedQueryAabbMax >= v7->m_quantizedAabbMin[0]
         && v7->m_quantizedAabbMax[0] >= *quantizedQueryAabbMin
         && quantizedQueryAabbMax[1] >= v7->m_quantizedAabbMin[1]
         && quantizedQueryAabbMax[2] >= v7->m_quantizedAabbMin[2]
         && v7->m_quantizedAabbMax[1] >= quantizedQueryAabbMin[1]
         && v7->m_quantizedAabbMax[2] >= quantizedQueryAabbMin[2]) < 0 )
        btQuantizedBvh::walkStacklessQuantizedTree(
          this,
          v7->m_rootNodeIndex,
          nodeCallback,
          quantizedQueryAabbMin,
          quantizedQueryAabbMax,
          v7->m_rootNodeIndex + v7->m_subtreeSize);
      ++v5;
      ++i;
    }
    while ( i < this->m_SubtreeHeaders.m_size );
  }
}
