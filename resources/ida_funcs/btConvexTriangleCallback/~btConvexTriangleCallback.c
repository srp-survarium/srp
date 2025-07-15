void __thiscall btConvexTriangleCallback::~btConvexTriangleCallback(btConvexTriangleCallback *this)
{
  btDispatcher *m_dispatcher; // ecx
  btPersistentManifold *m_manifoldPtr; // edx

  m_dispatcher = this->m_dispatcher;
  m_manifoldPtr = this->m_manifoldPtr;
  this->__vftable = (btConvexTriangleCallback_vtbl *)&btConvexTriangleCallback::`vftable';
  m_dispatcher->clearManifold(m_dispatcher, m_manifoldPtr);
  this->m_dispatcher->releaseManifold(this->m_dispatcher, this->m_manifoldPtr);
  this->__vftable = (btConvexTriangleCallback_vtbl *)&btTriangleCallback::`vftable';
}
