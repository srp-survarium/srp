float __usercall survarium::distance_from_capsule_center_to_point_on_shape@<xmm0>(
        const vostok::math::float4x4 *transform@<ecx>,
        const vostok::math::float3 *source_position@<eax>,
        float half_length,
        float radius)
{
  float v4; // xmm7_4
  float v5; // xmm3_4
  float v6; // xmm6_4
  float y; // xmm2_4
  float x; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm3_4
  float v11; // xmm7_4
  float v12; // xmm3_4
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float *v21; // esi
  float *v22; // esi
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm4_4
  float v29; // [esp+8h] [ebp-30h] BYREF
  float v30; // [esp+Ch] [ebp-2Ch]
  float v31; // [esp+10h] [ebp-28h]
  __int64 v32; // [esp+14h] [ebp-24h]
  float v33; // [esp+1Ch] [ebp-1Ch]
  float v34; // [esp+20h] [ebp-18h] BYREF
  float v35; // [esp+24h] [ebp-14h]
  float v36; // [esp+28h] [ebp-10h]
  __int64 v37; // [esp+2Ch] [ebp-Ch]
  float z; // [esp+34h] [ebp-4h]

  v37 = *(_QWORD *)&transform->lines[3].x;
  z = transform->c.z;
  v32 = *(_QWORD *)&transform->lines[1].x;
  v33 = transform->j.z;
  v4 = z + (float)(v33 * half_length);
  v34 = (float)(*(float *)&v32 * half_length) + *(float *)&v37;
  v5 = *((float *)&v37 + 1) + (float)(*((float *)&v32 + 1) * half_length);
  v29 = *(float *)&v37 - (float)(*(float *)&v32 * half_length);
  v6 = v29 - v34;
  v31 = z - (float)(v33 * half_length);
  v33 = v31 - v4;
  y = source_position->y;
  v30 = *((float *)&v37 + 1) - (float)(*((float *)&v32 + 1) * half_length);
  *((float *)&v32 + 1) = v30 - v5;
  x = source_position->x;
  v9 = (float)(y - v5) * (float)(v30 - v5);
  v35 = v5;
  v10 = source_position->z;
  v36 = v4;
  v11 = (float)((float)((float)((float)(x - v34) * (float)(v29 - v34)) + (float)((float)(v10 - v4) * (float)(v31 - v4)))
              + v9)
      / (float)((float)((float)(v6 * v6) + (float)((float)(v31 - v4) * (float)(v31 - v4)))
              + (float)(*((float *)&v32 + 1) * *((float *)&v32 + 1)));
  if ( v11 <= 0.0 || s_bm_current_air_resistance <= v11 )
  {
    v21 = &v34;
    if ( v11 >= 0.0 )
      v21 = &v29;
    *(float *)&v32 = *v21;
    v22 = v21 + 1;
    *((float *)&v32 + 1) = *v22;
    v33 = v22[1];
    v23 = y - *((float *)&v32 + 1);
    v24 = v10 - v33;
    v25 = x - *(float *)&v32;
    v26 = s_bm_current_air_resistance / fsqrt((float)((float)(v24 * v24) + (float)(v23 * v23)) + (float)(v25 * v25));
    v27 = (float)((float)((float)(v26 * v25) * radius) + *(float *)&v32) - *(float *)&v37;
    v19 = (float)((float)((float)((float)((float)(v24 * v26) * radius) + v33) - z)
                * (float)((float)((float)((float)(v24 * v26) * radius) + v33) - z))
        + (float)((float)((float)((float)((float)(v23 * v26) * radius) + *((float *)&v32 + 1)) - *((float *)&v37 + 1))
                * (float)((float)((float)((float)(v23 * v26) * radius) + *((float *)&v32 + 1)) - *((float *)&v37 + 1)));
    v20 = v27 * v27;
  }
  else
  {
    v12 = v10 - (float)((float)(v33 * v11) + v36);
    v31 = (float)(v33 * v11) + v36;
    v13 = (float)(v6 * v11) + v34;
    v14 = (float)(*((float *)&v32 + 1) * v11) + v35;
    v15 = x - v13;
    v16 = y - v14;
    v17 = s_bm_current_air_resistance / fsqrt((float)((float)(v15 * v15) + (float)(v12 * v12)) + (float)(v16 * v16));
    v18 = (float)(v16 * v17) * radius;
    v19 = (float)((float)((float)((float)((float)(v17 * v15) * radius) + v13) - *(float *)&v37)
                * (float)((float)((float)((float)(v17 * v15) * radius) + v13) - *(float *)&v37))
        + (float)((float)((float)((float)((float)(v12 * v17) * radius) + v31) - z)
                * (float)((float)((float)((float)(v12 * v17) * radius) + v31) - z));
    v20 = (float)((float)(v18 + v14) - *((float *)&v37 + 1)) * (float)((float)(v18 + v14) - *((float *)&v37 + 1));
  }
  return fsqrt(v19 + v20);
}
