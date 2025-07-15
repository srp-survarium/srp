btVector3 *__userpurge btConeTwistConstraint::GetPointForAngle@<eax>(
        btConeTwistConstraint *this@<ecx>,
        int a2@<eax>,
        btVector3 *result,
        float fAngleInRadians,
        float fLength)
{
  int v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  unsigned int v11; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm7_4
  float v15; // [esp+100h] [ebp-3Ch]
  float v16; // [esp+104h] [ebp-38h]
  float angle; // [esp+108h] [ebp-34h] BYREF
  btQuaternion v18; // [esp+10Ch] [ebp-30h] BYREF
  btVector3 axis; // [esp+11Ch] [ebp-20h] BYREF
  float v20; // [esp+134h] [ebp-8h]

  v15 = cosf(fAngleInRadians);
  v16 = sinf(fAngleInRadians);
  v6 = LODWORD(v15);
  angle = *(float *)(a2 + 480);
  v7 = v16;
  if ( fabs(v15) > 0.00000011920929 )
  {
    angle = sqrtf(
              (float)((float)((float)(v16 * v16) / (float)(v15 * v15)) + *(float *)&clear_value)
            / (float)((float)(*(float *)&clear_value / (float)(*(float *)(a2 + 484) * *(float *)(a2 + 484)))
                    + (float)((float)((float)(v16 * v16) / (float)(v15 * v15))
                            / (float)(*(float *)(a2 + 480) * *(float *)(a2 + 480)))));
    v7 = v16;
    v6 = LODWORD(v15);
  }
  axis.mVec128.m128_i32[0] = 0;
  axis.mVec128.m128_i32[1] = v6;
  axis.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(-v7);
  btQuaternion::setRotation(&v18, &axis, &angle);
  v8 = (float)((float)(v18.m_floats[3] * fLength) + (float)(v18.m_floats[1] * 0.0)) - (float)(v18.m_floats[2] * 0.0);
  v9 = (float)((float)(v18.m_floats[2] * fLength) + (float)(v18.m_floats[3] * 0.0)) - (float)(v18.m_floats[0] * 0.0);
  v20 = (float)((float)(v18.m_floats[0] * 0.0) + (float)(v18.m_floats[3] * 0.0)) - (float)(v18.m_floats[1] * fLength);
  v10 = (float)((float)-(float)(v18.m_floats[0] * fLength) - (float)(v18.m_floats[1] * 0.0))
      - (float)(v18.m_floats[2] * 0.0);
  *(float *)&v11 = (float)((float)((float)((float)-v18.m_floats[2] * v10) + (float)((float)-v18.m_floats[1] * v8))
                         + (float)(v18.m_floats[3] * v20))
                 - (float)((float)-v18.m_floats[0] * v9);
  v12 = (float)((float)((float)-v18.m_floats[1] * v10) + (float)((float)-v18.m_floats[0] * v20))
      + (float)(v18.m_floats[3] * v9);
  v13 = (float)-v18.m_floats[2] * v8;
  result->mVec128.m128_f32[0] = (float)((float)((float)(v10 * (float)-v18.m_floats[0]) + (float)(v18.m_floats[3] * v8))
                                      + (float)((float)-v18.m_floats[2] * v9))
                              - (float)((float)-v18.m_floats[1] * v20);
  result->mVec128.m128_f32[1] = v12 - v13;
  result->mVec128.m128_u64[1] = v11;
  return result;
}
