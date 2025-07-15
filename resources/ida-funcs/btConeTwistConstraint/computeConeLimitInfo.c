void __userpurge btConeTwistConstraint::computeConeLimitInfo(
        const btQuaternion *qCone@<edi>,
        btVector3 *vSwingAxis@<eax>,
        btConeTwistConstraint *this,
        float *swingAngle,
        float *swingLimit)
{
  float v5; // xmm0_4
  long double v7; // st7
  long double v8; // st7
  long double v9; // st7
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  const vostok::math::float4x4 *_X; // [esp+Ch] [ebp-18h]
  float v15; // [esp+Ch] [ebp-18h]
  float v16; // [esp+10h] [ebp-14h]
  unsigned __int64 v17; // [esp+1Ch] [ebp-8h]

  v5 = qCone->m_floats[3];
  _X = (const vostok::math::float4x4 *)LODWORD(v5);
  if ( v5 >= -1.0 )
  {
    if ( v5 > *(float *)&clear_value )
      _X = clear_value;
    v7 = acosf(*(float *)&_X);
  }
  else
  {
    v7 = acosf(-1.0);
  }
  v8 = v7 + v7;
  *swingAngle = v8;
  if ( v8 > 0.00000011920929 )
  {
    v17 = LODWORD(qCone->m_floats[2]);
    vSwingAxis->mVec128.m128_u64[0] = *(_QWORD *)qCone->m_floats;
    vSwingAxis->mVec128.m128_u64[1] = v17;
    v16 = vSwingAxis->mVec128.m128_f32[0];
    v9 = sqrtf(
           (float)((float)(v16 * v16) + (float)(vSwingAxis->mVec128.m128_f32[1] * vSwingAxis->mVec128.m128_f32[1]))
         + (float)(vSwingAxis->mVec128.m128_f32[2] * vSwingAxis->mVec128.m128_f32[2]));
    v10 = vSwingAxis->mVec128.m128_f32[1];
    v15 = 1.0 / v9;
    vSwingAxis->mVec128.m128_f32[0] = v16 * v15;
    v11 = vSwingAxis->mVec128.m128_f32[2] * v15;
    v12 = v10 * v15;
    vSwingAxis->mVec128.m128_f32[1] = v12;
    vSwingAxis->mVec128.m128_f32[2] = v11;
    v13 = -v11;
    *swingLimit = this->m_swingSpan1;
    if ( COERCE_FLOAT(LODWORD(v12) & _mask__AbsFloat_) > 0.00000011920929 )
      *swingLimit = sqrtf(
                      (float)((float)((float)(v13 * v13) / (float)(v12 * v12)) + *(float *)&clear_value)
                    / (float)((float)(*(float *)&clear_value / (float)(this->m_swingSpan2 * this->m_swingSpan2))
                            + (float)((float)((float)(v13 * v13) / (float)(v12 * v12))
                                    / (float)(this->m_swingSpan1 * this->m_swingSpan1))));
  }
}
