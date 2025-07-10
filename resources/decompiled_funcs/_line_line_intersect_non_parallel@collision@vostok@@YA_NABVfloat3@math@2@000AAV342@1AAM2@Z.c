char __usercall vostok::collision::line_line_intersect_non_parallel@<al>(
        const vostok::math::float3 *p2@<edx>,
        const vostok::math::float3 *d2@<eax>,
        float *mub@<edi>,
        const vostok::math::float3 *p1,
        const vostok::math::float3 *d1,
        vostok::math::float3 *pa,
        vostok::math::float3 *pb,
        float *mua)
{
  float z; // xmm6_4
  float y; // xmm7_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float x; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm5_4
  float v23; // xmm4_4
  float v24; // xmm3_4
  float v25; // xmm3_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  vostok::math::float3 p31; // [esp+0h] [ebp-Ch]
  float d1a; // [esp+14h] [ebp+8h]
  float paa; // [esp+18h] [ebp+Ch]
  float d3134; // [esp+1Ch] [ebp+10h]

  z = d2->z;
  y = d1->y;
  v11 = d2->y;
  v12 = d1->z;
  x = d1->x;
  v16 = p1->x;
  paa = p1->y;
  v17 = paa - p2->y;
  p31.x = p1->x - p2->x;
  d1a = p1->z;
  p31.z = d1a - p2->z;
  v18 = d2->x;
  p31.y = v17;
  v19 = (float)((float)(v11 * y) + (float)(z * v12)) + (float)(v18 * x);
  v20 = (float)((float)(d2->y * d2->y) + (float)(z * z)) + (float)(v18 * v18);
  d3134 = (float)((float)(v18 * p31.x) + (float)(p31.z * d2->z)) + (float)(v17 * d2->y);
  v21 = (float)((float)(d3134 * v19)
              - (float)((float)((float)((float)(x * p31.x) + (float)(d1->z * p31.z)) + (float)(d1->y * v17)) * v20))
      / (float)((float)((float)((float)((float)(d1->y * d1->y) + (float)(d1->z * d1->z)) + (float)(x * x)) * v20)
              - (float)(v19 * v19));
  v22 = (float)((float)(v21 * v19) + d3134) / v20;
  *mua = v21;
  *mub = v22;
  v23 = v16 + (float)(v21 * x);
  v24 = d1->z;
  p31.y = paa + (float)(v21 * d1->y);
  p31.z = d1a + (float)(v21 * v24);
  p31.x = v23;
  *(_QWORD *)&pa->x = *(_QWORD *)&p31.x;
  pa->z = d1a + (float)(v21 * v24);
  v25 = p2->x;
  v26 = d2->x * v22;
  v27 = v22 * d2->z;
  p31.y = (float)(v22 * d2->y) + p2->y;
  v28 = p2->z + v27;
  p31.x = v25 + v26;
  *(_QWORD *)&pb->x = *(_QWORD *)&p31.x;
  pb->z = v28;
  return 1;
}
