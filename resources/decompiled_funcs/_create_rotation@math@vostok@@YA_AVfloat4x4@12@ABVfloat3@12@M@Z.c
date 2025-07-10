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
