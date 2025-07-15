void __userpurge btRigidBody::internalWritebackVelocity(btRigidBody *this@<ecx>, int a2@<esi>, float timeStep)
{
  unsigned int v3; // xmm1_4
  __int64 v4; // [esp+18h] [ebp-50h]
  __int64 v5; // [esp+20h] [ebp-48h]
  btTransform newTransform; // [esp+28h] [ebp-40h] BYREF

  if ( *(float *)(a2 + 352) != 0.0 )
  {
    *(float *)&v4 = *(float *)(a2 + 320) + *(float *)(a2 + 576);
    *((float *)&v4 + 1) = *(float *)(a2 + 324) + *(float *)(a2 + 580);
    *(float *)&v5 = *(float *)(a2 + 328) + *(float *)(a2 + 584);
    *(_QWORD *)(a2 + 320) = v4;
    HIDWORD(v5) = 0;
    *(_QWORD *)(a2 + 328) = v5;
    *(float *)&v4 = *(float *)(a2 + 592) + *(float *)(a2 + 336);
    *((float *)&v4 + 1) = *(float *)(a2 + 596) + *(float *)(a2 + 340);
    *(float *)&v3 = *(float *)(a2 + 600) + *(float *)(a2 + 344);
    *(_QWORD *)(a2 + 336) = v4;
    *(_QWORD *)(a2 + 344) = v3;
    btTransformUtil::integrateTransform(
      (const btTransform *)(a2 + 16),
      (const btVector3 *)(a2 + 640),
      (const btVector3 *)(a2 + 656),
      timeStep,
      &newTransform);
    btCollisionObject::setWorldTransform((btCollisionObject *)a2, &newTransform);
  }
}


void __thiscall btRigidBody::internalWritebackVelocity(btRigidBody *this)
{
  unsigned int v1; // xmm1_4
  btVector3 v2; // [esp+0h] [ebp-10h]

  if ( this->m_inverseMass != 0.0 )
  {
    v2.mVec128.m128_f32[0] = this->m_linearVelocity.mVec128.m128_f32[0]
                           + this->m_deltaLinearVelocity.mVec128.m128_f32[0];
    v2.mVec128.m128_f32[1] = this->m_linearVelocity.mVec128.m128_f32[1]
                           + this->m_deltaLinearVelocity.mVec128.m128_f32[1];
    v2.mVec128.m128_f32[2] = this->m_linearVelocity.mVec128.m128_f32[2]
                           + this->m_deltaLinearVelocity.mVec128.m128_f32[2];
    v2.mVec128.m128_i32[3] = 0;
    this->m_linearVelocity = (btVector3)v2.mVec128;
    v2.mVec128.m128_f32[0] = this->m_angularVelocity.mVec128.m128_f32[0]
                           + this->m_deltaAngularVelocity.mVec128.m128_f32[0];
    v2.mVec128.m128_f32[1] = this->m_deltaAngularVelocity.mVec128.m128_f32[1]
                           + this->m_angularVelocity.mVec128.m128_f32[1];
    *(float *)&v1 = this->m_deltaAngularVelocity.mVec128.m128_f32[2] + this->m_angularVelocity.mVec128.m128_f32[2];
    this->m_angularVelocity.mVec128.m128_u64[0] = v2.mVec128.m128_u64[0];
    this->m_angularVelocity.mVec128.m128_u64[1] = v1;
  }
}
