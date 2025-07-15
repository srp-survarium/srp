vostok::math::float4x4 *__usercall vostok::math::create_rotation_z@<eax>(int a1@<esi>, vostok::math::float4x4 *result)
{
  long double v2; // st7
  vostok::math::float4x4 *v3; // eax
  __int64 v4; // xmm1_8
  __int64 v5; // xmm2_8
  __int64 v6; // xmm0_8
  float a; // [esp+4h] [ebp-18h]
  __int64 v8; // [esp+Ch] [ebp-10h]
  __int64 v9; // [esp+14h] [ebp-8h]

  a = sinf(*(float *)&result);
  v2 = cosf(*(float *)&result);
  *(float *)&v8 = v2;
  v9 = 0;
  v3 = (vostok::math::float4x4 *)a1;
  *((float *)&v8 + 1) = -a;
  *(_QWORD *)a1 = v8;
  *(float *)&v8 = a;
  *(_QWORD *)(a1 + 8) = v9;
  *((float *)&v8 + 1) = v2;
  v9 = 0;
  *(_QWORD *)(a1 + 16) = v8;
  v4 = v9;
  HIDWORD(v9) = 0;
  *(_QWORD *)(a1 + 24) = v4;
  LODWORD(v4) = clear_value;
  LODWORD(v9) = clear_value;
  *(_QWORD *)(a1 + 32) = 0;
  v5 = v9;
  LODWORD(v9) = 0;
  *(_QWORD *)(a1 + 48) = 0;
  HIDWORD(v9) = v4;
  v6 = v9;
  *(_QWORD *)(a1 + 40) = v5;
  *(_QWORD *)(a1 + 56) = v6;
  return v3;
}
