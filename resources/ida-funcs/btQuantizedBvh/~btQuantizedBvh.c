void __thiscall btQuantizedBvh::~btQuantizedBvh(btQuantizedBvh *this)
{
  btBvhSubtreeInfo *m_data; // eax
  btQuantizedBvhNode *v3; // eax
  btQuantizedBvhNode *v4; // eax
  btOptimizedBvhNode *v5; // eax
  btOptimizedBvhNode *v6; // eax

  this->__vftable = (btQuantizedBvh_vtbl *)&btQuantizedBvh::`vftable';
  m_data = this->m_SubtreeHeaders.m_data;
  if ( m_data )
  {
    if ( this->m_SubtreeHeaders.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
    this->m_SubtreeHeaders.m_data = 0;
  }
  this->m_SubtreeHeaders.m_ownsMemory = 1;
  this->m_SubtreeHeaders.m_data = 0;
  this->m_SubtreeHeaders.m_size = 0;
  this->m_SubtreeHeaders.m_capacity = 0;
  v3 = this->m_quantizedContiguousNodes.m_data;
  if ( v3 )
  {
    if ( this->m_quantizedContiguousNodes.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v3);
    }
    this->m_quantizedContiguousNodes.m_data = 0;
  }
  this->m_quantizedContiguousNodes.m_ownsMemory = 1;
  this->m_quantizedContiguousNodes.m_data = 0;
  this->m_quantizedContiguousNodes.m_size = 0;
  this->m_quantizedContiguousNodes.m_capacity = 0;
  v4 = this->m_quantizedLeafNodes.m_data;
  if ( v4 )
  {
    if ( this->m_quantizedLeafNodes.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v4);
    }
    this->m_quantizedLeafNodes.m_data = 0;
  }
  this->m_quantizedLeafNodes.m_ownsMemory = 1;
  this->m_quantizedLeafNodes.m_data = 0;
  this->m_quantizedLeafNodes.m_size = 0;
  this->m_quantizedLeafNodes.m_capacity = 0;
  v5 = this->m_contiguousNodes.m_data;
  if ( v5 )
  {
    if ( this->m_contiguousNodes.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v5);
    }
    this->m_contiguousNodes.m_data = 0;
  }
  this->m_contiguousNodes.m_ownsMemory = 1;
  this->m_contiguousNodes.m_data = 0;
  this->m_contiguousNodes.m_size = 0;
  this->m_contiguousNodes.m_capacity = 0;
  v6 = this->m_leafNodes.m_data;
  if ( v6 )
  {
    if ( this->m_leafNodes.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v6);
    }
    this->m_leafNodes.m_data = 0;
  }
  this->m_leafNodes.m_data = 0;
  this->m_leafNodes.m_size = 0;
  this->m_leafNodes.m_capacity = 0;
  this->m_leafNodes.m_ownsMemory = 1;
}
