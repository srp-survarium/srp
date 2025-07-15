btQuaternion *__usercall vostok::physics::from_vostok@<eax>(
        int a1@<ebx>,
        long double a2@<esi:edi>,
        btQuaternion *result)
{
  __m128 x_low; // xmm0
  __m128i v4; // xmm0
  float v5; // xmm1_4
  vostok::math::float3 x; // [esp+0h] [ebp-20h] BYREF
  int v8; // [esp+Ch] [ebp-14h]
  float v9; // [esp+18h] [ebp-8h]

  vostok::math::quaternion::get_axis_and_angle(
    (vostok::math::quaternion *)&x.elements[1],
    result->m_floats,
    a1,
    a2,
    &x,
    (float *)LODWORD(x.x));
  LODWORD(v9) = v8 ^ _mask__NegFloat_;
  x_low = (__m128)LODWORD(x.x);
  x.x = x.x * 0.5;
  x_low.m128_f32[0] = x.x;
  v4 = (__m128i)_mm_cvtps_pd(x_low);
  __libm_sse2_sin(v4);
  *(float *)v4.m128i_i32 = *(double *)v4.m128i_i64;
  *(float *)v4.m128i_i32 = *(float *)v4.m128i_i32
                         / fsqrt((float)((float)(x.y * x.y) + (float)(v9 * v9)) + (float)(x.z * x.z));
  *(float *)HIDWORD(a2) = *(float *)v4.m128i_i32 * x.y;
  v5 = *(float *)v4.m128i_i32 * x.z;
  *(float *)(HIDWORD(a2) + 8) = *(float *)v4.m128i_i32 * v9;
  *(double *)v4.m128i_i64 = x.x;
  *(float *)(HIDWORD(a2) + 4) = v5;
  __libm_sse2_cos(*(long double *)&x.x);
  *(float *)v4.m128i_i32 = *(double *)v4.m128i_i64;
  *(_DWORD *)(HIDWORD(a2) + 12) = v4.m128i_i32[0];
  return (btQuaternion *)HIDWORD(a2);
}


btTransform *__usercall vostok::physics::from_vostok@<eax>(const vostok::math::float4x4 *m@<eax>, btMatrix3x3 *a2)
{
  long double v2; // rdi
  int v4; // [esp+10h] [ebp-30h]
  int v5; // [esp+14h] [ebp-2Ch]
  int v6; // [esp+18h] [ebp-28h]
  vostok::math::quaternion v7; // [esp+20h] [ebp-20h] BYREF
  btQuaternion v8; // [esp+30h] [ebp-10h] BYREF

  v2 = COERCE_DOUBLE(__PAIR64__(&v8, (unsigned int)m));
  vostok::math::quaternion::quaternion(&v7, m);
  vostok::physics::from_vostok((int)a2, v2, (btQuaternion *)&v7);
  v4 = *(_DWORD *)(LODWORD(v2) + 48);
  v5 = *(_DWORD *)(LODWORD(v2) + 52);
  v6 = *(_DWORD *)(LODWORD(v2) + 56) ^ _mask__NegFloat_;
  btMatrix3x3::setRotation(&v8, a2);
  a2[1].m_el[0].mVec128.m128_i32[0] = v4;
  a2[1].m_el[0].mVec128.m128_i32[1] = v5;
  a2[1].m_el[0].mVec128.m128_i32[2] = v6;
  a2[1].m_el[0].mVec128.m128_i32[3] = 0;
  return (btTransform *)a2;
}
