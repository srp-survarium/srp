void __userpurge btDiscreteDynamicsWorld::setGravity(
        btDiscreteDynamicsWorld *this@<ecx>,
        const btVector3 *a2@<edi>,
        btRigidBody *gravity)
{
  btRigidBody *v4; // ecx
  int v5; // edi
  bool v6; // cc
  btRigidBody *v7; // edx
  int m_activationState1; // eax
  const btVector3 *v9; // [esp-4h] [ebp-8h]

  v4 = gravity;
  v9 = a2;
  this->m_gravity.mVec128.m128_u64[0] = *(_QWORD *)&gravity->__vftable;
  v5 = 0;
  v6 = this->m_nonStaticRigidBodies.m_size <= 0;
  this->m_gravity.mVec128.m128_u64[1] = *((_QWORD *)&gravity->__vftable + 1);
  if ( !v6 )
  {
    do
    {
      v7 = this->m_nonStaticRigidBodies.m_data[v5];
      m_activationState1 = v7->m_activationState1;
      if ( m_activationState1 != 2 && m_activationState1 != 5 && (v7->m_rigidbodyFlags & 1) == 0 )
        btRigidBody::setGravity(v4, v9);
      ++v5;
    }
    while ( v5 < this->m_nonStaticRigidBodies.m_size );
  }
}
