void __userpurge btBvhTriangleMeshShape::performRaycast(
        btBvhTriangleMeshShape *this@<eax>,
        btTriangleCallback *callback@<edx>,
        const btVector3 *raySource,
        const btVector3 *rayTarget)
{
  btOptimizedBvh *m_bvh; // edx
  btBvhTriangleMeshShape::performRaycast::__l2::MyNodeOverlapCallback myNodeCallback; // [esp+0h] [ebp-Ch] BYREF

  myNodeCallback.m_meshInterface = this->m_meshInterface;
  myNodeCallback.m_callback = callback;
  m_bvh = this->m_bvh;
  myNodeCallback.__vftable = (btBvhTriangleMeshShape::performRaycast::__l2::MyNodeOverlapCallback_vtbl *)&`btBvhTriangleMeshShape::performRaycast'::`2'::MyNodeOverlapCallback::`vftable';
  btQuantizedBvh::reportRayOverlappingNodex(m_bvh, &myNodeCallback, raySource, rayTarget);
}
