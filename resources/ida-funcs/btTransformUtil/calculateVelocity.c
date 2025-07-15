void __usercall btTransformUtil::calculateVelocity(
        const btTransform *transform0@<eax>,
        const btTransform *transform1@<ecx>,
        float timeStep,
        btVector3 *linVel,
        btVector3 *angVel)
{
  float v5; // xmm2_4
  float v6; // xmm3_4
  float angle; // [esp+0h] [ebp-18h] BYREF
  float v8; // [esp+4h] [ebp-14h]
  btVector3 axis; // [esp+8h] [ebp-10h] BYREF

  v5 = transform1->m_origin.mVec128.m128_f32[1] - transform0->m_origin.mVec128.m128_f32[1];
  v6 = transform1->m_origin.mVec128.m128_f32[2] - transform0->m_origin.mVec128.m128_f32[2];
  axis.mVec128.m128_f32[0] = (float)(transform1->m_origin.mVec128.m128_f32[0] - transform0->m_origin.mVec128.m128_f32[0])
                           * (float)(s_bm_current_air_resistance / timeStep);
  axis.mVec128.m128_f32[1] = (float)(s_bm_current_air_resistance / timeStep) * v5;
  axis.mVec128.m128_i32[3] = 0;
  v8 = s_bm_current_air_resistance / timeStep;
  axis.mVec128.m128_f32[2] = (float)(s_bm_current_air_resistance / timeStep) * v6;
  *linVel = (btVector3)axis.mVec128;
  btTransformUtil::calculateDiffAxisAngle(transform0, transform1, &axis, &angle);
  axis.mVec128.m128_f32[0] = (float)(axis.mVec128.m128_f32[0] * angle) * v8;
  axis.mVec128.m128_i32[3] = 0;
  axis.mVec128.m128_f32[1] = (float)(axis.mVec128.m128_f32[1] * angle) * v8;
  axis.mVec128.m128_f32[2] = (float)(axis.mVec128.m128_f32[2] * angle) * v8;
  *angVel = (btVector3)axis.mVec128;
}
