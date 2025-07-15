// local variable allocation has failed, the output may be wrong!
void __userpurge vostok::render::stage_lights::make_skin_scattering_texture(
        int l@<eax>,
        vostok::render::stage_lights *this,
        float instance)
{
  vostok::render::render_target *m_object; // edx
  vostok::render::render_target *v5; // eax
  ID3D11RenderTargetView *m_rt; // ecx
  const char *m_conflicted_key_name; // eax
  vostok::render::backend *v8; // ecx
  int y; // eax
  vostok::render::renderer_context *m_context; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  float x; // xmm4_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // ecx
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm3_4
  float v28; // xmm4_4
  float v29; // xmm3_4
  float v30; // xmm2_4
  float z; // xmm1_4
  vostok::render::enum_vertex_input_type v32; // ecx
  int v33; // eax
  vostok::render::material_effects *material_effects; // eax
  char *v35; // esi
  vostok::render::constants_handler<1> *v36; // ebx
  vostok::render::shader_constant_host *m_c_use_shadows; // eax
  vostok::render::shader_constant_host *m_c_is_shadower; // eax
  vostok::render::material_effects_instance *v39; // eax
  vostok::render::material_effects *p_m_material_effects; // eax
  _DWORD *v41; // eax
  unsigned int v42; // ecx
  vostok::render::shader_constant_host *v43; // eax
  unsigned int v44; // edx
  int m_buffer_index; // ecx
  vostok::render::shader_constant_host *m_c_light_position; // eax
  int v47; // ecx
  vostok::render::shader_constant_host *m_c_light_direction; // eax
  int v49; // ecx
  long double v50; // st7
  vostok::render::shader_constant_host *m_c_light_range; // eax
  unsigned int v52; // edx
  int v53; // ecx
  vostok::render::shader_constant_host *m_c_light_spot_penumbra_half_angle_cosine; // eax
  int v55; // ecx
  unsigned __int16 m_class_id; // dx
  vostok::render::shader_constant_host *m_c_light_spot_umbra_half_angle_cosine; // eax
  int v58; // ecx
  unsigned __int16 v59; // dx
  float v60; // xmm0_4
  float v61; // xmm0_4
  vostok::render::shader_constant_host *m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine; // ecx
  unsigned int v63; // edx
  int v64; // eax
  unsigned __int16 v65; // dx
  unsigned int m_slot_index; // ecx
  vostok::render::shader_constant_host *m_c_light_color; // eax
  int v68; // ecx
  unsigned __int16 v69; // dx
  vostok::render::light *v70; // ecx
  const vostok::math::float3 *v71; // eax
  vostok::render::shader_constant_host *v72; // eax
  int v73; // ecx
  vostok::render::shader_constant_host *v74; // eax
  vostok::render::material_effects_instance *v75; // eax
  vostok::render::material_effects *v76; // eax
  _DWORD *v77; // eax
  vostok::render::shader_constant_host *v78; // eax
  int v79; // ecx
  vostok::render::shader_constant_host *v80; // eax
  int v81; // ecx
  vostok::render::shader_constant_host *v82; // eax
  vostok::render::light *v83; // ecx
  unsigned __int16 v84; // dx
  const vostok::math::float3 *v85; // eax
  vostok::render::shader_constant_host *v86; // eax
  vostok::render::textures_handler<0> *v87; // ecx
  vostok::render::shader_constant_host *v88; // eax
  unsigned int v89; // ecx
  int v90; // ecx
  vostok::render::base_scene_view *v91; // eax
  int v92; // xmm0_4
  vostok::render::shader_constant_host *m_far_fog_color_and_distance; // eax
  vostok::render::base_scene_view *v94; // eax
  float v95; // xmm0_4
  float v96; // xmm0_4
  vostok::render::shader_constant_host *m_ambient_color; // eax
  vostok::render::enum_vertex_input_type v98; // edx
  vostok::render::render_target *v99; // eax
  double v100; // st7
  vostok::render::res_effect *v101; // ecx
  vostok::render::res_effect *v102; // eax
  const char *v103; // esi
  vostok::render::base_scene_view *v104; // eax
  float v105; // xmm0_4
  const char *v106; // esi
  float v107; // xmm0_4
  vostok::render::shader_constant_host *v108; // eax
  vostok::render::render_target *v109; // eax
  __int32 v110; // ecx
  vostok::render::material_effects *v111; // eax
  _DWORD *v112; // eax
  const char *v113; // esi
  vostok::render::base_scene_view *v114; // eax
  float v115; // xmm0_4
  const char *v116; // esi
  float v117; // xmm0_4
  vostok::render::shader_constant_host *v118; // eax
  vostok::render::constants_handler<1> *v119; // edi
  vostok::render::render_target *v120; // eax
  vostok::render::backend *v121; // ecx
  vostok::render::material_effects_instance *v122; // ecx
  vostok::render::material_effects *v123; // eax
  _DWORD *v124; // eax
  unsigned int v125; // ecx
  const char *v126; // esi
  vostok::render::base_scene_view *v127; // eax
  float v128; // xmm0_4
  const char *v129; // esi
  float v130; // xmm0_4
  vostok::render::shader_constant_host *v131; // eax
  vostok::render::constants_handler<1> *v132; // edi
  vostok::render::render_target *v133; // eax
  vostok::render::backend *v134; // ecx
  __int32 v135; // ecx
  vostok::render::material_effects *v136; // eax
  _DWORD *v137; // eax
  const char *v138; // esi
  vostok::render::base_scene_view *v139; // eax
  float v140; // xmm0_4
  const char *v141; // esi
  float v142; // xmm0_4
  vostok::render::shader_constant_host *v143; // eax
  vostok::render::constants_handler<1> *v144; // edi
  vostok::render::render_target *v145; // eax
  vostok::render::backend *v146; // ecx
  vostok::render::material_effects_instance *v147; // ecx
  vostok::render::material_effects *v148; // eax
  _DWORD *v149; // eax
  unsigned int v150; // ecx
  const char *v151; // esi
  vostok::render::base_scene_view *v152; // eax
  float v153; // xmm0_4
  const char *v154; // esi
  float v155; // xmm0_4
  vostok::render::shader_constant_host *v156; // eax
  vostok::render::constants_handler<1> *v157; // edi
  vostok::render::render_target *v158; // eax
  vostok::render::backend *v159; // ecx
  __int32 v160; // ecx
  vostok::render::material_effects *v161; // eax
  _DWORD *v162; // eax
  const char *v163; // esi
  const char *v164; // esi
  vostok::render::render_target *v165; // eax
  vostok::render::render_target *v166; // eax
  const char *v167; // ebx
  vostok::render::resource_manager *v168; // ecx
  const char *v169; // eax
  bool v170; // zf
  int v171; // eax
  survarium::game *m_game; // edx
  vostok::render::material_effects_instance *v173; // ecx
  vostok::render::material_effects *v174; // eax
  _DWORD *v175; // eax
  unsigned int v176; // ecx
  vostok::render::backend *v177; // esi
  vostok::render::constants_handler<1> *v178; // edi
  vostok::render::base_scene_view *v179; // eax
  float v180; // xmm0_4
  float v181; // xmm0_4
  vostok::render::shader_constant_host *v182; // eax
  vostok::render::renderer_context *v183; // ecx
  vostok::render::render_target *v184; // eax
  ID3D11RenderTargetView *v185; // ebp
  const char *v186; // ebx
  vostok::render::resource_manager *v187; // ecx
  int v188; // eax
  survarium::game *v189; // edx
  float _X[2]; // [esp+14h] [ebp-35Ch] BYREF
  float v191; // [esp+1Ch] [ebp-354h]
  __int128 light_direction; // [esp+2Ch] [ebp-344h] OVERLAPPED BYREF
  char src_ptr[8]; // [esp+3Ch] [ebp-334h] BYREF
  float light_range; // [esp+44h] [ebp-32Ch] BYREF
  vostok::render::shader_constant_buffer *v195; // [esp+48h] [ebp-328h] BYREF
  vostok::render::shader_constant_buffer *v196; // [esp+4Ch] [ebp-324h] BYREF
  vostok::render::enum_vertex_input_type v197; // [esp+50h] [ebp-320h]
  vostok::math::float3 v198; // [esp+54h] [ebp-31Ch] BYREF
  int v199; // [esp+60h] [ebp-310h]
  float penumbra_half_angle_cosine; // [esp+68h] [ebp-308h] BYREF
  float umbra_half_angle_cosine; // [esp+6Ch] [ebp-304h] BYREF
  vostok::math::float3 light_position; // [esp+70h] [ebp-300h] BYREF
  char v203[4]; // [esp+7Ch] [ebp-2F4h] BYREF
  vostok::math::float3 v204; // [esp+80h] [ebp-2F0h] BYREF
  int v205; // [esp+8Ch] [ebp-2E4h] BYREF
  int v206; // [esp+90h] [ebp-2E0h] BYREF
  char v207[4]; // [esp+94h] [ebp-2DCh] BYREF
  _BYTE arg[20]; // [esp+98h] [ebp-2D8h] BYREF
  vostok::math::float3 v209; // [esp+ACh] [ebp-2C4h] BYREF
  int v210; // [esp+B8h] [ebp-2B8h]
  vostok::math::float3 v211; // [esp+BCh] [ebp-2B4h] BYREF
  int v212; // [esp+C8h] [ebp-2A8h]
  vostok::math::float3 v213; // [esp+CCh] [ebp-2A4h] BYREF
  int v214; // [esp+D8h] [ebp-298h]
  vostok::math::float3 v215; // [esp+DCh] [ebp-294h] BYREF
  int v216; // [esp+E8h] [ebp-288h]
  vostok::math::float3 v217; // [esp+ECh] [ebp-284h] BYREF
  int v218; // [esp+F8h] [ebp-278h]
  vostok::math::float3 v219; // [esp+FCh] [ebp-274h] BYREF
  int v220; // [esp+108h] [ebp-268h]
  vostok::math::float3 v221; // [esp+10Ch] [ebp-264h] BYREF
  float v222; // [esp+118h] [ebp-258h]
  D3D11_VIEWPORT tmp_viewport; // [esp+11Ch] [ebp-254h] BYREF
  float weights_h[9]; // [esp+134h] [ebp-23Ch] BYREF
  float offsets_h[9]; // [esp+158h] [ebp-218h] BYREF
  float weights_v[9]; // [esp+17Ch] [ebp-1F4h] BYREF
  float offsets_v[9]; // [esp+1A0h] [ebp-1D0h] BYREF
  vostok::math::float4 blur_offsets_weights[9]; // [esp+1C4h] [ebp-1ACh] BYREF
  D3D11_VIEWPORT orig_viewport; // [esp+254h] [ebp-11Ch] BYREF
  vostok::math::float4x4 result; // [esp+26Ch] [ebp-104h] BYREF
  vostok::math::float4x4 v231; // [esp+2ACh] [ebp-C4h] BYREF
  vostok::math::float4 kernel_offsets[8]; // [esp+2ECh] [ebp-84h] BYREF

  m_object = this->m_rt_skin_scattering_stretch.m_object;
  v5 = this->m_rt_skin_scattering_temp.m_object;
  if ( v5 )
    m_rt = v5->m_rt;
  else
    m_rt = 0;
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
       + 535) != m_rt )
  {
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
    *((_BYTE *)m_conflicted_key_name + 163) = 1;
  }
  if ( m_object )
    v8 = (vostok::render::backend *)m_object->m_rt;
  else
    v8 = 0;
  if ( *((vostok::render::backend **)m_conflicted_key_name + 536) != v8 )
  {
    *((_DWORD *)m_conflicted_key_name + 536) = v8;
    *((_BYTE *)m_conflicted_key_name + 164) = 1;
  }
  if ( *((_DWORD *)m_conflicted_key_name + 537) )
  {
    *((_DWORD *)m_conflicted_key_name + 537) = 0;
    *((_BYTE *)m_conflicted_key_name + 165) = 1;
  }
  if ( *((_DWORD *)m_conflicted_key_name + 538) )
  {
    *((_DWORD *)m_conflicted_key_name + 538) = 0;
    *((_BYTE *)m_conflicted_key_name + 166) = 1;
  }
  LOBYTE(v8) = *((_DWORD *)m_conflicted_key_name + 539) != 0;
  *((_BYTE *)m_conflicted_key_name + 167) |= (unsigned __int8)v8;
  _X[1] = 0.0;
  *((_DWORD *)m_conflicted_key_name + 539) = 0;
  vostok::render::backend::clear_render_targets(v8, (int)m_conflicted_key_name, -1.0, 0.0, 0.0, _X[1], v191);
  y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  v206 = 1;
  (*(void (__stdcall **)(int, int *, D3D11_VIEWPORT *))(*(_DWORD *)y + 380))(y, &v206, &orig_viewport);
  tmp_viewport.TopLeftX = 0.0;
  tmp_viewport.TopLeftY = 0.0;
  tmp_viewport.Width = (float)*((unsigned int *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                              + 29);
  tmp_viewport.Height = (float)*((unsigned int *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                               + 29);
  tmp_viewport.MinDepth = 0.0;
  LODWORD(tmp_viewport.MaxDepth) = clear_value;
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 176))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    1,
    &tmp_viewport);
  m_context = this->m_context;
  v11 = *(float *)(l + 152);
  v12 = *(float *)(l + 148);
  x = m_context->m_v.k.x;
  v14 = m_context->m_v.j.x * v11;
  light_range = *(float *)(l + 224);
  *(_QWORD *)&arg[8] = *(_QWORD *)(l + 132);
  v15 = *(float *)(l + 156);
  v16 = (float)((float)(v14 + (float)(x * v15)) + (float)(v12 * m_context->m_v.i.x)) + m_context->m_v.c.x;
  v17 = m_context->m_v.j.y;
  light_position.x = v16;
  v18 = (float)((float)((float)(m_context->m_v.i.y * v12) + (float)(v17 * v11)) + (float)(m_context->m_v.k.y * v15))
      + m_context->m_v.c.y;
  v19 = m_context->m_v.k.x;
  light_position.y = v18;
  v20 = *(float *)(l + 140);
  v21 = (float)(m_context->m_v.i.z * v12) + (float)(m_context->m_v.j.z * v11);
  v22 = *(float *)(l + 164);
  v23 = m_context->m_v.k.z * v15;
  v24 = *(float *)(l + 172);
  v25 = (float)(v21 + v23) + m_context->m_v.c.z;
  v26 = *(float *)(l + 168);
  light_position.z = v25;
  v27 = (float)((float)(m_context->m_v.j.x * v26) + (float)(v19 * v24)) + (float)(m_context->m_v.i.x * v22);
  v28 = m_context->m_v.j.y;
  *(float *)&light_direction = v27;
  *((float *)&light_direction + 1) = (float)((float)(m_context->m_v.i.y * v22) + (float)(v28 * v26))
                                   + (float)(m_context->m_v.k.y * v24);
  v29 = m_context->m_v.i.z * v22;
  v30 = m_context->m_v.j.z * v26;
  z = m_context->m_v.k.z;
  *(float *)&arg[16] = v20;
  v32 = *(_DWORD *)LODWORD(instance);
  v33 = *(_DWORD *)(l + 380) & 0xF;
  *((float *)&light_direction + 2) = (float)(v29 + v30) + (float)(z * v24);
  v197 = v32;
  if ( v33 )
  {
    if ( v33 != 1 )
    {
      material_effects = vostok::render::render_surface::get_material_effects((vostok::render::render_surface *)v32);
      vostok::render::res_effect::apply(
        (vostok::render::res_effect *)1,
        &material_effects->m_effects[22].m_object->__vftable);
      v35 = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v36 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                   + 1476);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        this->m_c_light_direction,
        (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
      + 123,
        (const vostok::math::float3 *)&light_direction);
      ++*((_DWORD *)v35 + 23);
      m_c_use_shadows = this->m_c_use_shadows;
      *(_DWORD *)arg = 0;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        m_c_use_shadows,
        v36,
        (const vostok::math::float3 *)arg);
      ++*((_DWORD *)v35 + 23);
      m_c_is_shadower = this->m_c_is_shadower;
      v204.y = 0.0;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        m_c_is_shadower,
        v36,
        (vostok::math::float3 *)&v204.elements[1]);
