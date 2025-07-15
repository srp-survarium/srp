void __thiscall btSoftBody::CJoint::Terminate(btSoftBody::CJoint *this, float dt)
{
  btVector3 v3; // [esp+0h] [ebp-10h] BYREF

  if ( this->m_split > 0.0 )
  {
    v3.mVec128.m128_i32[0] = this->m_sdrift.mVec128.m128_i32[0] ^ _mask__NegFloat_;
    v3.mVec128.m128_i32[1] = this->m_sdrift.mVec128.m128_i32[1] ^ _mask__NegFloat_;
    v3.mVec128.m128_u64[1] = this->m_sdrift.mVec128.m128_u32[2] ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
    btSoftBody::Body::applyDImpulse(this->m_bodies, this->m_rpos, &v3);
    btSoftBody::Body::applyDImpulse(&this->m_bodies[1], &this->m_rpos[1], &this->m_sdrift);
  }
}
