bool __cdecl vostok::collision::test_triangle(
        const vostok::math::float3 *v0,
        const vostok::math::float3 *v1,
        const vostok::math::float3 *v2,
        const vostok::math::float3 *position,
        const vostok::math::float3 *direction,
        float max_distance,
        float *range)
{
  float y; // xmm3_4
  float z; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm6_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm7_4
  float v20; // xmm4_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float edge1_4; // [esp+4h] [ebp-20h]
  float edge1_8; // [esp+8h] [ebp-1Ch]
  float edge2; // [esp+Ch] [ebp-18h]
  float edge2_4; // [esp+10h] [ebp-14h]
  float edge2_8; // [esp+14h] [ebp-10h]
  float normal_4; // [esp+1Ch] [ebp-8h]
  float inverted_determinant; // [esp+2Ch] [ebp+8h]

  y = v0->y;
  z = v0->z;
  edge1_4 = v1->y - y;
  v9 = v2->y - y;
  edge1_8 = v1->z - z;
  v10 = v1->x - v0->x;
  v11 = v2->z - z;
  v12 = (float)(direction->y * v11) - (float)(direction->z * v9);
  edge2_4 = v9;
  edge2 = v2->x - v0->x;
  v13 = (float)(direction->x * v9) - (float)(direction->y * edge2);
  normal_4 = (float)(direction->z * edge2) - (float)(direction->x * v11);
  v14 = (float)((float)(v12 * v10) + (float)(v13 * edge1_8)) + (float)(normal_4 * edge1_4);
  edge2_8 = v11;
  if ( fabs(v14) < 0.0000099999997 )
    return 0;
  v16 = position->y - v0->y;
  v17 = position->x - v0->x;
  v18 = position->z - v0->z;
  inverted_determinant = *(float *)&clear_value / v14;
  v19 = (float)((float)((float)(v18 * v13) + (float)(v16 * normal_4)) + (float)(v17 * v12))
      * (float)(*(float *)&clear_value / v14);
  if ( v19 < 0.0 )
    return 0;
  if ( v19 > *(float *)&clear_value )
    return 0;
  v20 = (float)(v16 * edge1_8) - (float)(v18 * edge1_4);
  v21 = v17 * edge1_8;
  v22 = (float)(v17 * edge1_4) - (float)(v16 * v10);
  v23 = (float)(v18 * v10) - v21;
  v24 = (float)((float)((float)(direction->z * v22) + (float)(direction->y * v23)) + (float)(direction->x * v20))
      * inverted_determinant;
  if ( v24 < 0.0 )
    return 0;
  if ( (float)(v24 + v19) > *(float *)&clear_value )
    return 0;
  v25 = (float)((float)((float)(v23 * edge2_4) + (float)(v20 * edge2)) + (float)(v22 * edge2_8)) * inverted_determinant;
  *range = v25;
  return v25 > 0.0 && v25 <= max_distance;
}
