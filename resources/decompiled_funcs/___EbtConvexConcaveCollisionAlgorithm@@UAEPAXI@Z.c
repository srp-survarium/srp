btConvexConcaveCollisionAlgorithm *__thiscall btConvexConcaveCollisionAlgorithm::`vector deleting destructor'(
        btConvexConcaveCollisionAlgorithm *this,
        char a2)
{
  btDispatcher *m_dispatcher; // ecx
  btPersistentManifold *m_manifoldPtr; // edx

  this->__vftable = (btConvexConcaveCollisionAlgorithm_vtbl *)&btConvexConcaveCollisionAlgorithm::`vftable';
  m_dispatcher = this->m_btConvexTriangleCallback.m_dispatcher;
  m_manifoldPtr = this->m_btConvexTriangleCallback.m_manifoldPtr;
  this->m_btConvexTriangleCallback.__vftable = (btConvexTriangleCallback_vtbl *)&btConvexTriangleCallback::`vftable';
  m_dispatcher->clearManifold(m_dispatcher, m_manifoldPtr);
  this->m_btConvexTriangleCallback.m_dispatcher->releaseManifold(
    this->m_btConvexTriangleCallback.m_dispatcher,
    this->m_btConvexTriangleCallback.m_manifoldPtr);
  this->m_btConvexTriangleCallback.__vftable = (btConvexTriangleCallback_vtbl *)&btTriangleCallback::`vftable';
  this->__vftable = (btConvexConcaveCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
