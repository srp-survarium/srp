void __userpurge btQuantizedBvh::walkStacklessQuantizedTreeCacheFriendly(
        unsigned __int16 *quantizedQueryAabbMin@<edi>,
        unsigned __int16 *quantizedQueryAabbMax@<esi>,
        btQuantizedBvh *this,
        btNodeOverlapCallback *nodeCallback)
{
  btBvhSubtreeInfo *v5; // ecx
  int v6; // [esp+4h] [ebp-4h]
  int v7; // [esp+10h] [ebp+8h]

  v6 = 0;
  if ( this->m_SubtreeHeaders.m_size > 0 )
  {
    v7 = 0;
    do
    {
      v5 = &this->m_SubtreeHeaders.m_data[v7];
      if ( (*quantizedQueryAabbMax >= v5->m_quantizedAabbMin[0]
         && v5->m_quantizedAabbMax[0] >= *quantizedQueryAabbMin
         && quantizedQueryAabbMax[1] >= v5->m_quantizedAabbMin[1]
         && quantizedQueryAabbMax[2] >= v5->m_quantizedAabbMin[2]
         && v5->m_quantizedAabbMax[1] >= quantizedQueryAabbMin[1]
         && v5->m_quantizedAabbMax[2] >= quantizedQueryAabbMin[2]
          ? -1
          : *quantizedQueryAabbMax >= v5->m_quantizedAabbMin[0]
         && v5->m_quantizedAabbMax[0] >= *quantizedQueryAabbMin
         && quantizedQueryAabbMax[1] >= v5->m_quantizedAabbMin[1]
         && quantizedQueryAabbMax[2] >= v5->m_quantizedAabbMin[2]
         && v5->m_quantizedAabbMax[1] >= quantizedQueryAabbMin[1]
         && v5->m_quantizedAabbMax[2] >= quantizedQueryAabbMin[2]) < 0 )
        btQuantizedBvh::walkStacklessQuantizedTree(
          this,
          v5->m_rootNodeIndex,
          nodeCallback,
          quantizedQueryAabbMin,
          quantizedQueryAabbMax,
          v5->m_rootNodeIndex + v5->m_subtreeSize);
      ++v6;
      ++v7;
    }
    while ( v6 < this->m_SubtreeHeaders.m_size );
  }
}
