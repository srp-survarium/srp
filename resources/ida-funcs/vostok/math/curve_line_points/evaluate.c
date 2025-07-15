void __userpurge vostok::math::curve_line_points<float,0>::evaluate(
        vostok::math::curve_line_points<float,0> *this@<ecx>,
        int a2@<eax>,
        float time,
        float default_value,
        vostok::math::enum_evaluate_time_type time_type,
        float left_range_alpha,
        float right_range_alpha)
{
  unsigned int v7; // edi
  int v8; // ecx
  float v9; // xmm0_4
  unsigned int v10; // edx
  int v11; // ecx
  float *v12; // eax
  float v13; // xmm1_4

  v7 = *(_DWORD *)(a2 + 24);
  if ( v7 )
  {
    v8 = *(_DWORD *)(a2 + 16);
    if ( v7 != 1 )
    {
      v9 = time_type
         ? time
         : (float)((float)(s_bm_current_air_resistance - time) * *(float *)a2) + (float)(*(float *)(a2 + 4) * time);
      if ( *(float *)(v8 + 16) < v9 && v9 < *(float *)(24 * v7 + v8 - 24 + 16) )
      {
        v10 = 1;
        v11 = v8 + 24;
        v12 = (float *)(*(_DWORD *)(a2 + 16) + 16);
        do
        {
          if ( *v12 <= v9 )
          {
            v13 = v12[6];
            if ( v9 <= v13 && fabs(v13 - *v12) > 0.0000099999997 )
              break;
          }
          ++v10;
          v11 += 24;
          v12 += 6;
        }
        while ( v10 < v7 );
      }
    }
  }
}


