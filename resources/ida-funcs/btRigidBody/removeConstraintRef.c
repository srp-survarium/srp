void __userpurge btRigidBody::removeConstraintRef(
        btRigidBody *this@<ecx>,
        int a2@<esi>,
        btAlignedObjectArray<btTypedConstraint *> c)
{
  btAlignedObjectArray<btTypedConstraint *>::remove(&c, a2 + 504);
  *(_DWORD *)(a2 + 264) = *(_DWORD *)(a2 + 508) > 0;
}
