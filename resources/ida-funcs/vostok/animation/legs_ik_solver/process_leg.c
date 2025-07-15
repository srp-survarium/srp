void __thiscall vostok::animation::legs_ik_solver::process_leg(
        vostok::animation::legs_ik_solver *this,
        vostok::animation::legs_ik_solver::leg_params *params,
        const vostok::math::float4x4 *target_foot_obj_matrix,
        vostok::math::float3_pod *hip_obj_matrix,
        vostok::math::float4x4 *matrices,
        const vostok::math::float4x4 *transform,
        const vostok::math::float4x4 *a7)
{
  unsigned int v7; // ecx
  int v8; // edi
  signed int v9; // eax
  int v10; // ecx
  const vostok::math::float4x4 *v11; // esi
  const vostok::math::float4x4 *v12; // edx
  float v13; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  const vostok::math::float4x4 *v16; // edi
  float x; // xmm2_4
  float y; // xmm1_4
  float z; // xmm0_4
  vostok::math::float3_pod *v20; // esi
  unsigned int leg_bone_index; // edi
  const vostok::math::float4x4 *v22; // ecx
  const vostok::math::float4x4 *v23; // ecx
  const vostok::math::float4x4 *v24; // ecx
  vostok::animation::legs_ik_drawer *v25; // ecx
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm5_4
  float v30; // xmm4_4
  float v31; // xmm1_4
  float v32; // xmm4_4
  float v33; // xmm1_4
  float v34; // xmm1_4
  float v35; // xmm1_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm5_4
  float v39; // xmm3_4
  __m128i x_low; // xmm0
  float v41; // xmm2_4
  float v42; // xmm1_4
  float v43; // xmm3_4
  float v44; // xmm3_4
  float v45; // xmm5_4
  float v46; // xmm1_4
  float v47; // xmm5_4
  float v48; // xmm3_4
  float v49; // xmm1_4
  float v50; // xmm0_4
  float v51; // xmm2_4
  unsigned int v52; // esi
  const vostok::math::float4x4 *v53; // ecx
  const vostok::math::float4x4 *v54; // ecx
  const vostok::math::float4x4 *v55; // ecx
  vostok::animation::legs_ik_drawer *v56; // ecx
  float v57; // xmm1_4
  float v58; // xmm0_4
  float v59; // xmm2_4
  unsigned int v60; // eax
  float v61; // xmm4_4
  unsigned int v62; // esi
  float v63; // xmm1_4
  float v64; // xmm0_4
  float v65; // xmm1_4
  vostok::math::float4x4 *v66; // eax
  vostok::math::float4x4 *relative_matrix; // esi
  vostok::math::float4x4 *v68; // esi
  vostok::math::float4x4 *v69; // eax
  vostok::math::float3_pod *v70; // ebx
  vostok::math::float4x4 *v71; // eax
  const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *v72; // [esp-Ch] [ebp-270h]
  float v73; // [esp+4h] [ebp-260h]
  bool v74; // [esp+4h] [ebp-260h]
  vostok::math::float3_pod v75; // [esp+14h] [ebp-250h] BYREF
  vostok::math::color v76; // [esp+20h] [ebp-244h] BYREF
  vostok::math::color up_leg_color; // [esp+24h] [ebp-240h] BYREF
  vostok::math::float4x4 *v78; // [esp+28h] [ebp-23Ch]
  vostok::math::color foot_color; // [esp+2Ch] [ebp-238h] BYREF
  vostok::math::float4x4 *v80; // [esp+30h] [ebp-234h]
  vostok::math::float3_pod v81; // [esp+34h] [ebp-230h] BYREF
  vostok::math::color v82; // [esp+40h] [ebp-224h] BYREF
  float v83; // [esp+44h] [ebp-220h]
  vostok::math::color knee_color; // [esp+48h] [ebp-21Ch] BYREF
  vostok::math::float3 target_dir; // [esp+4Ch] [ebp-218h] BYREF
  vostok::math::float4x4 *v86; // [esp+58h] [ebp-20Ch]
  vostok::math::float4x4 v87; // [esp+5Ch] [ebp-208h] BYREF
  vostok::math::float4x4 *v88; // [esp+9Ch] [ebp-1C8h]
  vostok::math::color leg_color; // [esp+A0h] [ebp-1C4h] BYREF
  vostok::math::float4x4 original_matrix; // [esp+A4h] [ebp-1C0h] BYREF
  vostok::math::float4x4 v91; // [esp+E4h] [ebp-180h] BYREF
  vostok::math::float4x4 up_leg; // [esp+124h] [ebp-140h] BYREF
  vostok::math::float4x4 v93; // [esp+164h] [ebp-100h] BYREF
  vostok::math::float4x4 foot; // [esp+1A4h] [ebp-C0h] BYREF
  vostok::math::float4x4 knee; // [esp+1E4h] [ebp-80h] BYREF
  vostok::math::float4x4 leg; // [esp+224h] [ebp-40h] BYREF

  v7 = params->foot_bone_index + 272;
  v8 = (LODWORD(target_foot_obj_matrix->i.x) - (int)(*(_DWORD *)(params->foot_bone_index + 280) - v7) / 28) << 6;
  v9 = *(_DWORD *)(params->foot_bone_index + 280) - v7;
  v78 = (vostok::math::float4x4 *)(LODWORD(target_foot_obj_matrix->i.z) - v9 / 28);
  v10 = LODWORD(target_foot_obj_matrix->j.x) - (int)(*(_DWORD *)(v7 + 8) - v7) / 28;
  v11 = &transform[LODWORD(target_foot_obj_matrix->i.w) - v9 / 28];
  v12 = &transform[(_DWORD)v78];
  v13 = v12->c.y * v12->c.y;
  v14 = v12->c.z * v12->c.z;
  *(float *)&v82.m_value = fsqrt(
                             (float)((float)(v11->c.y * v11->c.y) + (float)(v11->c.x * v11->c.x))
                           + (float)(v11->c.z * v11->c.z));
  v15 = v13 + v14;
  v16 = (const vostok::math::float4x4 *)((char *)transform + v8);
  x = v16->c.x;
  y = v16->c.y;
  v83 = fsqrt(v15 + (float)(v12->c.x * v12->c.x));
  z = v16->c.z;
  v86 = (vostok::math::float4x4 *)v11;
  v80 = (vostok::math::float4x4 *)v12;
  v78 = (vostok::math::float4x4 *)v16;
  *(float *)&v76.m_value = fsqrt((float)((float)(x * x) + (float)(y * y)) + (float)(z * z));
  v88 = (vostok::math::float4x4 *)&transform[v10];
  vostok::math::mul4x3(matrices, v88, &original_matrix);
  vostok::math::mul4x3(&original_matrix, v11, &v91);
  vostok::math::mul4x3(&v91, v80, &v93);
  vostok::math::mul4x3(&v93, v16, &v87);
  v20 = hip_obj_matrix;
  if ( !vostok::math::float3_pod::is_similar((vostok::math::float3_pod *)&v87, hip_obj_matrix, 0.001)
    || !vostok::math::float3_pod::is_similar(
          (vostok::math::float3_pod *)&v87.lines[1],
          (vostok::math::float3_pod *)((char *)hip_obj_matrix + 16),
          0.001)
    || !vostok::math::float3_pod::is_similar(
          (vostok::math::float3_pod *)&v87.lines[2],
          (vostok::math::float3_pod *)((char *)hip_obj_matrix + 32),
          0.001)
    || !vostok::math::float3_pod::is_similar((vostok::math::float3_pod *)&v87.lines[3], hip_obj_matrix + 4, 0.001) )
  {
    if ( s_ik_legs_debug_draw_value )
    {
      leg_bone_index = params->leg_bone_index;
      if ( leg_bone_index )
      {
        *(float *)&foot_color.m_value = -3.0358524e38;
        leg_color = (vostok::math::color)-10223616;
        knee_color = (vostok::math::color)-16751616;
        *(float *)&up_leg_color.m_value = -1.7014321e38;
        vostok::math::mul4x3(a7, &v87, &foot);
        vostok::math::mul4x3(v22, &v93, &leg);
        vostok::math::mul4x3(v23, &v91, &knee);
        vostok::math::mul4x3(v24, &original_matrix, &up_leg);
        vostok::animation::legs_ik_drawer::draw_leg(
          v25,
          leg_bone_index,
          (vostok::math::aabb *)&up_leg,
          (vostok::math::aabb *)&knee,
          (vostok::math::aabb *)&leg,
          (vostok::math::aabb *)&foot,
          &up_leg_color,
          &knee_color,
          &leg_color,
          &foot_color,
          v73);
        v20 = hip_obj_matrix;
      }
    }
    v26 = v20[4].y - original_matrix.c.y;
    v27 = v20[4].x - original_matrix.c.x;
    v28 = v20[4].z - original_matrix.c.z;
    v29 = fsqrt((float)((float)(v28 * v28) + (float)(v26 * v26)) + (float)(v27 * v27));
    target_dir.x = v27 * (float)(s_bm_current_air_resistance / v29);
    v30 = (float)(v20[4].x - original_matrix.c.x) * (float)(v20[4].x - original_matrix.c.x);
    target_dir.y = v26 * (float)(s_bm_current_air_resistance / v29);
    v31 = v20[4].y - original_matrix.c.y;
    target_dir.z = v28 * (float)(s_bm_current_air_resistance / v29);
    *(float *)&foot_color.m_value = fsqrt(
                                      (float)(v30
                                            + (float)((float)(v20[4].z - original_matrix.c.z)
                                                    * (float)(v20[4].z - original_matrix.c.z)))
                                    + (float)(v31 * v31));
    v32 = s_bm_current_air_resistance
        / fsqrt(
            (float)((float)((float)(v93.c.z - v87.c.z) * (float)(v93.c.z - v87.c.z))
                  + (float)((float)(v93.c.y - v87.c.y) * (float)(v93.c.y - v87.c.y)))
          + (float)((float)(v93.c.x - v87.c.x) * (float)(v93.c.x - v87.c.x)));
    v33 = fsqrt(
            (float)((float)((float)(original_matrix.c.z - v91.c.z) * (float)(original_matrix.c.z - v91.c.z))
                  + (float)((float)(original_matrix.c.y - v91.c.y) * (float)(original_matrix.c.y - v91.c.y)))
          + (float)((float)(original_matrix.c.x - v91.c.x) * (float)(original_matrix.c.x - v91.c.x)));
    v34 = (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v93.c.x - v87.c.x) * v32) ^ _mask__NegFloat_)
                        * (float)((float)(original_matrix.c.x - v91.c.x) * (float)(s_bm_current_air_resistance / v33)))
                + (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v93.c.z - v87.c.z) * v32) ^ _mask__NegFloat_)
                        * (float)((float)(original_matrix.c.z - v91.c.z) * (float)(s_bm_current_air_resistance / v33))))
        + (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v93.c.y - v87.c.y) * v32) ^ _mask__NegFloat_)
                * (float)((float)(original_matrix.c.y - v91.c.y) * (float)(s_bm_current_air_resistance / v33)));
    *(float *)&up_leg_color.m_value = fabs(v34 - s_bm_current_air_resistance);
    if ( *(float *)&up_leg_color.m_value >= 0.0000099999997 )
      v35 = fsqrt((float)((float)(v83 * v83) * 0.5) / (float)(s_bm_current_air_resistance - v34));
    else
      v35 = v83 * 0.5;
    v36 = (float)((float)((float)(*(float *)&foot_color.m_value * *(float *)&foot_color.m_value)
                        + (float)((float)(v35 + *(float *)&v82.m_value) * (float)(v35 + *(float *)&v82.m_value)))
                - (float)((float)(v35 + *(float *)&v76.m_value) * (float)(v35 + *(float *)&v76.m_value)))
        / (float)((float)((float)(v35 + *(float *)&v82.m_value) * *(float *)&foot_color.m_value) * 2.0);
    v37 = FLOAT_N1_0;
    if ( v36 > -1.0 )
    {
      if ( s_bm_current_air_resistance < v36 )
        v37 = s_bm_current_air_resistance;
      else
        v37 = v36;
    }
    __libm_sse2_acos();
    *(float *)&v76.m_value = v37;
    v38 = fsqrt(
            (float)((float)((float)(v91.c.x - original_matrix.c.x) * (float)(v91.c.x - original_matrix.c.x))
                  + (float)((float)(v91.c.z - original_matrix.c.z) * (float)(v91.c.z - original_matrix.c.z)))
          + (float)((float)(v91.c.y - original_matrix.c.y) * (float)(v91.c.y - original_matrix.c.y)));
    v81.x = (float)(v91.c.x - original_matrix.c.x) * (float)(s_bm_current_air_resistance / v38);
    x_low = (__m128i)LODWORD(v87.c.x);
    v81.z = (float)(v91.c.z - original_matrix.c.z) * (float)(s_bm_current_air_resistance / v38);
    v81.y = (float)(v91.c.y - original_matrix.c.y) * (float)(s_bm_current_air_resistance / v38);
    v39 = s_bm_current_air_resistance
        / fsqrt(
            (float)((float)((float)(v87.c.x - original_matrix.c.x) * (float)(v87.c.x - original_matrix.c.x))
                  + (float)((float)(v87.c.z - original_matrix.c.z) * (float)(v87.c.z - original_matrix.c.z)))
          + (float)((float)(v87.c.y - original_matrix.c.y) * (float)(v87.c.y - original_matrix.c.y)));
    *(float *)x_low.m128i_i32 = (float)(v87.c.x - original_matrix.c.x) * v39;
    v75.x = *(float *)x_low.m128i_i32;
    v75.y = (float)(v87.c.y - original_matrix.c.y) * v39;
    v75.z = (float)(v87.c.z - original_matrix.c.z) * v39;
    if ( !vostok::math::float3_pod::is_similar(&v81, &v75, 0.001) )
    {
      x_low = (__m128i)LODWORD(v75.z);
      *(float *)x_low.m128i_i32 = (float)(v75.z * v81.y) - (float)(v75.y * v81.z);
      v41 = (float)(v81.x * v75.y) - (float)(v75.x * v81.y);
      v42 = (float)(v75.x * v81.z) - (float)(v81.x * v75.z);
      v43 = s_bm_current_air_resistance
          / fsqrt(
              (float)((float)(*(float *)x_low.m128i_i32 * *(float *)x_low.m128i_i32) + (float)(v41 * v41))
            + (float)(v42 * v42));
      *(float *)x_low.m128i_i32 = *(float *)x_low.m128i_i32 * v43;
      LODWORD(v75.x) = x_low.m128i_i32[0];
      v75.y = v42 * v43;
      v75.z = v41 * v43;
      LODWORD(target_foot_obj_matrix->j.w) = x_low.m128i_i32[0];
      *(_QWORD *)&target_foot_obj_matrix->lines[2].x = *(_QWORD *)&v75.elements[1];
    }
    vostok::math::create_rotation(
      (const vostok::math::float3 *)&target_foot_obj_matrix->lines[1].elements[3],
      (int)&v87,
      x_low,
      *(float *)&v76.m_value);
    v75.x = (float)((float)(target_dir.x * v87.i.x) + (float)(v87.j.x * target_dir.y)) + (float)(v87.k.x * target_dir.z);
    v75.y = (float)((float)(target_dir.x * v87.i.y) + (float)(v87.k.y * target_dir.z)) + (float)(v87.j.y * target_dir.y);
    v75.z = (float)((float)(target_dir.x * v87.i.z) + (float)(v87.k.z * target_dir.z)) + (float)(v87.j.z * target_dir.y);
    vostok::math::get_rotation_matrix((const vostok::math::float3 *)&v81, (const vostok::math::float3 *)&v75, &up_leg);
    vostok::math::change_matrix_orientation(&up_leg, &original_matrix);
    vostok::math::mul4x3(&original_matrix, v86, &v87);
    qmemcpy(&v91, &v87, sizeof(v91));
    vostok::math::mul4x3(&v91, v80, &foot);
    v44 = s_bm_current_air_resistance
        / fsqrt(
            (float)((float)((float)(foot.c.z - v87.c.z) * (float)(foot.c.z - v87.c.z))
                  + (float)((float)(foot.c.y - v87.c.y) * (float)(foot.c.y - v87.c.y)))
          + (float)((float)(foot.c.x - v87.c.x) * (float)(foot.c.x - v87.c.x)));
    v75.x = v44 * (float)(foot.c.x - v87.c.x);
    v75.y = (float)(foot.c.y - v87.c.y) * v44;
    v75.z = (float)(foot.c.z - v87.c.z) * v44;
    vostok::math::get_rotation_matrix((const vostok::math::float3 *)&v75, &target_dir, &up_leg);
    vostok::math::change_matrix_orientation(&up_leg, &v91);
    vostok::math::mul4x3(&v91, v80, &v87);
    qmemcpy(&v93, &v87, sizeof(v93));
    vostok::math::mul4x3(&v93, v78, &foot);
    v45 = fsqrt(
            (float)((float)((float)(foot.c.x - v87.c.x) * (float)(foot.c.x - v87.c.x))
                  + (float)((float)(foot.c.z - v87.c.z) * (float)(foot.c.z - v87.c.z)))
          + (float)((float)(foot.c.y - v87.c.y) * (float)(foot.c.y - v87.c.y)));
    v46 = (float)(foot.c.z - v87.c.z) * (float)(s_bm_current_air_resistance / v45);
    v47 = s_bm_current_air_resistance / v45;
    v48 = hip_obj_matrix[4].x - v87.c.x;
    v81.z = v46;
    v49 = hip_obj_matrix[4].z - v87.c.z;
    v81.x = v47 * (float)(foot.c.x - v87.c.x);
    v81.y = (float)(foot.c.y - v87.c.y) * v47;
    v50 = hip_obj_matrix[4].y - v87.c.y;
    v51 = s_bm_current_air_resistance / fsqrt((float)((float)(v48 * v48) + (float)(v49 * v49)) + (float)(v50 * v50));
    v75.x = v51 * v48;
    v75.y = v50 * v51;
    v75.z = v49 * v51;
    vostok::math::get_rotation_matrix((const vostok::math::float3 *)&v81, (const vostok::math::float3 *)&v75, &up_leg);
    vostok::math::change_matrix_orientation(&up_leg, &v93);
    if ( s_ik_legs_debug_draw_value )
    {
      v52 = params->leg_bone_index;
      if ( v52 )
      {
        *(float *)&v76.m_value = NAN;
        *(float *)&v82.m_value = NAN;
        *(float *)&up_leg_color.m_value = -1.7146522e38;
        knee_color = (vostok::math::color)-16776961;
        vostok::math::mul4x3(a7, (const vostok::math::float4x4 *)hip_obj_matrix, &up_leg);
        vostok::math::mul4x3(v53, &v93, &knee);
        vostok::math::mul4x3(v54, &v91, &leg);
        vostok::math::mul4x3(v55, &original_matrix, &foot);
        vostok::animation::legs_ik_drawer::draw_leg(
          v56,
          v52,
          (vostok::math::aabb *)&foot,
          (vostok::math::aabb *)&leg,
          (vostok::math::aabb *)&knee,
          (vostok::math::aabb *)&up_leg,
          &knee_color,
          &up_leg_color,
          &v82,
          &v76,
          v73);
        if ( LOBYTE(target_foot_obj_matrix->lines[2].elements[3]) )
        {
          v57 = hip_obj_matrix[4].y;
          v58 = hip_obj_matrix[4].z;
          v59 = hip_obj_matrix[4].x;
          v60 = params->leg_bone_index;
          v61 = a7->j.y;
          v75.x = (float)((float)((float)(a7->j.x * v57) + (float)(a7->k.x * v58)) + (float)(v59 * a7->i.x)) + a7->c.x;
          v75.y = (float)((float)((float)(a7->i.y * v59) + (float)(v61 * v57)) + (float)(a7->k.y * v58)) + a7->c.y;
          v72 = *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)v60;
          v75.z = (float)((float)((float)(a7->i.z * v59) + (float)(a7->j.z * v57)) + (float)(a7->k.z * v58)) + a7->c.z;
          *(float *)&v76.m_value = -1.7014636e38;
          vostok::render::debug::renderer::draw_cross(
            (vostok::render::debug::renderer *)(v60 + 4),
            v72,
            (vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)(v60 + 4),
            &v75.x,
            &v76,
            v74);
        }
        if ( BYTE1(target_foot_obj_matrix->lines[2].elements[3]) )
        {
          v62 = params->foot_bone_index + 272;
          v76 = (vostok::math::color)((signed int)(*(_DWORD *)(28 * (LODWORD(target_foot_obj_matrix->i.x) + 10)
                                                             + params->foot_bone_index)
                                                 - params->foot_bone_index
                                                 - 272)
                                    / 28);
          vostok::math::mul4x3(
            (const vostok::math::float4x4 *)hip_obj_matrix,
            &transform[*(_DWORD *)&v76 - (int)(*(_DWORD *)(v62 + 8) - v62) / 28],
            &v87);
          v63 = a7->j.y * v87.c.y;
          v75.x = (float)((float)((float)(a7->j.x * v87.c.y) + (float)(a7->k.x * v87.c.z)) + (float)(a7->i.x * v87.c.x))
                + a7->c.x;
          v64 = (float)((float)((float)(a7->i.y * v87.c.x) + v63) + (float)(a7->k.y * v87.c.z)) + a7->c.y;
          v65 = a7->j.z * v87.c.y;
          v75.y = v64;
          v75.z = (float)((float)((float)(a7->i.z * v87.c.x) + v65) + (float)(a7->k.z * v87.c.z)) + a7->c.z;
          v66 = vostok::math::create_translation((const vostok::math::float3 *)&v75, &up_leg);
          vostok::render::debug::renderer::draw_origin(
            (vostok::render::debug::renderer *)params->leg_bone_index,
            *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)params->leg_bone_index,
            (vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)(params->leg_bone_index + 4),
            (vostok::math::aabb *)v66,
            s_ik_foot_capsule_radius_value);
        }
      }
    }
    relative_matrix = vostok::math::get_relative_matrix(&up_leg, &original_matrix, matrices);
    qmemcpy(v88, relative_matrix, sizeof(vostok::math::float4x4));
    v68 = vostok::math::get_relative_matrix(&up_leg, &v91, &original_matrix);
    qmemcpy(v86, v68, sizeof(vostok::math::float4x4));
    v69 = vostok::math::get_relative_matrix(&up_leg, &v93, &v91);
    v70 = (vostok::math::float3_pod *)v78;
    qmemcpy(v80, v69, sizeof(vostok::math::float4x4));
    v70 += 4;
    v75 = *v70;
    v71 = vostok::math::get_relative_matrix(&up_leg, (const vostok::math::float4x4 *)hip_obj_matrix, &v93);
    qmemcpy(v78, v71, sizeof(vostok::math::float4x4));
    *v70 = v75;
  }
}
