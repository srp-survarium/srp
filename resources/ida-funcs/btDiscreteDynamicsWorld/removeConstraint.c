void __thiscall btDiscreteDynamicsWorld::removeConstraint(btDiscreteDynamicsWorld *this, btTypedConstraint *constraint)
{
  btTypedConstraint *v2; // esi
  btRigidBody *m_rbA; // edi
  BOOL v4; // edx
  btRigidBody *m_rbB; // edi
  btAlignedObjectArray<btSoftBody *> *v6; // ecx

  btAlignedObjectArray<btSoftBody::Joint *>::remove(
    (btAlignedObjectArray<btSoftBody *> *)this,
    (int)&this->m_constraints,
    (btSoftBody *const *)&constraint);
  v2 = constraint;
  m_rbA = constraint->m_rbA;
  btAlignedObjectArray<btSoftBody::Joint *>::remove(
    (btAlignedObjectArray<btSoftBody *> *)&constraint,
    (int)&m_rbA->m_constraintRefs,
    (btSoftBody *const *)&constraint);
  v4 = m_rbA->m_constraintRefs.m_size > 0;
  constraint = v2;
  m_rbA->m_checkCollideWith = v4;
  m_rbB = v2->m_rbB;
  btAlignedObjectArray<btSoftBody::Joint *>::remove(v6, (int)&m_rbB->m_constraintRefs, (btSoftBody *const *)&constraint);
  m_rbB->m_checkCollideWith = m_rbB->m_constraintRefs.m_size > 0;
}
