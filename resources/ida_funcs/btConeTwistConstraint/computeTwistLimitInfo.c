void __userpurge btConeTwistConstraint::computeTwistLimitInfo(
        const btQuaternion *qTwist@<esi>,
        btVector3 *vTwistAxis@<edi>,
        btConeTwistConstraint *this,
        float *twistAngle)
{
  float v4; // xmm0_4
  long double v5; // st7
  long double v6; // st7
  float v7; // xmm0_4
  int v8; // xmm1_4
  long double v9; // st7
  const vostok::math::float4x4 *_X; // [esp+2Ch] [ebp-30h]
  float v11; // [esp+2Ch] [ebp-30h]
  float v12; // [esp+2Ch] [ebp-30h]
  unsigned __int64 v13; // [esp+30h] [ebp-2Ch]
  float v14; // [esp+38h] [ebp-24h]
  btQuaternion v15; // [esp+3Ch] [ebp-20h]
  __int64 v16; // [esp+4Ch] [ebp-10h]

  v15 = *qTwist;
  v4 = qTwist->m_floats[3];
  _X = (const vostok::math::float4x4 *)LODWORD(v4);
  if ( v4 >= -1.0 )
  {
    if ( v4 > *(float *)&clear_value )
      _X = clear_value;
    v5 = acosf(*(float *)&_X);
  }
  else
  {
    v5 = acosf(-1.0);
  }
  v6 = v5 + v5;
  *(float *)&this->__vftable = v6;
  if ( v6 > 3.1415927 )
  {
    *(float *)&v16 = -qTwist->m_floats[0];
    *((float *)&v16 + 1) = -qTwist->m_floats[1];
    v7 = -qTwist->m_floats[3];
    *(_QWORD *)v15.m_floats = v16;
    v15.m_floats[2] = -qTwist->m_floats[2];
    v8 = -1082130432;
    v11 = v7;
    if ( v7 < -1.0 || (v8 = (int)clear_value, v7 > *(float *)&clear_value) )
      v11 = *(float *)&v8;
    v9 = acosf(v11);
    *(float *)&this->__vftable = v9 + v9;
  }
  vTwistAxis->mVec128.m128_u64[0] = *(_QWORD *)v15.m_floats;
  vTwistAxis->mVec128.m128_u64[1] = LODWORD(v15.m_floats[2]);
  if ( *(float *)&this->__vftable > 0.00000011920929 )
  {
    v13 = vTwistAxis->mVec128.m128_u64[0];
    v14 = vTwistAxis->mVec128.m128_f32[2];
    v12 = 1.0
        / sqrtf(
            (float)((float)(*(float *)&v13 * *(float *)&v13) + (float)(*((float *)&v13 + 1) * *((float *)&v13 + 1)))
          + (float)(v14 * v14));
    vTwistAxis->mVec128.m128_f32[0] = *(float *)&v13 * v12;
    vTwistAxis->mVec128.m128_f32[1] = *((float *)&v13 + 1) * v12;
    vTwistAxis->mVec128.m128_f32[2] = v14 * v12;
  }
}
