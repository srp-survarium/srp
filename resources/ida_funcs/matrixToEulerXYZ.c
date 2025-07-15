char __usercall matrixToEulerXYZ@<al>(const btMatrix3x3 *mat@<esi>, btVector3 *xyz@<edi>)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  int v4; // xmm1_4
  char result; // al
  int v6; // xmm0_4
  long double v7; // st7
  float _X; // [esp+8h] [ebp-4h]

  v2 = mat->m_el[2].mVec128.m128_f32[0];
  if ( *(float *)&clear_value <= v2 )
  {
    v7 = atan2f(mat->m_el[0].mVec128.m128_f32[1], mat->m_el[1].mVec128.m128_f32[1]);
    v6 = LODWORD(pi_d2_8);
    goto LABEL_9;
  }
  if ( v2 <= -1.0 )
  {
    v6 = -1077342245;
    v7 = -atan2f(mat->m_el[0].mVec128.m128_f32[1], mat->m_el[1].mVec128.m128_f32[1]);
LABEL_9:
    xyz->mVec128.m128_i32[1] = v6;
    xyz->mVec128.m128_f32[0] = v7;
    result = 0;
    xyz->mVec128.m128_i32[2] = 0;
    return result;
  }
  xyz->mVec128.m128_f32[0] = atan2f(-mat->m_el[2].mVec128.m128_f32[1], mat->m_el[2].mVec128.m128_f32[2]);
  v3 = mat->m_el[2].mVec128.m128_f32[0];
  v4 = -1082130432;
  _X = v3;
  if ( v3 < -1.0 || (v4 = (int)clear_value, v3 > *(float *)&clear_value) )
    _X = *(float *)&v4;
  xyz->mVec128.m128_f32[1] = asinf(_X);
  xyz->mVec128.m128_f32[2] = atan2f(-mat->m_el[1].mVec128.m128_f32[0], mat->m_el[0].mVec128.m128_f32[0]);
  return 1;
}
