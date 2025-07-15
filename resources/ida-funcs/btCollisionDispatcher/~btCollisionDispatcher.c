void __thiscall btCollisionDispatcher::~btCollisionDispatcher(btCollisionDispatcher *this)
{
  this->__vftable = (btCollisionDispatcher_vtbl *)&btCollisionDispatcher::`vftable';
  this->m_defaultManifoldResult.__vftable = (btManifoldResult_vtbl *)&btDiscreteCollisionDetectorInterface::Result::`vftable';
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    (int)&this->m_manifoldsPtr);
  this->__vftable = (btCollisionDispatcher_vtbl *)&btDispatcher::`vftable';
}
