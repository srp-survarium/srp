void __thiscall vostok::animation::hand_to_weapon_ik_solver::process_hand(
        vostok::animation::hand_to_weapon_ik_solver *this,
        const vostok::animation::hand_to_weapon_ik_solver::hand *h,
        const vostok::math::float4x4 *target_hand_transform,
        vostok::math::float4x4 *matrices,
        vostok::math::float4x4 *a5)
{
  int v5; // esi
  float v6; // ecx
  int v7; // eax
  float y; // xmm3_4
  float x; // xmm2_4
  float z; // xmm1_4
  float v12; // xmm0_4
  float *p_x; // ecx
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  const vostok::animation::skeleton *v20; // esi
  float *v21; // eax
  float v22; // xmm4_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm5_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm1_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  __m128i x_low; // xmm0
  float v36; // xmm4_4
  unsigned int v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm3_4
  float v40; // xmm3_4
  float *v41; // eax
  float v42; // xmm4_4
  float v43; // xmm3_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm5_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm3_4
  float *v50; // edi
  float v51; // xmm3_4
  float v52; // xmm2_4
  float v53; // xmm4_4
  float v54; // xmm0_4
  float v55; // xmm2_4
  vostok::math::float4x4 *relative_matrix; // esi
  vostok::math::float4x4 *v57; // eax
  vostok::math::float4x4 *bone_matrix_in_object_space; // eax
  vostok::math::float4x4 *v59; // eax
  vostok::math::float4x4 result; // [esp+14h] [ebp-F8h] BYREF
  vostok::math::float4x4 bone; // [esp+54h] [ebp-B8h] BYREF
  int v62; // [esp+94h] [ebp-78h]
  float v63; // [esp+98h] [ebp-74h]
  float v64; // [esp+9Ch] [ebp-70h]
  vostok::math::float4x4 *v65; // [esp+A0h] [ebp-6Ch]
  vostok::math::float4x4 v66; // [esp+A4h] [ebp-68h] BYREF
  vostok::math::float4x4 *v67; // [esp+E4h] [ebp-28h]
  vostok::math::float4x4 *matricesa; // [esp+E8h] [ebp-24h]
  float v69; // [esp+ECh] [ebp-20h]
  int v70; // [esp+F0h] [ebp-1Ch]
  vostok::math::float3 v71; // [esp+F4h] [ebp-18h] BYREF
  vostok::math::float3 v72; // [esp+100h] [ebp-Ch] BYREF
  float original_matrix; // [esp+11Ch] [ebp+10h]
  float original_matrixa; // [esp+11Ch] [ebp+10h]

  v5 = *(_DWORD *)&h[2].locators[0][0].m_name[12];
  v6 = *(float *)(28 * LODWORD(target_hand_transform[9].j.w) + v5 + 276);
  matricesa = *(vostok::math::float4x4 **)(LODWORD(v6) + 4);
  v7 = (*(_DWORD *)(v5 + 280) - (v5 + 272)) / 28;
  *(float *)&v67 = v6;
  v62 = ((int)&matricesa[-4] - v5 - 16) / 28 - (*(_DWORD *)(v5 + 280) - (v5 + 272)) / 28;
  y = a5[LODWORD(target_hand_transform[9].k.x)].c.y;
  x = a5[LODWORD(target_hand_transform[9].k.x)].c.x;
  z = a5[LODWORD(target_hand_transform[9].k.x)].c.z;
  v12 = fsqrt((float)((float)(y * y) + (float)(x * x)) + (float)(z * z));
  p_x = &a5[(LODWORD(v6) - v5 - 272) / 28 - v7].i.x;
  v14 = p_x[13];
  v15 = p_x[14];
  v69 = v12;
  v16 = p_x[12];
  v65 = (vostok::math::float4x4 *)p_x;
  original_matrix = fsqrt((float)((float)(v14 * v14) + (float)(v15 * v15)) + (float)(v16 * v16));
  vostok::animation::get_bone_matrix_in_object_space(
    *(const vostok::animation::skeleton **)&h[2].locators[0][0].m_name[12],
    &bone,
    (const vostok::animation::skeleton_bone *)matricesa,
    a5);
  v17 = fsqrt(
          (float)((float)((float)(matrices->c.x - bone.c.x) * (float)(matrices->c.x - bone.c.x))
                + (float)((float)(matrices->c.z - bone.c.z) * (float)(matrices->c.z - bone.c.z)))
        + (float)((float)(matrices->c.y - bone.c.y) * (float)(matrices->c.y - bone.c.y)));
  v70 = LODWORD(v17) & 0x7FFFFFFF;
  if ( COERCE_FLOAT(LODWORD(v17) & 0x7FFFFFFF) >= 0.0000099999997 )
  {
    v18 = (float)((float)((float)(v17 * v17) + (float)(original_matrix * original_matrix)) - (float)(v69 * v69))
        / (float)((float)(v17 * original_matrix) * 2.0);
    v19 = FLOAT_N1_0;
    if ( v18 > -1.0 )
    {
      if ( s_bm_current_air_resistance < v18 )
        v19 = s_bm_current_air_resistance;
      else
        v19 = v18;
    }
    __libm_sse2_acos();
    v20 = *(const vostok::animation::skeleton **)&h[2].locators[0][0].m_name[12];
    v70 = LODWORD(v19);
    vostok::animation::get_bone_matrix_in_object_space(v20, &v66, (const vostok::animation::skeleton_bone *)v67, a5);
    v21 = &a5[LODWORD(target_hand_transform[9].k.x)].c.x;
    v22 = a5[LODWORD(target_hand_transform[9].k.x)].c.y;
    v23 = a5[LODWORD(target_hand_transform[9].k.x)].c.z;
    v24 = (float)((float)((float)((float)(v66.i.y * *v21) + (float)(v66.j.y * v22)) + (float)(v66.k.y * v23)) + v66.c.y)
        - bone.c.y;
    v25 = (float)((float)((float)((float)(v66.i.z * *v21) + (float)(v66.j.z * v22)) + (float)(v66.k.z * v23)) + v66.c.z)
        - bone.c.z;
    v26 = (float)((float)((float)((float)(v66.i.x * *v21) + (float)(v66.j.x * v22)) + (float)(v66.k.x * v23)) + v66.c.x)
        - bone.c.x;
    original_matrixa = v25;
    v27 = v25;
    v28 = fsqrt((float)((float)(v25 * v25) + (float)(v24 * v24)) + (float)(v26 * v26));
    v71.z = v27 * (float)(s_bm_current_air_resistance / v28);
    *(float *)&v67 = v66.c.x - bone.c.x;
    v72.x = v66.c.x - bone.c.x;
    v71.x = v26 * (float)(s_bm_current_air_resistance / v28);
    v71.y = v24 * (float)(s_bm_current_air_resistance / v28);
    v63 = v66.c.y - bone.c.y;
    v64 = v66.c.z - bone.c.z;
    v29 = (float)((float)(v66.c.y - bone.c.y) * original_matrixa) - (float)((float)(v66.c.z - bone.c.z) * v24);
    v30 = (float)((float)(v66.c.z - bone.c.z) * v26) - (float)(original_matrixa * (float)(v66.c.x - bone.c.x));
    v31 = (float)(v24 * (float)(v66.c.x - bone.c.x)) - (float)((float)(v66.c.y - bone.c.y) * v26);
    if ( COERCE_FLOAT(
           COERCE_UNSIGNED_INT(fsqrt((float)((float)(v30 * v30) + (float)(v29 * v29)) + (float)(v31 * v31)))
         & 0x7FFFFFFF) >= 0.0000099999997 )
    {
      v32 = s_bm_current_air_resistance / fsqrt((float)((float)(v30 * v30) + (float)(v29 * v29)) + (float)(v31 * v31));
      v72.x = v29 * v32;
      v72.y = v30 * v32;
      v72.z = v31 * v32;
      vostok::math::get_rotation_matrix(&v71, &v72, &v66);
      v33 = matrices->c.y - bone.c.y;
      v34 = matrices->c.z - bone.c.z;
      x_low = (__m128i)LODWORD(matrices->c.x);
      *(float *)x_low.m128i_i32 = *(float *)x_low.m128i_i32 - bone.c.x;
      v36 = fsqrt(
              (float)((float)(v34 * v34) + (float)(v33 * v33))
            + (float)(*(float *)x_low.m128i_i32 * *(float *)x_low.m128i_i32));
      *(float *)&v37 = v33 * (float)(s_bm_current_air_resistance / v36);
      *(float *)x_low.m128i_i32 = *(float *)x_low.m128i_i32 * (float)(s_bm_current_air_resistance / v36);
      v38 = v34 * (float)(s_bm_current_air_resistance / v36);
      v71.x = (float)((float)(*(float *)x_low.m128i_i32 * v66.i.x) + (float)(*(float *)&v37 * v66.j.x))
            + (float)(v38 * v66.k.x);
      *(_QWORD *)&v72.x = __PAIR64__(v37, x_low.m128i_u32[0]);
      v39 = (float)(*(float *)x_low.m128i_i32 * v66.i.y) + (float)(*(float *)&v37 * v66.j.y);
      *(float *)x_low.m128i_i32 = (float)((float)(*(float *)x_low.m128i_i32 * v66.i.z)
                                        + (float)(*(float *)&v37 * v66.j.z))
                                + (float)(v38 * v66.k.z);
      v72.z = v38;
      v71.y = v39 + (float)(v38 * v66.k.y);
      LODWORD(v71.z) = x_low.m128i_i32[0];
      vostok::math::create_rotation(&v71, (int)&v66, x_low, *(float *)&v70);
      v71.x = (float)((float)(v72.x * v66.i.x) + (float)(v72.y * v66.j.x)) + (float)(v72.z * v66.k.x);
      v71.y = (float)((float)(v72.x * v66.i.y) + (float)(v72.y * v66.j.y)) + (float)(v72.z * v66.k.y);
      v71.z = (float)((float)(v66.i.z * v72.x) + (float)(v72.y * v66.j.z)) + (float)(v72.z * v66.k.z);
      v40 = s_bm_current_air_resistance
          / fsqrt((float)((float)(v64 * v64) + (float)(v63 * v63)) + (float)(*(float *)&v67 * *(float *)&v67));
      v72.x = *(float *)&v67 * v40;
      v72.y = v63 * v40;
      v72.z = v64 * v40;
      vostok::math::get_rotation_matrix(&v72, &v71, &v66);
      vostok::math::change_matrix_orientation(&v66, &bone);
      vostok::math::mul4x3(&bone, v65, &v66);
      v41 = &a5[LODWORD(target_hand_transform[9].k.x)].c.x;
      v42 = a5[LODWORD(target_hand_transform[9].k.x)].c.y;
      v43 = a5[LODWORD(target_hand_transform[9].k.x)].c.z;
      v44 = (float)((float)((float)((float)(v66.i.y * *v41) + (float)(v66.j.y * v42)) + (float)(v66.k.y * v43)) + v66.c.y)
          - v66.c.y;
      *(float *)x_low.m128i_i32 = (float)((float)((float)((float)(v66.j.x * v42) + (float)(v66.k.x * v43))
                                                + (float)(v66.i.x * *v41))
                                        + v66.c.x)
                                - v66.c.x;
      v45 = (float)((float)((float)((float)(v66.i.z * *v41) + (float)(v66.j.z * v42)) + (float)(v66.k.z * v43)) + v66.c.z)
          - v66.c.z;
      v46 = fsqrt(
              (float)((float)(v45 * v45) + (float)(v44 * v44))
            + (float)(*(float *)x_low.m128i_i32 * *(float *)x_low.m128i_i32));
      v72.y = v44 * (float)(s_bm_current_air_resistance / v46);
      v47 = matrices->c.y - v66.c.y;
      v72.z = v45 * (float)(s_bm_current_air_resistance / v46);
      v48 = matrices->c.z - v66.c.z;
      v72.x = *(float *)x_low.m128i_i32 * (float)(s_bm_current_air_resistance / v46);
      *(float *)x_low.m128i_i32 = matrices->c.x - v66.c.x;
      v49 = s_bm_current_air_resistance
          / fsqrt(
              (float)((float)(v48 * v48) + (float)(v47 * v47))
            + (float)(*(float *)x_low.m128i_i32 * *(float *)x_low.m128i_i32));
      v71.x = *(float *)x_low.m128i_i32 * v49;
      v71.y = v47 * v49;
      v71.z = v48 * v49;
      vostok::math::get_rotation_matrix(&v72, &v71, &result);
      vostok::math::change_matrix_orientation(&result, &v66);
      qmemcpy(
        &a5[LODWORD(target_hand_transform[9].k.x)],
        vostok::math::get_relative_matrix(&result, matrices, &v66),
        sizeof(vostok::math::float4x4));
      v50 = &a5[LODWORD(target_hand_transform[9].k.x)].c.x;
      v51 = a5[LODWORD(target_hand_transform[9].k.x)].c.z;
      v52 = a5[LODWORD(target_hand_transform[9].k.x)].c.y;
      if ( fabs(fsqrt((float)((float)(v51 * v51) + (float)(v52 * v52)) + (float)(*v50 * *v50)) - v69) >= 0.0000099999997 )
      {
        v53 = s_bm_current_air_resistance
            / fsqrt((float)((float)(*v50 * *v50) + (float)(v50[1] * v50[1])) + (float)(v50[2] * v50[2]));
        v54 = a5[LODWORD(target_hand_transform[9].k.x)].c.z;
        v55 = v53 * a5[LODWORD(target_hand_transform[9].k.x)].c.y;
        v71.x = (float)(v53 * *v50) * v69;
        v71.y = v55 * v69;
        v71.z = (float)(v54 * v53) * v69;
        *(vostok::math::float3 *)v50 = v71;
      }
      relative_matrix = vostok::math::get_relative_matrix(&result, &v66, &bone);
      v57 = matricesa;
      qmemcpy(v65, relative_matrix, sizeof(vostok::math::float4x4));
      bone_matrix_in_object_space = vostok::animation::get_bone_matrix_in_object_space(
                                      *(const vostok::animation::skeleton **)&h[2].locators[0][0].m_name[12],
                                      &result,
                                      (const vostok::animation::skeleton_bone *)LODWORD(v57->i.y),
                                      a5);
      v59 = vostok::math::get_relative_matrix(&v66, &bone, bone_matrix_in_object_space);
      qmemcpy(&a5[v62], v59, sizeof(vostok::math::float4x4));
    }
  }
}
