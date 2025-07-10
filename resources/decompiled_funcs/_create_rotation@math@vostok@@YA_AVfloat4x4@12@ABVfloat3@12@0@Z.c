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
