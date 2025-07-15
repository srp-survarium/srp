void __thiscall btGhostObject::~btGhostObject(btGhostObject *this)
{
  this->__vftable = (btGhostObject_vtbl *)&btGhostObject::`vftable';
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    (int)&this->m_overlappingObjects);
  this->__vftable = (btGhostObject_vtbl *)&btCollisionObject::`vftable';
}
