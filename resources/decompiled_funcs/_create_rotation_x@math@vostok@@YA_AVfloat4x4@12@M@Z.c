vostok::math::float4x4 *__usercall vostok::math::create_rotation_x@<eax>(
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
  v2 = clear_value;
  *((float *)&v8 + 1) = *(float *)&a_4;
  *a1 = (unsigned int)clear_value;
  *(float *)&v9 = -a;
  a1[1] = 0;
  LODWORD(v8) = 0;
  a1[2] = v8;
  a1[3] = (unsigned int)v9;
  *((float *)&v8 + 1) = a;
  LODWORD(v8) = 0;
  v9 = a_4;
  a1[4] = v8;
  v3 = v9;
  LODWORD(v9) = 0;
  a1[6] = 0;
  HIDWORD(v9) = v2;
  v4 = v9;
  a1[5] = v3;
  a1[7] = v4;
  return (vostok::math::float4x4 *)a1;
}
