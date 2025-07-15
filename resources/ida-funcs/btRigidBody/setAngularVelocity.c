void __usercall btRigidBody::setAngularVelocity(btRigidBody *this@<ecx>, const btVector3 *ang_vel@<eax>)
{
  btVector3 *p_m_angularVelocity; // ecx

  p_m_angularVelocity = &this->m_angularVelocity;
  *p_m_angularVelocity = (btVector3)ang_vel->mVec128;
  if ( fsqrt(
         (float)((float)(ang_vel->mVec128.m128_f32[0] * ang_vel->mVec128.m128_f32[0])
               + (float)(ang_vel->mVec128.m128_f32[1] * ang_vel->mVec128.m128_f32[1]))
       + (float)(ang_vel->mVec128.m128_f32[2] * ang_vel->mVec128.m128_f32[2])) > 0.0099999998 )
    *p_m_angularVelocity = (btVector3)ang_vel->mVec128;
}
