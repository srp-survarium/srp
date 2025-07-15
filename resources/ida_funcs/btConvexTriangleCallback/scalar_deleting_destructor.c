btConvexTriangleCallback *__thiscall btConvexTriangleCallback::`scalar deleting destructor'(
        btConvexTriangleCallback *this,
        char a2)
{
  btDispatcher *m_dispatcher; // ecx
  btPersistentManifold *m_manifoldPtr; // edx

  m_dispatcher = this->m_dispatcher;
  m_manifoldPtr = this->m_manifoldPtr;
  this->__vftable = (btConvexTriangleCallback_vtbl *)&btConvexTriangleCallback::`vftable';
  m_dispatcher->clearManifold(m_dispatcher, m_manifoldPtr);
  this->m_dispatcher->releaseManifold(this->m_dispatcher, this->m_manifoldPtr);
  this->__vftable = (btConvexTriangleCallback_vtbl *)&btTriangleCallback::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
