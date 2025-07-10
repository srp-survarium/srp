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
