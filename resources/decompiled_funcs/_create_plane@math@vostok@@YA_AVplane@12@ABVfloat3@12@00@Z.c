vostok::math::plane *__usercall vostok::math::create_plane@<eax>(
        const vostok::math::float3 *first@<esi>,
        const vostok::math::float3 *second@<ecx>,
        const vostok::math::float3 *third@<eax>,
        int a4@<edi>)
{
  float y; // xmm3_4
  float z; // xmm7_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm7_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm3_4
  float v18; // [esp+4h] [ebp-20h]
  float x; // [esp+8h] [ebp-1Ch]
  float v20; // [esp+10h] [ebp-14h]
  float v21; // [esp+14h] [ebp-10h]
  __int64 v22; // [esp+18h] [ebp-Ch]

  y = first->y;
  z = first->z;
  v6 = third->x - first->x;
  x = first->x;
  v7 = third->y - y;
  v8 = third->z - z;
  v9 = second->y - y;
  v10 = second->z - z;
  v11 = v10 * v6;
  v12 = (float)(v9 * v8) - (float)(v10 * v7);
  v13 = second->x - first->x;
  v21 = (float)(v13 * v7) - (float)(v6 * v9);
  v20 = v11 - (float)(v13 * v8);
  v18 = sqrtf((float)((float)(v21 * v21) + (float)(v20 * v20)) + (float)(v12 * v12));
  v14 = (float)(*(float *)&clear_value / v18) * v21;
  *((float *)&v22 + 1) = (float)(*(float *)&clear_value / v18) * v20;
  v15 = *((float *)&v22 + 1) * first->y;
  *(float *)&v22 = (float)(*(float *)&clear_value / v18) * v12;
  *(_QWORD *)a4 = v22;
  v16 = first->z * v14;
  *(float *)(a4 + 8) = v14;
  *(float *)(a4 + 12) = -(float)((float)(v16 + (float)(x * *(float *)&v22)) + v15);
  return (vostok::math::plane *)a4;
}
