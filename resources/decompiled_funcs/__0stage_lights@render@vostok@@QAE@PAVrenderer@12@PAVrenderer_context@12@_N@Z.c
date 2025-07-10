void __userpurge vostok::render::stage_lights::stage_lights(
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *context@<eax>,
        vostok::render::stage_lights *this,
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> is_forward_lighting_pass)
{
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *m_shadow_depth_stencil; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *m_shadow_depth_stencil_texture; // edi
  char m_object; // dl
  survarium::game_action_id *M_start; // ecx
  char v8; // al
  vostok::render::render_target *render_target; // eax
  vostok::render::resource_manager *v10; // ecx
  const char *v11; // eax
  vostok::render::render_target *v12; // eax
  vostok::render::render_target *v13; // ecx
  vostok::render::render_target *v14; // eax
  vostok::render::render_target *v15; // eax
  vostok::render::render_target *v16; // ecx
  const char *v17; // eax
  bool v18; // zf
  stlp_std::priv::_Rb_tree_node_base *texture; // eax
  vostok::render::res_texture *v20; // ecx
  const vostok::render::res_texture *v21; // esi
  stlp_std::priv::_Rb_tree_node_base *v22; // eax
  vostok::render::res_texture *v23; // ecx
  vostok::render::res_texture *v24; // esi
  stlp_std::priv::_Rb_tree_node_base *v25; // eax
  vostok::render::res_texture *v26; // ecx
  vostok::render::res_texture *v27; // esi
  vostok::render::stage_lights *v28; // ecx
  vostok::render::stage_lights *v29; // ecx
  vostok::render::stage_lights *v30; // ecx
  vostok::strings::shared::profile *v31; // eax
  vostok::render::backend *v32; // ecx
  vostok::strings::shared::manager *v33; // esi
  vostok::strings::shared::profile *v34; // eax
  vostok::render::backend *v35; // ecx
  vostok::strings::shared::manager *v36; // esi
  vostok::strings::shared::profile *v37; // eax
  vostok::render::backend *v38; // ecx
  vostok::strings::shared::manager *v39; // esi
  vostok::strings::shared::profile *v40; // eax
  vostok::render::backend *v41; // ecx
  vostok::strings::shared::manager *v42; // esi
  vostok::strings::shared::profile *v43; // eax
  vostok::render::backend *v44; // ecx
  vostok::strings::shared::manager *v45; // esi
  vostok::strings::shared::profile *v46; // eax
  vostok::render::backend *v47; // ecx
  vostok::strings::shared::manager *v48; // esi
  vostok::strings::shared::profile *v49; // eax
  vostok::render::backend *v50; // ecx
  vostok::strings::shared::manager *v51; // esi
  vostok::strings::shared::profile *v52; // eax
  vostok::render::backend *v53; // ecx
  vostok::strings::shared::manager *v54; // esi
  vostok::strings::shared::profile *v55; // eax
  vostok::render::backend *v56; // ecx
  vostok::strings::shared::manager *v57; // esi
  vostok::strings::shared::profile *v58; // eax
  vostok::render::backend *v59; // ecx
  vostok::strings::shared::profile *v60; // ecx
  vostok::strings::shared::profile *v61; // eax
  vostok::render::backend *v62; // ecx
  vostok::strings::shared::profile *v63; // ecx
  vostok::strings::shared::profile *v64; // eax
  vostok::render::backend *v65; // ecx
  vostok::strings::shared::profile *v66; // ecx
  vostok::strings::shared::profile *v67; // eax
  vostok::render::backend *v68; // ecx
  vostok::strings::shared::profile *v69; // ecx
  vostok::strings::shared::profile *v70; // eax
  vostok::render::backend *v71; // ecx
  vostok::strings::shared::profile *v72; // ecx
  vostok::strings::shared::profile *v73; // eax
  vostok::render::backend *v74; // ecx
  vostok::strings::shared::profile *v75; // ecx
  vostok::strings::shared::profile *v76; // eax
  vostok::render::backend *v77; // ecx
  vostok::strings::shared::profile *v78; // ecx
  vostok::strings::shared::profile *v79; // eax
  vostok::render::backend *v80; // ecx
  vostok::strings::shared::profile *v81; // ecx
  vostok::strings::shared::profile *v82; // eax
  vostok::render::backend *v83; // ecx
  vostok::strings::shared::profile *v84; // ecx
  vostok::strings::shared::profile *v85; // eax
  vostok::render::backend *v86; // ecx
  vostok::strings::shared::profile *v87; // ecx
  vostok::strings::shared::profile *v88; // eax
  vostok::render::backend *v89; // ecx
  vostok::strings::shared::profile *v90; // ecx
  vostok::strings::shared::profile *v91; // eax
  vostok::render::backend *v92; // ecx
  vostok::strings::shared::profile *v93; // ecx
  vostok::strings::shared::profile *v94; // eax
  vostok::render::backend *v95; // ecx
  vostok::strings::shared::profile *v96; // ecx
  vostok::strings::shared::profile *v97; // eax
  vostok::render::backend *v98; // ecx
  vostok::strings::shared::profile *v99; // ecx
  vostok::strings::shared::profile *v100; // eax
  vostok::render::backend *v101; // ecx
  vostok::strings::shared::profile *v102; // ecx
  vostok::strings::shared::profile *v103; // eax
  vostok::render::backend *v104; // ecx
  vostok::strings::shared::profile *v105; // ecx
  vostok::strings::shared::profile *v106; // eax
  vostok::render::backend *v107; // ecx
  vostok::strings::shared::profile *v108; // ecx
  vostok::strings::shared::profile *v109; // eax
  vostok::render::backend *v110; // ecx
  vostok::strings::shared::profile *v111; // ecx
  vostok::strings::shared::profile *v112; // eax
  vostok::render::backend *v113; // ecx
  vostok::strings::shared::profile *v114; // ecx
  vostok::strings::shared::profile *v115; // eax
  vostok::render::backend *v116; // ecx
  vostok::strings::shared::profile *v117; // ecx
  vostok::strings::shared::profile *v118; // eax
  vostok::render::backend *v119; // ecx
  vostok::strings::shared::profile *v120; // ecx
  vostok::strings::shared::profile *v121; // eax
  vostok::render::backend *v122; // ecx
  vostok::strings::shared::profile *v123; // ecx
  vostok::strings::shared::profile *v124; // eax
  vostok::render::backend *v125; // ecx
  vostok::strings::shared::profile *v126; // ecx
  vostok::strings::shared::profile *v127; // eax
  vostok::render::backend *v128; // ecx
  vostok::strings::shared::profile *v129; // ecx
  vostok::strings::shared::profile *v130; // eax
  vostok::render::backend *v131; // ecx
  vostok::strings::shared::profile *v132; // ecx
  vostok::strings::shared::profile *v133; // eax
  vostok::render::backend *v134; // ecx
  vostok::strings::shared::profile *v135; // ecx
  vostok::strings::shared::profile *v136; // eax
  vostok::render::backend *v137; // ecx
  vostok::strings::shared::profile *v138; // ecx
  vostok::strings::shared::profile *v139; // eax
  vostok::render::backend *v140; // ecx
  vostok::strings::shared::profile *v141; // ecx
  vostok::strings::shared::profile *v142; // eax
  vostok::render::backend *v143; // ecx
  vostok::strings::shared::profile *v144; // ecx
  vostok::strings::shared::profile *v145; // eax
  vostok::render::backend *v146; // ecx
  vostok::strings::shared::profile *v147; // ecx
  vostok::strings::shared::profile *v148; // eax
  vostok::render::backend *v149; // ecx
  vostok::strings::shared::profile *v150; // ecx
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::res_geometry *geometry; // eax
  vostok::strings::shared::profile *v153; // eax
  vostok::render::backend *v154; // ecx
  vostok::strings::shared::profile *v155; // ecx
  unsigned int m_num_instanced_lights; // esi
  char *v157; // eax
  unsigned int v158; // esi
  float *v159; // esi
  unsigned int i; // eax
  vostok::render::untyped_buffer *v161; // eax
  vostok::render::untyped_buffer *v162; // ecx
  vostok::render::res_state *v163; // edi
  float *v164; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::res_declaration *declaration; // eax
  vostok::render::res_declaration *v167; // ecx
  vostok::render::res_declaration *v168; // eax
  unsigned int v169; // [esp+0h] [ebp-5Ch]
  unsigned int v170; // [esp+0h] [ebp-5Ch]
  unsigned int v171; // [esp+0h] [ebp-5Ch]
  unsigned int v172; // [esp+4h] [ebp-58h]
  unsigned int v173; // [esp+4h] [ebp-58h]
  unsigned int v174; // [esp+4h] [ebp-58h]
  unsigned __int16 indices[6]; // [esp+14h] [ebp-48h] BYREF
  D3D11_INPUT_ELEMENT_DESC screen_vertex_layout[2]; // [esp+20h] [ebp-3Ch] BYREF

  this->m_context = context;
  this->m_renderer = in_renderer;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->__vftable = (vostok::render::stage_lights_vtbl *)&stru_9649F4.m_name.m_string.m_buffer[124];
  this->m_enable_env_probes = 1;
  this->m_rt_skin_scattering_position.m_object = 0;
  this->m_t_skin_scattering_position.m_object = 0;
  this->m_rt_skin_scattering_temp.m_object = 0;
  this->m_t_skin_scattering_temp.m_object = 0;
  this->m_rt_skin_scattering.m_object = 0;
  this->m_t_skin_scattering.m_object = 0;
  this->m_rt_skin_scattering_stretch.m_object = 0;
  this->m_t_skin_scattering_stretch.m_object = 0;
  this->m_rt_skin_scattering_small.m_object = 0;
  this->m_t_skin_scattering_small.m_object = 0;
  this->m_rt_skin_scattering_blurred_0.m_object = 0;
  this->m_t_skin_scattering_blurred_0.m_object = 0;
  this->m_rt_skin_scattering_blurred_1.m_object = 0;
  this->m_t_skin_scattering_blurred_1.m_object = 0;
  this->m_rt_skin_scattering_blurred_2.m_object = 0;
  this->m_t_skin_scattering_blurred_2.m_object = 0;
  this->m_rt_skin_scattering_blurred_3.m_object = 0;
  this->m_t_skin_scattering_blurred_3.m_object = 0;
  this->m_rt_skin_scattering_blurred_4.m_object = 0;
  this->m_t_skin_scattering_blurred_4.m_object = 0;
  this->m_skin_scattering_render_target.m_object = 0;
  m_shadow_depth_stencil = this->m_shadow_depth_stencil;
  this->m_skin_scattering_depth_stencil.m_object = 0;
  this->m_skin_scattering_texture.m_object = 0;
  `vector constructor iterator'(
    (char *)this->m_shadow_depth_stencil,
    4u,
    3,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  m_shadow_depth_stencil_texture = this->m_shadow_depth_stencil_texture;
  `vector constructor iterator'(
    (char *)this->m_shadow_depth_stencil_texture,
    4u,
    3,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  this->m_vcm_render_target.m_object = 0;
  this->m_vcm_depth_stencil.m_object = 0;
  `vector constructor iterator'(
    (char *)this->m_lookup_vcm_render_target,
    4u,
    6,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  `vector constructor iterator'(
    (char *)this->m_lookup_vcm_depth_stencil,
    4u,
    6,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  this->m_lookup_vcm_texture.m_object = 0;
  this->m_lookup_vcm_depth_stencil_texture.m_object = 0;
  `vector constructor iterator'(
    (char *)this->m_lookup_vcm_render_target_names,
    0x4Cu,
    6,
    (void *(__thiscall *)(void *))vostok::fixed_string<64>::fixed_string<64>);
  `vector constructor iterator'(
    (char *)this->m_lookup_vcm_depth_stencil_names,
    0x4Cu,
    6,
    (void *(__thiscall *)(void *))vostok::fixed_string<64>::fixed_string<64>);
  this->m_lookup_vcm_ib.m_object = 0;
  this->m_lookup_vcm_geometry.m_object = 0;
  `vector constructor iterator'(
    (char *)this->m_cubemap_face_render_target,
    4u,
    6,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  `vector constructor iterator'(
    (char *)this->m_cubemap_face_depth_stencil,
    4u,
    6,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  this->m_cubemap_texture.m_object = 0;
  this->m_depth_stencil_cubemap_texture.m_object = 0;
  `vector constructor iterator'(
    (char *)this->m_cubemap_face_render_target_names,
    0x4Cu,
    6,
    (void *(__thiscall *)(void *))vostok::fixed_string<64>::fixed_string<64>);
  `vector constructor iterator'(
    (char *)this->m_cubemap_face_depth_stencil_names,
    0x4Cu,
    6,
    (void *(__thiscall *)(void *))vostok::fixed_string<64>::fixed_string<64>);
  this->m_effect_accum_mask.m_object = 0;
  this->m_point_light_shadower.m_object = 0;
  this->m_point_light_accumulator.m_object = 0;
  this->m_shadowed_point_light_accumulator.m_object = 0;
  this->m_spot_light_accumulator.m_object = 0;
  this->m_shadowed_spot_light_accumulator.m_object = 0;
  this->m_capsule_light_accumulator.m_object = 0;
  this->m_obb_light_accumulator.m_object = 0;
  this->m_shadowed_obb_light_accumulator.m_object = 0;
  this->m_sphere_light_accumulator.m_object = 0;
  this->m_shadowed_sphere_light_accumulator.m_object = 0;
  this->m_plane_spot_light_accumulator.m_object = 0;
  this->m_shadowed_plane_spot_light_accumulator.m_object = 0;
  this->m_sh_downsample_skin_irradiance_texture.m_object = 0;
  this->m_sh_fix_irradiance_texture.m_object = 0;
  this->m_shadow_effect.m_object = 0;
  this->m_sphere_geometry.vertex_buffer.m_object = 0;
  this->m_sphere_geometry.index_buffer.m_object = 0;
  this->m_sphere_geometry.geometry.m_object = 0;
  this->m_pyramid_geometry.vertex_buffer.m_object = 0;
  this->m_pyramid_geometry.index_buffer.m_object = 0;
  this->m_pyramid_geometry.geometry.m_object = 0;
  this->m_obb_geometry.vertex_buffer.m_object = 0;
  this->m_obb_geometry.index_buffer.m_object = 0;
  this->m_obb_geometry.geometry.m_object = 0;
  this->m_screen_vertex_ib.m_object = 0;
  this->m_screen_vertex_geometry.m_object = 0;
  this->m_instance_vb_small.m_object = 0;
  this->m_instance_declaration.m_object = 0;
  this->m_instance_declaration_small.m_object = 0;
  `vector constructor iterator'(
    (char *)this->m_lights_instance,
    4u,
    4,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  m_object = (char)is_forward_lighting_pass.m_object;
  M_start = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
  this->m_is_forward_lighting_pass = (const bool)is_forward_lighting_pass.m_object;
  v8 = *((_BYTE *)M_start + 249);
  this->m_enabled = v8;
  if ( v8 )
  {
    if ( m_object )
      this->m_enabled = *((_BYTE *)M_start + 251);
    else
      this->m_enabled = *((_BYTE *)M_start + 252);
  }
  if ( *((_BYTE *)M_start + 267) )
  {
    render_target = vostok::render::resource_manager::create_render_target(
                      (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                      (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                      "$user$shadow_map_size_1024",
                      (vostok::render::res_texture *)0x400,
                      (ID3D11Texture2D **)0x400,
                      (const char *)0x35,
                      enum_rt_usage_depth_stencil,
                      0,
                      0,
                      v169,
                      v172);
    v10 = 0;
    if ( render_target )
    {
      ++render_target->m_reference_count;
      v10 = (vostok::render::resource_manager *)render_target;
    }
    v11 = (const char *)m_shadow_depth_stencil->m_object;
    m_shadow_depth_stencil->m_object = (vostok::render::render_target *)v10;
    if ( v11 )
    {
      if ( !--*(_DWORD *)v11 )
        vostok::render::resource_manager::release(
          v10,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v11);
    }
    v12 = vostok::render::resource_manager::create_render_target(
            v10,
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            "$user$shadow_map_size_512",
            (vostok::render::res_texture *)0x200,
            (ID3D11Texture2D **)0x200,
            (const char *)0x35,
            enum_rt_usage_depth_stencil,
            0,
            0,
            v170,
            v173);
    v13 = 0;
    if ( v12 )
    {
      ++v12->m_reference_count;
      v13 = v12;
    }
    v14 = this->m_shadow_depth_stencil[1].m_object;
    this->m_shadow_depth_stencil[1].m_object = v13;
    if ( v14 )
    {
      if ( !--v14->m_reference_count )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v14);
    }
    v15 = vostok::render::resource_manager::create_render_target(
            (vostok::render::resource_manager *)v13,
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            "$user$shadow_map_size_256",
            (vostok::render::res_texture *)0x100,
            (ID3D11Texture2D **)0x100,
            (const char *)0x35,
            enum_rt_usage_depth_stencil,
            0,
            0,
            v171,
            v174);
    v16 = 0;
    if ( v15 )
    {
      ++v15->m_reference_count;
      v16 = v15;
    }
    v17 = (const char *)this->m_shadow_depth_stencil[2].m_object;
    this->m_shadow_depth_stencil[2].m_object = v16;
    if ( v17 )
    {
      v18 = (*(_DWORD *)v17)-- == 1;
      if ( v18 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)v16,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v17);
    }
    texture = vostok::render::resource_manager::create_texture(
                (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                "$user$shadow_map_size_1024",
                0,
                0,
                0,
                1,
                1,
                0xFFFFFFFF);
    v20 = 0;
    if ( texture )
    {
      ++texture->_M_parent;
      v20 = (vostok::render::res_texture *)texture;
    }
    v21 = m_shadow_depth_stencil_texture->m_object;
    m_shadow_depth_stencil_texture->m_object = v20;
    if ( v21 )
    {
      v18 = v21->m_reference_count-- == 1;
      if ( v18 )
        vostok::render::res_texture::destroy_impl(v20, v21);
    }
    v22 = vostok::render::resource_manager::create_texture(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            "$user$shadow_map_size_512",
            0,
            0,
            0,
            1,
            1,
            0xFFFFFFFF);
    v23 = 0;
    if ( v22 )
    {
      ++v22->_M_parent;
      v23 = (vostok::render::res_texture *)v22;
    }
    v24 = this->m_shadow_depth_stencil_texture[1].m_object;
    this->m_shadow_depth_stencil_texture[1].m_object = v23;
    if ( v24 )
    {
      v18 = v24->m_reference_count-- == 1;
      if ( v18 )
        vostok::render::res_texture::destroy_impl(v23, v24);
    }
    v25 = vostok::render::resource_manager::create_texture(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            "$user$shadow_map_size_256",
            0,
            0,
            0,
            1,
            1,
            0xFFFFFFFF);
    v26 = 0;
    if ( v25 )
    {
      ++v25->_M_parent;
      v26 = (vostok::render::res_texture *)v25;
    }
    v27 = this->m_shadow_depth_stencil_texture[2].m_object;
    this->m_shadow_depth_stencil_texture[2].m_object = v26;
    if ( v27 )
    {
      v18 = v27->m_reference_count-- == 1;
      if ( v18 )
        vostok::render::res_texture::destroy_impl(v26, v27);
    }
  }
  vostok::render::effect_manager::create_effect<vostok::render::effect_shadow_map>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_shadow_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_light_mask>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_effect_accum_mask);
  vostok::render::effect_manager::create_effect<vostok::render::point_light_effect<0,0>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_point_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::point_light_effect<0,1>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_point_light_shadower);
  vostok::render::effect_manager::create_effect<vostok::render::point_light_effect<1,0>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_shadowed_point_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::spot_light_effect<0>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_spot_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::spot_light_effect<1>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_shadowed_spot_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::capsule_light_effect>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_capsule_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::obb_light_effect<0>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_obb_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::obb_light_effect<1>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_shadowed_obb_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::sphere_light_effect<0>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sphere_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::sphere_light_effect<1>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_shadowed_sphere_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::plane_spot_light_effect<0>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_plane_spot_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::plane_spot_light_effect<1>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_shadowed_plane_spot_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::effect_downsample_skin_irradiance_texture>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sh_downsample_skin_irradiance_texture);
  vostok::render::effect_manager::create_effect<vostok::render::effect_fix_irradiance_texture>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sh_fix_irradiance_texture);
  vostok::render::stage_lights::new_sphere_geometry(v28, (bool)m_shadow_depth_stencil_texture, this);
  vostok::render::stage_lights::create_pyramid_geometry(v29, (bool)m_shadow_depth_stencil_texture, this);
  vostok::render::stage_lights::create_obb_geometry(v30, (bool)m_shadow_depth_stencil_texture, this);
  v31 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v33 = 0;
  is_forward_lighting_pass.m_object = 0;
  if ( v31 )
  {
    v33 = (vostok::strings::shared::manager *)v31;
    is_forward_lighting_pass.m_object = v31;
    _InterlockedExchangeAdd(&v31->m_reference_count, 1u);
  }
  this->m_c_view_to_light_matrix = vostok::render::backend::register_constant_host(
                                     v32,
                                     (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                     (const vostok::shared_string *)&is_forward_lighting_pass,
                                     rc_float);
  if ( v33 && !_InterlockedExchangeAdd((volatile signed __int32 *)v33, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v33, (vostok::strings::shared::profile *)s_manager.m_variable);
  v34 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v36 = 0;
  is_forward_lighting_pass.m_object = 0;
  if ( v34 )
  {
    v36 = (vostok::strings::shared::manager *)v34;
    is_forward_lighting_pass.m_object = v34;
    _InterlockedExchangeAdd(&v34->m_reference_count, 1u);
  }
  this->m_c_shadow_z_bias = vostok::render::backend::register_constant_host(
                              v35,
                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                              (const vostok::shared_string *)&is_forward_lighting_pass,
                              rc_float);
  if ( v36 && !_InterlockedExchangeAdd((volatile signed __int32 *)v36, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v36, (vostok::strings::shared::profile *)s_manager.m_variable);
  v37 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v39 = 0;
  is_forward_lighting_pass.m_object = 0;
  if ( v37 )
  {
    v39 = (vostok::strings::shared::manager *)v37;
    is_forward_lighting_pass.m_object = v37;
    _InterlockedExchangeAdd(&v37->m_reference_count, 1u);
  }
  this->m_c_shadow_map_size = vostok::render::backend::register_constant_host(
                                v38,
                                (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                (const vostok::shared_string *)&is_forward_lighting_pass,
                                rc_float);
  if ( v39 && !_InterlockedExchangeAdd((volatile signed __int32 *)v39, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v39, (vostok::strings::shared::profile *)s_manager.m_variable);
  v40 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v42 = 0;
  is_forward_lighting_pass.m_object = 0;
  if ( v40 )
  {
    v42 = (vostok::strings::shared::manager *)v40;
    is_forward_lighting_pass.m_object = v40;
    _InterlockedExchangeAdd(&v40->m_reference_count, 1u);
  }
  this->m_c_shadow_transparency = vostok::render::backend::register_constant_host(
                                    v41,
                                    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                    (const vostok::shared_string *)&is_forward_lighting_pass,
                                    rc_float);
  if ( v42 && !_InterlockedExchangeAdd((volatile signed __int32 *)v42, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v42, (vostok::strings::shared::profile *)s_manager.m_variable);
  v43 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v45 = 0;
  is_forward_lighting_pass.m_object = 0;
  if ( v43 )
  {
    v45 = (vostok::strings::shared::manager *)v43;
    is_forward_lighting_pass.m_object = v43;
    _InterlockedExchangeAdd(&v43->m_reference_count, 1u);
  }
  this->m_c_light_color = vostok::render::backend::register_constant_host(
                            v44,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            (const vostok::shared_string *)&is_forward_lighting_pass,
                            rc_float);
  if ( v45 && !_InterlockedExchangeAdd((volatile signed __int32 *)v45, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v45, (vostok::strings::shared::profile *)s_manager.m_variable);
  v46 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v48 = 0;
  is_forward_lighting_pass.m_object = 0;
  if ( v46 )
  {
    v48 = (vostok::strings::shared::manager *)v46;
    is_forward_lighting_pass.m_object = v46;
    _InterlockedExchangeAdd(&v46->m_reference_count, 1u);
  }
  this->m_c_light_intensity = vostok::render::backend::register_constant_host(
                                v47,
                                (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                (const vostok::shared_string *)&is_forward_lighting_pass,
                                rc_float);
  if ( v48 && !_InterlockedExchangeAdd((volatile signed __int32 *)v48, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v48, (vostok::strings::shared::profile *)s_manager.m_variable);
  v49 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v51 = 0;
  is_forward_lighting_pass.m_object = 0;
  if ( v49 )
  {
    v51 = (vostok::strings::shared::manager *)v49;
    is_forward_lighting_pass.m_object = v49;
    _InterlockedExchangeAdd(&v49->m_reference_count, 1u);
  }
  this->m_c_light_position = vostok::render::backend::register_constant_host(
                               v50,
                               (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                               (const vostok::shared_string *)&is_forward_lighting_pass,
                               rc_float);
  if ( v51 && !_InterlockedExchangeAdd((volatile signed __int32 *)v51, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v51, (vostok::strings::shared::profile *)s_manager.m_variable);
  v52 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v54 = 0;
  is_forward_lighting_pass.m_object = 0;
  if ( v52 )
  {
    v54 = (vostok::strings::shared::manager *)v52;
    is_forward_lighting_pass.m_object = v52;
    _InterlockedExchangeAdd(&v52->m_reference_count, 1u);
  }
  this->m_c_light_direction = vostok::render::backend::register_constant_host(
                                v53,
                                (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                (const vostok::shared_string *)&is_forward_lighting_pass,
                                rc_float);
  if ( v54 && !_InterlockedExchangeAdd((volatile signed __int32 *)v54, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v54, (vostok::strings::shared::profile *)s_manager.m_variable);
  v55 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v57 = 0;
  is_forward_lighting_pass.m_object = 0;
  if ( v55 )
  {
    v57 = (vostok::strings::shared::manager *)v55;
    is_forward_lighting_pass.m_object = v55;
    _InterlockedExchangeAdd(&v55->m_reference_count, 1u);
  }
  this->m_c_light_attenuation_power = vostok::render::backend::register_constant_host(
                                        v56,
                                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                        (const vostok::shared_string *)&is_forward_lighting_pass,
                                        rc_float);
  if ( v57 && !_InterlockedExchangeAdd((volatile signed __int32 *)v57, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v57, (vostok::strings::shared::profile *)s_manager.m_variable);
  v58 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v58);
  this->m_c_light_range = vostok::render::backend::register_constant_host(
                            v59,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            (const vostok::shared_string *)&is_forward_lighting_pass,
                            rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v60 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v60,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v61 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v61);
  this->m_c_lighting_model = vostok::render::backend::register_constant_host(
                               v62,
                               (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                               (const vostok::shared_string *)&is_forward_lighting_pass,
                               rc_int);
  if ( is_forward_lighting_pass.m_object )
  {
    v63 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v63,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v64 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v64);
  this->m_c_diffuse_influence_factor = vostok::render::backend::register_constant_host(
                                         v65,
                                         (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                         (const vostok::shared_string *)&is_forward_lighting_pass,
                                         rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v66 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v66,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v67 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v67);
  this->m_c_specular_influence_factor = vostok::render::backend::register_constant_host(
                                          v68,
                                          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                          (const vostok::shared_string *)&is_forward_lighting_pass,
                                          rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v69 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v69,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v70 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v70);
  this->m_c_is_shadower = vostok::render::backend::register_constant_host(
                            v71,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            (const vostok::shared_string *)&is_forward_lighting_pass,
                            rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v72 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v72,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v73 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v73);
  this->m_c_light_spot_penumbra_half_angle_cosine = vostok::render::backend::register_constant_host(
                                                      v74,
                                                      (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                      (const vostok::shared_string *)&is_forward_lighting_pass,
                                                      rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v75 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v75,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v76 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v76);
  this->m_c_light_spot_umbra_half_angle_cosine = vostok::render::backend::register_constant_host(
                                                   v77,
                                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                   (const vostok::shared_string *)&is_forward_lighting_pass,
                                                   rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v78 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v78,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v79 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v79);
  this->m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine = vostok::render::backend::register_constant_host(
                                                                                             v80,
                                                                                             (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                                                             (const vostok::shared_string *)&is_forward_lighting_pass,
                                                                                             rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v81 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v81,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v82 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v82);
  this->m_c_light_spot_falloff = vostok::render::backend::register_constant_host(
                                   v83,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   (const vostok::shared_string *)&is_forward_lighting_pass,
                                   rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v84 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v84,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v85 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v85);
  this->m_c_light_type = vostok::render::backend::register_constant_host(
                           v86,
                           (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                           (const vostok::shared_string *)&is_forward_lighting_pass,
                           rc_int);
  if ( is_forward_lighting_pass.m_object )
  {
    v87 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v87,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v88 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v88);
  this->m_c_light_capsule_half_width = vostok::render::backend::register_constant_host(
                                         v89,
                                         (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                         (const vostok::shared_string *)&is_forward_lighting_pass,
                                         rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v90 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v90,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v91 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v91);
  this->m_c_light_capsule_radius = vostok::render::backend::register_constant_host(
                                     v92,
                                     (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                     (const vostok::shared_string *)&is_forward_lighting_pass,
                                     rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v93 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v93,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v94 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v94);
  this->m_c_light_sphere_radius = vostok::render::backend::register_constant_host(
                                    v95,
                                    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                    (const vostok::shared_string *)&is_forward_lighting_pass,
                                    rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v96 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v96,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v97 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v97);
  this->m_c_light_local_to_world = vostok::render::backend::register_constant_host(
                                     v98,
                                     (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                     (const vostok::shared_string *)&is_forward_lighting_pass,
                                     rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v99 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v99,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v100 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v100);
  this->m_c_light_sphere_radius = vostok::render::backend::register_constant_host(
                                    v101,
                                    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                    (const vostok::shared_string *)&is_forward_lighting_pass,
                                    rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v102 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v102,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v103 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v103);
  this->m_c_eye_ray_corner = vostok::render::backend::register_constant_host(
                               v104,
                               (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                               (const vostok::shared_string *)&is_forward_lighting_pass,
                               rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v105 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v105,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v106 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v106);
  this->m_c_near_far = vostok::render::backend::register_constant_host(
                         v107,
                         (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                         (const vostok::shared_string *)&is_forward_lighting_pass,
                         rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v108 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v108,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v109 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v109);
  this->m_far_fog_color_and_distance = vostok::render::backend::register_constant_host(
                                         v110,
                                         (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                         (const vostok::shared_string *)&is_forward_lighting_pass,
                                         rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v111 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v111,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v112 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v112);
  this->m_near_fog_distance = vostok::render::backend::register_constant_host(
                                v113,
                                (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                (const vostok::shared_string *)&is_forward_lighting_pass,
                                rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v114 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v114,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v115 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v115);
  this->m_c_is_unwrap_pass = vostok::render::backend::register_constant_host(
                               v116,
                               (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                               (const vostok::shared_string *)&is_forward_lighting_pass,
                               rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v117 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v117,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v118 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v118);
  this->m_blur_offsets_weights = vostok::render::backend::register_constant_host(
                                   v119,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   (const vostok::shared_string *)&is_forward_lighting_pass,
                                   rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v120 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v120,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v121 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v121);
  this->m_kernel_offsets = vostok::render::backend::register_constant_host(
                             v122,
                             (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                             (const vostok::shared_string *)&is_forward_lighting_pass,
                             rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v123 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v123,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v124 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v124);
  this->m_c_use_shadows = vostok::render::backend::register_constant_host(
                            v125,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            (const vostok::shared_string *)&is_forward_lighting_pass,
                            rc_int);
  if ( is_forward_lighting_pass.m_object )
  {
    v126 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v126,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v127 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v127);
  this->m_ambient_color = vostok::render::backend::register_constant_host(
                            v128,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            (const vostok::shared_string *)&is_forward_lighting_pass,
                            rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v129 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v129,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v130 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v130);
  this->m_gamma_correction_factor = vostok::render::backend::register_constant_host(
                                      v131,
                                      (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                      (const vostok::shared_string *)&is_forward_lighting_pass,
                                      rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v132 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v132,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v133 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v133);
  this->m_probe_parameters0 = vostok::render::backend::register_constant_host(
                                v134,
                                (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                (const vostok::shared_string *)&is_forward_lighting_pass,
                                rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v135 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v135,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v136 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v136);
  this->m_probe_parameters1 = vostok::render::backend::register_constant_host(
                                v137,
                                (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                (const vostok::shared_string *)&is_forward_lighting_pass,
                                rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v138 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v138,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v139 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v139);
  this->m_shadow[0] = vostok::render::backend::register_constant_host(
                        v140,
                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                        (const vostok::shared_string *)&is_forward_lighting_pass,
                        rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v141 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v141,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v142 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v142);
  this->m_shadow[1] = vostok::render::backend::register_constant_host(
                        v143,
                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                        (const vostok::shared_string *)&is_forward_lighting_pass,
                        rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v144 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v144,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v145 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v145);
  this->m_shadow[2] = vostok::render::backend::register_constant_host(
                        v146,
                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                        (const vostok::shared_string *)&is_forward_lighting_pass,
                        rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v147 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v147,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v148 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v148);
  this->m_shadow[3] = vostok::render::backend::register_constant_host(
                        v149,
                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                        (const vostok::shared_string *)&is_forward_lighting_pass,
                        rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v150 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v150,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  screen_vertex_layout[1].Format = DXGI_FORMAT_R32G32_FLOAT;
  screen_vertex_layout[1].AlignedByteOffset = 16;
  indices[0] = 0;
  indices[1] = 1;
  indices[2] = 2;
  indices[3] = 3;
  indices[4] = 2;
  indices[5] = 1;
  screen_vertex_layout[0].SemanticName = "POSITION";
  screen_vertex_layout[0].SemanticIndex = 0;
  screen_vertex_layout[0].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
  screen_vertex_layout[0].InputSlot = 0;
  screen_vertex_layout[0].AlignedByteOffset = 0;
  screen_vertex_layout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  screen_vertex_layout[0].InstanceDataStepRate = 0;
  screen_vertex_layout[1].SemanticName = "TEXCOORD";
  screen_vertex_layout[1].SemanticIndex = 0;
  screen_vertex_layout[1].InputSlot = 0;
  screen_vertex_layout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  screen_vertex_layout[1].InstanceDataStepRate = 0;
  buffer = vostok::render::resource_manager::create_buffer(
             0xCu,
             (bool)&is_forward_lighting_pass,
             (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
             indices,
             enum_buffer_type_index,
             0,
             0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)buffer,
    (const vostok::render::untyped_buffer **)&this->m_screen_vertex_ib.m_object);
  geometry = vostok::render::resource_manager::create_geometry(
               (stlp_std::forward_iterator_tag *)screen_vertex_layout,
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               2u,
               0x18u,
               *((vostok::render::untyped_buffer **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
               + 10),
               this->m_screen_vertex_ib.m_object);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)geometry,
    (const vostok::render::res_geometry **)&this->m_screen_vertex_geometry.m_object);
  this->m_num_instanced_lights = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                                 + 44);
  v153 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  is_forward_lighting_pass.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &is_forward_lighting_pass,
    v153);
  this->m_c_light_instances = vostok::render::backend::register_constant_host(
                                v154,
                                (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                (const vostok::shared_string *)&is_forward_lighting_pass,
                                rc_float);
  if ( is_forward_lighting_pass.m_object )
  {
    v155 = is_forward_lighting_pass.m_object;
    if ( !_InterlockedExchangeAdd(&is_forward_lighting_pass.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v155,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  m_num_instanced_lights = this->m_num_instanced_lights;
  v157 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(
                   (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                   (m_num_instanced_lights << 6) + 8);
  *(_DWORD *)v157 = m_num_instanced_lights;
  v157 += 4;
  *(_DWORD *)v157 = 64;
  v158 = this->m_num_instanced_lights;
  this->m_light_instances = (vostok::math::float4x4 *)(v157 + 4);
  v159 = vostok::memory::new_array_helper<float>::call<vostok::memory::doug_lea_allocator>(
           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
           v158);
  for ( i = 0; i < this->m_num_instanced_lights; ++i )
  {
    is_forward_lighting_pass.m_object = (vostok::strings::shared::profile *)i;
    v159[i] = (float)i;
  }
  v161 = vostok::render::resource_manager::create_buffer(
           4 * this->m_num_instanced_lights,
           (bool)&is_forward_lighting_pass,
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           v159,
           enum_buffer_type_vertex,
           0,
           0);
  v162 = 0;
  if ( v161 )
  {
    ++v161->m_reference_count;
    v162 = v161;
  }
  v163 = (vostok::render::res_state *)this->m_instance_vb_small.m_object;
  this->m_instance_vb_small.m_object = v162;
  if ( v163 )
  {
    v18 = v163->m_reference_count-- == 1;
    if ( v18 )
      vostok::render::resource_manager::release(
        v163,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v164 = v159 - 2;
  m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v164);
  declaration = vostok::render::resource_manager::create_declaration(
                  2u,
                  (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                  (stlp_std::forward_iterator_tag *)instance_data_layout_small);
  v167 = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    v167 = declaration;
  }
  v168 = this->m_instance_declaration_small.m_object;
  this->m_instance_declaration_small.m_object = v167;
  if ( v168 )
  {
    v18 = v168->m_reference_count-- == 1;
    if ( v18 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v168);
  }
}