LABEL_81:
      ++*((_DWORD *)v35 + 23);
      goto LABEL_82;
    }
    v39 = *(vostok::render::material_effects_instance **)(v32 + 148);
    if ( !v39 || s_use_one_material_value )
      p_m_material_effects = s_nomaterial_material_effects[*(_DWORD *)(v32 + 4)];
    else
      p_m_material_effects = &v39->m_material_effects;
    v41 = &p_m_material_effects->m_effects[22].m_object->__vftable;
    v42 = (v41[71] - v41[70]) >> 2;
    if ( v42 > 1 )
    {
      v41[69] = 1;
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v42, LODWORD(v191));
    }
    v43 = this->m_c_is_shadower;
    v35 = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v44 = v43->m_update_markers[1];
    v204.z = 0.0;
    if ( v44 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                + 573) )
    {
      m_buffer_index = v43->m_shader_slots[1].m_buffer_index;
      if ( m_buffer_index != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          v43->m_shader_slots[1].m_slot_index,
          (unsigned __int8)v43->m_shader_slots[1].m_class_id,
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                   + 371)
                                                                 + 16)
                                                     + 4 * m_buffer_index),
          (const char *)&v204.elements[2]);
    }
    ++*((_DWORD *)v35 + 23);
    m_c_light_position = this->m_c_light_position;
    if ( m_c_light_position->m_update_markers[1] == *((_DWORD *)v35 + 573) )
    {
      v47 = m_c_light_position->m_shader_slots[1].m_buffer_index;
      if ( v47 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          m_c_light_position->m_shader_slots[1].m_slot_index,
          (unsigned __int8)m_c_light_position->m_shader_slots[1].m_class_id,
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v35 + 371) + 16) + 4 * v47),
          (const char *)&light_position);
    }
    ++*((_DWORD *)v35 + 23);
    m_c_light_direction = this->m_c_light_direction;
    if ( m_c_light_direction->m_update_markers[1] == *((_DWORD *)v35 + 573) )
    {
      v49 = m_c_light_direction->m_shader_slots[1].m_buffer_index;
      if ( v49 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          m_c_light_direction->m_shader_slots[1].m_slot_index,
          (unsigned __int8)m_c_light_direction->m_shader_slots[1].m_class_id,
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v35 + 371) + 16) + 4 * v49),
          (const char *)&light_direction);
    }
    ++*((_DWORD *)v35 + 23);
    v50 = sinf(*(float *)(l + 188) * 0.5);
    m_c_light_range = this->m_c_light_range;
    v52 = m_c_light_range->m_update_markers[1];
    *(float *)src_ptr = light_range / v50;
    if ( v52 == *((_DWORD *)v35 + 573) )
    {
      v53 = m_c_light_range->m_shader_slots[1].m_buffer_index;
      if ( v53 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          m_c_light_range->m_shader_slots[1].m_slot_index,
          (unsigned __int8)m_c_light_range->m_shader_slots[1].m_class_id,
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v35 + 371) + 16) + 4 * v53),
          src_ptr);
    }
    ++*((_DWORD *)v35 + 23);
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      this->m_c_light_attenuation_power,
      (vostok::render::constants_handler<1> *)v35 + 123,
      (const vostok::math::float3 *)(l + 220));
    ++*((_DWORD *)v35 + 23);
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      this->m_c_diffuse_influence_factor,
      (vostok::render::constants_handler<1> *)v35 + 123,
      (const vostok::math::float3 *)(l + 340));
    ++*((_DWORD *)v35 + 23);
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      this->m_c_specular_influence_factor,
      (vostok::render::constants_handler<1> *)v35 + 123,
      (const vostok::math::float3 *)(l + 344));
    ++*((_DWORD *)v35 + 23);
    penumbra_half_angle_cosine = cosf(*(float *)(l + 188) * 0.5);
    m_c_light_spot_penumbra_half_angle_cosine = this->m_c_light_spot_penumbra_half_angle_cosine;
    if ( m_c_light_spot_penumbra_half_angle_cosine->m_update_markers[1] == *((_DWORD *)v35 + 573) )
    {
      v55 = m_c_light_spot_penumbra_half_angle_cosine->m_shader_slots[1].m_buffer_index;
      if ( v55 != 0xFFFF )
      {
        m_class_id = m_c_light_spot_penumbra_half_angle_cosine->m_shader_slots[1].m_class_id;
        *(_DWORD *)src_ptr = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v35 + 371) + 16) + 4 * v55);
        vostok::render::shader_constant_buffer::set_memory(
          m_c_light_spot_penumbra_half_angle_cosine->m_shader_slots[1].m_slot_index,
          (unsigned __int8)m_class_id,
          *(vostok::render::shader_constant_buffer **)src_ptr,
          (const char *)&penumbra_half_angle_cosine);
      }
    }
    ++*((_DWORD *)v35 + 23);
    umbra_half_angle_cosine = cosf(*(float *)(l + 160) * 0.5);
    m_c_light_spot_umbra_half_angle_cosine = this->m_c_light_spot_umbra_half_angle_cosine;
    if ( m_c_light_spot_umbra_half_angle_cosine->m_update_markers[1] == *((_DWORD *)v35 + 573) )
    {
      v58 = m_c_light_spot_umbra_half_angle_cosine->m_shader_slots[1].m_buffer_index;
      if ( v58 != 0xFFFF )
      {
        v59 = m_c_light_spot_umbra_half_angle_cosine->m_shader_slots[1].m_class_id;
        *(_DWORD *)src_ptr = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v35 + 371) + 16) + 4 * v58);
        vostok::render::shader_constant_buffer::set_memory(
          m_c_light_spot_umbra_half_angle_cosine->m_shader_slots[1].m_slot_index,
          (unsigned __int8)v59,
          *(vostok::render::shader_constant_buffer **)src_ptr,
          (const char *)&umbra_half_angle_cosine);
      }
    }
    v60 = umbra_half_angle_cosine;
    ++*((_DWORD *)v35 + 23);
    v61 = v60 - penumbra_half_angle_cosine;
    if ( v61 <= 0.000099999997 )
      v61 = FLOAT_0_000099999997;
    m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine = this->m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine;
    v63 = m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine->m_update_markers[1];
    *(float *)&v195 = *(float *)&clear_value / v61;
    if ( v63 == *((_DWORD *)v35 + 573) )
    {
      v64 = m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine->m_shader_slots[1].m_buffer_index;
      if ( v64 != 0xFFFF )
      {
        v65 = m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine->m_shader_slots[1].m_class_id;
        m_slot_index = m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine->m_shader_slots[1].m_slot_index;
        *(_DWORD *)src_ptr = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v35 + 371) + 16) + 4 * v64);
        vostok::render::shader_constant_buffer::set_memory(
          m_slot_index,
          (unsigned __int8)v65,
          *(vostok::render::shader_constant_buffer **)src_ptr,
          (const char *)&v195);
      }
    }
    ++*((_DWORD *)v35 + 23);
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      this->m_c_light_spot_falloff,
      (vostok::render::constants_handler<1> *)v35 + 123,
      (const vostok::math::float3 *)(l + 204));
    ++*((_DWORD *)v35 + 23);
    m_c_light_color = this->m_c_light_color;
    if ( m_c_light_color->m_update_markers[1] == *((_DWORD *)v35 + 573) )
    {
      v68 = m_c_light_color->m_shader_slots[1].m_buffer_index;
      if ( v68 != 0xFFFF )
      {
        v69 = m_c_light_color->m_shader_slots[1].m_class_id;
        v195 = *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v35 + 371) + 16) + 4 * v68);
        vostok::render::shader_constant_buffer::set_memory(
          m_c_light_color->m_shader_slots[1].m_slot_index,
          (unsigned __int8)v69,
          v195,
          &arg[8]);
      }
    }
    ++*((_DWORD *)v35 + 23);
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      this->m_c_light_intensity,
      (vostok::render::constants_handler<1> *)v35 + 123,
      (const vostok::math::float3 *)(l + 144));
    ++*((_DWORD *)v35 + 23);
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      this->m_c_lighting_model,
      (vostok::render::constants_handler<1> *)v35 + 123,
      (const vostok::math::float3 *)(l + 376));
    ++*((_DWORD *)v35 + 23);
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      this->m_c_eye_ray_corner,
      (vostok::render::constants_handler<1> *)v35 + 123,
      this->m_context->m_eye_rays);
    ++*((_DWORD *)v35 + 23);
    if ( !vostok::render::light::is_cast_shadows(v70, l)
      || !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
          + 267) )
    {
      LODWORD(_X[1]) = &v196;
      v74 = this->m_c_use_shadows;
      v196 = 0;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        v74,
        (vostok::render::constants_handler<1> *)v35 + 123,
        (const vostok::math::float3 *)&v196);
      goto LABEL_81;
    }
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      this->m_c_shadow_transparency,
      (vostok::render::constants_handler<1> *)v35 + 123,
      (const vostok::math::float3 *)(l + 228));
    ++*((_DWORD *)v35 + 23);
    v71 = (const vostok::math::float3 *)vostok::math::transpose(&result, &this->m_view_to_light_matrix);
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      this->m_c_view_to_light_matrix,
      (vostok::render::constants_handler<1> *)v35 + 123,
      v71);
    ++*((_DWORD *)v35 + 23);
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      this->m_c_shadow_z_bias,
      (vostok::render::constants_handler<1> *)v35 + 123,
      (const vostok::math::float3 *)&this->m_shadow_z_bias);
    ++*((_DWORD *)v35 + 23);
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      this->m_c_shadow_map_size,
      (vostok::render::constants_handler<1> *)v35 + 123,
      (const vostok::math::float3 *)&this->m_shadow_map_size);
    ++*((_DWORD *)v35 + 23);
    *(_DWORD *)&arg[4] = 1;
    v72 = this->m_c_use_shadows;
    if ( v72->m_update_markers[1] == *((_DWORD *)v35 + 573) )
    {
      v73 = v72->m_shader_slots[1].m_buffer_index;
      if ( v73 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          v72->m_shader_slots[1].m_slot_index,
          (unsigned __int8)v72->m_shader_slots[1].m_class_id,
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v35 + 371) + 16) + 4 * v73),
          &arg[4]);
    }
    ++*((_DWORD *)v35 + 23);
    vostok::render::backend::set_ps_texture(
      (vostok::render::backend *)v35,
      (vostok::render::textures_handler<0> *)&stru_9649F4);
    v35 = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  }
  else
  {
    v75 = *(vostok::render::material_effects_instance **)(v32 + 148);
    if ( !v75 || s_use_one_material_value )
    {
      v32 = *(_DWORD *)(v32 + 4);
      v76 = s_nomaterial_material_effects[v32];
    }
    else
    {
      v76 = &v75->m_material_effects;
    }
    v77 = &v76->m_effects[22].m_object->__vftable;
    if ( (unsigned int)((v77[71] - v77[70]) >> 2) > 1 )
    {
      v77[69] = 1;
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v32, LODWORD(v191));
    }
    v78 = this->m_c_light_position;
    v35 = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( v78->m_update_markers[1] == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                     + 573) )
    {
      v79 = v78->m_shader_slots[1].m_buffer_index;
      if ( v79 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          v78->m_shader_slots[1].m_slot_index,
          (unsigned __int8)v78->m_shader_slots[1].m_class_id,
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                   + 371)
                                                                 + 16)
                                                     + 4 * v79),
          (const char *)&light_position);
    }
    ++*((_DWORD *)v35 + 23);
    v80 = this->m_c_light_range;
    if ( v80->m_update_markers[1] == *((_DWORD *)v35 + 573) )
    {
      v81 = v80->m_shader_slots[1].m_buffer_index;
      if ( v81 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          v80->m_shader_slots[1].m_slot_index,
          (unsigned __int8)v80->m_shader_slots[1].m_class_id,
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v35 + 371) + 16) + 4 * v81),
          (const char *)&light_range);
    }
    ++*((_DWORD *)v35 + 23);
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      this->m_c_light_attenuation_power,
      (vostok::render::constants_handler<1> *)v35 + 123,
      (const vostok::math::float3 *)(l + 220));
    ++*((_DWORD *)v35 + 23);
    v82 = this->m_c_is_shadower;
    v83 = (vostok::render::light *)v82->m_update_markers[1];
    *(_DWORD *)v207 = 0;
    if ( v83 == *((vostok::render::light **)v35 + 573) )
    {
      v83 = (vostok::render::light *)v82->m_shader_slots[1].m_buffer_index;
      if ( v83 != (vostok::render::light *)0xFFFF )
      {
        v84 = v82->m_shader_slots[1].m_class_id;
        v196 = *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v35 + 371) + 16) + 4 * (_DWORD)v83);
        vostok::render::shader_constant_buffer::set_memory(
          v82->m_shader_slots[1].m_slot_index,
          (unsigned __int8)v84,
          v196,
          v207);
      }
    }
    ++*((_DWORD *)v35 + 23);
    if ( !vostok::render::light::is_cast_shadows(v83, l)
      || !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
          + 267) )
    {
      v88 = this->m_c_use_shadows;
      v89 = v88->m_update_markers[1];
      *(_DWORD *)v203 = 0;
      if ( v89 == *((_DWORD *)v35 + 573) )
      {
        v90 = v88->m_shader_slots[1].m_buffer_index;
        if ( v90 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            v88->m_shader_slots[1].m_slot_index,
            (unsigned __int8)v88->m_shader_slots[1].m_class_id,
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v35 + 371) + 16) + 4 * v90),
            v203);
      }
      goto LABEL_81;
    }
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      this->m_c_shadow_transparency,
      (vostok::render::constants_handler<1> *)v35 + 123,
      (const vostok::math::float3 *)(l + 228));
    ++*((_DWORD *)v35 + 23);
    v85 = (const vostok::math::float3 *)vostok::math::transpose(&v231, &this->m_view_to_light_matrix);
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      this->m_c_view_to_light_matrix,
      (vostok::render::constants_handler<1> *)v35 + 123,
      v85);
    ++*((_DWORD *)v35 + 23);
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      this->m_c_shadow_z_bias,
      (vostok::render::constants_handler<1> *)v35 + 123,
      (const vostok::math::float3 *)&this->m_shadow_z_bias);
    ++*((_DWORD *)v35 + 23);
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      this->m_c_shadow_map_size,
      (vostok::render::constants_handler<1> *)v35 + 123,
      (const vostok::math::float3 *)&this->m_shadow_map_size);
    ++*((_DWORD *)v35 + 23);
    v205 = 1;
    v86 = this->m_c_use_shadows;
    v87 = (vostok::render::textures_handler<0> *)v86->m_update_markers[1];
    if ( v87 == *((vostok::render::textures_handler<0> **)v35 + 573) )
    {
      v87 = (vostok::render::textures_handler<0> *)v86->m_shader_slots[1].m_buffer_index;
      if ( v87 != (vostok::render::textures_handler<0> *)0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          v86->m_shader_slots[1].m_slot_index,
          (unsigned __int8)v86->m_shader_slots[1].m_class_id,
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v35 + 371) + 16) + 4 * (_DWORD)v87),
          (const char *)&v205);
    }
    ++*((_DWORD *)v35 + 23);
    v35[159] = vostok::render::textures_handler<0>::set_overwrite(
                 v87,
                 v35 + 1488,
                 (vostok::render::res_texture *)&stru_9649F4,
                 this->m_shadow_depth_stencil_texture[*(_DWORD *)(l + 368)].m_object);
    v35 = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  }
