float __usercall survarium::distance_from_cylinder_center_to_point_on_shape@<xmm0>(
        const vostok::math::float4x4 *transform@<ecx>,
        const vostok::math::float3 *source_position@<eax>,
        float radius,
        float half_length)
{
  float v4; // xmm7_4
  float v5; // xmm3_4
  float v6; // xmm6_4
  float y; // xmm2_4
  float x; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm6_4
  float v13; // xmm5_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm4_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float *v23; // esi
  float *v24; // esi
  __int64 v25; // [esp+8h] [ebp-30h] BYREF
  float v26; // [esp+10h] [ebp-28h]
  float v27; // [esp+14h] [ebp-24h] BYREF
  float v28; // [esp+18h] [ebp-20h]
  float v29; // [esp+1Ch] [ebp-1Ch]
  float v30; // [esp+20h] [ebp-18h]
  float v31; // [esp+24h] [ebp-14h]
  float v32; // [esp+28h] [ebp-10h]
  __int64 v33; // [esp+2Ch] [ebp-Ch]
  float z; // [esp+34h] [ebp-4h]

  v33 = *(_QWORD *)&transform->lines[3].x;
  z = transform->c.z;
  v25 = *(_QWORD *)&transform->lines[1].x;
  v26 = transform->j.z;
  v4 = z + (float)(v26 * half_length);
  v27 = (float)(*(float *)&v25 * half_length) + *(float *)&v33;
  v5 = *((float *)&v33 + 1) + (float)(*((float *)&v25 + 1) * half_length);
  v6 = (float)(*(float *)&v33 - (float)(*(float *)&v25 * half_length)) - v27;
  v32 = (float)(z - (float)(v26 * half_length)) - v4;
  y = source_position->y;
  v31 = (float)(*((float *)&v33 + 1) - (float)(*((float *)&v25 + 1) * half_length)) - v5;
  x = source_position->x;
  v9 = (float)(y - v5) * v31;
  v28 = v5;
  v10 = source_position->z;
  v29 = v4;
  v11 = (float)((float)((float)((float)(x - v27) * v6) + (float)((float)(v10 - v4) * v32)) + v9)
      / (float)((float)((float)(v6 * v6) + (float)(v32 * v32)) + (float)(v31 * v31));
  if ( v11 <= 0.0 || s_bm_current_air_resistance <= v11 )
  {
    v20 = x - *(float *)&v33;
    v21 = y - *((float *)&v33 + 1);
    v22 = v10 - z;
    if ( v11 >= 0.0 )
    {
      LODWORD(v27) = v25 ^ _mask__NegFloat_;
      LODWORD(v28) = HIDWORD(v25) ^ _mask__NegFloat_;
      LODWORD(v29) = LODWORD(v26) ^ _mask__NegFloat_;
      v23 = &v27;
    }
    else
    {
      v23 = (float *)&v25;
    }
    v30 = *v23;
    v24 = v23 + 1;
    v31 = *v24;
    return fsqrt((float)((float)(v22 * v22) + (float)(v21 * v21)) + (float)(v20 * v20))
         * (float)(half_length / (float)((float)((float)(v20 * v30) + (float)(v24[1] * v22)) + (float)(v31 * v21)));
  }
  else
  {
    v12 = (float)(v6 * v11) + v27;
    v13 = (float)(v31 * v11) + v28;
    v14 = (float)(v32 * v11) + v29;
    v15 = v10 - v14;
    v16 = x - v12;
    v17 = y - v13;
    v18 = s_bm_current_air_resistance / fsqrt((float)((float)(v16 * v16) + (float)(v15 * v15)) + (float)(v17 * v17));
    return fsqrt(
             (float)((float)((float)((float)((float)((float)(v18 * v16) * radius) + v12) - *(float *)&v33)
                           * (float)((float)((float)((float)(v18 * v16) * radius) + v12) - *(float *)&v33))
                   + (float)((float)((float)((float)((float)(v15 * v18) * radius) + v14) - z)
                           * (float)((float)((float)((float)(v15 * v18) * radius) + v14) - z)))
           + (float)((float)((float)((float)((float)(v17 * v18) * radius) + v13) - *((float *)&v33 + 1))
                   * (float)((float)((float)((float)(v17 * v18) * radius) + v13) - *((float *)&v33 + 1))));
  }
}
