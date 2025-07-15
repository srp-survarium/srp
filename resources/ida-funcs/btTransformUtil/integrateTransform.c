void __usercall btTransformUtil::integrateTransform(
        const btTransform *curTrans@<ecx>,
        const btVector3 *linvel@<eax>,
        const btVector3 *angvel@<edi>,
        float timeStep,
        btTransform *predictedTransform)
{
  float v5; // xmm2_4
  float v7; // xmm3_4
  long double v8; // st7
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  long double v12; // st7
  btMatrix3x3 *v13; // ecx
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // [esp+E8h] [ebp-48h]
  float v19; // [esp+ECh] [ebp-44h]
  float v20; // [esp+ECh] [ebp-44h]
  btMatrix3x3 v21; // [esp+F0h] [ebp-40h] BYREF
  float v22; // [esp+12Ch] [ebp-4h]

  v5 = linvel->mVec128.m128_f32[2] * timeStep;
  v7 = curTrans->m_origin.mVec128.m128_f32[0] + (float)(linvel->mVec128.m128_f32[0] * timeStep);
  v21.m_el[2].mVec128.m128_f32[1] = curTrans->m_origin.mVec128.m128_f32[1]
                                  + (float)(linvel->mVec128.m128_f32[1] * timeStep);
  v21.m_el[2].mVec128.m128_f32[2] = curTrans->m_origin.mVec128.m128_f32[2] + v5;
  v21.m_el[2].mVec128.m128_f32[0] = v7;
  v21.m_el[2].mVec128.m128_i32[3] = 0;
  predictedTransform->m_origin = v21.m_el[2];
  v19 = angvel->mVec128.m128_f32[0];
  v8 = sqrtf(
         (float)((float)(v19 * v19) + (float)(angvel->mVec128.m128_f32[1] * angvel->mVec128.m128_f32[1]))
       + (float)(angvel->mVec128.m128_f32[2] * angvel->mVec128.m128_f32[2]));
  v18 = v8;
  v9 = timeStep;
  if ( v8 * timeStep <= 0.78539819 )
  {
    v10 = v8;
  }
  else
  {
    v10 = 0.78539819 / timeStep;
    v18 = 0.78539819 / timeStep;
  }
  if ( v10 >= 0.001 )
  {
    v12 = sinf((float)(v10 * timeStep) * 0.5) / v18;
    v9 = timeStep;
    v21.m_el[2].mVec128.m128_i32[3] = 0;
    v21.m_el[2].mVec128.m128_f32[0] = v19 * v12;
    v21.m_el[2].mVec128.m128_f32[1] = angvel->mVec128.m128_f32[1] * v12;
    v21.m_el[2].mVec128.m128_f32[2] = v12 * angvel->mVec128.m128_f32[2];
    v21.m_el[1] = (btVector3)_mm_load_si128((const __m128i *)&v21.m_el[2]);
    v10 = v18;
  }
  else
  {
    v11 = (float)(timeStep * 0.5)
        - (float)((float)((float)((float)((float)(timeStep * timeStep) * timeStep) * v10) * v10) * 0.020833334);
    v21.m_el[2].mVec128.m128_f32[0] = v19 * v11;
    v21.m_el[2].mVec128.m128_f32[1] = angvel->mVec128.m128_f32[1] * v11;
    v21.m_el[2].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(angvel->mVec128.m128_f32[2] * v11);
    v21.m_el[1] = (btVector3)_mm_load_si128((const __m128i *)&v21.m_el[2]);
  }
  v22 = cosf((float)(v10 * v9) * 0.5);
  btMatrix3x3::getRotation(v13, (float *)curTrans, (btQuaternion *)&v21.m_el[2]);
  v14 = (float)((float)((float)(v21.m_el[2].mVec128.m128_f32[2] * v21.m_el[1].mVec128.m128_f32[1])
                      + (float)(v21.m_el[2].mVec128.m128_f32[3] * v21.m_el[1].mVec128.m128_f32[0]))
              + (float)(v22 * v21.m_el[2].mVec128.m128_f32[0]))
      - (float)(v21.m_el[2].mVec128.m128_f32[1] * v21.m_el[1].mVec128.m128_f32[2]);
  v15 = (float)((float)((float)(v21.m_el[2].mVec128.m128_f32[1] * v22)
                      + (float)(v21.m_el[2].mVec128.m128_f32[3] * v21.m_el[1].mVec128.m128_f32[1]))
              + (float)(v21.m_el[1].mVec128.m128_f32[2] * v21.m_el[2].mVec128.m128_f32[0]))
      - (float)(v21.m_el[2].mVec128.m128_f32[2] * v21.m_el[1].mVec128.m128_f32[0]);
  v16 = (float)((float)((float)(v21.m_el[2].mVec128.m128_f32[3] * v22)
                      - (float)(v21.m_el[1].mVec128.m128_f32[0] * v21.m_el[2].mVec128.m128_f32[0]))
              - (float)(v21.m_el[2].mVec128.m128_f32[1] * v21.m_el[1].mVec128.m128_f32[1]))
      - (float)(v21.m_el[2].mVec128.m128_f32[2] * v21.m_el[1].mVec128.m128_f32[2]);
  v17 = (float)((float)((float)(v21.m_el[2].mVec128.m128_f32[2] * v22)
                      + (float)(v21.m_el[2].mVec128.m128_f32[1] * v21.m_el[1].mVec128.m128_f32[0]))
              + (float)(v21.m_el[2].mVec128.m128_f32[3] * v21.m_el[1].mVec128.m128_f32[2]))
      - (float)(v21.m_el[1].mVec128.m128_f32[1] * v21.m_el[2].mVec128.m128_f32[0]);
  v21.m_el[0].mVec128.m128_f32[3] = v16;
  v21.m_el[0].mVec128.m128_f32[2] = v17;
  v21.m_el[0].mVec128.m128_f32[1] = v15;
  v21.m_el[0].mVec128.m128_f32[0] = v14;
  v20 = 1.0 / sqrtf((float)((float)((float)(v16 * v16) + (float)(v17 * v17)) + (float)(v15 * v15)) + (float)(v14 * v14));
  v21.m_el[0].mVec128.m128_f32[0] = v14 * v20;
  v21.m_el[0].mVec128.m128_f32[1] = v15 * v20;
  v21.m_el[0].mVec128.m128_f32[2] = v17 * v20;
  v21.m_el[0].mVec128.m128_f32[3] = v16 * v20;
  btMatrix3x3::setRotation(&v21, (int)predictedTransform);
}
