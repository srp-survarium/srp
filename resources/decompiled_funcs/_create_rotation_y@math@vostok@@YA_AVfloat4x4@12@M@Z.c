vostok::math::float4x4 *__usercall vostok::math::create_rotation_y@<eax>(
        _QWORD *a1@<esi>,
        vostok::math::float4x4 *result)
{
  const vostok::math::float4x4 *v2; // xmm1_4
  __int64 v3; // xmm2_8
  __int64 v4; // xmm0_8
  float a; // [esp+4h] [ebp-18h]
  unsigned int a_4; // [esp+8h] [ebp-14h]
  __int64 v8; // [esp+Ch] [ebp-10h]
  __int64 v9; // [esp+14h] [ebp-8h]

  a = sinf(*(float *)&result);
  *(float *)&a_4 = cosf(*(float *)&result);
  HIDWORD(v9) = 0;
  *(float *)&v9 = a;
  *a1 = a_4;
  LODWORD(v8) = 0;
  a1[1] = v9;
  v2 = clear_value;
  HIDWORD(v8) = clear_value;
  a1[2] = v8;
  a1[3] = 0;
  v9 = a_4;
  a1[4] = COERCE_UNSIGNED_INT(-a);
  v3 = v9;
  LODWORD(v9) = 0;
  a1[6] = 0;
  HIDWORD(v9) = v2;
  v4 = v9;
  a1[5] = v3;
  a1[7] = v4;
  return (vostok::math::float4x4 *)a1;
}
