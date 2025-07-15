bool __usercall vostok::collision::test_triangle@<al>(
        const vostok::math::float3 *v1@<esi>,
        const vostok::math::float3 *v2@<edx>,
        const vostok::math::float3 *position@<edi>,
        const vostok::math::float3 *direction@<ecx>,
        const vostok::math::float3 *v0,
        float max_distance,
        float *range)
{
  float y; // xmm4_4
  float z; // xmm6_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm2_4
  float v12; // xmm5_4
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm4_4
  float v16; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm7_4
  float v22; // xmm4_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // [esp+4h] [ebp-28h]
  float v29; // [esp+Ch] [ebp-20h]
  float v30; // [esp+10h] [ebp-1Ch]
  float v31; // [esp+14h] [ebp-18h]
  float v32; // [esp+1Ch] [ebp-10h]
  float v33; // [esp+20h] [ebp-Ch]
  float v34; // [esp+34h] [ebp+8h]

  y = v0->y;
  z = v0->z;
  v9 = v2->y - y;
  v32 = v1->y - y;
  v10 = v2->z - z;
  v33 = v1->z - z;
  v11 = v2->x - v0->x;
  v12 = v1->x - v0->x;
  v13 = (float)(direction->y * v10) - (float)(direction->z * v9);
  v31 = v10;
  v14 = direction->x * v10;
  v30 = v9;
  v15 = (float)(direction->x * v9) - (float)(direction->y * v11);
  v28 = (float)(direction->z * v11) - v14;
  v16 = (float)((float)(v13 * v12) + (float)(v15 * v33)) + (float)(v28 * v32);
  v29 = v11;
  if ( fabs(v16) < 0.0000099999997 )
    return 0;
  v18 = position->y - v0->y;
  v19 = position->x - v0->x;
  v20 = position->z - v0->z;
  v34 = s_bm_current_air_resistance / v16;
  v21 = (float)((float)((float)(v20 * v15) + (float)(v18 * v28)) + (float)(v19 * v13))
      * (float)(s_bm_current_air_resistance / v16);
  if ( v21 < 0.0 )
    return 0;
  if ( v21 > s_bm_current_air_resistance )
    return 0;
  v22 = (float)(v18 * v33) - (float)(v20 * v32);
  v23 = v19 * v33;
  v24 = (float)(v19 * v32) - (float)(v18 * v12);
  v25 = (float)(v20 * v12) - v23;
  v26 = (float)((float)((float)(direction->z * v24) + (float)(direction->y * v25)) + (float)(direction->x * v22)) * v34;
  if ( v26 < 0.0 )
    return 0;
  if ( (float)(v26 + v21) > s_bm_current_air_resistance )
    return 0;
  v27 = (float)((float)((float)(v25 * v30) + (float)(v22 * v29)) + (float)(v24 * v31)) * v34;
  *range = v27;
  return v27 > 0.0 && v27 <= max_distance;
}
