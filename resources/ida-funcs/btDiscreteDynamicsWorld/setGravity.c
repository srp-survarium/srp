void __thiscall btDiscreteDynamicsWorld::setGravity(btDiscreteDynamicsWorld *this, btRigidBody *gravity)
{
  btRigidBody *v3; // ecx
  int i; // esi
  btRigidBody *v5; // edx
  int m_activationState1; // eax

  v3 = gravity;
  this->m_gravity.mVec128.m128_i32[0] = (int)gravity->__vftable;
  this->m_gravity.mVec128.m128_i32[1] = *((_DWORD *)&gravity->__vftable + 1);
  this->m_gravity.mVec128.m128_i32[2] = *((_DWORD *)&gravity->__vftable + 2);
  this->m_gravity.mVec128.m128_i32[3] = *((_DWORD *)&gravity->__vftable + 3);
  for ( i = 0; i < this->m_nonStaticRigidBodies.m_size; ++i )
  {
    v5 = this->m_nonStaticRigidBodies.m_data[i];
    m_activationState1 = v5->m_activationState1;
    if ( m_activationState1 != 2 && m_activationState1 != 5 && (v5->m_rigidbodyFlags & 1) == 0 )
      btRigidBody::setGravity(v3, (int)v5);
  }
}
