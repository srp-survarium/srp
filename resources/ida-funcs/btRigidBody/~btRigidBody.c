void __thiscall btRigidBody::~btRigidBody(btRigidBody *this)
{
  this->__vftable = (btRigidBody_vtbl *)&btRigidBody::`vftable';
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    (int)&this->m_constraintRefs);
  this->__vftable = (btRigidBody_vtbl *)&btCollisionObject::`vftable';
}
