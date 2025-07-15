void __fastcall btQuantizedBvh::assignInternalNodeFromLeafNode(
        int leafNodeIndex,
        int internalNode,
        btQuantizedBvh *this)
{
  __int64 v3; // xmm0_8
  btQuantizedBvhNode *v4; // eax
  btQuantizedBvhNode *v5; // ecx

  if ( this->m_useQuantization )
  {
    v3 = *(_QWORD *)this->m_quantizedLeafNodes.m_data[leafNodeIndex].m_quantizedAabbMin;
    v4 = &this->m_quantizedLeafNodes.m_data[leafNodeIndex];
    v5 = &this->m_quantizedContiguousNodes.m_data[internalNode];
    *(_QWORD *)v5->m_quantizedAabbMin = v3;
    *(_QWORD *)&v5->m_quantizedAabbMax[1] = *(_QWORD *)&v4->m_quantizedAabbMax[1];
  }
  else
  {
    qmemcpy(
      &this->m_contiguousNodes.m_data[internalNode],
      &this->m_leafNodes.m_data[leafNodeIndex],
      sizeof(this->m_contiguousNodes.m_data[internalNode]));
  }
}
