int __userpurge survarium::distance_from_box_center_to_point_on_shape@<xmm0>(
        const vostok::math::float3 *source_position@<ecx>,
        const vostok::math::float4x4 *transform@<edx>,
        const vostok::math::float3 *dim)
{
  vostok::math::float4_pod *p_c; // eax
  float v4; // xmm5_4
  float v5; // xmm6_4
  float v6; // xmm7_4
  int v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm4_4
  float v14; // xmm4_4
  float v15; // xmm1_4
  int result; // xmm0_4
  vostok::math::float3 v17; // [esp+0h] [ebp-24h]
  unsigned __int64 v18; // [esp+Ch] [ebp-18h]
  float v19; // [esp+14h] [ebp-10h]
  __int64 v20; // [esp+18h] [ebp-Ch]
  float z; // [esp+20h] [ebp-4h]

  p_c = &transform->c;
  v4 = source_position->x - transform->c.x;
  v5 = source_position->y - transform->c.y;
  v6 = source_position->z - transform->c.z;
  v20 = *(_QWORD *)&transform->lines[3].x;
  z = transform->c.z;
  v17 = *dim;
  v7 = 0;
  do
  {
    v18 = *(_QWORD *)&transform->i.x;
    v19 = transform->i.z;
    v8 = s_bm_current_air_resistance
       / fsqrt(
           (float)((float)(v19 * v19) + (float)(*((float *)&v18 + 1) * *((float *)&v18 + 1)))
         + (float)(*(float *)&v18 * *(float *)&v18));
    v9 = *((float *)&v18 + 1) * v8;
    v10 = v8 * *(float *)&v18;
    v11 = v19 * v8;
    v12 = (float)((float)((float)(v19 * v8) * v6) + (float)((float)(*((float *)&v18 + 1) * v8) * v5))
        + (float)((float)(v8 * *(float *)&v18) * v4);
    v13 = *(&v17.x + v7);
    v18 = __PAIR64__(LODWORD(v9), LODWORD(v10));
    v19 = v11;
    if ( v12 > v13 )
      v12 = v13;
    LODWORD(v14) = LODWORD(v13) ^ _mask__NegFloat_;
    if ( v14 > v12 )
      v12 = v14;
    v15 = (float)(v10 * v12) + *(float *)&v20;
    *((float *)&v20 + 1) = *((float *)&v20 + 1) + (float)(v9 * v12);
    ++v7;
    transform = (const vostok::math::float4x4 *)((char *)transform + 16);
    *(float *)&v20 = v15;
    z = z + (float)(v11 * v12);
  }
  while ( v7 < 3 );
  *(float *)&result = fsqrt(
                        (float)((float)((float)(p_c->z - z) * (float)(p_c->z - z))
                              + (float)((float)(p_c->y - *((float *)&v20 + 1)) * (float)(p_c->y - *((float *)&v20 + 1))))
                      + (float)((float)(p_c->x - v15) * (float)(p_c->x - v15)));
  return result;
}
