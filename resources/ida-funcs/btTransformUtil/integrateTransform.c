void __usercall btTransformUtil::integrateTransform(
        const btVector3 *linvel@<eax>,
        long double a2@<esi:edi>,
        const btTransform *curTrans,
        const btVector3 *angvel,
        float timeStep,
        btTransform *predictedTransform)
{
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  __m128 v11; // xmm4
  __m128 v12; // xmm0
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  float v21; // [esp+Ch] [ebp-38h]
  float v22; // [esp+10h] [ebp-34h]
  float v23; // [esp+14h] [ebp-30h]
  float v24; // [esp+18h] [ebp-2Ch]
  float v25; // [esp+1Ch] [ebp-28h]
  btQuaternion q; // [esp+24h] [ebp-20h] BYREF
  btQuaternion v27; // [esp+34h] [ebp-10h] BYREF

  v6 = linvel->mVec128.m128_f32[2];
  v7 = timeStep;
  v8 = curTrans->m_origin.mVec128.m128_f32[0] + (float)(linvel->mVec128.m128_f32[0] * timeStep);
  q.m_floats[1] = curTrans->m_origin.mVec128.m128_f32[1] + (float)(linvel->mVec128.m128_f32[1] * timeStep);
  v9 = curTrans->m_origin.mVec128.m128_f32[2];
  q.m_floats[0] = v8;
  q.m_floats[2] = v9 + (float)(v6 * timeStep);
  q.m_floats[3] = 0.0;
  predictedTransform->m_origin.mVec128.m128_f32[0] = v8;
  *(unsigned __int64 *)((char *)predictedTransform->m_origin.mVec128.m128_u64 + 4) = *(_QWORD *)&q.m_floats[1];
  predictedTransform->m_origin.mVec128.m128_i32[3] = LODWORD(q.m_floats[3]);
  v10 = angvel->mVec128.m128_f32[0];
  v12 = (__m128)angvel->mVec128.m128_u32[2];
  v11 = (__m128)LODWORD(pi_d4);
  v12.m128_f32[0] = fsqrt(
                      (float)((float)(v10 * v10) + (float)(angvel->mVec128.m128_f32[1] * angvel->mVec128.m128_f32[1]))
                    + (float)(v12.m128_f32[0] * v12.m128_f32[0]));
  v22 = angvel->mVec128.m128_f32[0];
  v21 = v12.m128_f32[0];
  if ( (float)(v12.m128_f32[0] * timeStep) > 0.78539819 )
  {
    v11.m128_f32[0] = 0.78539819 / timeStep;
    v12 = v11;
    v21 = 0.78539819 / timeStep;
  }
  if ( v12.m128_f32[0] >= 0.001 )
  {
    v12.m128_f32[0] = (float)(v12.m128_f32[0] * timeStep) * 0.5;
    v12 = (__m128)_mm_cvtps_pd(v12);
    __libm_sse2_sin((__m128i)v12);
    v7 = timeStep;
    v14 = *(double *)v12.m128_u64;
    v12.m128_f32[0] = v21;
    v15 = v14 / v21;
    q.m_floats[0] = v22 * v15;
    q.m_floats[1] = angvel->mVec128.m128_f32[1] * v15;
    q.m_floats[2] = angvel->mVec128.m128_f32[2] * v15;
  }
  else
  {
    v13 = (float)(timeStep * 0.5)
        - (float)((float)((float)((float)((float)(timeStep * timeStep) * timeStep) * v12.m128_f32[0]) * v12.m128_f32[0])
                * 0.020833334);
    q.m_floats[0] = v10 * v13;
    q.m_floats[1] = angvel->mVec128.m128_f32[1] * v13;
    q.m_floats[2] = angvel->mVec128.m128_f32[2] * v13;
  }
  q.m_floats[3] = 0.0;
  v23 = q.m_floats[0];
  v24 = q.m_floats[1];
  v25 = q.m_floats[2];
  __libm_sse2_cos(a2);
  v27.m_floats[3] = (float)(v12.m128_f32[0] * v7) * 0.5;
  btMatrix3x3::getRotation(&curTrans->m_basis, &q);
  v16 = (float)((float)((float)(q.m_floats[2] * v24) + (float)(q.m_floats[3] * v23))
              + (float)(v27.m_floats[3] * q.m_floats[0]))
      - (float)(q.m_floats[1] * v25);
  v17 = (float)((float)((float)(q.m_floats[1] * v27.m_floats[3]) + (float)(q.m_floats[3] * v24))
              + (float)(v25 * q.m_floats[0]))
      - (float)(q.m_floats[2] * v23);
  v18 = (float)((float)((float)(q.m_floats[3] * v27.m_floats[3]) - (float)(v23 * q.m_floats[0]))
              - (float)(q.m_floats[1] * v24))
      - (float)(q.m_floats[2] * v25);
  v19 = (float)((float)((float)(q.m_floats[2] * v27.m_floats[3]) + (float)(q.m_floats[3] * v25))
              + (float)(q.m_floats[1] * v23))
      - (float)(v24 * q.m_floats[0]);
  v20 = s_bm_current_air_resistance
      / fsqrt((float)((float)((float)(v18 * v18) + (float)(v19 * v19)) + (float)(v17 * v17)) + (float)(v16 * v16));
  v27.m_floats[0] = v16 * v20;
  v27.m_floats[1] = v17 * v20;
  v27.m_floats[2] = v19 * v20;
  v27.m_floats[3] = v18 * v20;
  btMatrix3x3::setRotation(&v27, &predictedTransform->m_basis);
}
