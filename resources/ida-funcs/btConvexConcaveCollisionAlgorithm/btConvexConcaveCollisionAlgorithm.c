void __userpurge btConvexConcaveCollisionAlgorithm::btConvexConcaveCollisionAlgorithm(
        btConvexConcaveCollisionAlgorithm *this@<esi>,
        const btCollisionAlgorithmConstructionInfo *ci@<eax>,
        bool isSwapped@<dl>,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  btDispatcher *m_dispatcher1; // ecx
  btCollisionObject *v6; // eax
  btCollisionObject *v7; // edi
  btPersistentManifold *v8; // eax
  btDispatcher *m_dispatcher; // ecx

  this->__vftable = (btConvexConcaveCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  this->m_dispatcher = ci->m_dispatcher1;
  this->__vftable = (btConvexConcaveCollisionAlgorithm_vtbl *)&btConvexConcaveCollisionAlgorithm::`vftable';
  this->m_isSwapped = isSwapped;
  m_dispatcher1 = ci->m_dispatcher1;
  this->m_btConvexTriangleCallback.m_dispatchInfoPtr = 0;
  v6 = body0;
  v7 = body1;
  if ( !isSwapped )
  {
    v7 = body0;
    v6 = body1;
  }
  this->m_btConvexTriangleCallback.__vftable = (btConvexTriangleCallback_vtbl *)&btConvexTriangleCallback::`vftable';
  this->m_btConvexTriangleCallback.m_dispatcher = m_dispatcher1;
  this->m_btConvexTriangleCallback.m_convexBody = v7;
  this->m_btConvexTriangleCallback.m_triBody = v6;
  v8 = m_dispatcher1->getNewManifold(m_dispatcher1, v7, v6);
  m_dispatcher = this->m_btConvexTriangleCallback.m_dispatcher;
  this->m_btConvexTriangleCallback.m_manifoldPtr = v8;
  m_dispatcher->clearManifold(m_dispatcher, v8);
}
