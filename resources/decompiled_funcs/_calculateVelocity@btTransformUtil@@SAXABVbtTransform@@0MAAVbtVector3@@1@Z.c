void __usercall btTransformUtil::calculateVelocity(
        const btTransform *transform1@<eax>,
        btVector3 *linVel@<edx>,
        btVector3 *angVel@<esi>,
        const btTransform *transform0,
        float timeStep)
{
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // [esp+2Ch] [ebp-18h] BYREF
  float v10; // [esp+30h] [ebp-14h]
  btVector3 v11; // [esp+34h] [ebp-10h] BYREF

  v5 = *(float *)&clear_value / timeStep;
  v6 = transform1->m_origin.mVec128.m128_f32[1] - transform0->m_origin.mVec128.m128_f32[1];
  v7 = transform1->m_origin.mVec128.m128_f32[2] - transform0->m_origin.mVec128.m128_f32[2];
  v11.mVec128.m128_f32[0] = (float)(transform1->m_origin.mVec128.m128_f32[0] - transform0->m_origin.mVec128.m128_f32[0])
                          * (float)(*(float *)&clear_value / timeStep);
  v11.mVec128.m128_f32[1] = (float)(*(float *)&clear_value / timeStep) * v6;
  v11.mVec128.m128_i32[3] = 0;
  v10 = *(float *)&clear_value / timeStep;
  linVel->mVec128.m128_u64[0] = v11.mVec128.m128_u64[0];
  v11.mVec128.m128_f32[2] = v5 * v7;
  linVel->mVec128.m128_u64[1] = v11.mVec128.m128_u64[1];
  btTransformUtil::calculateDiffAxisAngle(transform0, transform1, &v11, &v9);
  v11.mVec128.m128_f32[0] = (float)(v11.mVec128.m128_f32[0] * v9) * v10;
  v11.mVec128.m128_i32[3] = 0;
  v11.mVec128.m128_f32[1] = (float)(v11.mVec128.m128_f32[1] * v9) * v10;
  v8 = (float)(v11.mVec128.m128_f32[2] * v9) * v10;
  angVel->mVec128.m128_u64[0] = v11.mVec128.m128_u64[0];
  v11.mVec128.m128_f32[2] = v8;
  angVel->mVec128.m128_u64[1] = v11.mVec128.m128_u64[1];
}
