void __thiscall survarium::hand_to_weapon_ik_processor::process_hand(
        survarium::hand_to_weapon_ik_processor *this,
        survarium::game_camera *h,
        const vostok::math::float4x4 *target_hand_obj_space_transform,
        vostok::math::float4x4 *matrices)
{
  vostok::animation::skeleton *v4; // ecx
  vostok::animation::skeleton *v5; // ecx
  float *v6; // eax
  vostok::math::float3_pod *v7; // ecx
  survarium::game_camera *v8; // ecx
  float *v9; // eax
  vostok::math::float3_pod *v10; // ecx
  survarium::game_camera *v11; // ecx
  survarium::game_camera *v12; // ecx
  survarium::game_camera *v13; // ecx
  vostok::math::float3 *v14; // eax
  const vostok::math::float3_pod *v15; // eax
  vostok::math::float3 *v16; // eax
  survarium::game_camera *v17; // ecx
  const vostok::math::float3_pod *v18; // eax
  vostok::math::float3 *v19; // eax
  survarium::game_camera *v20; // ecx
  const vostok::math::float3 *v21; // eax
  vostok::math::float3 *v22; // eax
  vostok::math::float3 *v23; // eax
  survarium::game_camera *v24; // ecx
  int v25; // eax
  const vostok::math::float3 *v26; // eax
  vostok::math::float3 *v27; // eax
  const vostok::math::float3_pod *v28; // eax
  vostok::math::float3 *v29; // eax
  float *v30; // eax
  vostok::math::float3_pod *v31; // ecx
  const vostok::math::float3_pod *v32; // eax
  vostok::math::float3 *v33; // eax
  vostok::math::float3 *v34; // esi
  vostok::math::float3 *v35; // eax
  vostok::math::float4x4 *relative_matrix; // eax
  const vostok::math::float4x4 *bone_matrix_in_object_space; // eax
  vostok::math::float4x4 *v38; // eax
  int v40; // [esp+184h] [ebp-3DCh]
  int v41; // [esp+1A4h] [ebp-3BCh]
  vostok::math::float4x4 v42; // [esp+1B0h] [ebp-3B0h] BYREF
  vostok::math::float4x4 v43; // [esp+1F0h] [ebp-370h] BYREF
  vostok::math::float4x4 v44; // [esp+230h] [ebp-330h] BYREF
  vostok::math::float3 v45; // [esp+270h] [ebp-2F0h] BYREF
  float v46[3]; // [esp+27Ch] [ebp-2E4h] BYREF
  float left; // [esp+288h] [ebp-2D8h] BYREF
  vostok::math::float4x4 v48; // [esp+28Ch] [ebp-2D4h] BYREF
  vostok::math::float3 v49; // [esp+2CCh] [ebp-294h] BYREF
  vostok::math::float3 v50; // [esp+2D8h] [ebp-288h] BYREF
  vostok::math::float3 v51; // [esp+2E4h] [ebp-27Ch] BYREF
  vostok::math::float3 v52; // [esp+2F0h] [ebp-270h] BYREF
  vostok::math::float4x4 result; // [esp+2FCh] [ebp-264h] BYREF
  vostok::math::float3 v54; // [esp+33Ch] [ebp-224h] BYREF
  vostok::math::float3 v55; // [esp+348h] [ebp-218h] BYREF
  char v56; // [esp+356h] [ebp-20Ah]
  char v57; // [esp+357h] [ebp-209h]
  const vostok::math::float3 *arm_to_hand_dir; // [esp+358h] [ebp-208h]
  float v59[3]; // [esp+35Ch] [ebp-204h] BYREF
  vostok::math::float3 v60; // [esp+368h] [ebp-1F8h] BYREF
  vostok::math::float3 v61; // [esp+374h] [ebp-1ECh] BYREF
  unsigned int forearm_matrix_index; // [esp+380h] [ebp-1E0h]
  const vostok::math::float3 *original_forearm_dir; // [esp+384h] [ebp-1DCh]
  const vostok::animation::skeleton_bone *arm_bone; // [esp+388h] [ebp-1D8h]
  unsigned int arm_matrix_index; // [esp+38Ch] [ebp-1D4h]
  vostok::math::float3 arm_pos; // [esp+390h] [ebp-1D0h] BYREF
  const vostok::math::float3 *new_forearm_dir; // [esp+39Ch] [ebp-1C4h]
  vostok::math::float4x4 v68; // [esp+3A0h] [ebp-1C0h] BYREF
  vostok::math::float4x4 forearm_obj_matrix; // [esp+3E0h] [ebp-180h] BYREF
  survarium::game_camera adjacent0; // [esp+424h] [ebp-13Ch] BYREF
  vostok::math::float3_pod v71; // [esp+4B4h] [ebp-ACh] BYREF
  vostok::math::float4x4 v72; // [esp+4C0h] [ebp-A0h] BYREF
  vostok::math::float4x4 v73; // [esp+500h] [ebp-60h] BYREF
  const vostok::math::float3 *original_arm_dir; // [esp+544h] [ebp-1Ch]
  const vostok::animation::skeleton_bone *forearm_bone; // [esp+548h] [ebp-18h]
  float arm_to_hand_len; // [esp+54Ch] [ebp-14h] BYREF
  const vostok::math::float3 *initial_forearm_pos; // [esp+550h] [ebp-10h]
  const vostok::math::float4x4 *alpha_rotation_matrix; // [esp+554h] [ebp-Ch]
  float forearm_len; // [esp+558h] [ebp-8h] BYREF
  const vostok::math::float3 *rotation_axis; // [esp+55Ch] [ebp-4h]

  LODWORD(adjacent0.m_inverted_view_matrix.i.z) = vostok::animation::skeleton::get_bone(
                                                    (vostok::animation::skeleton *)this->m_skeleton,
                                                    LODWORD(h->m_inverted_view_matrix.i.x));
  forearm_bone = *(const vostok::animation::skeleton_bone **)(LODWORD(adjacent0.m_inverted_view_matrix.i.z) + 4);
  arm_bone = forearm_bone->m_parent;
  v41 = forearm_bone
      - vostok::animation::skeleton::get_root((vostok::animation::skeleton *)this->m_skeleton, (int)this->m_skeleton);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0x14);
  forearm_matrix_index = v41 - vostok::animation::skeleton::get_root_bones_count(v4, (int)this->m_skeleton);
  v40 = arm_bone
      - vostok::animation::skeleton::get_root(
          (vostok::animation::skeleton *)forearm_matrix_index,
          (int)this->m_skeleton);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0x14);
  arm_matrix_index = v40 - vostok::animation::skeleton::get_root_bones_count(v5, (int)this->m_skeleton);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)matrices);
  forearm_len = vostok::math::float3_pod::length(v7, v6);
  survarium::weapon_user_dead_state::finalize(v8);
  adjacent0.m_inverted_view_matrix.c.w = vostok::math::float3_pod::length(v10, v9);
  v57 = 0;
  survarium::weapon_user_dead_state::finalize(v11);
  v56 = 0;
  survarium::weapon_user_dead_state::finalize(v12);
  survarium::get_bone_matrix_in_object_space(
    (vostok::math::float4x4 *)&adjacent0.m_far_plane,
    arm_bone,
    this->m_skeleton,
    matrices);
  survarium::weapon_user_dead_state::finalize(v13);
  arm_pos = *v14;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)LODWORD(arm_pos.y));
  v16 = vostok::math::operator-(&arm_pos, v15, &v55);
  arm_to_hand_len = vostok::math::length(v16);
  if ( !vostok::math::is_zero<float>(&arm_to_hand_len, &epsilon_5_87) )
  {
    survarium::weapon_user_dead_state::finalize(v17);
    v19 = vostok::math::operator-(&arm_pos, v18, &v54);
    vostok::math::normalize(v19, v59);
    arm_to_hand_dir = (const vostok::math::float3 *)v59;
    survarium::get_bone_matrix_in_object_space(&result, forearm_bone, this->m_skeleton, matrices);
    survarium::weapon_user_dead_state::finalize(v20);
    initial_forearm_pos = v21;
    v22 = vostok::math::operator-(&arm_pos, v21, &v52);
    vostok::math::normalize(v22, &v71.x);
    original_arm_dir = (const vostok::math::float3 *)&v71;
    v23 = vostok::math::operator^(arm_to_hand_dir, &v71, &v51);
    vostok::math::normalize(v23, &adjacent0.m_inverted_view_matrix.i.w);
    rotation_axis = (const vostok::math::float3 *)&adjacent0.m_inverted_view_matrix.lines[0].elements[3];
    adjacent0.m_inverted_view_matrix.k.z = survarium::get_angle(
                                             adjacent0.m_inverted_view_matrix.c.w,
                                             arm_to_hand_len,
                                             forearm_len);
    vostok::math::create_rotation(rotation_axis, adjacent0.m_inverted_view_matrix.k.z);
    alpha_rotation_matrix = &v68;
    vostok::math::float4x4::transform_direction(arm_to_hand_dir, &v60, &v68);
    LODWORD(adjacent0.m_inverted_view_matrix.j.z) = &v60;
    vostok::math::get_rotation_matrix(&v72, original_arm_dir, &v60);
    adjacent0.m_game_scene = (survarium::base_game_scene *)&v72;
    vostok::math::change_matrix_orientation(&v72, (vostok::math::float4x4 *)&adjacent0.m_far_plane);
    vostok::math::operator*(
      &forearm_obj_matrix,
      &matrices[forearm_matrix_index],
      (const vostok::math::float4x4 *)&adjacent0.m_far_plane);
    survarium::weapon_user_dead_state::finalize(v24);
    *(_QWORD *)&adjacent0.m_inverted_view_matrix.lines[3].x = *(_QWORD *)v25;
    adjacent0.m_inverted_view_matrix.c.z = *(float *)(v25 + 8);
    survarium::weapon_user_dead_state::finalize(h);
    vostok::math::float4x4::transform_position(
      v26,
      (vostok::math::float3 *)&adjacent0.m_inverted_view_matrix.lines[1].elements[3],
      &forearm_obj_matrix);
    LODWORD(adjacent0.m_near_plane) = &adjacent0.m_inverted_view_matrix.j.w;
    v27 = vostok::math::operator-(
            (const vostok::math::float3_pod *)&adjacent0.m_inverted_view_matrix.lines[3],
            (const vostok::math::float3_pod *)&adjacent0.m_inverted_view_matrix.lines[1].elements[3],
            &v50);
    vostok::math::normalize(v27, (float *)&adjacent0);
    original_forearm_dir = (const vostok::math::float3 *)&adjacent0;
    survarium::weapon_user_dead_state::finalize(&adjacent0);
    v29 = vostok::math::operator-(
            (const vostok::math::float3_pod *)&adjacent0.m_inverted_view_matrix.lines[3],
            v28,
            &v49);
    vostok::math::normalize(v29, &v61.x);
    new_forearm_dir = &v61;
    vostok::math::get_rotation_matrix(&v73, original_forearm_dir, &v61);
    LODWORD(adjacent0.m_inverted_view_matrix.k.w) = &v73;
    vostok::math::change_matrix_orientation(&v73, &forearm_obj_matrix);
    qmemcpy(
      (void *)&matrices[LODWORD(h->m_inverted_view_matrix.i.y)],
      vostok::math::get_relative_matrix(&v48, target_hand_obj_space_transform, &forearm_obj_matrix),
      sizeof(vostok::math::float4x4));
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)matrices);
    left = vostok::math::float3_pod::length(v31, v30);
    if ( !vostok::math::is_similar<float>(&left, &forearm_len, 0.0000099999997) )
    {
      survarium::weapon_user_dead_state::finalize(h);
      v33 = vostok::math::normalize(v32, v46);
      v34 = vostok::math::operator*(v33, &v45, &forearm_len);
      survarium::weapon_user_dead_state::finalize(h);
      *v35 = *v34;
    }
    relative_matrix = vostok::math::get_relative_matrix(
                        &v44,
                        &forearm_obj_matrix,
                        (const vostok::math::float4x4 *)&adjacent0.m_far_plane);
    qmemcpy((void *)&matrices[forearm_matrix_index], relative_matrix, sizeof(vostok::math::float4x4));
    bone_matrix_in_object_space = survarium::get_bone_matrix_in_object_space(
                                    &v43,
                                    arm_bone->m_parent,
                                    this->m_skeleton,
                                    matrices);
    v38 = vostok::math::get_relative_matrix(
            &v42,
            (const vostok::math::float4x4 *)&adjacent0.m_far_plane,
            bone_matrix_in_object_space);
    qmemcpy((void *)&matrices[arm_matrix_index], v38, sizeof(vostok::math::float4x4));
  }
}
