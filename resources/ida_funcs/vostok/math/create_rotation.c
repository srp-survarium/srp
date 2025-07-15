vostok::math::float4x4 *__usercall vostok::math::create_rotation@<eax>(
        const vostok::math::float3 *direction@<eax>,
        const vostok::math::float3 *normal@<edi>,
        _QWORD *a3@<esi>)
{
  float z; // xmm4_4
  float y; // xmm6_4
  float v5; // xmm0_4
  float v6; // xmm2_4
  double v7; // st7
  float v8; // xmm5_4
  float v9; // xmm3_4
  float v11; // [esp+8h] [ebp-28h]
  float x; // [esp+Ch] [ebp-24h]
  float v13; // [esp+14h] [ebp-1Ch]
  __int128 v14; // [esp+1Ch] [ebp-14h]

  z = direction->z;
  y = direction->y;
  v5 = (float)(normal->y * z) - (float)(normal->z * y);
  x = normal->x;
  v6 = (float)(normal->x * y) - (float)(direction->x * normal->y);
  v13 = (float)(direction->x * normal->z) - (float)(normal->x * z);
  v7 = sqrtf((float)((float)(v6 * v6) + (float)(v5 * v5)) + (float)(v13 * v13));
  v8 = normal->z;
  v11 = 1.0 / v7;
  *(float *)&v14 = v11 * v5;
  *((float *)&v14 + 1) = v11 * v13;
  *a3 = v14;
  a3[1] = COERCE_UNSIGNED_INT(v6 * v11);
  *(_QWORD *)((char *)&v14 + 4) = *(_QWORD *)&normal->elements[1];
  *(float *)&v14 = x;
  a3[2] = v14;
  a3[3] = DWORD2(v14);
  v9 = normal->y;
  *(float *)&v14 = (float)(v8 * (float)(v11 * v13)) - (float)(v9 * (float)(v6 * v11));
  *((float *)&v14 + 1) = (float)(x * (float)(v6 * v11)) - (float)(v8 * (float)(v11 * v5));
  a3[4] = v14;
  a3[5] = COERCE_UNSIGNED_INT((float)(v9 * (float)(v11 * v5)) - (float)(x * (float)(v11 * v13)));
  HIDWORD(v14) = clear_value;
  a3[6] = 0;
  DWORD2(v14) = 0;
  a3[7] = *((_QWORD *)&v14 + 1);
  return (vostok::math::float4x4 *)a3;
}


vostok::math::float4x4 *__cdecl vostok::math::create_rotation(
        vostok::math::float4x4 *result,
        const vostok::math::float3 *angles)
{
  long double v2; // st7
  vostok::math::float4x4 *v3; // eax
  float xsXzc; // [esp+8h] [ebp-2Ch]
  float xsXzca; // [esp+8h] [ebp-2Ch]
  float xsXzcb; // [esp+8h] [ebp-2Ch]
  float z; // [esp+Ch] [ebp-28h]
  float z_4; // [esp+10h] [ebp-24h]
  float x; // [esp+14h] [ebp-20h]
  float x_4; // [esp+18h] [ebp-1Ch]
  unsigned int y; // [esp+1Ch] [ebp-18h]
  float y_4; // [esp+20h] [ebp-14h]
  __int64 v13; // [esp+24h] [ebp-10h]
  __int64 v14; // [esp+2Ch] [ebp-8h]

  xsXzc = angles->x;
  x = sinf(xsXzc);
  x_4 = cosf(xsXzc);
  xsXzca = angles->y;
  *(float *)&y = sinf(xsXzca);
  y_4 = cosf(xsXzca);
  xsXzcb = angles->z;
  z = sinf(xsXzcb);
  v2 = cosf(xsXzcb);
  v3 = result;
  z_4 = v2;
  *(float *)&v13 = v2 * y_4;
  *((float *)&v13 + 1) = -(y_4 * z);
  *(_QWORD *)&result->i.x = v13;
  *(_QWORD *)&result->lines[0].elements[2] = y;
  *(float *)&v13 = (float)(z * x_4) + (float)(*(float *)&y * (float)(z_4 * x));
  *((float *)&v13 + 1) = (float)(z_4 * x_4) - (float)((float)(*(float *)&y * z) * x);
  *(_QWORD *)&result->lines[1].x = v13;
  *(_QWORD *)&result->lines[1].elements[2] = COERCE_UNSIGNED_INT(-(float)(y_4 * x));
  *((float *)&v13 + 1) = (float)((float)(*(float *)&y * z) * x_4) + (float)(z_4 * x);
  *(float *)&v13 = (float)(z * x) - (float)((float)(*(float *)&y * z_4) * x_4);
  *(_QWORD *)&result->lines[2].x = v13;
  *(_QWORD *)&result->lines[2].elements[2] = COERCE_UNSIGNED_INT(x_4 * y_4);
  HIDWORD(v14) = clear_value;
  *(_QWORD *)&result->lines[3].x = 0;
  LODWORD(v14) = 0;
  *(_QWORD *)&result->lines[3].elements[2] = v14;
  return v3;
}


