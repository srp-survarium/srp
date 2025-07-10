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
