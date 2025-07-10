void __usercall btQuaternion::setRotation(
        btQuaternion *this@<edi>,
        const btVector3 *axis@<esi>,
        const float *angle@<eax>)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // [esp+4h] [ebp-14h]
  __int64 v6; // [esp+8h] [ebp-10h]
  float s; // [esp+10h] [ebp-8h]
  float sa; // [esp+10h] [ebp-8h]
  float _X; // [esp+14h] [ebp-4h]

  v6 = *(__int64 *)((char *)axis->mVec128.m128_i64 + 4);
  _X = *angle * 0.5;
  v5 = axis->mVec128.m128_f32[0];
  s = sinf(_X);
  sa = s
     / sqrtf(
         (float)((float)(v5 * v5) + (float)(*(float *)&v6 * *(float *)&v6))
       + (float)(*((float *)&v6 + 1) * *((float *)&v6 + 1)));
  v3 = sa * axis->mVec128.m128_f32[2];
  v4 = sa * axis->mVec128.m128_f32[1];
  this->m_floats[0] = v5 * sa;
  this->m_floats[1] = v4;
  this->m_floats[2] = v3;
  this->m_floats[3] = cosf(_X);
}