vostok::math::float3_pod *__userpurge vostok::math::curve_line_points<vostok::math::float3_pod,0>::evaluate@<eax>(
        vostok::math::curve_line_points<vostok::math::float3_pod,0> *this@<ecx>,
        int a2@<eax>,
        vostok::math::float3_pod *result,
        float time,
        vostok::math::float3_pod default_value,
        vostok::math::enum_evaluate_time_type time_type,
        float left_range_alpha,
        float right_range_alpha)
{
  vostok::math::float3_pod *v8; // ebx
  unsigned int v9; // esi
  vostok::math::float3_pod *v10; // eax
  unsigned int v11; // edi
  float *v12; // ecx
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm0_4
  vostok::math::float3_pod *v19; // edi
  vostok::math::float3_pod *v20; // eax
  vostok::math::float3_pod *p_default_value; // esi
  _DWORD *v22; // edi
  _DWORD *p_y; // esi
  vostok::math::float3_pod *v24; // esi
  char *v25; // ecx
  float *p_x; // edx
  float v27; // xmm1_4
  float *v28; // eax
  float v29; // xmm0_4
  bool v30; // zf
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm7_4
  float v35; // xmm6_4
  float v36; // xmm0_4
  float v37; // xmm4_4
  float v38; // xmm5_4
  float v39; // xmm2_4
  vostok::math::float3_pod v40; // [esp+Ch] [ebp-30h] BYREF
  float x; // [esp+18h] [ebp-24h]
  float y; // [esp+1Ch] [ebp-20h]
  float z; // [esp+20h] [ebp-1Ch]
  vostok::math::float3_pod v44; // [esp+24h] [ebp-18h]
  float v45; // [esp+30h] [ebp-Ch]
  float v46; // [esp+34h] [ebp-8h]
  float v47; // [esp+38h] [ebp-4h]

  v8 = result;
  v9 = *(_DWORD *)(a2 + 40);
  if ( !v9 )
    goto LABEL_5;
  v10 = *(vostok::math::float3_pod **)(a2 + 32);
  v11 = 1;
  v12 = (float *)((char *)&v10[-4] + 56 * v9 - 8);
  if ( v9 == 1 )
  {
    v44 = *v10;
    x = v10[1].x;
    y = v10[1].y;
    z = v10[1].z;
    v13 = y;
    v14 = z;
    v15 = v44.x * 0.0;
    v16 = v44.y * 0.0;
    v17 = v44.z * 0.0;
    v18 = x;
LABEL_4:
    default_value.x = v18 + v15;
    default_value.y = v13 + v16;
    default_value.z = v14 + v17;
LABEL_5:
    v19 = v8;
    v20 = v8;
    goto LABEL_6;
  }
  if ( v10[4].x >= time )
  {
    x = v10->x;
    y = v10->y;
    z = v10->z;
    v24 = v10 + 1;
LABEL_10:
    v44 = *v24;
    v13 = v44.y;
    v14 = v44.z;
    v15 = x * 0.0;
    v16 = y * 0.0;
    v17 = z * 0.0;
    v18 = v44.x;
    goto LABEL_4;
  }
  if ( time >= v12[12] )
  {
    x = *v12;
    y = v12[1];
    z = v12[2];
    v24 = (vostok::math::float3_pod *)(v12 + 3);
    goto LABEL_10;
  }
  v25 = (char *)&v10[4].elements[2];
  p_x = &v10[4].x;
  while ( 1 )
  {
    v27 = *p_x;
    v28 = p_x - 12;
    if ( *p_x > time )
      goto LABEL_18;
    v29 = p_x[14];
    if ( time > v29 )
      goto LABEL_18;
    v46 = v29 - v27;
    v47 = v29 - v27;
    v45 = fabs(v29 - v27);
    if ( v45 > 0.0000099999997 )
      break;
    v8 = result;
LABEL_18:
    ++v11;
    v25 += 56;
    p_x += 14;
    if ( v11 >= v9 )
      goto LABEL_5;
  }
  v30 = *((_DWORD *)v28 + 13) == 0;
  x = *v28;
  y = v28[1];
  z = v28[2];
  v31 = x;
  v32 = y;
  v33 = z;
  v44 = *(vostok::math::float3_pod *)((_BYTE *)v28 + 1);
  x = *(float *)v25;
  y = *((float *)v25 + 1);
  z = *((float *)v25 + 2);
  v40 = *(vostok::math::float3_pod *)(v25 + 1);
  v34 = v44.z + (float)(v33 * 0.0);
  v35 = v44.y + (float)(v32 * 0.0);
  v44.x = v44.x + (float)(v31 * 0.0);
  v36 = v40.x + (float)(x * 0.0);
  v37 = v40.y + (float)(y * 0.0);
  v38 = v40.z + (float)(z * 0.0);
  v44.y = v35;
  v44.z = v34;
  v40.x = v36;
  v40.y = v37;
  v40.z = v38;
  if ( !v30 || *((_DWORD *)v25 + 13) )
  {
    p_default_value = (vostok::math::float3_pod *)vostok::math::cubic_interpolation<vostok::math::float3_pod,float>(
                                                    &v40.x,
                                                    (float)(time - *p_x) / v47,
                                                    v44,
                                                    *(vostok::math::float3_pod *)(v28 + 9),
                                                    v40,
                                                    *((vostok::math::float3_pod *)v25 + 2));
    v20 = result;
    v19 = result;
  }
  else
  {
    v20 = result;
    v39 = (float)(time - *p_x) / v47;
    default_value.x = (float)((float)(s_bm_current_air_resistance - v39) * v44.x) + (float)(v36 * v39);
    default_value.y = (float)(v35 * (float)(s_bm_current_air_resistance - v39)) + (float)(v37 * v39);
    default_value.z = (float)(v34 * (float)(s_bm_current_air_resistance - v39)) + (float)(v38 * v39);
    v19 = result;
LABEL_6:
    p_default_value = &default_value;
  }
  v19->x = p_default_value->x;
  p_y = (_DWORD *)&p_default_value->y;
  v22 = (_DWORD *)&v19->y;
  *v22 = *p_y;
  v22[1] = p_y[1];
  return v20;
}


