void __thiscall btQuantizedBvh::buildTree(btQuantizedBvh *this, int startIndex, int endIndex)
{
  int v3; // ebx
  int v5; // eax
  btQuantizedBvh *v6; // ecx
  btVector3 *AabbMin; // eax
  int v8; // ebx
  btQuantizedBvh *v9; // ecx
  int v10; // edi
  int v11; // [esp+94h] [ebp-34h]
  int v12; // [esp+98h] [ebp-30h]
  int v13; // [esp+9Ch] [ebp-2Ch]
  const btVector3 *newAabbMaxa; // [esp+A0h] [ebp-28h]
  btVector3 *newAabbMax; // [esp+A0h] [ebp-28h]
  int m_curNodeIndex; // [esp+A4h] [ebp-24h]
  btVector3 v17; // [esp+A8h] [ebp-20h] BYREF
  btVector3 v18; // [esp+B8h] [ebp-10h] BYREF

  v3 = startIndex;
  m_curNodeIndex = this->m_curNodeIndex;
  if ( endIndex - startIndex == 1 )
  {
    btQuantizedBvh::assignInternalNodeFromLeafNode(startIndex, this->m_curNodeIndex, this);
    ++this->m_curNodeIndex;
  }
  else
  {
    v5 = btQuantizedBvh::calcSplittingAxis(this, this, startIndex, endIndex);
    v12 = btQuantizedBvh::sortAndCalcSplittingIndex(v6, this, startIndex, endIndex, v5);
    v13 = this->m_curNodeIndex;
    btQuantizedBvh::setInternalNodeAabbMin(v13, &this->m_bvhAabbMax, this);
    btQuantizedBvh::setInternalNodeAabbMax(this->m_curNodeIndex, &this->m_bvhAabbMin, this);
    v11 = startIndex;
    if ( startIndex < endIndex )
    {
      do
      {
        newAabbMaxa = btQuantizedBvh::getAabbMax(v3, &v17, this);
        AabbMin = btQuantizedBvh::getAabbMin(v3, &v18, this);
        btQuantizedBvh::mergeInternalNodeAabb(AabbMin, newAabbMaxa, this, this->m_curNodeIndex);
        v3 = ++v11;
      }
      while ( v11 < endIndex );
      v3 = startIndex;
    }
    newAabbMax = (btVector3 *)++this->m_curNodeIndex;
    btQuantizedBvh::buildTree(this, v3, v12);
    v8 = this->m_curNodeIndex;
    btQuantizedBvh::buildTree(this, v12, endIndex);
    v10 = this->m_curNodeIndex - m_curNodeIndex;
    if ( !this->m_useQuantization )
      goto LABEL_11;
    if ( 16 * v10 > 2048 )
      btQuantizedBvh::updateSubtreeHeaders(v9, (int)this, (int)newAabbMax, v8);
    if ( this->m_useQuantization )
      this->m_quantizedContiguousNodes.m_data[v13].m_escapeIndexOrTriangleIndex = -v10;
    else
LABEL_11:
      this->m_contiguousNodes.m_data[v13].m_escapeIndex = v10;
  }
}
