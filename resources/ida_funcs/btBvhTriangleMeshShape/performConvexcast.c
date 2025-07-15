void __userpurge btBvhTriangleMeshShape::performConvexcast(
        const btVector3 *rayTarget@<eax>,
        const btVector3 *aabbMin@<esi>,
        const btVector3 *aabbMax@<edx>,
        btBvhTriangleMeshShape *this,
        btTriangleCallback *callback,
        const btVector3 *raySource)
{
  btOptimizedBvh *m_bvh; // ecx
  int v7; // [esp+0h] [ebp-18h]
  int v8; // [esp+4h] [ebp-14h]
  btBvhTriangleMeshShape::performConvexcast::__l2::MyNodeOverlapCallback myNodeCallback; // [esp+Ch] [ebp-Ch] BYREF

  m_bvh = this->m_bvh;
  myNodeCallback.m_meshInterface = this->m_meshInterface;
  myNodeCallback.__vftable = (btBvhTriangleMeshShape::performConvexcast::__l2::MyNodeOverlapCallback_vtbl *)&`btBvhTriangleMeshShape::performConvexcast'::`2'::MyNodeOverlapCallback::`vftable';
  myNodeCallback.m_callback = callback;
  if ( m_bvh->m_useQuantization )
    btQuantizedBvh::walkStacklessQuantizedTreeAgainstRay(
      m_bvh,
      &myNodeCallback,
      raySource,
      rayTarget,
      aabbMin,
      aabbMax,
      m_bvh->m_curNodeIndex,
      v7);
  else
    btQuantizedBvh::walkStacklessTreeAgainstRay(m_bvh, &myNodeCallback, raySource, rayTarget, aabbMin, aabbMax, v7, v8);
}