vostok::math::float4x4 *__usercall vostok::math::create_rotation@<eax>(
        const vostok::math::float3 *axis@<edi>,
        int a2@<esi>,
        float angle)
{
  float y; // xmm3_4
  float z; // xmm5_4
  const vostok::math::float4x4 *v5; // xmm7_4
  float v6; // xmm1_4
  float v7; // xmm4_4
  float v8; // xmm6_4
  float v9; // xmm5_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float sqr_y; // [esp+Ch] [ebp-10h]
  float sqr_z; // [esp+10h] [ebp-Ch]
  float temp; // [esp+14h] [ebp-8h]
  float temp_4; // [esp+18h] [ebp-4h]

  temp = sinf(angle);
  temp_4 = cosf(angle);
  y = axis->y;
  z = axis->z;
  v5 = clear_value;
  sqr_y = y * y;
  sqr_z = z * z;
  v6 = (float)(z * axis->x) * (float)(*(float *)&clear_value - temp_4);
  v7 = (float)(y * axis->x) * (float)(*(float *)&clear_value - temp_4);
  v8 = (float)(z * y) * (float)(*(float *)&clear_value - temp_4);
  v9 = z * temp;
  v10 = y * temp;
  v11 = axis->x * temp;
  *(float *)a2 = (float)((float)(*(float *)&clear_value - (float)(axis->x * axis->x)) * temp_4)
               + (float)(axis->x * axis->x);
  *(float *)(a2 + 4) = v7 - v9;
  *(float *)(a2 + 8) = v10 + v6;
  *(_DWORD *)(a2 + 12) = 0;
  *(float *)(a2 + 16) = v9 + v7;
  *(_DWORD *)(a2 + 28) = 0;
  *(float *)(a2 + 20) = (float)((float)(*(float *)&v5 - sqr_y) * temp_4) + sqr_y;
  *(float *)(a2 + 24) = v8 - v11;
  *(float *)(a2 + 32) = v6 - v10;
  *(float *)(a2 + 36) = v11 + v8;
  *(_DWORD *)(a2 + 44) = 0;
  *(float *)(a2 + 40) = (float)((float)(*(float *)&v5 - sqr_z) * temp_4) + sqr_z;
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 56) = 0;
  *(float *)(a2 + 60) = *(float *)&v5;
  return (vostok::math::float4x4 *)a2;
}


vostok::math::float4x4 *__usercall vostok::math::create_rotation@<eax>(
        const vostok::math::float3 *angles@<edi>,
        _QWORD *a2@<esi>)
{
  long double v2; // st7
  __int64 v3; // xmm7_8
  float _X; // [esp+8h] [ebp-30h]
  float v6; // [esp+8h] [ebp-30h]
  float v7; // [esp+8h] [ebp-30h]
  float z; // [esp+Ch] [ebp-2Ch]
  float z_4; // [esp+10h] [ebp-28h]
  unsigned int x; // [esp+14h] [ebp-24h]
  float x_4; // [esp+18h] [ebp-20h]
  float y; // [esp+1Ch] [ebp-1Ch]
  float y_4; // [esp+20h] [ebp-18h]
  __int64 v14; // [esp+24h] [ebp-14h]
  __int64 v15; // [esp+2Ch] [ebp-Ch]

  _X = angles->x;
  *(float *)&x = sinf(_X);
  x_4 = cosf(_X);
  v6 = angles->y;
  y = sinf(v6);
  y_4 = cosf(v6);
  v7 = angles->z;
  z = sinf(v7);
  v2 = cosf(v7);
  z_4 = v2;
  *((float *)&v14 + 1) = -(z * x_4);
  *(float *)&v14 = (float)(y_4 * z_4) - (float)(*(float *)&x * (float)(z * y));
  v3 = v14;
  *((float *)&v14 + 1) = v2 * x_4;
  *a2 = v3;
  a2[1] = COERCE_UNSIGNED_INT((float)(*(float *)&x * (float)(y_4 * z)) + (float)(z_4 * y));
  *(float *)&v14 = (float)(*(float *)&x * (float)(z_4 * y)) + (float)(y_4 * z);
  a2[2] = v14;
  a2[3] = COERCE_UNSIGNED_INT((float)(z * y) - (float)(*(float *)&x * (float)(y_4 * z_4)));
  a2[4] = __PAIR64__(x, -(float)(x_4 * y));
  a2[5] = COERCE_UNSIGNED_INT(x_4 * y_4);
  HIDWORD(v15) = clear_value;
  a2[6] = 0;
  LODWORD(v15) = 0;
  a2[7] = v15;
  return (vostok::math::float4x4 *)a2;
}
