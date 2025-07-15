void __usercall applyAnisotropicFriction(btCollisionObject *colObj@<eax>, btVector3 *frictionDirection@<ecx>)
{
  float v2; // xmm3_4
  float v3; // xmm4_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  unsigned int v9; // xmm2_4
  float v10; // [esp+14h] [ebp-Ch]

  if ( colObj )
  {
    if ( colObj->m_hasAnisotropicFriction )
    {
      v2 = frictionDirection->mVec128.m128_f32[2];
      v3 = frictionDirection->mVec128.m128_f32[1];
      v4 = (float)((float)(colObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]
                         * frictionDirection->mVec128.m128_f32[0])
                 + (float)(colObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v3))
         + (float)(colObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v2);
      v5 = (float)((float)(colObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]
                         * frictionDirection->mVec128.m128_f32[0])
                 + (float)(colObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v3))
         + (float)(colObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v2);
      v6 = colObj->m_anisotropicFriction.mVec128.m128_f32[0]
         * (float)((float)((float)(colObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v3)
                         + (float)(colObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v2))
                 + (float)(colObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0]
                         * frictionDirection->mVec128.m128_f32[0]));
      v7 = colObj->m_anisotropicFriction.mVec128.m128_f32[1] * v4;
      v8 = colObj->m_anisotropicFriction.mVec128.m128_f32[2] * v5;
      v10 = (float)((float)(colObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v8)
                  + (float)(colObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v7))
          + (float)(colObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v6);
      *(float *)&v9 = (float)((float)(colObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v8)
                            + (float)(colObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v7))
                    + (float)(colObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v6);
      frictionDirection->mVec128.m128_f32[0] = (float)((float)(colObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]
                                                             * v8)
                                                     + (float)(colObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]
                                                             * v7))
                                             + (float)(colObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v6);
      frictionDirection->mVec128.m128_f32[1] = v10;
      frictionDirection->mVec128.m128_u64[1] = v9;
    }
  }
}
