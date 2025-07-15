vostok::math::float4x4 *__thiscall vostok::animation::legs_ik_solver::get_foot_fixed_transform(
        vostok::animation::legs_ik_solver *this,
        vostok::math::float4x4 *result,
        vostok::math::float4x4 *params,
        const vostok::math::float4x4 *hip_world_matrix,
        int matrices,
        float *delta_len,
        float *a8)
{
  int v8; // esi
  float *v10; // edi
  vostok::math::float4x4 *v11; // ecx
  float v12; // xmm5_4
  float v13; // xmm0_4
  float v14; // xmm5_4
  float v15; // xmm5_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm6_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm5_4
  float v24; // xmm0_4
  float v25; // xmm3_4
  float v26; // xmm2_4
  __m128i v27; // xmm1
  __m128i v28; // xmm0
  vostok::math::float4x4 *v29; // eax
  float v30; // xmm1_4
  vostok::math::float4x4 *v31; // edx
  char v32; // al
  float v33; // xmm2_4
  float v34; // xmm3_4
  double y_low; // st6
  vostok::math::float4x4 *v36; // edi
  double v37; // st6
  float y; // eax
  double v39; // st7
  double z_low; // st6
  float x; // eax
  float v42; // eax
  float v43; // eax
  int v44; // ecx
  float v45; // xmm3_4
  float *v46; // esi
  float v47; // xmm7_4
  float *v48; // edi
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm2_4
  int v52; // ecx
  float *v53; // eax
  float v54; // xmm4_4
  float v55; // xmm7_4
  float v56; // xmm6_4
  float v57; // xmm4_4
  float v58; // xmm5_4
  float v59; // xmm0_4
  float v60; // xmm5_4
  float v61; // xmm3_4
  float v62; // xmm2_4
  float v63; // ebx
  vostok::math::float4x4 *p_original_matrix; // esi
  vostok::math::float4x4 *v65; // eax
  float epsilon; // [esp+4h] [ebp-18Ch]
  float epsilona; // [esp+4h] [ebp-18Ch]
  float epsilonb; // [esp+4h] [ebp-18Ch]
  float epsilonc; // [esp+4h] [ebp-18Ch]
  vostok::math::float4x4 *v70; // [esp+8h] [ebp-188h]
  vostok::math::float4x4 v71; // [esp+18h] [ebp-178h] BYREF
  vostok::math::float4x4 resulta; // [esp+58h] [ebp-138h] BYREF
  vostok::math::float4x4 parent_matrix; // [esp+98h] [ebp-F8h] BYREF
  vostok::math::float4x4 original_matrix; // [esp+D8h] [ebp-B8h] BYREF
  vostok::math::float4x4 v75; // [esp+118h] [ebp-78h] BYREF
  int v76; // [esp+15Ch] [ebp-34h] BYREF
  float v77; // [esp+160h] [ebp-30h] BYREF
  float v78; // [esp+164h] [ebp-2Ch]
  float z; // [esp+168h] [ebp-28h]
  vostok::math::float3 v80; // [esp+16Ch] [ebp-24h] BYREF
  vostok::math::float3 v81; // [esp+178h] [ebp-18h] BYREF
  vostok::math::float3 v82; // [esp+184h] [ebp-Ch]
  float v83; // [esp+198h] [ebp+8h]
  float v84; // [esp+1A0h] [ebp+10h]
  float v85; // [esp+1A0h] [ebp+10h]

  v8 = LODWORD(result->i.x) + 272;
  v10 = delta_len;
  vostok::math::mul4x3(
    (const vostok::math::float4x4 *)matrices,
    (const vostok::math::float4x4 *)&delta_len[16
                                             * (LODWORD(hip_world_matrix->j.x)
                                              - (*(_DWORD *)(LODWORD(result->i.x) + 280) - v8) / 28)],
    &v71);
  vostok::math::mul4x3(
    &v71,
    (const vostok::math::float4x4 *)&v10[16 * (LODWORD(hip_world_matrix->i.w) - (*(_DWORD *)(v8 + 8) - v8) / 28)],
    &resulta);
  vostok::math::mul4x3(
    &resulta,
    (const vostok::math::float4x4 *)&v10[16 * (LODWORD(hip_world_matrix->i.z) - (*(_DWORD *)(v8 + 8) - v8) / 28)],
    &v75);
  vostok::math::mul4x3(
    &v75,
    (const vostok::math::float4x4 *)&v10[16 * (LODWORD(hip_world_matrix->i.x) - (*(_DWORD *)(v8 + 8) - v8) / 28)],
    &original_matrix);
  vostok::math::mul4x3(
    &original_matrix,
    (const vostok::math::float4x4 *)&v10[16 * (LODWORD(hip_world_matrix->i.y) - (*(_DWORD *)(v8 + 8) - v8) / 28)],
    &resulta);
  if ( vostok::math::float3_pod::is_similar(
         (vostok::math::float3_pod *)&resulta.lines[3],
         (const vostok::math::float3_pod *)&original_matrix.lines[3],
         0.0000099999997)
    || vostok::math::float3_pod::is_similar(
         (vostok::math::float3_pod *)&v75.lines[3],
         (const vostok::math::float3_pod *)&original_matrix.lines[3],
         0.0000099999997) )
  {
    p_original_matrix = &original_matrix;
    goto LABEL_23;
  }
  v12 = fsqrt(
          (float)((float)((float)(resulta.c.x - original_matrix.c.x) * (float)(resulta.c.x - original_matrix.c.x))
                + (float)((float)(resulta.c.z - original_matrix.c.z) * (float)(resulta.c.z - original_matrix.c.z)))
        + (float)((float)(resulta.c.y - original_matrix.c.y) * (float)(resulta.c.y - original_matrix.c.y)));
  v13 = (float)(resulta.c.x - original_matrix.c.x) * (float)(s_bm_current_air_resistance / v12);
  v14 = s_bm_current_air_resistance / v12;
  v82.x = v13;
  v82.z = v14 * (float)(resulta.c.z - original_matrix.c.z);
  v15 = v14 * (float)(resulta.c.y - original_matrix.c.y);
  v16 = s_bm_current_air_resistance
      / fsqrt(
          (float)((float)((float)(v75.c.x - original_matrix.c.x) * (float)(v75.c.x - original_matrix.c.x))
                + (float)((float)(v75.c.z - original_matrix.c.z) * (float)(v75.c.z - original_matrix.c.z)))
        + (float)((float)(v75.c.y - original_matrix.c.y) * (float)(v75.c.y - original_matrix.c.y)));
  v17 = (float)(v75.c.x - original_matrix.c.x) * v16;
  v18 = v16 * (float)(v75.c.z - original_matrix.c.z);
  v19 = v16 * (float)(v75.c.y - original_matrix.c.y);
  v20 = (float)(v19 * v82.z) - (float)(v18 * v15);
  v21 = (float)(v82.x * v18) - (float)(v17 * v82.z);
  v82.y = v15;
  v22 = (float)(v17 * v15) - (float)(v82.x * v19);
  v23 = fsqrt((float)((float)(v20 * v20) + (float)(v22 * v22)) + (float)(v21 * v21));
  v80.x = v20 * (float)(s_bm_current_air_resistance / v23);
  v80.y = (float)(s_bm_current_air_resistance / v23) * v21;
  v80.z = (float)(s_bm_current_air_resistance / v23) * v22;
  vostok::math::float4x4::identity(v11, &parent_matrix);
  v24 = (float)(v80.y * v82.z) - (float)(v80.z * v82.y);
  *(_QWORD *)&parent_matrix.i.x = *(_QWORD *)&v80.x;
  parent_matrix.i.z = v80.z;
  v25 = (float)(v80.x * v82.y) - (float)(v82.x * v80.y);
  v26 = (float)(v82.x * v80.z) - (float)(v80.x * v82.z);
  *(_QWORD *)&parent_matrix.lines[1].x = *(_QWORD *)&v82.x;
  v27 = (__m128i)LODWORD(s_bm_current_air_resistance);
  parent_matrix.j.z = v82.z;
  *(float *)v27.m128i_i32 = s_bm_current_air_resistance
                          / fsqrt((float)((float)(v24 * v24) + (float)(v25 * v25)) + (float)(v26 * v26));
  v77 = v24 * *(float *)v27.m128i_i32;
  v28 = v27;
  *(float *)v28.m128i_i32 = *(float *)v27.m128i_i32 * v26;
  v78 = *(float *)v27.m128i_i32 * v26;
  z = *(float *)v27.m128i_i32 * v25;
  parent_matrix.k.x = v77;
  parent_matrix.k.y = *(float *)v27.m128i_i32 * v26;
  parent_matrix.k.z = *(float *)v27.m128i_i32 * v25;
  v29 = vostok::math::create_rotation(&v80, (int)&resulta, v28, 0.52359879);
  vostok::math::mul4x3(v29, &parent_matrix, &v75);
  v30 = (float)((float)((float)(v75.i.x * 0.0) + (float)(v75.j.x * 0.082000002)) + (float)(v75.k.x * 0.050000001))
      + original_matrix.c.x;
  qmemcpy(v31, &v75, sizeof(vostok::math::float4x4));
  v82.x = v30;
  v32 = LOBYTE(hip_world_matrix->lines[2].elements[3]);
  v33 = (float)((float)((float)(v75.j.y * 0.082000002) + (float)(v75.k.y * 0.050000001)) + (float)(v75.i.y * 0.0))
      + original_matrix.c.y;
  v34 = (float)((float)((float)(v75.j.z * 0.082000002) + (float)(v75.k.z * 0.050000001)) + (float)(v75.i.z * 0.0))
      + original_matrix.c.z;
  v82.y = v33;
  v82.z = v34;
  parent_matrix.c.x = v30;
  parent_matrix.c.y = v33;
  parent_matrix.c.z = v34;
  *(_QWORD *)&v80.x = __PAIR64__(LODWORD(FLOAT_0_12), LODWORD(s_ik_foot_capsule_radius_value));
  v80.z = s_ik_foot_capsule_radius_value;
  matrices = -2147483448;
  v76 = -2147432448;
  v84 = 0.0;
  if ( v32 )
  {
    if ( BYTE1(hip_world_matrix->lines[2].elements[3]) )
    {
      y_low = (double)LODWORD(hip_world_matrix->j.y);
      v77 = (float)(dist_to_test * 0.0) + v30;
      v78 = dist_to_test + v33;
      z = (float)(dist_to_test * 0.0) + v34;
      v82.x = v30 - (float)(dist_to_test * 0.0);
      v82.y = v33 - dist_to_test;
      v82.z = v34 - (float)(dist_to_test * 0.0);
      v81.x = v82.x;
      v81.y = v33 - dist_to_test;
      v81.z = v82.z;
      v36 = result;
      epsilon = 0.001 * y_low;
      v84 = 1.0 - ((double (__stdcall *)(_DWORD))*(_DWORD *)LODWORD(result[2].i.y))(LODWORD(epsilon));
      goto LABEL_12;
    }
    v37 = (double)LODWORD(hip_world_matrix->j.y);
    v81.z = (float)(dist_to_test * 0.0) + v34;
    v77 = (float)(dist_to_test * 0.0) + v30;
    v78 = dist_to_test + v33;
    z = v81.z;
    v82.x = v30 - (float)(dist_to_test * 0.0);
    v82.y = v33 - dist_to_test;
    v82.z = v34 - (float)(dist_to_test * 0.0);
    v81.x = v82.x;
    v81.y = v33 - dist_to_test;
    y = result[2].i.y;
    v81.z = v82.z;
    epsilona = 0.001 * v37;
    v39 = 1.0 - ((double (__stdcall *)(_DWORD))*(_DWORD *)LODWORD(y))(LODWORD(epsilona));
  }
  else
  {
    if ( !BYTE1(hip_world_matrix->lines[2].elements[3]) )
    {
      v77 = (float)(dist_to_test * 0.0) + v30;
      v78 = dist_to_test + v33;
      z = (float)(dist_to_test * 0.0) + v34;
      v81 = v82;
      BYTE1(v76) = 100;
      LOBYTE(matrices) = 100;
      goto LABEL_11;
    }
    z_low = (double)LODWORD(hip_world_matrix->j.z);
    v81.z = (float)(dist_to_test * 0.0) + v34;
    v77 = (float)(dist_to_test * 0.0) + v30;
    v78 = dist_to_test + v33;
    z = v81.z;
    v82.x = v30 - (float)(dist_to_test * 0.0);
    v82.y = v33 - dist_to_test;
    v82.z = v34 - (float)(dist_to_test * 0.0);
    v81.x = v82.x;
    v81.y = v33 - dist_to_test;
    x = result[2].j.x;
    v81.z = v82.z;
    v39 = 0.001 * z_low;
    epsilonb = 0.001 * z_low;
    (*(void (__stdcall **)(_DWORD))LODWORD(x))(LODWORD(epsilonb));
  }
  v84 = v39;
LABEL_11:
  v36 = result;
LABEL_12:
  vostok::math::get_relative_matrix(&resulta, &original_matrix, &parent_matrix);
  if ( s_ik_legs_debug_draw_value )
  {
    v42 = v36->i.z;
    if ( v42 != 0.0 )
      vostok::render::debug::renderer::draw_line_capsule(
        &v80,
        (vostok::render::debug::renderer *)(LODWORD(v42) + 4),
        *(vostok::render::debug::renderer **)LODWORD(v42),
        (vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)(LODWORD(v42) + 4),
        &parent_matrix,
        (vostok::math::color *)&matrices,
        0);
  }
  vostok::physics::bullet_physics_world::adjust_foot_transform(
    (vostok::console_commands::cc_bool *)&v77,
    &v81,
    *(vostok::physics::bullet_physics_world **)(LODWORD(v36->i.w) + 8),
    &v80,
    v84,
    &parent_matrix,
    v70);
  if ( s_ik_legs_debug_draw_value )
  {
    v43 = v36->i.z;
    if ( v43 != 0.0 )
      vostok::render::debug::renderer::draw_solid_capsule(
        (vostok::render::debug::renderer *)(LODWORD(v43) + 4),
        (bool)v36,
        *(vostok::render::debug::renderer **)LODWORD(v43),
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(LODWORD(v43) + 4),
        &parent_matrix,
        &v80,
        (const vostok::math::color *)&v76);
  }
  vostok::math::mul4x3(&parent_matrix, &resulta, &v75);
  v44 = LODWORD(v36->i.x) + 272;
  v45 = fsqrt(
          (float)((float)((float)(v75.c.x - v71.c.x) * (float)(v75.c.x - v71.c.x))
                + (float)((float)(v75.c.z - v71.c.z) * (float)(v75.c.z - v71.c.z)))
        + (float)((float)(v75.c.y - v71.c.y) * (float)(v75.c.y - v71.c.y)));
  v46 = &delta_len[16 * (LODWORD(hip_world_matrix->i.w) - (*(_DWORD *)(LODWORD(v36->i.x) + 280) - v44) / 28) + 12];
  v47 = *v46 * *v46;
  v48 = &delta_len[16 * (LODWORD(hip_world_matrix->i.z) - (*(_DWORD *)(LODWORD(v36->i.x) + 280) - v44) / 28) + 12];
  v49 = v48[2];
  v50 = *v48;
  v51 = v48[1];
  v52 = (LODWORD(hip_world_matrix->i.x) - (*(_DWORD *)(v44 + 8) - v44) / 28) << 6;
  v53 = (float *)((char *)delta_len + v52 + 48);
  v54 = *(float *)((char *)delta_len + v52 + 52);
  v85 = *v53;
  delta_len = *((float **)v46 + 1);
  v55 = (float)(v47 + (float)(v46[2] * v46[2])) + (float)(*(float *)&delta_len * *(float *)&delta_len);
  matrices = LODWORD(v54);
  v56 = (float)((float)(v85 * v85) + (float)(v53[2] * v53[2])) + (float)(v54 * v54);
  v57 = v45 * v45;
  v58 = (float)(fsqrt(v55) + fsqrt(v56)) + fsqrt((float)((float)(v49 * v49) + (float)(v51 * v51)) + (float)(v50 * v50));
  v59 = original_matrix.c.x - v71.c.x;
  v60 = v58 - v45;
  v61 = (float)(original_matrix.c.z - v71.c.z) * (float)(original_matrix.c.z - v71.c.z);
  v62 = (float)(original_matrix.c.y - v71.c.y) * (float)(original_matrix.c.y - v71.c.y);
  *a8 = v60;
  if ( v57 > (float)((float)(v61 + v62) + (float)(v59 * v59)) )
  {
    v63 = hip_world_matrix->j.y;
    if ( v63 != 0.0 )
    {
      epsilonc = (double)LODWORD(v63) * 0.001;
      v83 = ((double (__stdcall *)(_DWORD))*(_DWORD *)LODWORD(result[2].i.y))(LODWORD(epsilonc));
      v77 = (float)(v75.c.x * (float)(s_bm_current_air_resistance - v83)) + (float)(v83 * original_matrix.c.x);
      v78 = (float)((float)(s_bm_current_air_resistance - v83) * v75.c.y) + (float)(v83 * original_matrix.c.y);
      z = (float)((float)(s_bm_current_air_resistance - v83) * v75.c.z) + (float)(v83 * original_matrix.c.z);
      v75.c.x = v77;
      v75.c.y = v78;
      v75.c.z = z;
    }
  }
  p_original_matrix = &v75;
LABEL_23:
  v65 = params;
  qmemcpy(params, p_original_matrix, sizeof(vostok::math::float4x4));
  return v65;
}
