void __thiscall survarium::legs_ik_processor::process_leg(
        survarium::legs_ik_processor *this,
        vostok::animation::skeleton *params,
        const vostok::math::float4x4 *target_foot_obj_matrix,
        const vostok::math::float4x4 *hip_obj_matrix,
        vostok::math::float4x4 *matrices,
        const vostok::math::float4x4 *transform)
{
  float *v6; // eax
  vostok::math::float3_pod *v7; // ecx
  survarium::game_camera *v8; // ecx
  float *v9; // eax
  vostok::math::float3_pod *v10; // ecx
  float *v11; // eax
  vostok::math::float3_pod *v12; // ecx
  survarium::game_camera *v13; // ecx
  const vostok::math::float3 *v14; // eax
  const vostok::math::float3 *v15; // esi
  survarium::game_camera *v16; // ecx
  const vostok::math::float3 *v17; // eax
  survarium::game_camera *v18; // ecx
  const vostok::math::float3 *v19; // eax
  const vostok::math::float3 *v20; // esi
  survarium::game_camera *v21; // ecx
  const vostok::math::float3 *v22; // eax
  const vostok::math::float3 *v23; // eax
  const vostok::math::float3 *v24; // esi
  survarium::game_camera *v25; // ecx
  const vostok::math::float3 *v26; // eax
  const vostok::math::float3 *v27; // eax
  const vostok::math::float3 *v28; // esi
  survarium::game_camera *v29; // ecx
  const vostok::math::float3 *v30; // eax
  const vostok::math::color *v31; // eax
  const vostok::math::color *v32; // eax
  const vostok::math::color *v33; // eax
  const vostok::math::color *v34; // eax
  const vostok::math::float4x4 *v35; // eax
  const vostok::math::float3_pod *v36; // eax
  const vostok::math::float3_pod *v37; // esi
  survarium::game_camera *v38; // ecx
  const vostok::math::float3_pod *v39; // eax
  vostok::math::float3 *v40; // eax
  survarium::game_camera *v41; // ecx
  const vostok::math::float3_pod *v42; // eax
  const vostok::math::float3_pod *v43; // esi
  survarium::game_camera *v44; // ecx
  const vostok::math::float3_pod *v45; // eax
  vostok::math::float3 *v46; // eax
  vostok::math::float3_pod *v47; // ecx
  survarium::game_camera *v48; // ecx
  const vostok::math::float3_pod *v49; // eax
  const vostok::math::float3_pod *v50; // esi
  survarium::game_camera *v51; // ecx
  const vostok::math::float3_pod *v52; // eax
  vostok::math::float3 *v53; // eax
  survarium::game_camera *v54; // ecx
  const vostok::math::float3_pod *v55; // eax
  const vostok::math::float3_pod *v56; // esi
  survarium::game_camera *v57; // ecx
  const vostok::math::float3_pod *v58; // eax
  vostok::math::float3 *v59; // eax
  vostok::math::float3 *v60; // eax
  survarium::game_camera *v61; // ecx
  const vostok::math::float3_pod *v62; // eax
  const vostok::math::float3_pod *v63; // esi
  survarium::game_camera *v64; // ecx
  const vostok::math::float3_pod *v65; // eax
  vostok::math::float3 *v66; // eax
  survarium::game_camera *v67; // ecx
  const vostok::math::float3_pod *v68; // eax
  const vostok::math::float3_pod *v69; // esi
  survarium::game_camera *v70; // ecx
  const vostok::math::float3_pod *v71; // eax
  vostok::math::float3 *v72; // eax
  vostok::math::float3 *v73; // eax
  const vostok::math::float3_pod *v74; // eax
  const vostok::math::float3_pod *v75; // esi
  survarium::game_camera *v76; // ecx
  const vostok::math::float3_pod *v77; // eax
  vostok::math::float3 *v78; // eax
  const vostok::math::float3_pod *v79; // eax
  const vostok::math::float3_pod *v80; // esi
  survarium::game_camera *v81; // ecx
  const vostok::math::float3_pod *v82; // eax
  vostok::math::float3 *v83; // eax
  survarium::game_camera *v84; // ecx
  const vostok::math::float3_pod *v85; // eax
  const vostok::math::float3_pod *v86; // esi
  survarium::game_camera *v87; // ecx
  const vostok::math::float3_pod *v88; // eax
  vostok::math::float3 *v89; // eax
  const vostok::math::color *v90; // eax
  const vostok::math::color *v91; // eax
  const vostok::math::color *v92; // eax
  const vostok::math::color *v93; // eax
  const vostok::math::float4x4 *v94; // eax
  survarium::game_camera *v95; // ecx
  const vostok::math::float3 *v96; // eax
  const vostok::math::color *v97; // eax
  const vostok::animation::skeleton_bone *bone; // eax
  boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *v99; // ecx
  vostok::socket_error_types_enum *v100; // eax
  unsigned int bone_index; // esi
  vostok::animation::skeleton *v102; // ecx
  survarium::game_camera *v103; // ecx
  const vostok::math::float3 *v104; // eax
  const vostok::math::float4x4 *v105; // eax
  vostok::math::float4x4 *relative_matrix; // eax
  vostok::math::float4x4 *v107; // eax
  vostok::math::float4x4 *v108; // eax
  vostok::math::float3 *v109; // eax
  vostok::math::float4x4 *v110; // eax
  vostok::math::float3 *v111; // eax
  const vostok::math::float4x4 *v112; // [esp-14h] [ebp-974h]
  const vostok::math::float4x4 *v113; // [esp-14h] [ebp-974h]
  const vostok::math::float4x4 *v114; // [esp-10h] [ebp-970h]
  const vostok::math::float4x4 *v115; // [esp-10h] [ebp-970h]
  const vostok::math::float4x4 *v116; // [esp-Ch] [ebp-96Ch]
  const vostok::math::float4x4 *v117; // [esp-Ch] [ebp-96Ch]
  const vostok::math::color *v118; // [esp-8h] [ebp-968h]
  const vostok::math::color *v119; // [esp-8h] [ebp-968h]
  const vostok::math::color *v120; // [esp-4h] [ebp-964h]
  const vostok::math::color *v121; // [esp-4h] [ebp-964h]
  const vostok::math::color *adjacent0; // [esp+0h] [ebp-960h]
  const vostok::math::color *adjacent0a; // [esp+0h] [ebp-960h]
  const vostok::math::color *adjacent1; // [esp+4h] [ebp-95Ch]
  vostok::math::float3 *adjacent1a; // [esp+4h] [ebp-95Ch]
  const vostok::math::color *adjacent1b; // [esp+4h] [ebp-95Ch]
  float adjacent1c; // [esp+4h] [ebp-95Ch]
  float epsilon; // [esp+8h] [ebp-958h]
  vostok::math::float4x4 v130; // [esp+FCh] [ebp-864h] BYREF
  vostok::math::float4x4 v131; // [esp+13Ch] [ebp-824h] BYREF
  vostok::math::float4x4 v132; // [esp+17Ch] [ebp-7E4h] BYREF
  vostok::math::float4x4 v133; // [esp+1BCh] [ebp-7A4h] BYREF
  vostok::math::float4x4 v134; // [esp+1FCh] [ebp-764h] BYREF
  vostok::math::float4x4 v135; // [esp+23Ch] [ebp-724h] BYREF
  vostok::math::color v136; // [esp+27Ch] [ebp-6E4h] BYREF
  vostok::math::float4x4 v137; // [esp+280h] [ebp-6E0h] BYREF
  vostok::math::float4x4 v138; // [esp+2C0h] [ebp-6A0h] BYREF
  vostok::math::float4x4 v139; // [esp+300h] [ebp-660h] BYREF
  vostok::math::float4x4 v140; // [esp+340h] [ebp-620h] BYREF
  vostok::math::color v141; // [esp+380h] [ebp-5E0h] BYREF
  vostok::math::color v142; // [esp+384h] [ebp-5DCh] BYREF
  vostok::math::color v143; // [esp+388h] [ebp-5D8h] BYREF
  vostok::math::color v144; // [esp+38Ch] [ebp-5D4h] BYREF
  vostok::math::float3 v145; // [esp+390h] [ebp-5D0h] BYREF
  vostok::math::float3 v146; // [esp+39Ch] [ebp-5C4h] BYREF
  vostok::math::float4x4 v147; // [esp+3A8h] [ebp-5B8h] BYREF
  vostok::math::float4x4 v148; // [esp+3E8h] [ebp-578h] BYREF
  vostok::math::float3 v149; // [esp+428h] [ebp-538h] BYREF
  vostok::math::float4x4 v150; // [esp+434h] [ebp-52Ch] BYREF
  vostok::math::float4x4 v151; // [esp+474h] [ebp-4ECh] BYREF
  float v152[3]; // [esp+4B4h] [ebp-4ACh] BYREF
  vostok::math::float3 v153; // [esp+4C0h] [ebp-4A0h] BYREF
  vostok::math::float3 v154; // [esp+4CCh] [ebp-494h] BYREF
  vostok::math::float3 v155; // [esp+4D8h] [ebp-488h] BYREF
  float v156[3]; // [esp+4E4h] [ebp-47Ch] BYREF
  vostok::math::float3 v157; // [esp+4F0h] [ebp-470h] BYREF
  float v158[3]; // [esp+4FCh] [ebp-464h] BYREF
  vostok::math::float3 v159; // [esp+508h] [ebp-458h] BYREF
  vostok::math::float3 v160; // [esp+514h] [ebp-44Ch] BYREF
  vostok::math::float3 v161; // [esp+520h] [ebp-440h] BYREF
  vostok::math::float4x4 v162; // [esp+52Ch] [ebp-434h] BYREF
  vostok::math::float4x4 v163; // [esp+56Ch] [ebp-3F4h] BYREF
  vostok::math::float4x4 v164; // [esp+5ACh] [ebp-3B4h] BYREF
  vostok::math::float4x4 result; // [esp+5ECh] [ebp-374h] BYREF
  vostok::math::color v166; // [esp+62Ch] [ebp-334h] BYREF
  vostok::math::color v167; // [esp+630h] [ebp-330h] BYREF
  vostok::math::color v168; // [esp+634h] [ebp-32Ch] BYREF
  vostok::math::color v169; // [esp+638h] [ebp-328h] BYREF
  const vostok::math::float3 *toe_pos; // [esp+63Ch] [ebp-324h]
  unsigned int v171; // [esp+640h] [ebp-320h]
  vostok::math::float3 v172; // [esp+644h] [ebp-31Ch] BYREF
  vostok::math::float3 *p; // [esp+650h] [ebp-310h]
  vostok::math::float3 v174; // [esp+654h] [ebp-30Ch] BYREF
  vostok::math::float3 v175; // [esp+660h] [ebp-300h] BYREF
  const vostok::math::float3 *target_leg_dir; // [esp+66Ch] [ebp-2F4h]
  float v177[4]; // [esp+670h] [ebp-2F0h] BYREF
  vostok::math::float4x4 v178; // [esp+680h] [ebp-2E0h] BYREF
  const vostok::math::float3 *original_leg_dir; // [esp+6C0h] [ebp-2A0h]
  const vostok::math::float4x4 *v180; // [esp+6C4h] [ebp-29Ch]
  vostok::math::float4x4 v181; // [esp+6C8h] [ebp-298h] BYREF
  const vostok::math::float3 *original_knee_dir; // [esp+708h] [ebp-258h]
  vostok::math::float3 v183; // [esp+70Ch] [ebp-254h] BYREF
  float v184[3]; // [esp+718h] [ebp-248h] BYREF
  const vostok::math::float3 *original_up_leg_to_foot_dir; // [esp+724h] [ebp-23Ch]
  vostok::math::float4x4 v186; // [esp+728h] [ebp-238h] BYREF
  float up_leg_alpha_angle; // [esp+76Ch] [ebp-1F4h]
  float additive_len; // [esp+770h] [ebp-1F0h]
  float up_leg_to_foot_len; // [esp+774h] [ebp-1ECh]
  const vostok::math::float3 *original_up_leg_dir; // [esp+778h] [ebp-1E8h]
  vostok::math::float3 v191; // [esp+77Ch] [ebp-1E4h] BYREF
  const vostok::math::float3 *target_up_leg_dir; // [esp+788h] [ebp-1D8h]
  const vostok::math::float4x4 *rotation_matrix; // [esp+78Ch] [ebp-1D4h]
  vostok::math::float4x4 v194; // [esp+790h] [ebp-1D0h] BYREF
  vostok::math::float3 v195; // [esp+7D0h] [ebp-190h] BYREF
  const vostok::math::float4x4 *alpha_rotation_matrix; // [esp+7DCh] [ebp-184h]
  vostok::math::float4x4 up_leg_obj_matrix; // [esp+7E0h] [ebp-180h] BYREF
  vostok::math::float4x4 foot_obj_matrix; // [esp+820h] [ebp-140h] BYREF
  const vostok::math::float3 *target_up_leg_to_foot_dir; // [esp+864h] [ebp-FCh]
  unsigned int up_leg_matrix_index; // [esp+868h] [ebp-F8h]
  unsigned int leg_matrix_index; // [esp+86Ch] [ebp-F4h]
  vostok::math::float4x4 knee_obj_matrix; // [esp+870h] [ebp-F0h] BYREF
  vostok::math::float4x4 toe_obj_matrix; // [esp+8B0h] [ebp-B0h] BYREF
  unsigned int foot_matrix_index; // [esp+8F0h] [ebp-70h]
  float leg_len; // [esp+8F4h] [ebp-6Ch]
  float v206[3]; // [esp+8F8h] [ebp-68h] BYREF
  unsigned int toe_matrix_index; // [esp+904h] [ebp-5Ch]
  vostok::math::float3 foot_pos; // [esp+908h] [ebp-58h]
  float up_leg_len; // [esp+914h] [ebp-4Ch]
  vostok::math::float4x4 leg_obj_matrix; // [esp+918h] [ebp-48h] BYREF
  unsigned int knee_matrix_index; // [esp+958h] [ebp-8h]
  float knee_len; // [esp+95Ch] [ebp-4h]

  toe_matrix_index = params->type
                   - vostok::animation::skeleton::get_root_bones_count(
                       (vostok::animation::skeleton *)this,
                       (int)this->m_skeleton);
  foot_matrix_index = (unsigned int)params->__vftable
                    - vostok::animation::skeleton::get_root_bones_count(params, (int)this->m_skeleton);
  leg_matrix_index = params->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                   - vostok::animation::skeleton::get_root_bones_count(params, (int)this->m_skeleton);
  knee_matrix_index = *((_DWORD *)&params->vostok::resources::resource_flags + 3)
                    - vostok::animation::skeleton::get_root_bones_count(params, (int)this->m_skeleton);
  up_leg_matrix_index = LODWORD(params->m_reconstruction_info_actuality_tick)
                      - vostok::animation::skeleton::get_root_bones_count(params, (int)this->m_skeleton);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)matrices);
  up_leg_len = vostok::math::float3_pod::length(v7, v6);
  survarium::weapon_user_dead_state::finalize(v8);
  knee_len = vostok::math::float3_pod::length(v10, v9);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(foot_matrix_index << 6));
  leg_len = vostok::math::float3_pod::length(v12, v11);
  vostok::math::operator*(&up_leg_obj_matrix, &matrices[up_leg_matrix_index], hip_obj_matrix);
  vostok::math::operator*(&knee_obj_matrix, &matrices[knee_matrix_index], &up_leg_obj_matrix);
  vostok::math::operator*(&leg_obj_matrix, &matrices[leg_matrix_index], &knee_obj_matrix);
  vostok::math::operator*(&foot_obj_matrix, &matrices[foot_matrix_index], &leg_obj_matrix);
  vostok::math::operator*(&toe_obj_matrix, &matrices[toe_matrix_index], &foot_obj_matrix);
  survarium::weapon_user_dead_state::finalize(v13);
  v15 = v14;
  survarium::weapon_user_dead_state::finalize(v16);
  if ( !vostok::math::is_similar(v17, v15, 0.001) )
    goto LABEL_19;
  survarium::weapon_user_dead_state::finalize(v18);
  v20 = v19;
  survarium::weapon_user_dead_state::finalize(v21);
  if ( !vostok::math::is_similar(v22, v20, 0.001)
    || (survarium::weapon_user_dead_state::finalize(v18),
        v24 = v23,
        survarium::weapon_user_dead_state::finalize(v25),
        !vostok::math::is_similar(v26, v24, 0.001))
    || (survarium::weapon_user_dead_state::finalize(v18),
        v28 = v27,
        survarium::weapon_user_dead_state::finalize(v29),
        !vostok::math::is_similar(v30, v28, 0.001)) )
  {
LABEL_19:
    if ( s_ik_legs_debug_draw_value )
    {
      v18 = (survarium::game_camera *)this;
      if ( this->m_drawer )
      {
        vostok::math::color::color(&v169, 0x64u, 0x64u, 0x64u);
        adjacent1 = v31;
        vostok::math::color::color(&v168, 0x64u, 0, 0);
        adjacent0 = v32;
        vostok::math::color::color(&v167, 0, 0, 0x64u);
        v120 = v33;
        vostok::math::color::color(&v166, 0, 0x64u, 0);
        v118 = v34;
        v116 = vostok::math::operator*(&result, &foot_obj_matrix, transform);
        v114 = vostok::math::operator*(&v164, &leg_obj_matrix, transform);
        v112 = vostok::math::operator*(&v163, &knee_obj_matrix, transform);
        v35 = vostok::math::operator*(&v162, &up_leg_obj_matrix, transform);
        survarium::legs_ik_drawer::draw_leg(
          this->m_drawer,
          v35,
          v112,
          v114,
          v116,
          v118,
          v120,
          adjacent0,
          adjacent1,
          0.0);
      }
    }
    survarium::weapon_user_dead_state::finalize(v18);
    v37 = v36;
    survarium::weapon_user_dead_state::finalize(v38);
    v40 = vostok::math::operator-(v37, v39, &v161);
    vostok::math::normalize(v40, v206);
    target_up_leg_to_foot_dir = (const vostok::math::float3 *)v206;
    survarium::weapon_user_dead_state::finalize(v41);
    v43 = v42;
    survarium::weapon_user_dead_state::finalize(v44);
    v46 = vostok::math::operator-(v43, v45, &v160);
    up_leg_to_foot_len = vostok::math::float3_pod::length(v47, &v46->x);
    epsilon = knee_len;
    survarium::weapon_user_dead_state::finalize(v48);
    v50 = v49;
    survarium::weapon_user_dead_state::finalize(v51);
    v53 = vostok::math::operator-(v50, v52, &v159);
    adjacent1a = vostok::math::normalize(v53, v158);
    survarium::weapon_user_dead_state::finalize(v54);
    v56 = v55;
    survarium::weapon_user_dead_state::finalize(v57);
    v59 = vostok::math::operator-(v56, v58, &v157);
    v60 = vostok::math::normalize(v59, v156);
    additive_len = survarium::get_additional_length(v60, adjacent1a, epsilon);
    up_leg_alpha_angle = survarium::get_angle(up_leg_len + additive_len, up_leg_to_foot_len, leg_len + additive_len);
    survarium::weapon_user_dead_state::finalize(v61);
    v63 = v62;
    survarium::weapon_user_dead_state::finalize(v64);
    v66 = vostok::math::operator-(v63, v65, &v155);
    vostok::math::normalize(v66, v184);
    original_up_leg_dir = (const vostok::math::float3 *)v184;
    survarium::weapon_user_dead_state::finalize(v67);
    v69 = v68;
    survarium::weapon_user_dead_state::finalize(v70);
    v72 = vostok::math::operator-(v69, v71, &v154);
    vostok::math::normalize(v72, &v195.x);
    original_up_leg_to_foot_dir = &v195;
    if ( !vostok::math::is_similar(original_up_leg_dir, &v195, 0.001) )
    {
      v73 = vostok::math::operator^(original_up_leg_to_foot_dir, original_up_leg_dir, &v153);
      *(vostok::math::float3 *)(&params->m_reconstruction_size + 1) = *vostok::math::normalize(v73, v152);
    }
    vostok::math::create_rotation(
      (const vostok::math::float3 *)(&params->m_reconstruction_size + 1),
      up_leg_alpha_angle);
    alpha_rotation_matrix = &v194;
    vostok::math::float4x4::transform_direction(target_up_leg_to_foot_dir, &v191, &v194);
    target_up_leg_dir = &v191;
    vostok::math::get_rotation_matrix(&v186, original_up_leg_dir, &v191);
    rotation_matrix = &v186;
    vostok::math::change_matrix_orientation(&v186, &up_leg_obj_matrix);
    qmemcpy(
      (void *)&knee_obj_matrix,
      vostok::math::operator*(&v151, &matrices[knee_matrix_index], &up_leg_obj_matrix),
      sizeof(knee_obj_matrix));
    qmemcpy(
      (void *)&leg_obj_matrix,
      vostok::math::operator*(&v150, &matrices[leg_matrix_index], &knee_obj_matrix),
      sizeof(leg_obj_matrix));
    survarium::weapon_user_dead_state::finalize(0);
    v75 = v74;
    survarium::weapon_user_dead_state::finalize(v76);
    v78 = vostok::math::operator-(v75, v77, &v149);
    vostok::math::normalize(v78, &v183.x);
    original_knee_dir = &v183;
    vostok::math::get_rotation_matrix(&v181, &v183, target_up_leg_to_foot_dir);
    v180 = &v181;
    vostok::math::change_matrix_orientation(&v181, &knee_obj_matrix);
    qmemcpy(
      (void *)&leg_obj_matrix,
      vostok::math::operator*(&v148, &matrices[leg_matrix_index], &knee_obj_matrix),
      sizeof(leg_obj_matrix));
    qmemcpy(
      (void *)&foot_obj_matrix,
      vostok::math::operator*(&v147, &matrices[foot_matrix_index], &leg_obj_matrix),
      sizeof(foot_obj_matrix));
    survarium::weapon_user_dead_state::finalize(0);
    v80 = v79;
    survarium::weapon_user_dead_state::finalize(v81);
    v83 = vostok::math::operator-(v80, v82, &v146);
    vostok::math::normalize(v83, v177);
    original_leg_dir = (const vostok::math::float3 *)v177;
    survarium::weapon_user_dead_state::finalize(v84);
    v86 = v85;
    survarium::weapon_user_dead_state::finalize(v87);
    v89 = vostok::math::operator-(v86, v88, &v145);
    vostok::math::normalize(v89, &v175.x);
    target_leg_dir = &v175;
    vostok::math::get_rotation_matrix(&v178, original_leg_dir, &v175);
    LODWORD(v177[3]) = &v178;
    vostok::math::change_matrix_orientation(&v178, &leg_obj_matrix);
    qmemcpy((void *)&foot_obj_matrix, target_foot_obj_matrix, sizeof(foot_obj_matrix));
    if ( s_ik_legs_debug_draw_value && this->m_drawer )
    {
      vostok::math::color::color(&v144, 0x96u, 0x96u, 0x96u);
      adjacent1b = v90;
      vostok::math::color::color(&v143, 0xFFu, 0, 0);
      adjacent0a = v91;
      vostok::math::color::color(&v142, 0, 0, 0xFFu);
      v121 = v92;
      vostok::math::color::color(&v141, 0, 0xFFu, 0);
      v119 = v93;
      v117 = vostok::math::operator*(&v140, target_foot_obj_matrix, transform);
      v115 = vostok::math::operator*(&v139, &leg_obj_matrix, transform);
      v113 = vostok::math::operator*(&v138, &knee_obj_matrix, transform);
      v94 = vostok::math::operator*(&v137, &up_leg_obj_matrix, transform);
      survarium::legs_ik_drawer::draw_leg(
        this->m_drawer,
        v94,
        v113,
        v115,
        v117,
        v119,
        v121,
        adjacent0a,
        adjacent1b,
        0.0);
      if ( LOBYTE(params->m_children_resources.m_thread_id) )
      {
        LOBYTE(v95) = params->m_children_resources.m_thread_id;
        survarium::weapon_user_dead_state::finalize(v95);
        vostok::math::float4x4::transform_position(v96, &v174, transform);
        p = &v174;
        vostok::math::color::color(&v136, 0, 0xFFu, 0);
        survarium::legs_ik_drawer::draw_cross(this->m_drawer, p, 0.050000001, v97, 0);
      }
      if ( BYTE1(params->m_children_resources.m_thread_id) )
      {
        bone = vostok::animation::skeleton::get_bone(
                 (vostok::animation::skeleton *)this->m_skeleton,
                 (unsigned int)params->__vftable);
        v100 = boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>::operator[](
                 v99,
                 (int)bone);
        bone_index = vostok::animation::skeleton::get_bone_index(
                       (vostok::animation::skeleton *)this->m_skeleton,
                       (const vostok::animation::skeleton_bone *)v100);
        v171 = bone_index - vostok::animation::skeleton::get_root_bones_count(v102, (int)this->m_skeleton);
        vostok::math::operator*(&v135, &matrices[v171], target_foot_obj_matrix);
        survarium::weapon_user_dead_state::finalize(v103);
        vostok::math::float4x4::transform_position(v104, &v172, transform);
        toe_pos = &v172;
        adjacent1c = s_ik_foot_capsule_radius_value;
        v105 = vostok::math::create_translation(&v134, &v172);
        survarium::legs_ik_drawer::draw_origin(this->m_drawer, v105, adjacent1c, 0);
      }
    }
    relative_matrix = vostok::math::get_relative_matrix(&v133, &up_leg_obj_matrix, hip_obj_matrix);
    qmemcpy((void *)&matrices[up_leg_matrix_index], relative_matrix, sizeof(vostok::math::float4x4));
    v107 = vostok::math::get_relative_matrix(&v132, &knee_obj_matrix, &up_leg_obj_matrix);
    qmemcpy((void *)&matrices[knee_matrix_index], v107, sizeof(vostok::math::float4x4));
    v108 = vostok::math::get_relative_matrix(&v131, &leg_obj_matrix, &knee_obj_matrix);
    qmemcpy((void *)&matrices[leg_matrix_index], v108, sizeof(vostok::math::float4x4));
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)matrices);
    foot_pos = *v109;
    v110 = vostok::math::get_relative_matrix(&v130, target_foot_obj_matrix, &leg_obj_matrix);
    qmemcpy((void *)&matrices[foot_matrix_index], v110, sizeof(vostok::math::float4x4));
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)matrices);
    *v111 = foot_pos;
  }
}
