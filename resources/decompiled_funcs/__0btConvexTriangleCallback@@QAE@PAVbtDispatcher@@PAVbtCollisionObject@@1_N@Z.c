void __userpurge btConvexTriangleCallback::btConvexTriangleCallback(
        btConvexTriangleCallback *this@<esi>,
        btDispatcher *dispatcher@<ecx>,
        btCollisionObject *body1@<eax>,
        btCollisionObject *body0,
        bool isSwapped)
{
  btCollisionObject *v5; // edx
  btPersistentManifold *v6; // eax
  btDispatcher *m_dispatcher; // ecx

  this->__vftable = (btConvexTriangleCallback_vtbl *)&btConvexTriangleCallback::`vftable';
  this->m_dispatcher = dispatcher;
  this->m_dispatchInfoPtr = 0;
  v5 = body1;
  if ( !isSwapped )
    v5 = body0;
  this->m_convexBody = v5;
  if ( isSwapped )
    body1 = body0;
  this->m_triBody = body1;
  v6 = dispatcher->getNewManifold(dispatcher, v5, body1);
  m_dispatcher = this->m_dispatcher;
  this->m_manifoldPtr = v6;
  m_dispatcher->clearManifold(m_dispatcher, v6);
}
