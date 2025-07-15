void __fastcall btQuantizedBvh::assignInternalNodeFromLeafNode(
        int leafNodeIndex,
        int internalNode,
        btQuantizedBvh *this)
{
  btQuantizedBvhNode *v3; // esi
  btQuantizedBvhNode *v4; // edi

  if ( this->m_useQuantization )
  {
    v3 = &this->m_quantizedLeafNodes.m_data[leafNodeIndex];
    v4 = &this->m_quantizedContiguousNodes.m_data[internalNode];
    *(_DWORD *)v4->m_quantizedAabbMin = *(_DWORD *)v3->m_quantizedAabbMin;
    v3 = (btQuantizedBvhNode *)((char *)v3 + 4);
    v4 = (btQuantizedBvhNode *)((char *)v4 + 4);
    *(_DWORD *)v4->m_quantizedAabbMin = *(_DWORD *)v3->m_quantizedAabbMin;
    v3 = (btQuantizedBvhNode *)((char *)v3 + 4);
    v4 = (btQuantizedBvhNode *)((char *)v4 + 4);
    *(_DWORD *)v4->m_quantizedAabbMin = *(_DWORD *)v3->m_quantizedAabbMin;
    *(_DWORD *)&v4->m_quantizedAabbMin[2] = *(_DWORD *)&v3->m_quantizedAabbMin[2];
  }
  else
  {
    qmemcpy(
      &this->m_contiguousNodes.m_data[internalNode],
      &this->m_leafNodes.m_data[leafNodeIndex],
      sizeof(this->m_contiguousNodes.m_data[internalNode]));
  }
}