LABEL_82:
  v91 = this->m_context->m_scene_view.m_object;
  v219 = *(vostok::math::float3 *)&v91[1].m_fat_it.m_link_target;
  v92 = *((_DWORD *)&v91[1].m_memory_type_data + 1);
  LODWORD(_X[1]) = &v219;
  m_far_fog_color_and_distance = this->m_far_fog_color_and_distance;
  v220 = v92;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    m_far_fog_color_and_distance,
    (vostok::render::constants_handler<1> *)v35 + 123,
    &v219);
  ++*((_DWORD *)v35 + 23);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_near_fog_distance,
    (vostok::render::constants_handler<1> *)v35 + 123,
    (const vostok::math::float3 *)&this->m_context->m_scene_view.m_object[1].vostok::resources::unmanaged_intrusive_base);
  ++*((_DWORD *)v35 + 23);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_c_light_color,
    (vostok::render::constants_handler<1> *)v35 + 123,
    (const vostok::math::float3 *)&arg[8]);
  ++*((_DWORD *)v35 + 23);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_c_light_intensity,
    (vostok::render::constants_handler<1> *)v35 + 123,
    (const vostok::math::float3 *)(l + 144));
  ++*((_DWORD *)v35 + 23);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_c_lighting_model,
    (vostok::render::constants_handler<1> *)v35 + 123,
    (const vostok::math::float3 *)(l + 376));
  ++*((_DWORD *)v35 + 23);
  LODWORD(v204.x) = *(_DWORD *)(l + 380) & 0xF;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_c_light_type,
    (vostok::render::constants_handler<1> *)v35 + 123,
    &v204);
  ++*((_DWORD *)v35 + 23);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_c_diffuse_influence_factor,
    (vostok::render::constants_handler<1> *)v35 + 123,
    (const vostok::math::float3 *)(l + 340));
  ++*((_DWORD *)v35 + 23);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_c_specular_influence_factor,
    (vostok::render::constants_handler<1> *)v35 + 123,
    (const vostok::math::float3 *)(l + 344));
  ++*((_DWORD *)v35 + 23);
  v94 = this->m_context->m_scene_view.m_object;
  v95 = *(float *)&v94[1].m_next_for_query_finished_callback;
  v94 = (vostok::render::base_scene_view *)((char *)v94 + 460);
  v215.x = v95;
  LODWORD(v215.y) = v94->type;
  v96 = *(float *)&v94->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  m_ambient_color = this->m_ambient_color;
  v215.z = v96;
  v216 = 0;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    m_ambient_color,
    (vostok::render::constants_handler<1> *)v35 + 123,
    &v215);
  v98 = v197;
  ++*((_DWORD *)v35 + 23);
  vostok::render::res_geometry::apply(*(vostok::render::res_geometry **)(v98 + 48));
  vostok::render::renderer_context::set_w(this->m_context, *(const vostok::math::float4x4 **)(LODWORD(instance) + 4));
  vostok::render::backend::render_indexed(
    (vostok::render::backend *)v35,
    3 * *(_DWORD *)(*(_DWORD *)LODWORD(instance) + 68),
    D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
    0,
    0);
  vostok::render::res_effect::apply(0, &this->m_sh_fix_irradiance_texture.m_object->__vftable);
  _X[1] = 0.0;
  v99 = this->m_rt_skin_scattering.m_object;
  if ( v99 )
  {
    _X[1] = *(float *)&this->m_rt_skin_scattering.m_object;
    ++v99->m_reference_count;
  }
  vostok::render::stage_lights::fill_surface(
    (vostok::render::stage_lights *)&_X[1],
    this,
    (vostok::render::resource_manager *)LODWORD(_X[1]));
  v100 = (double)*((unsigned int *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                 + 29);
  *(_QWORD *)&v198.x = (__int64)v100;
  get_gaussain_weights_offsets(weights_h, (__int64)v100, instance, offsets_h);
  get_gaussain_weights_offsets(weights_v, (__int64)v100, instance, offsets_v);
  `vector constructor iterator'(
    (char *)kernel_offsets,
    0x10u,
    8,
    (void *(__thiscall *)(void *))survarium::weapon_core::cast_weapon_core);
  `vector constructor iterator'(
    (char *)blur_offsets_weights,
    0x10u,
    9,
    (void *(__thiscall *)(void *))survarium::weapon_core::cast_weapon_core);
  *(_QWORD *)&blur_offsets_weights[0].x = __PAIR64__(LODWORD(weights_h[0]), LODWORD(offsets_h[0]));
  *(_QWORD *)&blur_offsets_weights[0].elements[2] = __PAIR64__(LODWORD(weights_v[0]), LODWORD(offsets_v[0]));
  *(_QWORD *)&blur_offsets_weights[1].x = __PAIR64__(LODWORD(weights_h[1]), LODWORD(offsets_h[1]));
  *(_QWORD *)&blur_offsets_weights[1].elements[2] = __PAIR64__(LODWORD(weights_v[1]), LODWORD(offsets_v[1]));
  *(_QWORD *)&blur_offsets_weights[2].x = __PAIR64__(LODWORD(weights_h[2]), LODWORD(offsets_h[2]));
  *(_QWORD *)&blur_offsets_weights[2].elements[2] = __PAIR64__(LODWORD(weights_v[2]), LODWORD(offsets_v[2]));
  *(_QWORD *)&blur_offsets_weights[3].x = __PAIR64__(LODWORD(weights_h[3]), LODWORD(offsets_h[3]));
  *(_QWORD *)&blur_offsets_weights[3].elements[2] = __PAIR64__(LODWORD(weights_v[3]), LODWORD(offsets_v[3]));
  *(_QWORD *)&blur_offsets_weights[4].x = __PAIR64__(LODWORD(weights_h[4]), LODWORD(offsets_h[4]));
  *(_QWORD *)&blur_offsets_weights[4].elements[2] = __PAIR64__(LODWORD(weights_v[4]), LODWORD(offsets_v[4]));
  *(_QWORD *)&blur_offsets_weights[5].x = __PAIR64__(LODWORD(weights_h[5]), LODWORD(offsets_h[5]));
  *(_QWORD *)&blur_offsets_weights[5].elements[2] = __PAIR64__(LODWORD(weights_v[5]), LODWORD(offsets_v[5]));
  *(_QWORD *)&light_direction = __PAIR64__(LODWORD(weights_h[6]), LODWORD(offsets_h[6]));
  *((_QWORD *)&light_direction + 1) = __PAIR64__(LODWORD(weights_v[6]), LODWORD(offsets_v[6]));
  *(_QWORD *)&blur_offsets_weights[6].x = __PAIR64__(LODWORD(weights_h[6]), LODWORD(offsets_h[6]));
  *(_QWORD *)&blur_offsets_weights[6].elements[2] = __PAIR64__(LODWORD(weights_v[6]), LODWORD(offsets_v[6]));
  v102 = this->m_sh_downsample_skin_irradiance_texture.m_object;
  *(_QWORD *)&blur_offsets_weights[7].x = __PAIR64__(LODWORD(weights_h[7]), LODWORD(offsets_h[7]));
  *(_QWORD *)&blur_offsets_weights[7].elements[2] = __PAIR64__(LODWORD(weights_v[7]), LODWORD(offsets_v[7]));
  *(_QWORD *)&light_direction = __PAIR64__(LODWORD(weights_h[8]), LODWORD(offsets_h[8]));
  *((_QWORD *)&light_direction + 1) = __PAIR64__(LODWORD(weights_v[8]), LODWORD(offsets_v[8]));
  *(_QWORD *)&blur_offsets_weights[8].x = __PAIR64__(LODWORD(weights_h[8]), LODWORD(offsets_h[8]));
  *(_QWORD *)&blur_offsets_weights[8].elements[2] = __PAIR64__(LODWORD(weights_v[8]), LODWORD(offsets_v[8]));
  if ( v102->m_techniques._M_impl._M_finish - v102->m_techniques._M_impl._M_start )
  {
    v102->m_cur_technique = 0;
    vostok::render::res_effect::apply_pass(v101, LODWORD(v191));
  }
  _X[1] = *(float *)&this->m_t_skin_scattering.m_object;
  v103 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v103 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                             (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                   + 1488),
                             (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                           + 1488,
                             (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                             (vostok::render::res_texture *)LODWORD(_X[1]));
  v104 = this->m_context->m_scene_view.m_object;
  v105 = *(float *)&v104[1].m_next_for_query_finished_callback;
  v106 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v104 = (vostok::render::base_scene_view *)((char *)v104 + 460);
  v198.x = v105;
  LODWORD(v198.y) = v104->type;
  v107 = *(float *)&v104->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  v108 = this->m_ambient_color;
  v198.z = v107;
  v199 = 0;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    v108,
    (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
  + 123,
    &v198);
  ++*((_DWORD *)v106 + 23);
  _X[1] = 0.0;
  v109 = this->m_rt_skin_scattering_small.m_object;
  if ( v109 )
  {
    _X[1] = *(float *)&this->m_rt_skin_scattering_small.m_object;
    ++v109->m_reference_count;
  }
  vostok::render::stage_lights::fill_surface(
    (vostok::render::stage_lights *)&_X[1],
    this,
    (vostok::render::resource_manager *)LODWORD(_X[1]));
  v110 = *(_DWORD *)(*(_DWORD *)LODWORD(instance) + 148);
  if ( !v110 || s_use_one_material_value )
  {
    v110 = *(_DWORD *)(*(_DWORD *)LODWORD(instance) + 4);
    v111 = s_nomaterial_material_effects[v110];
  }
  else
  {
    v111 = (vostok::render::material_effects *)(v110 + 264);
  }
  v112 = &v111->m_effects[22].m_object->__vftable;
  if ( (unsigned int)((v112[71] - v112[70]) >> 2) > 2 )
  {
    v112[69] = 2;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v110, LODWORD(v191));
  }
  _X[1] = *(float *)&this->m_t_skin_scattering_small.m_object;
  v113 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v113 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                             (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                   + 1488),
                             (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                           + 1488,
                             (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                             (vostok::render::res_texture *)LODWORD(_X[1]));
  v114 = this->m_context->m_scene_view.m_object;
  v115 = *(float *)&v114[1].m_next_for_query_finished_callback;
  v116 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v114 = (vostok::render::base_scene_view *)((char *)v114 + 460);
  v221.x = v115;
  LODWORD(v221.y) = v114->type;
  v117 = *(float *)&v114->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  v118 = this->m_ambient_color;
  v221.z = v117;
  v119 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                + 1476);
  v222 = 0.0;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    v118,
    (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
  + 123,
    &v221);
  ++*((_DWORD *)v116 + 23);
  vostok::render::constants_handler<1>::set_constant_array<vostok::math::float4>(
    (vostok::render::constants_handler<1> *)this->m_blur_offsets_weights,
    v119,
    blur_offsets_weights,
    LODWORD(v191));
  ++*((_DWORD *)v116 + 23);
  _X[1] = 0.0;
  v120 = this->m_rt_skin_scattering_blurred_0.m_object;
  if ( v120 )
  {
    _X[1] = *(float *)&this->m_rt_skin_scattering_blurred_0.m_object;
    ++v120->m_reference_count;
  }
  vostok::render::stage_lights::fill_surface(
    (vostok::render::stage_lights *)&_X[1],
    this,
    (vostok::render::resource_manager *)LODWORD(_X[1]));
  vostok::render::backend::flush_rt_shader_resources(
    v121,
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  v122 = *(vostok::render::material_effects_instance **)(*(_DWORD *)LODWORD(instance) + 148);
  if ( !v122 || s_use_one_material_value )
    v123 = s_nomaterial_material_effects[*(_DWORD *)(*(_DWORD *)LODWORD(instance) + 4)];
  else
    v123 = &v122->m_material_effects;
  v124 = &v123->m_effects[22].m_object->__vftable;
  v125 = (v124[71] - v124[70]) >> 2;
  if ( v125 > 2 )
  {
    v124[69] = 2;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v125, LODWORD(v191));
  }
  _X[1] = *(float *)&this->m_t_skin_scattering_blurred_0.m_object;
  v126 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v126 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                             (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                   + 1488),
                             (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                           + 1488,
                             (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                             (vostok::render::res_texture *)LODWORD(_X[1]));
  v127 = this->m_context->m_scene_view.m_object;
  v128 = *(float *)&v127[1].m_next_for_query_finished_callback;
  v129 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v127 = (vostok::render::base_scene_view *)((char *)v127 + 460);
  v209.x = v128;
  LODWORD(v209.y) = v127->type;
  v130 = *(float *)&v127->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  LODWORD(_X[1]) = &v209;
  v131 = this->m_ambient_color;
  v209.z = v130;
  v132 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                + 1476);
  v210 = 0;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    v131,
    (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
  + 123,
    &v209);
  ++*((_DWORD *)v129 + 23);
  vostok::render::constants_handler<1>::set_constant_array<vostok::math::float4>(
    (vostok::render::constants_handler<1> *)this->m_blur_offsets_weights,
    v132,
    blur_offsets_weights,
    LODWORD(v191));
  ++*((_DWORD *)v129 + 23);
  _X[1] = 0.0;
  v133 = this->m_rt_skin_scattering_blurred_1.m_object;
  if ( v133 )
  {
    _X[1] = *(float *)&this->m_rt_skin_scattering_blurred_1.m_object;
    ++v133->m_reference_count;
  }
  vostok::render::stage_lights::fill_surface(
    (vostok::render::stage_lights *)&_X[1],
    this,
    (vostok::render::resource_manager *)LODWORD(_X[1]));
  vostok::render::backend::flush_rt_shader_resources(
    v134,
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  v135 = *(_DWORD *)(*(_DWORD *)LODWORD(instance) + 148);
  if ( !v135 || s_use_one_material_value )
  {
    v135 = *(_DWORD *)(*(_DWORD *)LODWORD(instance) + 4);
    v136 = s_nomaterial_material_effects[v135];
  }
  else
  {
    v136 = (vostok::render::material_effects *)(v135 + 264);
  }
  v137 = &v136->m_effects[22].m_object->__vftable;
  if ( (unsigned int)((v137[71] - v137[70]) >> 2) > 2 )
  {
    v137[69] = 2;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v135, LODWORD(v191));
  }
  _X[1] = *(float *)&this->m_t_skin_scattering_blurred_1.m_object;
  v138 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v138 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                             (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                   + 1488),
                             (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                           + 1488,
                             (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                             (vostok::render::res_texture *)LODWORD(_X[1]));
  v139 = this->m_context->m_scene_view.m_object;
  v140 = *(float *)&v139[1].m_next_for_query_finished_callback;
  v141 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v139 = (vostok::render::base_scene_view *)((char *)v139 + 460);
  v213.x = v140;
  LODWORD(v213.y) = v139->type;
  v142 = *(float *)&v139->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  v143 = this->m_ambient_color;
  v213.z = v142;
  v144 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                + 1476);
  v214 = 0;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    v143,
    (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
  + 123,
    &v213);
  ++*((_DWORD *)v141 + 23);
  vostok::render::constants_handler<1>::set_constant_array<vostok::math::float4>(
    (vostok::render::constants_handler<1> *)this->m_blur_offsets_weights,
    v144,
    blur_offsets_weights,
    LODWORD(v191));
  ++*((_DWORD *)v141 + 23);
  _X[1] = 0.0;
  v145 = this->m_rt_skin_scattering_blurred_2.m_object;
  if ( v145 )
  {
    _X[1] = *(float *)&this->m_rt_skin_scattering_blurred_2.m_object;
    ++v145->m_reference_count;
  }
  vostok::render::stage_lights::fill_surface(
    (vostok::render::stage_lights *)&_X[1],
    this,
    (vostok::render::resource_manager *)LODWORD(_X[1]));
  vostok::render::backend::flush_rt_shader_resources(
    v146,
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  v147 = *(vostok::render::material_effects_instance **)(*(_DWORD *)LODWORD(instance) + 148);
  if ( !v147 || s_use_one_material_value )
    v148 = s_nomaterial_material_effects[*(_DWORD *)(*(_DWORD *)LODWORD(instance) + 4)];
  else
    v148 = &v147->m_material_effects;
  v149 = &v148->m_effects[22].m_object->__vftable;
  v150 = (v149[71] - v149[70]) >> 2;
  if ( v150 > 2 )
  {
    v149[69] = 2;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v150, LODWORD(v191));
  }
  _X[1] = *(float *)&this->m_t_skin_scattering_blurred_2.m_object;
  v151 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v151 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                             (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                   + 1488),
                             (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                           + 1488,
                             (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                             (vostok::render::res_texture *)LODWORD(_X[1]));
  v152 = this->m_context->m_scene_view.m_object;
  v153 = *(float *)&v152[1].m_next_for_query_finished_callback;
  v154 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v152 = (vostok::render::base_scene_view *)((char *)v152 + 460);
  v217.x = v153;
  LODWORD(v217.y) = v152->type;
  v155 = *(float *)&v152->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  LODWORD(_X[1]) = &v217;
  v156 = this->m_ambient_color;
  v217.z = v155;
  v157 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                + 1476);
  v218 = 0;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    v156,
    (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
  + 123,
    &v217);
  ++*((_DWORD *)v154 + 23);
  vostok::render::constants_handler<1>::set_constant_array<vostok::math::float4>(
    (vostok::render::constants_handler<1> *)this->m_blur_offsets_weights,
    v157,
    blur_offsets_weights,
    LODWORD(v191));
  ++*((_DWORD *)v154 + 23);
  _X[1] = 0.0;
  v158 = this->m_rt_skin_scattering_blurred_3.m_object;
  if ( v158 )
  {
    _X[1] = *(float *)&this->m_rt_skin_scattering_blurred_3.m_object;
    ++v158->m_reference_count;
  }
  vostok::render::stage_lights::fill_surface(
    (vostok::render::stage_lights *)&_X[1],
    this,
    (vostok::render::resource_manager *)LODWORD(_X[1]));
  vostok::render::backend::flush_rt_shader_resources(
    v159,
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  v160 = *(_DWORD *)(*(_DWORD *)LODWORD(instance) + 148);
  if ( !v160 || s_use_one_material_value )
  {
    v160 = *(_DWORD *)(*(_DWORD *)LODWORD(instance) + 4);
    v161 = s_nomaterial_material_effects[v160];
  }
  else
  {
    v161 = (vostok::render::material_effects *)(v160 + 264);
  }
  v162 = &v161->m_effects[22].m_object->__vftable;
  if ( (unsigned int)((v162[71] - v162[70]) >> 2) > 2 )
  {
    v162[69] = 2;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v160, LODWORD(v191));
  }
  _X[1] = *(float *)&this->m_t_skin_scattering_blurred_3.m_object;
  v163 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v163 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                             (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                   + 1488),
                             (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                           + 1488,
                             (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                             (vostok::render::res_texture *)LODWORD(_X[1]));
  v164 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  vostok::render::constants_handler<1>::set_constant_array<vostok::math::float4>(
    (vostok::render::constants_handler<1> *)this->m_blur_offsets_weights,
    (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
  + 123,
    blur_offsets_weights,
    LODWORD(v191));
  ++*((_DWORD *)v164 + 23);
  _X[1] = 0.0;
  v165 = this->m_rt_skin_scattering_blurred_4.m_object;
  if ( v165 )
  {
    _X[1] = *(float *)&this->m_rt_skin_scattering_blurred_4.m_object;
    ++v165->m_reference_count;
  }
  vostok::render::stage_lights::fill_surface(
    (vostok::render::stage_lights *)&_X[1],
    this,
    (vostok::render::resource_manager *)LODWORD(_X[1]));
  v166 = this->m_context->m_targets->m_family[47].target.m_object;
  *(_DWORD *)&src_ptr[4] = 0;
  if ( v166 )
  {
    ++v166->m_reference_count;
    *(_DWORD *)&src_ptr[4] = v166;
  }
  v167 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  vostok::render::backend::set_render_targets(
    *(ID3D11RenderTargetView **)&src_ptr[4],
    0,
    0,
    0,
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  if ( *(_DWORD *)&src_ptr[4] )
  {
    v169 = *(const char **)&src_ptr[4];
    v170 = (**(_DWORD **)&src_ptr[4])-- == 1;
    if ( v170 )
    {
      vostok::render::resource_manager::release(
        v168,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v169);
      v167 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    }
  }
  v171 = *((_DWORD *)v167 + 547);
  m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
  *((_BYTE *)v167 + 167) |= *((_DWORD *)v167 + 539) != v171;
  *((_DWORD *)v167 + 539) = v171;
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)m_game->m_game_world.m_mouse_pos.y + 176))(
    m_game->m_game_world.m_mouse_pos.y,
    1,
    &orig_viewport);
  v173 = *(vostok::render::material_effects_instance **)(*(_DWORD *)LODWORD(instance) + 148);
  if ( !v173 || s_use_one_material_value )
    v174 = s_nomaterial_material_effects[*(_DWORD *)(*(_DWORD *)LODWORD(instance) + 4)];
  else
    v174 = &v173->m_material_effects;
  v175 = &v174->m_effects[22].m_object->__vftable;
  v176 = (v175[71] - v175[70]) >> 2;
  if ( v176 > 3 )
  {
    v175[69] = 3;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v176, LODWORD(v191));
  }
  v177 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v178 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                + 1476);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_c_light_position,
    (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
  + 123,
    &light_position);
  LODWORD(_X[1]) = &light_range;
  ++v177->num_setted_shader_constants;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_c_light_range,
    v178,
    (const vostok::math::float3 *)LODWORD(_X[1]));
  ++v177->num_setted_shader_constants;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_c_light_color,
    v178,
    (const vostok::math::float3 *)&arg[8]);
  ++v177->num_setted_shader_constants;
  v179 = this->m_context->m_scene_view.m_object;
  v180 = *(float *)&v179[1].m_next_for_query_finished_callback;
  v179 = (vostok::render::base_scene_view *)((char *)v179 + 460);
  v211.x = v180;
  LODWORD(v211.y) = v179->type;
  v181 = *(float *)&v179->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  LODWORD(_X[1]) = &v211;
  v182 = this->m_ambient_color;
  v211.z = v181;
  v212 = 0;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(v182, v178, &v211);
  ++v177->num_setted_shader_constants;
  vostok::render::res_geometry::apply(*(vostok::render::res_geometry **)(v197 + 48));
  vostok::render::renderer_context::set_w(this->m_context, *(const vostok::math::float4x4 **)(LODWORD(instance) + 4));
  vostok::render::backend::render_indexed(
    v177,
    3 * *(_DWORD *)(*(_DWORD *)LODWORD(instance) + 68),
    D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
    0,
    0);
  v183 = this->m_context;
  v184 = v183->m_targets->m_family[47].target.m_object;
  v185 = 0;
  if ( v184 )
  {
    v185 = (ID3D11RenderTargetView *)v183->m_targets->m_family[47].target.m_object;
    ++v184->m_reference_count;
  }
  v186 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  vostok::render::backend::set_render_targets(
    v185,
    0,
    0,
    0,
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  if ( v185 )
  {
    v170 = v185->lpVtbl-- == (ID3D11RenderTargetView_vtbl *)1;
    if ( v170 )
    {
      vostok::render::resource_manager::release(
        v187,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)v185);
      v186 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    }
  }
  v188 = *((_DWORD *)v186 + 547);
  v189 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
  *((_BYTE *)v186 + 167) |= *((_DWORD *)v186 + 539) != v188;
  *((_DWORD *)v186 + 539) = v188;
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)v189->m_game_world.m_mouse_pos.y + 176))(
    v189->m_game_world.m_mouse_pos.y,
    1,
    &orig_viewport);
}
