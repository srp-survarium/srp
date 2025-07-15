void __thiscall btQuantizedBvh::buildTree(btQuantizedBvh *this, int startIndex, int endIndex)
{
  int v4; // eax
  btQuantizedBvh *v5; // ecx
  const btVector3 *v6; // [esp+0h] [ebp-40h]

  if ( endIndex - startIndex != 1 )
  {
    v4 = btQuantizedBvh::calcSplittingAxis(this, this, startIndex, endIndex);
    btQuantizedBvh::sortAndCalcSplittingIndex(v5, this, startIndex, endIndex, v4);
    btQuantizedBvh::setInternalNodeAabbMin(
      (btQuantizedBvh *)this->m_curNodeIndex,
      (int)this,
      (int)&this->m_bvhAabbMax,
      v6);
    JUMPOUT(0x93A82);
  }
  btQuantizedBvh::assignInternalNodeFromLeafNode(startIndex, this->m_curNodeIndex, this);
  ++this->m_curNodeIndex;
}
