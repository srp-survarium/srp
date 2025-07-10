void __usercall applyAnisotropicFriction(btCollisionObject *colObj@<eax>, btVector3 *frictionDirection@<ecx>)
{
  float v2; // xmm3_4
  float v3; // xmm4_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm5_4
  float v7; // xmm4_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  unsigned __int64 v12; // [esp+0h] [ebp-10h]
  unsigned __int64 v13; // [esp+8h] [ebp-8h]

  if ( colObj )
  {
    if ( colObj->m_hasAnisotropicFriction )
    {
      v2 = frictionDirection->mVec128.m128_f32[2];
      v3 = frictionDirection->mVec128.m128_f32[1];
      v4 = (float)((float)(colObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v3)
                 + (float)(colObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v2))
         + (float)(colObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * frictionDirection->mVec128.m128_f32[0]);
      v5 = (float)((float)(colObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]
                         * frictionDirection->mVec128.m128_f32[0])
                 + (float)(colObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v3))
         + (float)(colObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v2);
      v6 = colObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v3;
      v7 = colObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v2;
      v8 = colObj->m_anisotropicFriction.mVec128.m128_f32[0] * v4;
      v9 = colObj->m_anisotropicFriction.mVec128.m128_f32[1] * v5;
      v10 = colObj->m_anisotropicFriction.mVec128.m128_f32[2]
          * (float)((float)((float)(colObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]
                                  * frictionDirection->mVec128.m128_f32[0])
                          + v6)
                  + v7);
      *(float *)&v12 = (float)((float)(colObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v10)
                             + (float)(colObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v9))
                     + (float)(colObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v8);
      *((float *)&v12 + 1) = (float)((float)(colObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v10)
                                   + (float)(colObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v9))
                           + (float)(colObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v8);
      v11 = (float)((float)(colObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v10)
                  + (float)(colObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v9))
          + (float)(colObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v8);
      HIDWORD(v13) = 0;
      frictionDirection->mVec128.m128_u64[0] = v12;
      *(float *)&v13 = v11;
      frictionDirection->mVec128.m128_u64[1] = v13;
    }
  }
}
