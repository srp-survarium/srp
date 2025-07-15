void __userpurge btConvexConcaveCollisionAlgorithm::btConvexConcaveCollisionAlgorithm(
        btConvexConcaveCollisionAlgorithm *this@<edi>,
        const btCollisionAlgorithmConstructionInfo *ci@<ecx>,
        bool isSwapped@<al>,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  btDispatcher *m_dispatcher1; // edx

  this->__vftable = (btConvexConcaveCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  m_dispatcher1 = ci->m_dispatcher1;
  this->m_isSwapped = isSwapped;
  this->m_dispatcher = m_dispatcher1;
  this->__vftable = (btConvexConcaveCollisionAlgorithm_vtbl *)&btConvexConcaveCollisionAlgorithm::`vftable';
  btConvexTriangleCallback::btConvexTriangleCallback(
    &this->m_btConvexTriangleCallback,
    ci->m_dispatcher1,
    body1,
    body0,
    isSwapped);
}
