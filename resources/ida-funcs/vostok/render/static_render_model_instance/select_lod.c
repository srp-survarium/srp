unsigned __int8 __thiscall vostok::render::static_render_model_instance::select_lod(
        vostok::render::static_render_model_instance *this,
        const vostok::math::float4x4 *mat_vp,
        const vostok::math::float3 *view_pos,
        float *a4)
{
  float x; // eax
  _BYTE *v5; // ecx
  unsigned __int8 result; // al
  float *v7; // ecx
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float *p_z; // eax
  int v13; // ecx
  float v14; // xmm6_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm5_4
  bool v21; // cc
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm4_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm3_4
  float v28; // xmm4_4
  float v29; // [esp+Ch] [ebp-D4h]
  float v30; // [esp+Ch] [ebp-D4h]
  float z; // [esp+10h] [ebp-D0h]
  _BYTE *v32; // [esp+14h] [ebp-CCh]
  float y; // [esp+14h] [ebp-CCh]
  float *v34; // [esp+18h] [ebp-C8h]
  vostok::math::aabb v35; // [esp+1Ch] [ebp-C4h] BYREF
  vostok::math::aabb v36; // [esp+34h] [ebp-ACh] BYREF
  float v37; // [esp+4Ch] [ebp-94h]
  float v38; // [esp+50h] [ebp-90h]
  float v39; // [esp+54h] [ebp-8Ch]
  float v40; // [esp+58h] [ebp-88h]
  float v41; // [esp+5Ch] [ebp-84h]
  float v42; // [esp+60h] [ebp-80h]
  float v43; // [esp+64h] [ebp-7Ch]
  float v44; // [esp+68h] [ebp-78h]
  float v45; // [esp+6Ch] [ebp-74h]
  float v46; // [esp+70h] [ebp-70h]
  float v47; // [esp+74h] [ebp-6Ch]
  float v48; // [esp+78h] [ebp-68h]
  float v49; // [esp+7Ch] [ebp-64h]
  vostok::math::aabb v50[4]; // [esp+80h] [ebp-60h] BYREF

  x = mat_vp[9].k.x;
  v5 = *(_BYTE **)(LODWORD(x) + 296);
  v32 = v5;
  if ( !*v5 )
    return -86;
  if ( !v5[1] )
    return 0;
  if ( v5[32] )
    v7 = &vostok::render::lod_def_params[3 * (unsigned __int8)v5[16]];
  else
    v7 = (float *)(v5 + 20);
  v34 = v7;
  qmemcpy(&v35, (const void *)(LODWORD(x) + 264), sizeof(v35));
  vostok::math::aabb::modify((vostok::math::aabb *)&mat_vp[5].lines[0].elements[3], &v35);
  v8 = (float)((float)(v35.max.y + v35.min.y) * 0.5) - a4[1];
  v9 = (float)((float)(v35.max.x + v35.min.x) * 0.5) - *a4;
  v10 = (float)((float)(v35.max.z + v35.min.z) * 0.5) - a4[2];
  qmemcpy(&v36, (const void *)(LODWORD(mat_vp[9].k.x) + 264), sizeof(v36));
  qmemcpy(v50, &mat_vp[5].lines[0].elements[3], 0x40u);
  v29 = fsqrt((float)((float)(v9 * v9) + (float)(v8 * v8)) + (float)(v10 * v10));
  vostok::math::aabb::modify(v50, &v36);
  if ( v32[16] )
  {
    if ( v32[16] != 1 )
      return 0;
    vostok::math::aabb::vertices(v50, (int)&v36);
    v35.min.x = FLOAT_N1_0;
    v35.min.y = FLOAT_N1_0;
    v35.min.z = FLOAT_N1_0;
    v41 = view_pos[4].x;
    z = view_pos[2].z;
    y = view_pos[1].y;
    v30 = view_pos->x;
    v45 = view_pos[4].y;
    v48 = view_pos[3].x;
    v46 = view_pos[1].z;
    v39 = view_pos->y;
    v47 = view_pos[4].z;
    v49 = view_pos[3].y;
    v37 = view_pos[2].x;
    v43 = view_pos->z;
    v44 = view_pos[5].x;
    v40 = view_pos[3].z;
    v38 = view_pos[2].y;
    v11 = view_pos[1].x;
    v36.min.x = s_bm_current_air_resistance;
    v36.min.y = s_bm_current_air_resistance;
    v36.min.z = s_bm_current_air_resistance;
    v42 = v11;
    p_z = &v50[0].min.z;
    v13 = 8;
    do
    {
      v14 = *(p_z - 1);
      v15 = *(p_z - 2);
      v16 = (float)((float)((float)(y * v14) + (float)(z * *p_z)) + (float)(v30 * v15)) + v41;
      v17 = (float)((float)((float)(v46 * v14) + (float)(v48 * *p_z)) + (float)(v39 * v15)) + v45;
      v18 = (float)((float)((float)(v37 * v14) + (float)(v49 * *p_z)) + (float)(v43 * v15)) + v47;
      v19 = s_bm_current_air_resistance
          / (float)((float)((float)((float)(v38 * v14) + (float)(v40 * *p_z)) + (float)(v42 * v15)) + v44);
      v20 = v19 * v16;
      v21 = (float)(v19 * v16) <= v36.min.x;
      v22 = v19 * v17;
      v23 = v19 * v18;
      if ( v21 )
        v36.min.x = v20;
      if ( v22 <= v36.min.y )
        v36.min.y = v22;
      if ( v23 <= v36.min.z )
        v36.min.z = v23;
      v24 = v35.min.x;
      if ( v35.min.x <= v20 )
      {
        v24 = v20;
        v35.min.x = v20;
      }
      v25 = v35.min.y;
      if ( v35.min.y <= v22 )
      {
        v25 = v22;
        v35.min.y = v22;
      }
      if ( v35.min.z <= v23 )
        v35.min.z = v23;
      p_z += 3;
      --v13;
    }
    while ( v13 );
    v26 = v24 - v36.min.x;
    v27 = v25 - v36.min.y;
    if ( v26 <= v27 )
      v26 = v27;
    v28 = v26 * 0.5;
    if ( v34[2] <= v28 )
    {
      if ( v34[1] > v28 )
        return 2;
      return *v34 > v28;
    }
    return 3;
  }
  if ( *v34 > v29 )
    return 0;
  if ( v34[1] > v29 )
    return 1;
  result = 2;
  if ( v34[2] <= v29 )
    return 3;
  return result;
}
