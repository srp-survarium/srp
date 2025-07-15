__m128 __usercall vostok::math::segment_to_segment_distance@<xmm0>(
        const vostok::math::float3 *p2@<esi>,
        const vostok::math::float3 *p3@<edx>,
        const vostok::math::float3 *p4@<ecx>,
        const vostok::math::float3 *p1)
{
  float y; // xmm6_4
  float z; // xmm1_4
  float x; // xmm5_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm1_4
  float v13; // xmm5_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  __m128 result; // xmm0
  float v17; // xmm0_4
  const vostok::math::float4x4 *v18; // xmm4_4
  float v19; // xmm4_4
  const vostok::math::float4x4 *v20; // xmm0_4
  float v21; // xmm7_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm1_4
  const vostok::math::float4x4 *v25; // xmm0_4
  float v26; // xmm2_4
  __int128 v27; // xmm1
  float v28; // [esp+0h] [ebp-64h]
  float v29; // [esp+4h] [ebp-60h]
  float v30; // [esp+8h] [ebp-5Ch]
  float v31; // [esp+Ch] [ebp-58h]
  float v32; // [esp+10h] [ebp-54h]
  float v33; // [esp+14h] [ebp-50h]
  float v34; // [esp+18h] [ebp-4Ch]
  float v35; // [esp+1Ch] [ebp-48h]
  float mua; // [esp+20h] [ebp-44h] BYREF
  float v37; // [esp+24h] [ebp-40h]
  float v38; // [esp+28h] [ebp-3Ch]
  float v39; // [esp+2Ch] [ebp-38h]
  float mub; // [esp+30h] [ebp-34h] BYREF
  vostok::math::float3 d1; // [esp+34h] [ebp-30h] BYREF
  vostok::math::float3 d2; // [esp+40h] [ebp-24h] BYREF
  vostok::math::float3 pb; // [esp+4Ch] [ebp-18h] BYREF
  vostok::math::float3 pa; // [esp+58h] [ebp-Ch] BYREF
  float p1a; // [esp+68h] [ebp+4h]

  y = p2->y;
  z = p2->z;
  x = p4->x;
  v8 = p4->y;
  v9 = p4->z;
  v29 = p1->x;
  v37 = p2->x;
  v10 = v37 - v29;
  v30 = p1->y;
  v38 = y;
  v11 = y - v30;
  v31 = p1->z;
  v39 = z;
  v12 = z - v31;
  p1a = p3->x;
  v33 = x;
  v13 = x - p3->x;
  v28 = p3->y;
  v34 = v8;
  v14 = v8 - v28;
  v32 = p3->z;
  v35 = v9;
  v15 = v9 - v32;
  pb.x = (float)(v15 * v11) - (float)(v14 * v12);
  pb.y = (float)(v12 * v13) - (float)(v15 * (float)(v37 - v29));
  mua = fabs(pb.x);
  d1.x = v37 - v29;
  *(_QWORD *)&d1.elements[1] = __PAIR64__(LODWORD(v12), LODWORD(v11));
  *(_QWORD *)&d2.x = __PAIR64__(LODWORD(v14), LODWORD(v13));
  d2.z = v15;
  if ( mua >= 0.0000099999997
    || (LODWORD(mua) = LODWORD(pb.y) & 0x7FFFFFFF, COERCE_FLOAT(LODWORD(pb.y) & 0x7FFFFFFF) >= 0.0000099999997)
    || (mua = fabs((float)(v14 * v10) - (float)(v13 * v11)), mua >= 0.0000099999997) )
  {
    line_line_intersect_non_parallel(p3, &d2, &mub, p1, &d1, &pa, &pb, &mua);
    result = 0;
    if ( mua > 0.0 && *(float *)&clear_value > mua && mub > 0.0 && *(float *)&clear_value > mub )
      return result;
    v12 = d1.z;
    v11 = d1.y;
    v10 = d1.x;
    v15 = d2.z;
    v14 = d2.y;
    v13 = d2.x;
  }
  d2.x = v33 - v29;
  d2.y = v34 - v30;
  d2.z = v35 - v31;
  mua = (float)((float)(v12 * v12) + (float)(v10 * v10)) + (float)(v11 * v11);
  v17 = (float)((float)((float)((float)(v35 - v31) * v12) + (float)((float)(v34 - v30) * v11))
              + (float)((float)(v33 - v29) * v10))
      / mua;
  *(float *)&v18 = 0.0;
  if ( v17 <= 0.0 || (v18 = clear_value, *(float *)&clear_value < v17) )
    v17 = *(float *)&v18;
  d2.x = v17 * v10;
  d2.y = v17 * v11;
  d1.x = v29 + (float)(v17 * v10);
  d1.y = (float)(v17 * v11) + v30;
  d1.z = (float)(v12 * v17) + v31;
  pb.x = v33 - d1.x;
  d2.z = v12 * v17;
  mub = (float)((float)((float)(v35 - d1.z) * (float)(v35 - d1.z)) + (float)((float)(v34 - d1.y) * (float)(v34 - d1.y)))
      + (float)(pb.x * pb.x);
  pb.x = p1a - v29;
  pb.y = v28 - v30;
  v19 = (float)((float)((float)((float)(v32 - v31) * v12) + (float)((float)(v28 - v30) * v11))
              + (float)((float)(p1a - v29) * v10))
      / mua;
  *(float *)&v20 = 0.0;
  if ( v19 <= 0.0 || (v20 = clear_value, *(float *)&clear_value < v19) )
    v19 = *(float *)&v20;
  mua = (float)((float)((float)(v32 - (float)((float)(v12 * v19) + v31))
                      * (float)(v32 - (float)((float)(v12 * v19) + v31)))
              + (float)((float)(v28 - (float)((float)(v19 * v11) + v30))
                      * (float)(v28 - (float)((float)(v19 * v11) + v30))))
      + (float)((float)(p1a - (float)((float)(v19 * v10) + v29)) * (float)(p1a - (float)((float)(v19 * v10) + v29)));
  v21 = 0.0;
  v22 = (float)((float)(v15 * v15) + (float)(v14 * v14)) + (float)(v13 * v13);
  v23 = (float)((float)((float)((float)(v37 - p1a) * v13) + (float)((float)(v39 - v32) * v15))
              + (float)((float)(v38 - v28) * v14))
      / v22;
  if ( v23 > 0.0 )
  {
    v21 = *(float *)&clear_value;
    if ( *(float *)&clear_value >= v23 )
      v21 = (float)((float)((float)((float)(v37 - p1a) * v13) + (float)((float)(v39 - v32) * v15))
                  + (float)((float)(v38 - v28) * v14))
          / v22;
  }
  v39 = (float)((float)((float)(v39 - (float)((float)(v15 * v21) + v32))
                      * (float)(v39 - (float)((float)(v15 * v21) + v32)))
              + (float)((float)(v38 - (float)((float)(v14 * v21) + v28))
                      * (float)(v38 - (float)((float)(v14 * v21) + v28))))
      + (float)((float)(v37 - (float)((float)(v21 * v13) + p1a)) * (float)(v37 - (float)((float)(v21 * v13) + p1a)));
  v24 = (float)((float)((float)((float)(v29 - p1a) * v13) + (float)((float)(v31 - v32) * v15))
              + (float)((float)(v30 - v28) * v14))
      / v22;
  *(float *)&v25 = 0.0;
  if ( v24 <= 0.0 || (v25 = clear_value, *(float *)&clear_value < v24) )
    v24 = *(float *)&v25;
  result = (__m128)LODWORD(v31);
  result.m128_f32[0] = (float)((float)(v31 - (float)((float)(v15 * v24) + v32))
                             * (float)(v31 - (float)((float)(v15 * v24) + v32)))
                     + (float)((float)(v30 - (float)((float)(v14 * v24) + v28))
                             * (float)(v30 - (float)((float)(v14 * v24) + v28)));
  v26 = (float)(v29 - (float)((float)(v24 * v13) + p1a)) * (float)(v29 - (float)((float)(v24 * v13) + p1a));
  v27 = LODWORD(mua);
  result.m128_f32[0] = result.m128_f32[0] + v26;
  if ( mub <= mua )
    v27 = LODWORD(mub);
  if ( *(float *)&v27 > v39 )
    v27 = LODWORD(v39);
  if ( *(float *)&v27 <= result.m128_f32[0] )
    return (__m128)v27;
  return result;
}
