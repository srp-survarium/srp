bool __usercall vostok::collision::segment_segment_intersect@<al>(
        float *a1@<eax>,
        const vostok::math::float3 *a2@<ecx>,
        float a3@<xmm0>,
        const vostok::math::float3 *p1,
        const vostok::math::float3 *p4)
{
  float x; // xmm2_4
  float y; // xmm1_4
  float v9; // xmm5_4
  float v10; // xmm3_4
  float z; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // eax
  float v18; // xmm3_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm3_4
  vostok::math::float3 *v25; // eax
  vostok::math::float3 *v26; // eax
  float max_distance_squared; // [esp+0h] [ebp-64h]
  float v28; // [esp+4h] [ebp-60h]
  vostok::math::float3 v29; // [esp+8h] [ebp-5Ch]
  float v30; // [esp+14h] [ebp-50h]
  float v31; // [esp+18h] [ebp-4Ch]
  float v32; // [esp+1Ch] [ebp-48h]
  float mua; // [esp+20h] [ebp-44h] BYREF
  float mub; // [esp+24h] [ebp-40h] BYREF
  float v35; // [esp+28h] [ebp-3Ch]
  float v36; // [esp+2Ch] [ebp-38h]
  float v37; // [esp+30h] [ebp-34h]
  vostok::math::float3 d2; // [esp+34h] [ebp-30h] BYREF
  vostok::math::float3 d1; // [esp+40h] [ebp-24h] BYREF
  vostok::math::float3 pa; // [esp+4Ch] [ebp-18h] BYREF
  vostok::math::float3 pb; // [esp+58h] [ebp-Ch] BYREF
  const vostok::math::float3 *p1a; // [esp+68h] [ebp+4h]
  float p4a; // [esp+6Ch] [ebp+8h]

  max_distance_squared = a3 * a3;
  v29 = *p1;
  x = p4->x;
  y = p4->y;
  v30 = *a1;
  v9 = *a1 - p1->x;
  v31 = a1[1];
  v32 = a1[2];
  v10 = v32 - p1->z;
  z = a2->z;
  p4a = a2->x;
  v35 = x;
  v13 = x - p4a;
  v14 = a2->y;
  v36 = y;
  v15 = y - v14;
  *(float *)&p1a = v14;
  v28 = z;
  v37 = p4->z;
  v16 = v37 - z;
  d1.z = v10;
  v17 = (float)((float)(v37 - z) * (float)(v31 - v29.y)) - (float)(v15 * v10);
  v18 = (float)(v10 * v13) - (float)((float)(v37 - z) * v9);
  d1.y = v31 - v29.y;
  LODWORD(mua) = LODWORD(v17) & 0x7FFFFFFF;
  d1.x = v9;
  *(_QWORD *)&d2.x = __PAIR64__(LODWORD(v15), LODWORD(v13));
  d2.z = v37 - z;
  if ( COERCE_FLOAT(LODWORD(v17) & 0x7FFFFFFF) >= 0.0000099999997
    || (LODWORD(mua) = LODWORD(v18) & 0x7FFFFFFF, COERCE_FLOAT(LODWORD(v18) & 0x7FFFFFFF) >= 0.0000099999997)
    || (mua = fabs((float)(v15 * v9) - (float)((float)(v31 - v29.y) * v13)), mua >= 0.0000099999997) )
  {
    vostok::collision::line_line_intersect_non_parallel(a2, &d2, &mub, p1, &d1, &pa, &pb, &mua);
    if ( (float)((float)((float)((float)(pa.x - pb.x) * (float)(pa.x - pb.x))
                       + (float)((float)(pa.z - pb.z) * (float)(pa.z - pb.z)))
               + (float)((float)(pa.y - pb.y) * (float)(pa.y - pb.y))) > max_distance_squared )
      return 0;
    if ( mua > 0.0 && *(float *)&clear_value > mua && mub > 0.0 && *(float *)&clear_value > mub )
      return 1;
    v16 = d2.z;
    v15 = d2.y;
    v13 = d2.x;
  }
  v20 = (float)((float)(v13 * v13) + (float)(v16 * v16)) + (float)(v15 * v15);
  v21 = 0.0;
  v22 = (float)((float)((float)((float)(v29.x - p4a) * v13) + (float)((float)(v29.z - v28) * v16))
              + (float)((float)(v29.y - *(float *)&p1a) * v15))
      / v20;
  if ( v22 > 0.0 )
  {
    v21 = *(float *)&clear_value;
    if ( *(float *)&clear_value >= v22 )
      v21 = (float)((float)((float)((float)(v29.x - p4a) * v13) + (float)((float)(v29.z - v28) * v16))
                  + (float)((float)(v29.y - *(float *)&p1a) * v15))
          / v20;
  }
  if ( max_distance_squared > (float)((float)((float)((float)(v29.x - (float)((float)(v21 * v13) + p4a))
                                                    * (float)(v29.x - (float)((float)(v21 * v13) + p4a)))
                                            + (float)((float)(v29.z - (float)((float)(v16 * v21) + v28))
                                                    * (float)(v29.z - (float)((float)(v16 * v21) + v28))))
                                    + (float)((float)(v29.y - (float)((float)(v15 * v21) + *(float *)&p1a))
                                            * (float)(v29.y - (float)((float)(v15 * v21) + *(float *)&p1a)))) )
    return 1;
  v23 = 0.0;
  v24 = (float)((float)((float)((float)(v30 - p4a) * v13) + (float)((float)(v32 - v28) * v16))
              + (float)((float)(v31 - *(float *)&p1a) * v15))
      / v20;
  if ( v24 > 0.0 )
  {
    v23 = *(float *)&clear_value;
    if ( *(float *)&clear_value >= v24 )
      v23 = (float)((float)((float)((float)(v30 - p4a) * v13) + (float)((float)(v32 - v28) * v16))
                  + (float)((float)(v31 - *(float *)&p1a) * v15))
          / v20;
  }
  if ( max_distance_squared > (float)((float)((float)((float)(v30 - (float)((float)(v23 * v13) + p4a))
                                                    * (float)(v30 - (float)((float)(v23 * v13) + p4a)))
                                            + (float)((float)(v32 - (float)((float)(v16 * v23) + v28))
                                                    * (float)(v32 - (float)((float)(v16 * v23) + v28))))
                                    + (float)((float)(v31 - (float)((float)(v15 * v23) + *(float *)&p1a))
                                            * (float)(v31 - (float)((float)(v15 * v23) + *(float *)&p1a)))) )
    return 1;
  v25 = vostok::collision::closest_point_on_segment(a2, p1, &d1, &pb);
  if ( max_distance_squared > (float)((float)((float)((float)(v28 - v25->z) * (float)(v28 - v25->z))
                                            + (float)((float)(*(float *)&p1a - v25->y) * (float)(*(float *)&p1a - v25->y)))
                                    + (float)((float)(p4a - v25->x) * (float)(p4a - v25->x))) )
    return 1;
  v26 = vostok::collision::closest_point_on_segment(p4, p1, &d1, &pb);
  return max_distance_squared > (float)((float)((float)((float)(v37 - v26->z) * (float)(v37 - v26->z))
                                              + (float)((float)(v36 - v26->y) * (float)(v36 - v26->y)))
                                      + (float)((float)(v35 - v26->x) * (float)(v35 - v26->x)));
}
