void __userpurge btRigidBody::removeConstraintRef(btRigidBody *this@<ecx>, int a2@<esi>, btTypedConstraint *c)
{
  btAlignedObjectArray<btSoftBody::Joint *>::remove(
    (btAlignedObjectArray<btSoftBody *> *)this,
    a2 + 504,
    (btSoftBody *const *)&c);
  *(_DWORD *)(a2 + 264) = *(_DWORD *)(a2 + 508) > 0;
}
