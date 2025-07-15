void __userpurge btQuantizedBvh::reportBoxCastOverlappingNodex(
        const btVector3 *rayTarget@<eax>,
        const btVector3 *aabbMin@<esi>,
        const btVector3 *aabbMax@<edx>,
        btQuantizedBvh *this,
        btNodeOverlapCallback *nodeCallback,
        const btVector3 *raySource)
{
  int v6; // [esp+0h] [ebp-10h]
  int v7; // [esp+4h] [ebp-Ch]

  if ( this->m_useQuantization )
    btQuantizedBvh::walkStacklessQuantizedTreeAgainstRay(
      this,
      (int)this,
      nodeCallback,
      raySource,
      rayTarget,
      aabbMin,
      aabbMax,
      this->m_curNodeIndex,
      v6);
  else
    btQuantizedBvh::walkStacklessTreeAgainstRay(raySource, rayTarget, this, nodeCallback, aabbMin, aabbMax, v6, v7);
}
