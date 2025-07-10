void __thiscall btSoftBody::AJoint::Terminate(btSoftBody::AJoint *this, float dt)
{
  btVector3 *p_m_sdrift; // ebx
  btVector3 impulse; // [esp+4h] [ebp-10h] BYREF

  if ( this->m_split > 0.0 )
  {
    p_m_sdrift = &this->m_sdrift;
    impulse.mVec128.m128_f32[0] = -this->m_sdrift.mVec128.m128_f32[0];
    impulse.mVec128.m128_f32[1] = -this->m_sdrift.mVec128.m128_f32[1];
    impulse.mVec128.m128_f32[2] = -this->m_sdrift.mVec128.m128_f32[2];
    impulse.mVec128.m128_i32[3] = 0;
    btSoftBody::Body::applyDAImpulse(this->m_bodies, (btRigidBody *)&impulse);
    btSoftBody::Body::applyDAImpulse(&this->m_bodies[1], (btRigidBody *)p_m_sdrift);
  }
}
