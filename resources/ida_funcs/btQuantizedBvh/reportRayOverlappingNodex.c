void __userpurge btQuantizedBvh::reportRayOverlappingNodex(
        btNodeOverlapCallback *nodeCallback@<edx>,
        const btVector3 *rayTarget@<eax>,
        int a3@<edi>,
        int a4@<esi>,
        btQuantizedBvh *this,
        const btVector3 *raySource)
{
  bool v6; // zf
  btVector3 aabbMax; // [esp+8h] [ebp-20h] BYREF
  btVector3 aabbMin; // [esp+18h] [ebp-10h] BYREF

  v6 = !this->m_useQuantization;
  memset(&aabbMax, 0, sizeof(aabbMax));
  memset(&aabbMin, 0, sizeof(aabbMin));
  if ( v6 )
    btQuantizedBvh::walkStacklessTreeAgainstRay(raySource, rayTarget, this, nodeCallback, &aabbMin, &aabbMax, a3, a4);
  else
    btQuantizedBvh::walkStacklessQuantizedTreeAgainstRay(
      this,
      (int)this,
      nodeCallback,
      raySource,
      rayTarget,
      &aabbMin,
      &aabbMax,
      this->m_curNodeIndex,
      a3);
}