vostok::math::float4_pod *__userpurge vostok::math::curve_line_points<vostok::math::float4_pod,1>::evaluate@<eax>(
        vostok::math::curve_line_points<vostok::math::float4_pod,1> *this@<ecx>,
        int a2@<eax>,
        vostok::math::float4_pod *result,
        float time,
        vostok::math::float4_pod default_value,
        vostok::math::enum_evaluate_time_type time_type,
        float left_range_alpha,
        float right_range_alpha)
{
  unsigned int v9; // edx
  vostok::math::float4_pod *v10; // eax
  int v11; // ecx
  float *p_x; // esi
  float v13; // xmm1_4
  vostok::math::float4_pod *v14; // eax
  float *v15; // esi
  vostok::math::float4_pod *v16; // eax
  vostok::math::float4_pod *p_default_value; // esi
  unsigned int v18; // ecx
  float *v19; // eax
  float v20; // xmm1_4
  float *v21; // ebx
  float v22; // xmm0_4
  vostok::math::float4_pod *v23; // eax
  float *p_y; // esi
  vostok::math::float4_pod *v25; // eax
  vostok::math::float4_pod v26; // [esp-20h] [ebp-60h]
  vostok::math::float4_pod v27; // [esp-10h] [ebp-50h]
  vostok::math::float4_pod v28; // [esp+10h] [ebp-30h] BYREF
  vostok::math::float4_pod v29; // [esp+20h] [ebp-20h] BYREF
  float v30; // [esp+30h] [ebp-10h]
  float v31; // [esp+34h] [ebp-Ch]
  float v32; // [esp+38h] [ebp-8h]
  vostok::math::float4_pod *v33; // [esp+3Ch] [ebp-4h]

  v9 = *(_DWORD *)(a2 + 48);
  if ( !v9 )
  {
LABEL_16:
    p_default_value = &default_value;
    goto LABEL_17;
  }
  v10 = *(vostok::math::float4_pod **)(a2 + 40);
  v11 = (int)&v10[-4] + 72 * v9 - 8;
  if ( v9 == 1 || v10[4].x >= time )
  {
    v27 = *v10;
    p_x = &v10[1].x;
LABEL_4:
    v13 = 0.0;
    v14 = &v29;
    goto LABEL_5;
  }
  if ( time >= *(float *)(v11 + 64) )
  {
    v27 = *(vostok::math::float4_pod *)v11;
    p_x = (float *)(v11 + 16);
    goto LABEL_4;
  }
  v18 = 1;
  v33 = (vostok::math::float4_pod *)((char *)v10 + 72);
  v19 = &v10[4].x;
  while ( 1 )
  {
    v20 = *v19;
    v21 = v19 - 16;
    if ( *v19 <= time )
    {
      v22 = v19[18];
      if ( time <= v22 )
      {
        v32 = v22 - v20;
        v31 = v22 - v20;
        v30 = fabs(v22 - v20);
        if ( v30 > 0.0000099999997 )
          break;
      }
    }
    v33 = (vostok::math::float4_pod *)((char *)v33 + 72);
    ++v18;
    v19 += 18;
    if ( v18 >= v9 )
      goto LABEL_16;
  }
  v32 = COERCE_FLOAT(
          vostok::math::linear_interpolation<vostok::math::float4_pod>(
            &v29,
            0.0,
            *(vostok::math::float4_pod *)(v21 + 4),
            *(vostok::math::float4_pod *)v21));
  v25 = vostok::math::linear_interpolation<vostok::math::float4_pod>(&v28, 0.0, v33[1], *v33);
  if ( *((_DWORD *)v21 + 17) || LODWORD(v33[4].y) )
  {
    v16 = (vostok::math::float4_pod *)vostok::math::cubic_interpolation<vostok::math::float4_pod,float>(
                                        &v28.x,
                                        (float)(time - v21[16]) / v31,
                                        *(vostok::math::float4_pod *)LODWORD(v32),
                                        *(vostok::math::float4_pod *)(v21 + 12),
                                        *v25,
                                        v33[2]);
    goto LABEL_6;
  }
  v13 = (float)(time - v21[16]) / v31;
  v27 = *v25;
  p_x = (float *)LODWORD(v32);
  v14 = &v28;
LABEL_5:
  v26.x = *p_x;
  v15 = p_x + 1;
  v26.y = *v15;
  *(_QWORD *)&v26.elements[2] = *(_QWORD *)(v15 + 1);
  v16 = vostok::math::linear_interpolation<vostok::math::float4_pod>(v14, v13, v26, v27);
LABEL_6:
  p_default_value = v16;
LABEL_17:
  v23 = result;
  result->x = p_default_value->x;
  p_y = &p_default_value->y;
  result->y = *p_y;
  *(_QWORD *)&result->elements[2] = *(_QWORD *)(p_y + 1);
  return v23;
}
