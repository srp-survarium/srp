vostok::math::float4x4 *__thiscall survarium::legs_ik_processor::get_foot_fixed_transform(
        survarium::legs_ik_processor *this,
        vostok::math::float4x4 *result,
        survarium::game_camera *params,
        const vostok::math::float4x4 *hip_world_matrix,
        const vostok::math::float4x4 *matrices,
        float *delta_len)
{
  int root_bones_count; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  const vostok::math::float3 *v11; // eax
  const vostok::math::float3 *v12; // esi
  survarium::game_camera *v13; // ecx
  const vostok::math::float3 *v14; // eax
  survarium::game_camera *v15; // ecx
  const vostok::math::float3 *v16; // eax
  const vostok::math::float3 *v17; // esi
  survarium::game_camera *v18; // ecx
  const vostok::math::float3 *v19; // eax
  survarium::game_camera *v20; // ecx
  const vostok::math::float3_pod *v22; // eax
  const vostok::math::float3_pod *v23; // esi
  survarium::game_camera *v24; // ecx
  const vostok::math::float3_pod *v25; // eax
  vostok::math::float3 *v26; // eax
  survarium::game_camera *v27; // ecx
  const vostok::math::float3_pod *v28; // eax
  const vostok::math::float3_pod *v29; // esi
  survarium::game_camera *v30; // ecx
  const vostok::math::float3_pod *v31; // eax
  vostok::math::float3 *v32; // eax
  vostok::math::float3 *v33; // eax
  const vostok::math::float3 *v34; // esi
  survarium::game_camera *v35; // ecx
  _DWORD *v36; // eax
  survarium::game_camera *y_low; // ecx
  const vostok::math::float3 *v38; // esi
  vostok::math::float3 *v39; // eax
  vostok::math::float3 *v40; // eax
  vostok::math::float3 *v41; // esi
  survarium::game_camera *v42; // ecx
  vostok::math::float3 *v43; // eax
  const vostok::math::float4x4 *rotation; // eax
  survarium::game_camera *v45; // ecx
  survarium::game_camera *v46; // ecx
  survarium::game_camera *v47; // ecx
  _DWORD *v48; // eax
  _DWORD *v49; // esi
  survarium::game_camera *v50; // ecx
  _DWORD *v51; // eax
  vostok::math::float3 *v52; // esi
  survarium::game_camera *v53; // ecx
  vostok::math::float3 *v54; // eax
  vostok::math::float3 *v55; // esi
  survarium::game_camera *v56; // ecx
  const vostok::math::float3_pod *v57; // eax
  vostok::math::float3 *v58; // esi
  survarium::game_camera *v59; // ecx
  const vostok::math::float3_pod *v60; // eax
  vostok::math::float3 *v61; // esi
  survarium::game_camera *v62; // ecx
  const vostok::math::float3_pod *v63; // eax
  vostok::math::float3 *v64; // esi
  survarium::game_camera *v65; // ecx
  const vostok::math::float3_pod *v66; // eax
  vostok::math::float3 *v67; // esi
  survarium::game_camera *v68; // ecx
  const vostok::math::float3_pod *v69; // eax
  vostok::math::float3 *v70; // esi
  survarium::game_camera *v71; // ecx
  const vostok::math::float3_pod *v72; // eax
  vostok::math::float3 *v73; // esi
  survarium::game_camera *v74; // ecx
  const vostok::math::float3_pod *v75; // eax
  vostok::math::float3 *v76; // eax
  int v77; // eax
  float *v78; // eax
  vostok::math::float3_pod *v79; // ecx
  vostok::animation::skeleton *v80; // ecx
  float *v81; // eax
  vostok::math::float3_pod *v82; // ecx
  int v83; // eax
  float *v84; // eax
  vostok::math::float3_pod *v85; // ecx
  survarium::game_camera *v86; // ecx
  const vostok::math::float3_pod *v87; // eax
  const vostok::math::float3_pod *v88; // esi
  survarium::game_camera *v89; // ecx
  const vostok::math::float3_pod *v90; // eax
  vostok::math::float3 *v91; // eax
  vostok::math::float3_pod *v92; // ecx
  survarium::game_camera *v93; // ecx
  const vostok::math::float3_pod *v94; // eax
  const vostok::math::float3_pod *v95; // esi
  survarium::game_camera *v96; // ecx
  const vostok::math::float3_pod *v97; // eax
  vostok::math::float3 *v98; // eax
  float v99; // xmm0_4
  survarium::game_camera *v100; // ecx
  const vostok::math::float3_pod *v101; // eax
  vostok::math::float3 *v102; // esi
  const vostok::math::float3_pod *v103; // eax
  vostok::math::float3 *v104; // eax
  survarium::game_camera *v105; // ecx
  vostok::math::float3 *v106; // eax
  float v107; // [esp+Ch] [ebp-604h]
  vostok::math::float3 v110; // [esp+1A0h] [ebp-470h] BYREF
  survarium::game_camera v111; // [esp+1ACh] [ebp-464h] BYREF
  vostok::math::float3 v112; // [esp+204h] [ebp-40Ch] BYREF
  vostok::math::float3 v113; // [esp+210h] [ebp-400h] BYREF
  vostok::math::float3 v114; // [esp+21Ch] [ebp-3F4h] BYREF
  vostok::math::float3 v115; // [esp+228h] [ebp-3E8h] BYREF
  vostok::math::float3 v116; // [esp+234h] [ebp-3DCh] BYREF
  vostok::math::float3 v117; // [esp+240h] [ebp-3D0h] BYREF
  vostok::math::float3 v118; // [esp+24Ch] [ebp-3C4h] BYREF
  vostok::math::float3 v119; // [esp+258h] [ebp-3B8h] BYREF
  vostok::math::float3 v120; // [esp+264h] [ebp-3ACh] BYREF
  vostok::math::float3 v121; // [esp+270h] [ebp-3A0h] BYREF
  vostok::math::float3 v122; // [esp+27Ch] [ebp-394h] BYREF
  char v123; // [esp+289h] [ebp-387h]
  char v124; // [esp+28Ah] [ebp-386h]
  char v125; // [esp+28Bh] [ebp-385h]
  vostok::math::float4x4 v126; // [esp+28Ch] [ebp-384h] BYREF
  float v127[3]; // [esp+30Ch] [ebp-304h] BYREF
  vostok::math::float3 v128; // [esp+318h] [ebp-2F8h] BYREF
  vostok::math::float3 v129; // [esp+324h] [ebp-2ECh] BYREF
  vostok::math::float3 v130; // [esp+330h] [ebp-2E0h] BYREF
  vostok::math::float3 v131; // [esp+33Ch] [ebp-2D4h] BYREF
  vostok::math::float3 v132; // [esp+348h] [ebp-2C8h] BYREF
  float position_iterpolation_koef; // [esp+354h] [ebp-2BCh] BYREF
  const vostok::math::float3 *position; // [esp+358h] [ebp-2B8h]
  const vostok::math::float4x4 *leg_world_matrix; // [esp+35Ch] [ebp-2B4h]
  const vostok::math::float3 *foot_to_toe_dir; // [esp+360h] [ebp-2B0h]
  const vostok::math::float3 *foot_to_leg_dir; // [esp+364h] [ebp-2ACh]
  vostok::math::float4x4 resulta; // [esp+368h] [ebp-2A8h] BYREF
  vostok::math::float4x4 v139; // [esp+3A8h] [ebp-268h] BYREF
  float v140[3]; // [esp+3E8h] [ebp-228h] BYREF
  float rotation_angle; // [esp+3F4h] [ebp-21Ch]
  vostok::math::float3 foot_to_cube_center_offset; // [esp+3F8h] [ebp-218h] BYREF
  vostok::math::float3 capsule_size; // [esp+404h] [ebp-20Ch] BYREF
  const vostok::math::float4x4 *foot_to_center_rel; // [esp+410h] [ebp-200h]
  vostok::math::float3 start; // [esp+414h] [ebp-1FCh] BYREF
  vostok::math::float4x4 v146; // [esp+420h] [ebp-1F0h] BYREF
  vostok::math::float4x4 v147; // [esp+460h] [ebp-1B0h] BYREF
  vostok::math::color original_color; // [esp+4A0h] [ebp-170h] BYREF
  float leg_len; // [esp+4A4h] [ebp-16Ch]
  vostok::math::color fixed_color; // [esp+4A8h] [ebp-168h] BYREF
  float up_leg_to_original_foot_dist_sqr; // [esp+4ACh] [ebp-164h]
  float rotation_interpolation_koef; // [esp+4B0h] [ebp-160h]
  float up_leg_len; // [esp+4B4h] [ebp-15Ch]
  vostok::math::float4x4 v154; // [esp+4B8h] [ebp-158h] BYREF
  float v155[3]; // [esp+4FCh] [ebp-114h] BYREF
  vostok::math::float4x4 v156; // [esp+508h] [ebp-108h] BYREF
  const vostok::math::float4x4 *knee_world_matrix; // [esp+54Ch] [ebp-C4h]
  vostok::math::float3 up_dir; // [esp+550h] [ebp-C0h] BYREF
  float up_leg_to_fixed_foot_dist; // [esp+55Ch] [ebp-B4h] BYREF
  const vostok::math::float4x4 *foot_world_matrix; // [esp+560h] [ebp-B0h]
  const vostok::math::float4x4 *toe_world_matrix; // [esp+564h] [ebp-ACh]
  const vostok::math::float3 *left_dir; // [esp+568h] [ebp-A8h]
  vostok::math::float3 finish; // [esp+56Ch] [ebp-A4h] BYREF
  float knee_len; // [esp+578h] [ebp-98h]
  const vostok::math::float4x4 *up_leg_world_matrix; // [esp+57Ch] [ebp-94h]
  vostok::math::float4x4 v166; // [esp+580h] [ebp-90h] BYREF
  vostok::math::float3_pod v167; // [esp+5C4h] [ebp-4Ch] BYREF
  vostok::math::float4x4 foot_center_transform; // [esp+5D0h] [ebp-40h] BYREF

  root_bones_count = vostok::animation::skeleton::get_root_bones_count(
                       (vostok::animation::skeleton *)this,
                       (int)this->m_skeleton);
  vostok::math::operator*(
    &v146,
    &matrices[LODWORD(params->m_inverted_view_matrix.i.w) - root_bones_count],
    hip_world_matrix);
  up_leg_world_matrix = &v146;
  v7 = vostok::animation::skeleton::get_root_bones_count((vostok::animation::skeleton *)&v146, (int)this->m_skeleton);
  vostok::math::operator*(&v139, &matrices[LODWORD(params->m_inverted_view_matrix.i.z) - v7], &v146);
  knee_world_matrix = &v139;
  v8 = vostok::animation::skeleton::get_root_bones_count((vostok::animation::skeleton *)&v139, (int)this->m_skeleton);
  vostok::math::operator*(&v166, &matrices[LODWORD(params->m_inverted_view_matrix.i.y) - v8], &v139);
  leg_world_matrix = &v166;
  v9 = vostok::animation::skeleton::get_root_bones_count((vostok::animation::skeleton *)&v166, (int)this->m_skeleton);
  vostok::math::operator*(&v154, &matrices[(int)params->__vftable - v9], &v166);
  foot_world_matrix = &v154;
  v10 = vostok::animation::skeleton::get_root_bones_count((vostok::animation::skeleton *)&v154, (int)this->m_skeleton);
  vostok::math::operator*(&v147, &matrices[LODWORD(params->m_inverted_view_matrix.i.x) - v10], &v154);
  toe_world_matrix = &v147;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v147);
  v12 = v11;
  survarium::weapon_user_dead_state::finalize(v13);
  if ( vostok::math::is_similar(v14, v12, 0.0000099999997)
    || (survarium::weapon_user_dead_state::finalize(v15),
        v17 = v16,
        survarium::weapon_user_dead_state::finalize(v18),
        vostok::math::is_similar(v19, v17, 0.0000099999997)) )
  {
    qmemcpy((void *)result, foot_world_matrix, sizeof(vostok::math::float4x4));
    return result;
  }
  else
  {
    survarium::weapon_user_dead_state::finalize(v20);
    v23 = v22;
    survarium::weapon_user_dead_state::finalize(v24);
    v26 = vostok::math::operator-(v23, v25, &v131);
    vostok::math::normalize(v26, v140);
    foot_to_toe_dir = (const vostok::math::float3 *)v140;
    survarium::weapon_user_dead_state::finalize(v27);
    v29 = v28;
    survarium::weapon_user_dead_state::finalize(v30);
    v32 = vostok::math::operator-(v29, v31, &v130);
    vostok::math::normalize(v32, &v167.x);
    foot_to_leg_dir = (const vostok::math::float3 *)&v167;
    v33 = vostok::math::operator^(foot_to_toe_dir, &v167, &v129);
    vostok::math::normalize(v33, v155);
    left_dir = (const vostok::math::float3 *)v155;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&foot_center_transform);
    vostok::math::float4x4::identity(&foot_center_transform);
    v34 = left_dir;
    survarium::weapon_user_dead_state::finalize(v35);
    *v36 = LODWORD(v34->x);
    y_low = (survarium::game_camera *)LODWORD(v34->y);
    v36[1] = y_low;
    v36[2] = LODWORD(v34->z);
    v38 = foot_to_toe_dir;
    survarium::weapon_user_dead_state::finalize(y_low);
    *v39 = *v38;
    v40 = vostok::math::operator^(foot_to_toe_dir, left_dir, &v128);
    v41 = vostok::math::normalize(v40, v127);
    survarium::weapon_user_dead_state::finalize(v42);
    *v43 = *v41;
    vostok::math::deg2rad();
    rotation_angle = default_fps_3;
    rotation = vostok::math::create_rotation(left_dir, 30.0);
    qmemcpy(
      (void *)&foot_center_transform,
      vostok::math::operator*(&v126, &foot_center_transform, rotation),
      sizeof(foot_center_transform));
    v125 = 0;
    survarium::weapon_user_dead_state::finalize(0);
    v124 = 0;
    survarium::weapon_user_dead_state::finalize(v45);
    v123 = 0;
    survarium::weapon_user_dead_state::finalize(v46);
    survarium::weapon_user_dead_state::finalize(v47);
    v49 = v48;
    survarium::weapon_user_dead_state::finalize(v50);
    *v51 = *v49;
    v51[1] = v49[1];
    v51[2] = v49[2];
    vostok::math::float3::float3(
      &foot_to_cube_center_offset,
      COERCE_UNSIGNED_INT(0.0),
      COERCE_UNSIGNED_INT(0.082000002),
      0.050000001);
    v52 = vostok::math::float4x4::transform_position(&foot_to_cube_center_offset, &v122, &foot_center_transform);
    survarium::weapon_user_dead_state::finalize(v53);
    *v54 = *v52;
    vostok::math::float3::float3(
      &capsule_size,
      LODWORD(s_ik_foot_capsule_radius_value),
      COERCE_UNSIGNED_INT(0.12),
      s_ik_foot_capsule_radius_value);
    vostok::math::float3::float3(&up_dir, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(1.0), 0.0);
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&start);
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&finish);
    vostok::math::color::color(&original_color, 128, 0xC8u, 0, 0);
    vostok::math::color::color(&fixed_color, 128, 0, 0xC8u, 0);
    rotation_interpolation_koef = *(float *)&FLOAT_0_0;
    if ( LOBYTE(params->m_inverted_view_matrix.lines[2].elements[2])
      && BYTE1(params->m_inverted_view_matrix.lines[2].elements[2]) )
    {
      v55 = vostok::math::operator*(&up_dir, &v121, &dist_to_test);
      survarium::weapon_user_dead_state::finalize(v56);
      start = *vostok::math::operator+(v55, v57, &v120);
      v58 = vostok::math::operator*(&up_dir, &v119, &dist_to_test);
      survarium::weapon_user_dead_state::finalize(v59);
      finish = *vostok::math::operator-(v58, v60, &v118);
      rotation_interpolation_koef = 1.0
                                  - ((double (__thiscall *)(_DWORD, _DWORD))this->m_heel_interpolator.interpolated_value)(
                                      &this->m_heel_interpolator,
                                      params->m_inverted_view_matrix.j.x);
    }
    else if ( LOBYTE(params->m_inverted_view_matrix.lines[2].elements[2]) )
    {
      v61 = vostok::math::operator*(&up_dir, &v117, &dist_to_test);
      survarium::weapon_user_dead_state::finalize(v62);
      start = *vostok::math::operator+(v61, v63, &v116);
      v64 = vostok::math::operator*(&up_dir, &v115, &dist_to_test);
      survarium::weapon_user_dead_state::finalize(v65);
      finish = *vostok::math::operator-(v64, v66, &v114);
      rotation_interpolation_koef = 1.0
                                  - ((double (__thiscall *)(_DWORD, _DWORD))this->m_heel_interpolator.interpolated_value)(
                                      &this->m_heel_interpolator,
                                      params->m_inverted_view_matrix.j.x);
    }
    else if ( BYTE1(params->m_inverted_view_matrix.lines[2].elements[2]) )
    {
      v67 = vostok::math::operator*(&up_dir, &v113, &dist_to_test);
      survarium::weapon_user_dead_state::finalize(v68);
      start = *vostok::math::operator+(v67, v69, &v112);
      v70 = vostok::math::operator*(&up_dir, (vostok::math::float3 *)&v111.m_far_plane, &dist_to_test);
      survarium::weapon_user_dead_state::finalize(v71);
      finish = *vostok::math::operator-(
                  v70,
                  v72,
                  (vostok::math::float3 *)&v111.m_inverted_view_matrix.lines[3].elements[3]);
      rotation_interpolation_koef = ((double (__thiscall *)(_DWORD, _DWORD))this->m_toe_interpolator.interpolated_value)(
                                      &this->m_toe_interpolator,
                                      params->m_inverted_view_matrix.j.y);
    }
    else
    {
      v73 = vostok::math::operator*(
              &up_dir,
              (vostok::math::float3 *)&v111.m_inverted_view_matrix.lines[3],
              &dist_to_test);
      survarium::weapon_user_dead_state::finalize(v74);
      start = *vostok::math::operator+(
                 v73,
                 v75,
                 (vostok::math::float3 *)&v111.m_inverted_view_matrix.lines[2].elements[1]);
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)LODWORD(start.y));
      finish = *v76;
      fixed_color.g = 100;
      original_color.r = 100;
    }
    vostok::math::get_relative_matrix(&v156, foot_world_matrix, &foot_center_transform);
    foot_to_center_rel = &v156;
    if ( s_ik_legs_debug_draw_value && this->m_drawer )
      survarium::legs_ik_drawer::draw_line_capsule(
        this->m_drawer,
        &foot_center_transform,
        &capsule_size,
        &original_color,
        0);
    vostok::physics::bt_character_controller::adjust_foot_transform(
      this->m_character_controller,
      &capsule_size,
      &start,
      &finish,
      rotation_interpolation_koef,
      v107,
      &foot_center_transform);
    if ( s_ik_legs_debug_draw_value && this->m_drawer )
      survarium::legs_ik_drawer::draw_solid_capsule(
        this->m_drawer,
        &foot_center_transform,
        &capsule_size,
        &fixed_color,
        1);
    vostok::math::operator*(&resulta, foot_to_center_rel, &foot_center_transform);
    v77 = vostok::animation::skeleton::get_root_bones_count((vostok::animation::skeleton *)this, (int)this->m_skeleton);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)((LODWORD(params->m_inverted_view_matrix.i.z)
                                                                          - v77) << 6));
    up_leg_len = vostok::math::float3_pod::length(v79, v78);
    vostok::animation::skeleton::get_root_bones_count(v80, (int)this->m_skeleton);
    survarium::weapon_user_dead_state::finalize(params);
    knee_len = vostok::math::float3_pod::length(v82, v81);
    v83 = vostok::animation::skeleton::get_root_bones_count((vostok::animation::skeleton *)this, (int)this->m_skeleton);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(((int)params->__vftable - v83) << 6));
    leg_len = vostok::math::float3_pod::length(v85, v84);
    survarium::weapon_user_dead_state::finalize(v86);
    v88 = v87;
    survarium::weapon_user_dead_state::finalize(v89);
    v91 = vostok::math::operator-(v88, v90, (vostok::math::float3 *)&v111.m_inverted_view_matrix.lines[1].elements[2]);
    up_leg_to_fixed_foot_dist = vostok::math::float3_pod::length(v92, &v91->x);
    *delta_len = (float)((float)(up_leg_len + knee_len) + leg_len) - up_leg_to_fixed_foot_dist;
    survarium::weapon_user_dead_state::finalize(v93);
    v95 = v94;
    survarium::weapon_user_dead_state::finalize(v96);
    v98 = vostok::math::operator-(v95, v97, (vostok::math::float3 *)&v111.m_inverted_view_matrix.lines[0].elements[3]);
    up_leg_to_original_foot_dist_sqr = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)v98);
    v99 = vostok::math::sqr<float>(&up_leg_to_fixed_foot_dist);
    if ( v99 > up_leg_to_original_foot_dist_sqr && params->m_inverted_view_matrix.j.x != 0.0 )
    {
      position_iterpolation_koef = ((double (__thiscall *)(_DWORD, _DWORD))this->m_heel_interpolator.interpolated_value)(
                                     &this->m_heel_interpolator,
                                     params->m_inverted_view_matrix.j.x);
      *(float *)&v111.__vftable = *(float *)&clear_value - position_iterpolation_koef;
      survarium::weapon_user_dead_state::finalize(v100);
      v102 = vostok::math::operator*(
               v101,
               (vostok::math::float3 *)&v111.m_inverted_view_matrix,
               &position_iterpolation_koef);
      survarium::weapon_user_dead_state::finalize(&v111);
      v104 = vostok::math::operator*(v103, &v110, (float *)&v111);
      vostok::math::operator+(v102, v104, &v132);
      position = &v132;
      survarium::weapon_user_dead_state::finalize(v105);
      *v106 = v132;
    }
    qmemcpy((void *)result, &resulta, sizeof(vostok::math::float4x4));
    return result;
  }
}
