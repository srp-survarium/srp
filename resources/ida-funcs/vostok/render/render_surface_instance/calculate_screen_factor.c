void __thiscall vostok::render::render_surface_instance::calculate_screen_factor(
        vostok::render::render_surface_instance *this,
        const vostok::math::float4x4 *projection_matrix,
        const vostok::math::float4x4 *viewer_position,
        float *a4)
{
  vostok::math::aabb *v4; // eax
  float v5; // xmm1_4
  float v6; // xmm1_4
  float *p_z; // esi
  int v8; // edi
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  bool v12; // zf
  float *v13; // eax
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float x; // ecx
  float v22; // xmm0_4
  float v23; // xmm0_4
  long double v24; // [esp+4h] [ebp-150h]
  long double v25; // [esp+Ch] [ebp-148h]
  float v26; // [esp+14h] [ebp-140h]
  float v27; // [esp+18h] [ebp-13Ch]
  float v28; // [esp+1Ch] [ebp-138h]
  vostok::math::float3 v29; // [esp+20h] [ebp-134h] BYREF
  float v30; // [esp+2Ch] [ebp-128h] BYREF
  float v31; // [esp+30h] [ebp-124h]
  vostok::math::aabb v32; // [esp+34h] [ebp-120h] BYREF
  float v33; // [esp+4Ch] [ebp-108h]
  float v34; // [esp+50h] [ebp-104h]
  float v35; // [esp+54h] [ebp-100h]
  int v36; // [esp+58h] [ebp-FCh] BYREF
  vostok::math::float3 v37; // [esp+5Ch] [ebp-F8h] BYREF
  vostok::math::float3 v38; // [esp+68h] [ebp-ECh] BYREF
  vostok::math::float4x4 v39; // [esp+74h] [ebp-E0h] BYREF
  vostok::math::float4x4 v40; // [esp+B4h] [ebp-A0h] BYREF
  vostok::math::aabb v41; // [esp+F4h] [ebp-60h] BYREF

  qmemcpy(&v32, (const void *)(LODWORD(projection_matrix->j.x) + 108), sizeof(v32));
  v4 = vostok::math::aabb::modify((vostok::math::aabb *)LODWORD(projection_matrix->k.y), &v32);
  vostok::math::aabb::vertices(&v41, (int)v4);
  v28 = 0.0;
  v31 = 0.0;
  v34 = v32.max.x + v32.min.x;
  v26 = s_bm_current_air_resistance;
  v27 = s_bm_current_air_resistance;
  v38.x = (float)(v32.max.x + v32.min.x) * 0.5;
  v5 = *a4;
  *(_QWORD *)&v37.x = __PAIR64__(LODWORD(FLOAT_0_89999998), LODWORD(FLOAT_N0_1));
  v29.x = v5 + 0.1;
  v29.y = a4[1] + 0.1;
  v6 = a4[2];
  v35 = v32.max.y + v32.min.y;
  v33 = v32.max.z + v32.min.z;
  v37.z = FLOAT_0_1;
  v38.y = (float)(v32.max.y + v32.min.y) * 0.5;
  v38.z = (float)(v32.max.z + v32.min.z) * 0.5;
  v29.z = v6 + 0.1;
  vostok::math::create_camera_at(&v29, &v38, &v40, &v37);
  vostok::math::mul4x4(viewer_position, &v40, &v39);
  v36 = 0;
  p_z = &v41.min.z;
  v8 = 8;
  do
  {
    v9 = *(p_z - 2);
    v10 = *p_z;
    v11 = *(p_z - 1);
    v29.x = (float)((float)((float)(v39.k.x * *p_z) + (float)(v39.i.x * v9)) + (float)(v39.j.x * v11)) + v39.c.x;
    v29.y = (float)((float)((float)(v39.i.y * v9) + (float)(v39.k.y * v10)) + (float)(v39.j.y * v11)) + v39.c.y;
    v29.z = (float)((float)((float)(v39.i.z * v9) + (float)(v39.k.z * v10)) + (float)(v39.j.z * v11)) + v39.c.z;
    v30 = (float)((float)((float)(v39.i.w * v9) + (float)(v39.k.w * v10)) + (float)(v39.j.w * v11)) + v39.c.w;
    v12 = !vostok::math::is_similar<float>(&v30, (const float *)&v36, 0.001);
    v13 = (float *)&epsilon_3_24;
    if ( v12 )
      v13 = &v30;
    v14 = s_bm_current_air_resistance / *v13;
    v15 = (float)((float)(v14 * v29.x) * 0.5) + 0.5;
    v16 = (float)((float)(COERCE_FLOAT(LODWORD(v29.y) ^ _mask__NegFloat_) * v14) * 0.5) + 0.5;
    if ( v15 <= v26 )
      v26 = (float)((float)(v14 * v29.x) * 0.5) + 0.5;
    v17 = v28;
    if ( v28 <= v15 )
    {
      v17 = v15;
      v28 = v15;
    }
    if ( v16 <= v27 )
      v27 = v16;
    v18 = v31;
    if ( v31 <= v16 )
    {
      v18 = v16;
      v31 = v16;
    }
    p_z += 3;
    --v8;
  }
  while ( v8 );
  v19 = v17 - v26;
  v20 = v18 - v27;
  if ( v19 > v20 )
    v20 = v19;
  __libm_sse2_pow(v24, v25);
  x = projection_matrix->j.x;
  v22 = v20 * s_spot_max_distance;
  projection_matrix->k.w = v22;
  if ( (*(_BYTE *)(LODWORD(x) + 148) & 0x78) != 0 )
    projection_matrix->k.w = v22 * 6.0;
  v23 = fsqrt(
          (float)((float)((float)((float)(v33 * 0.5) - a4[2]) * (float)((float)(v33 * 0.5) - a4[2]))
                + (float)((float)((float)(v35 * 0.5) - a4[1]) * (float)((float)(v35 * 0.5) - a4[1])))
        + (float)((float)((float)(v34 * 0.5) - *a4) * (float)((float)(v34 * 0.5) - *a4)))
      - fsqrt(
          (float)((float)((float)((float)(v32.max.z - v32.min.z) * 0.5) * (float)((float)(v32.max.z - v32.min.z) * 0.5))
                + (float)((float)((float)(v32.max.y - v32.min.y) * 0.5) * (float)((float)(v32.max.y - v32.min.y) * 0.5)))
        + (float)((float)((float)(v32.max.x - v32.min.x) * 0.5) * (float)((float)(v32.max.x - v32.min.x) * 0.5)));
  if ( v23 < 0.0 )
    v23 = 0.0;
  projection_matrix->c.x = v23;
}
