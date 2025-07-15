void __thiscall vostok::render::stage_lights::stage_lights(
        vostok::render::renderer_context *context,
        vostok::render::stage_lights *this,
        vostok::render::renderer *in_renderer,
        bool is_forward_lighting_pass)
{
  vostok::fixed_string<64> *m_lookup_vcm_render_target_names; // ecx
  char *m_buffer; // eax
  vostok::fixed_string<64> *m_lookup_vcm_depth_stencil_names; // ecx
  char *v7; // eax
  vostok::fixed_string<64> *m_cubemap_face_render_target_names; // ecx
  int v9; // edx
  char *v10; // eax
  vostok::fixed_string<64> *m_cubemap_face_depth_stencil_names; // ecx
  char *v12; // eax
  stlp_std::priv::_Rb_tree_node_base *render_target; // eax
  vostok::render::resource_manager *v14; // ecx
  stlp_std::priv::_Rb_tree_node_base *v15; // eax
  vostok::render::resource_manager *v16; // ecx
  stlp_std::priv::_Rb_tree_node_base *v17; // eax
  vostok::render::resource_manager *v18; // ecx
  stlp_std::priv::_Rb_tree_node_base *v19; // eax
  vostok::render::resource_manager *v20; // ecx
  stlp_std::priv::_Rb_tree_node_base *v21; // eax
  const char *v22; // edi
  const char *v23; // esi
  int v24; // ecx
  bool v25; // cf
  bool v26; // zf
  int v27; // edx
  vostok::render::res_texture *texture; // eax
  const char *v29; // edi
  const char *v30; // esi
  int v31; // ecx
  bool v32; // cf
  bool v33; // zf
  int v34; // edx
  vostok::render::res_texture *v35; // eax
  const char *v36; // edi
  const char *v37; // esi
  int v38; // ecx
  bool v39; // cf
  bool v40; // zf
  int v41; // edx
  vostok::render::res_texture *v42; // eax
  const char *v43; // edi
  const char *v44; // esi
  int v45; // ecx
  bool v46; // cf
  bool v47; // zf
  int v48; // edx
  vostok::render::res_texture *v49; // eax
  const char *v50; // edi
  const char *v51; // esi
  int v52; // ecx
  bool v53; // cf
  bool v54; // zf
  int v55; // edx
  vostok::render::res_texture *v56; // eax
  vostok::render::effect_manager *v57; // ecx
  vostok::render::effect_manager *v58; // ecx
  vostok::render::effect_manager *v59; // ecx
  vostok::render::effect_manager *v60; // ecx
  vostok::render::effect_manager *v61; // ecx
  vostok::render::effect_manager *v62; // ecx
  vostok::render::effect_manager *v63; // ecx
  vostok::render::effect_manager *v64; // ecx
  vostok::render::effect_manager *v65; // ecx
  vostok::render::effect_manager *v66; // ecx
  vostok::render::effect_manager *v67; // ecx
  vostok::render::effect_manager *v68; // ecx
  vostok::render::effect_manager *v69; // ecx
  vostok::render::effect_manager *v70; // ecx
  vostok::render::effect_manager *v71; // ecx
  vostok::render::effect_manager *v72; // ecx
  vostok::render::stage_lights *v73; // ecx
  vostok::render::stage_lights *v74; // ecx
  vostok::render::stage_lights *v75; // ecx
  vostok::shared_string *v76; // ecx
  vostok::render::backend *v77; // ecx
  vostok::shared_string *v78; // ecx
  vostok::render::backend *v79; // ecx
  vostok::shared_string *v80; // ecx
  vostok::render::backend *v81; // ecx
  vostok::shared_string *v82; // ecx
  vostok::render::backend *v83; // ecx
  vostok::shared_string *v84; // ecx
  vostok::render::backend *v85; // ecx
  vostok::shared_string *v86; // ecx
  vostok::render::backend *v87; // ecx
  vostok::shared_string *v88; // ecx
  vostok::render::backend *v89; // ecx
  vostok::shared_string *v90; // ecx
  vostok::render::backend *v91; // ecx
  vostok::shared_string *v92; // ecx
  vostok::render::backend *v93; // ecx
  vostok::shared_string *v94; // ecx
  vostok::render::backend *v95; // ecx
  vostok::shared_string *v96; // ecx
  vostok::render::backend *v97; // ecx
  vostok::shared_string *v98; // ecx
  vostok::render::backend *v99; // ecx
  vostok::shared_string *v100; // ecx
  vostok::render::backend *v101; // ecx
  vostok::shared_string *v102; // ecx
  vostok::render::backend *v103; // ecx
  vostok::shared_string *v104; // ecx
  vostok::render::backend *v105; // ecx
  vostok::shared_string *v106; // ecx
  vostok::render::backend *v107; // ecx
  vostok::shared_string *v108; // ecx
  vostok::render::backend *v109; // ecx
  vostok::shared_string *v110; // ecx
  vostok::render::backend *v111; // ecx
  vostok::shared_string *v112; // ecx
  vostok::render::backend *v113; // ecx
  vostok::shared_string *v114; // ecx
  vostok::render::backend *v115; // ecx
  vostok::shared_string *v116; // ecx
  vostok::render::backend *v117; // ecx
  vostok::shared_string *v118; // ecx
  vostok::render::backend *v119; // ecx
  vostok::shared_string *v120; // ecx
  vostok::render::backend *v121; // ecx
  vostok::shared_string *v122; // ecx
  vostok::render::backend *v123; // ecx
  vostok::shared_string *v124; // ecx
  vostok::render::backend *v125; // ecx
  vostok::shared_string *v126; // ecx
  vostok::render::backend *v127; // ecx
  vostok::shared_string *v128; // ecx
  vostok::render::backend *v129; // ecx
  vostok::shared_string *v130; // ecx
  vostok::render::backend *v131; // ecx
  vostok::shared_string *v132; // ecx
  vostok::render::backend *v133; // ecx
  vostok::shared_string *v134; // ecx
  vostok::render::backend *v135; // ecx
  vostok::shared_string *v136; // ecx
  vostok::render::backend *v137; // ecx
  vostok::shared_string *v138; // ecx
  vostok::render::backend *v139; // ecx
  vostok::shared_string *v140; // ecx
  vostok::render::backend *v141; // ecx
  vostok::shared_string *v142; // ecx
  vostok::render::backend *v143; // ecx
  vostok::shared_string *v144; // ecx
  vostok::render::backend *v145; // ecx
  vostok::shared_string *v146; // ecx
  vostok::render::backend *v147; // ecx
  vostok::shared_string *v148; // ecx
  vostok::render::backend *v149; // ecx
  vostok::shared_string *v150; // ecx
  vostok::render::backend *v151; // ecx
  vostok::shared_string *v152; // ecx
  vostok::render::backend *v153; // ecx
  vostok::shared_string *v154; // ecx
  vostok::render::backend *v155; // ecx
  vostok::shared_string *v156; // ecx
  vostok::render::backend *v157; // ecx
  vostok::shared_string *v158; // ecx
  vostok::render::backend *v159; // ecx
  vostok::shared_string *v160; // ecx
  vostok::render::backend *v161; // ecx
  vostok::shared_string *v162; // ecx
  vostok::render::backend *v163; // ecx
  vostok::shared_string *v164; // ecx
  vostok::render::backend *v165; // ecx
  vostok::shared_string *v166; // ecx
  vostok::render::backend *v167; // ecx
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v168; // eax
  vostok::render::resource_manager *v169; // ecx
  vostok::render::res_geometry *v170; // eax
  vostok::memory::doug_lea_allocator *v171; // esi
  char *v172; // eax
  vostok::memory::doug_lea_allocator *v173; // ecx
  char *v174; // ecx
  unsigned int num_max_lights_per_particle; // eax
  vostok::render::shader_buffer *v176; // ecx
  vostok::render::shader_buffer *v177; // eax
  unsigned int v178; // [esp+0h] [ebp-58h]
  unsigned int v179; // [esp+0h] [ebp-58h]
  unsigned int v180; // [esp+0h] [ebp-58h]
  unsigned int v181; // [esp+0h] [ebp-58h]
  unsigned int v182; // [esp+0h] [ebp-58h]
  const char *v183; // [esp+0h] [ebp-58h]
  unsigned int v184; // [esp+0h] [ebp-58h]
  const char *v185; // [esp+4h] [ebp-54h]
  DXGI_FORMAT v186; // [esp+4h] [ebp-54h]
  unsigned int v187; // [esp+8h] [ebp-50h]
  vostok::shared_string name; // [esp+10h] [ebp-48h] BYREF
  _WORD data[6]; // [esp+14h] [ebp-44h] BYREF
  D3D11_INPUT_ELEMENT_DESC decl_size; // [esp+20h] [ebp-38h] BYREF
  const char *v191; // [esp+3Ch] [ebp-1Ch]
  int v192; // [esp+40h] [ebp-18h]
  int v193; // [esp+44h] [ebp-14h]
  int v194; // [esp+48h] [ebp-10h]
  int v195; // [esp+4Ch] [ebp-Ch]
  int v196; // [esp+50h] [ebp-8h]
  int v197; // [esp+54h] [ebp-4h]

  vostok::render::stage::stage(this, context, in_renderer);
  this->__vftable = (vostok::render::stage_lights_vtbl *)&vostok::render::stage_lights::`vftable';
  this->m_enable_env_probes = 1;
  this->m_light_parameters_buffer.m_object = 0;
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
  this->m_skin_scattering_depth_stencil.m_object = 0;
  this->m_skin_scattering_texture.m_object = 0;
  this->m_shadow_depth_stencil[0].m_object = 0;
  this->m_shadow_depth_stencil[1].m_object = 0;
  this->m_shadow_depth_stencil[2].m_object = 0;
  this->m_shadow_depth_stencil[3].m_object = 0;
  this->m_shadow_depth_stencil[4].m_object = 0;
  this->m_shadow_depth_stencil_texture[0].m_object = 0;
  this->m_shadow_depth_stencil_texture[1].m_object = 0;
  this->m_shadow_depth_stencil_texture[2].m_object = 0;
  this->m_shadow_depth_stencil_texture[3].m_object = 0;
  this->m_shadow_depth_stencil_texture[4].m_object = 0;
  this->m_vcm_render_target.m_object = 0;
  this->m_vcm_depth_stencil.m_object = 0;
  memset(this->m_lookup_vcm_render_target, 0, sizeof(this->m_lookup_vcm_render_target));
  memset(this->m_lookup_vcm_depth_stencil, 0, sizeof(this->m_lookup_vcm_depth_stencil));
  m_lookup_vcm_render_target_names = this->m_lookup_vcm_render_target_names;
  this->m_lookup_vcm_texture.m_object = 0;
  this->m_lookup_vcm_depth_stencil_texture.m_object = 0;
  name.m_pointer.m_object = (vostok::strings::shared::profile *)5;
  m_buffer = this->m_lookup_vcm_render_target_names[0].m_buffer;
  do
  {
    m_lookup_vcm_render_target_names->m_begin = m_buffer;
    *((_DWORD *)m_buffer - 2) = m_buffer;
    *((_DWORD *)m_buffer - 1) = m_buffer + 64;
    *m_buffer = 0;
    ++m_lookup_vcm_render_target_names;
    m_buffer += 76;
    --name.m_pointer.m_object;
  }
  while ( (int)name.m_pointer.m_object >= 0 );
  m_lookup_vcm_depth_stencil_names = this->m_lookup_vcm_depth_stencil_names;
  name.m_pointer.m_object = (vostok::strings::shared::profile *)5;
  v7 = this->m_lookup_vcm_depth_stencil_names[0].m_buffer;
  do
  {
    m_lookup_vcm_depth_stencil_names->m_begin = v7;
    *((_DWORD *)v7 - 2) = v7;
    *((_DWORD *)v7 - 1) = v7 + 64;
    *v7 = 0;
    ++m_lookup_vcm_depth_stencil_names;
    v7 += 76;
    --name.m_pointer.m_object;
  }
  while ( (int)name.m_pointer.m_object >= 0 );
  this->m_lookup_vcm_ib.m_object = 0;
  this->m_lookup_vcm_geometry.m_object = 0;
  memset(this->m_cubemap_face_render_target, 0, sizeof(this->m_cubemap_face_render_target));
  memset(this->m_cubemap_face_depth_stencil, 0, sizeof(this->m_cubemap_face_depth_stencil));
  this->m_cubemap_texture.m_object = 0;
  m_cubemap_face_render_target_names = this->m_cubemap_face_render_target_names;
  this->m_depth_stencil_cubemap_texture.m_object = 0;
  v9 = 5;
  v10 = this->m_cubemap_face_render_target_names[0].m_buffer;
  do
  {
    m_cubemap_face_render_target_names->m_begin = v10;
    *((_DWORD *)v10 - 1) = v10 + 64;
    *((_DWORD *)v10 - 2) = v10;
    *v10 = 0;
    *v10 = 0;
    ++m_cubemap_face_render_target_names;
    v10 += 76;
    --v9;
  }
  while ( v9 >= 0 );
  m_cubemap_face_depth_stencil_names = this->m_cubemap_face_depth_stencil_names;
  name.m_pointer.m_object = (vostok::strings::shared::profile *)5;
  v12 = this->m_cubemap_face_depth_stencil_names[0].m_buffer;
  do
  {
    m_cubemap_face_depth_stencil_names->m_begin = v12;
    *((_DWORD *)v12 - 2) = v12;
    *((_DWORD *)v12 - 1) = v12 + 64;
    *v12 = 0;
    *v12 = 0;
    ++m_cubemap_face_depth_stencil_names;
    v12 += 76;
    --name.m_pointer.m_object;
  }
  while ( (int)name.m_pointer.m_object >= 0 );
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
  this->m_lights_instance[0].m_instance_vb.m_object = 0;
  this->m_lights_instance[1].m_instance_vb.m_object = 0;
  this->m_lights_instance[2].m_instance_vb.m_object = 0;
  this->m_lights_instance[3].m_instance_vb.m_object = 0;
  this->m_is_forward_lighting_pass = is_forward_lighting_pass;
  this->m_use_probes = 1;
  render_target = vostok::render::resource_manager::create_render_target(
                    0,
                    (const char **)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                    "$user$shadow_map_size_1024",
                    0x400u,
                    0x400u,
                    (char *)0x35,
                    DXGI_FORMAT_UNKNOWN,
                    0,
                    0,
                    0,
                    v178);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    this->m_shadow_depth_stencil,
    (vostok::render::render_target *)render_target);
  v15 = vostok::render::resource_manager::create_render_target(
          v14,
          (const char **)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          "$user$shadow_map_size_512",
          0x200u,
          0x200u,
          (char *)0x35,
          DXGI_FORMAT_UNKNOWN,
          0,
          0,
          0,
          v179);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &this->m_shadow_depth_stencil[1],
    (vostok::render::render_target *)v15);
  v17 = vostok::render::resource_manager::create_render_target(
          v16,
          (const char **)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          "$user$shadow_map_size_256",
          0x100u,
          0x100u,
          (char *)0x35,
          DXGI_FORMAT_UNKNOWN,
          0,
          0,
          0,
          v180);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &this->m_shadow_depth_stencil[2],
    (vostok::render::render_target *)v17);
  v19 = vostok::render::resource_manager::create_render_target(
          v18,
          (const char **)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          "$user$shadow_map_size_128",
          0x80u,
          0x80u,
          (char *)0x35,
          DXGI_FORMAT_UNKNOWN,
          0,
          0,
          0,
          v181);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &this->m_shadow_depth_stencil[3],
    (vostok::render::render_target *)v19);
  v21 = vostok::render::resource_manager::create_render_target(
          v20,
          (const char **)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          "$user$shadow_map_size_64",
          0x40u,
          0x40u,
          (char *)0x35,
          DXGI_FORMAT_UNKNOWN,
          0,
          0,
          0,
          v182);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &this->m_shadow_depth_stencil[4],
    (vostok::render::render_target *)v21);
  v22 = "null";
  v23 = "$user$shadow_map_size_1024";
  v24 = 27;
  v27 = 0;
  v25 = 0;
  v26 = 1;
  do
  {
    if ( !v24 )
      break;
    v25 = *v23 < (unsigned int)*v22;
    v26 = *v23++ == *v22++;
    --v24;
  }
  while ( v26 );
  name.m_pointer.m_object = (vostok::strings::shared::profile *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  if ( !v26 )
    v27 = -v25 - (v25 - 1);
  if ( v27 )
  {
    texture = (vostok::render::res_texture *)vostok::render::resource_manager::find_texture(
                                               (vostok::render::resource_manager *)v24,
                                               (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                               "$user$shadow_map_size_1024");
    if ( !texture )
      texture = vostok::render::resource_manager::load_texture(
                  (vostok::render::resource_manager *)name.m_pointer.m_object,
                  "$user$shadow_map_size_1024",
                  0,
                  0,
                  0,
                  1,
                  1,
                  0xFFFFFFFF,
                  1,
                  0);
  }
  else
  {
    texture = 0;
  }
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    texture,
    (vostok::render::res_texture *)this->m_shadow_depth_stencil_texture);
  v29 = "null";
  v30 = "$user$shadow_map_size_512";
  v31 = 26;
  v34 = 0;
  v32 = 0;
  v33 = 1;
  do
  {
    if ( !v31 )
      break;
    v32 = *v30 < (unsigned int)*v29;
    v33 = *v30++ == *v29++;
    --v31;
  }
  while ( v33 );
  name.m_pointer.m_object = (vostok::strings::shared::profile *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  if ( !v33 )
    v34 = -v32 - (v32 - 1);
  if ( v34 )
  {
    v35 = (vostok::render::res_texture *)vostok::render::resource_manager::find_texture(
                                           (vostok::render::resource_manager *)v31,
                                           (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                           "$user$shadow_map_size_512");
    if ( !v35 )
      v35 = vostok::render::resource_manager::load_texture(
              (vostok::render::resource_manager *)name.m_pointer.m_object,
              "$user$shadow_map_size_512",
              0,
              0,
              0,
              1,
              1,
              0xFFFFFFFF,
              1,
              0);
  }
  else
  {
    v35 = 0;
  }
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v35,
    (vostok::render::res_texture *)&this->m_shadow_depth_stencil_texture[1]);
  v36 = "null";
  v37 = "$user$shadow_map_size_256";
  v38 = 26;
  v41 = 0;
  v39 = 0;
  v40 = 1;
  do
  {
    if ( !v38 )
      break;
    v39 = *v37 < (unsigned int)*v36;
    v40 = *v37++ == *v36++;
    --v38;
  }
  while ( v40 );
  name.m_pointer.m_object = (vostok::strings::shared::profile *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  if ( !v40 )
    v41 = -v39 - (v39 - 1);
  if ( v41 )
  {
    v42 = (vostok::render::res_texture *)vostok::render::resource_manager::find_texture(
                                           (vostok::render::resource_manager *)v38,
                                           (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                           "$user$shadow_map_size_256");
    if ( !v42 )
      v42 = vostok::render::resource_manager::load_texture(
              (vostok::render::resource_manager *)name.m_pointer.m_object,
              "$user$shadow_map_size_256",
              0,
              0,
              0,
              1,
              1,
              0xFFFFFFFF,
              1,
              0);
  }
  else
  {
    v42 = 0;
  }
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v42,
    (vostok::render::res_texture *)&this->m_shadow_depth_stencil_texture[2]);
  v43 = "null";
  v44 = "$user$shadow_map_size_128";
  v45 = 26;
  v48 = 0;
  v46 = 0;
  v47 = 1;
  do
  {
    if ( !v45 )
      break;
    v46 = *v44 < (unsigned int)*v43;
    v47 = *v44++ == *v43++;
    --v45;
  }
  while ( v47 );
  name.m_pointer.m_object = (vostok::strings::shared::profile *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  if ( !v47 )
    v48 = -v46 - (v46 - 1);
  if ( v48 )
  {
    v49 = (vostok::render::res_texture *)vostok::render::resource_manager::find_texture(
                                           (vostok::render::resource_manager *)v45,
                                           (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                           "$user$shadow_map_size_128");
    if ( !v49 )
      v49 = vostok::render::resource_manager::load_texture(
              (vostok::render::resource_manager *)name.m_pointer.m_object,
              "$user$shadow_map_size_128",
              0,
              0,
              0,
              1,
              1,
              0xFFFFFFFF,
              1,
              0);
  }
  else
  {
    v49 = 0;
  }
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v49,
    (vostok::render::res_texture *)&this->m_shadow_depth_stencil_texture[3]);
  v50 = "null";
  v51 = "$user$shadow_map_size_64";
  v52 = 25;
  v55 = 0;
  v53 = 0;
  v54 = 1;
  do
  {
    if ( !v52 )
      break;
    v53 = *v51 < (unsigned int)*v50;
    v54 = *v51++ == *v50++;
    --v52;
  }
  while ( v54 );
  name.m_pointer.m_object = (vostok::strings::shared::profile *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  if ( !v54 )
    v55 = -v53 - (v53 - 1);
  if ( v55 )
  {
    v56 = (vostok::render::res_texture *)vostok::render::resource_manager::find_texture(
                                           (vostok::render::resource_manager *)v52,
                                           (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                           "$user$shadow_map_size_64");
    if ( !v56 )
      v56 = vostok::render::resource_manager::load_texture(
              (vostok::render::resource_manager *)name.m_pointer.m_object,
              "$user$shadow_map_size_64",
              0,
              0,
              0,
              1,
              1,
              0xFFFFFFFF,
              1,
              0);
  }
  else
  {
    v56 = 0;
  }
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v56,
    (vostok::render::res_texture *)&this->m_shadow_depth_stencil_texture[4]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_shadow_map>(
    v57,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_shadow_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_light_mask>(
    v58,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_effect_accum_mask);
  vostok::render::effect_manager::create_effect<vostok::render::point_light_effect<0,0>>(
    v59,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_point_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::point_light_effect<0,1>>(
    v60,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_point_light_shadower);
  vostok::render::effect_manager::create_effect<vostok::render::point_light_effect<1,0>>(
    v61,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_shadowed_point_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::spot_light_effect<0>>(
    v62,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_spot_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::spot_light_effect<1>>(
    v63,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_shadowed_spot_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::capsule_light_effect>(
    v64,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_capsule_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::obb_light_effect<0>>(
    v65,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_obb_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::obb_light_effect<1>>(
    v66,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_shadowed_obb_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::sphere_light_effect<0>>(
    v67,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_sphere_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::sphere_light_effect<1>>(
    v68,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_shadowed_sphere_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::plane_spot_light_effect<0>>(
    v69,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_plane_spot_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::plane_spot_light_effect<1>>(
    v70,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_shadowed_plane_spot_light_accumulator);
  vostok::render::effect_manager::create_effect<vostok::render::effect_downsample_skin_irradiance_texture>(
    v71,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_sh_downsample_skin_irradiance_texture);
  vostok::render::effect_manager::create_effect<vostok::render::effect_fix_irradiance_texture>(
    v72,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_sh_fix_irradiance_texture);
  vostok::render::stage_lights::new_sphere_geometry(v73, (int)this);
  vostok::render::stage_lights::create_pyramid_geometry(v74, (int)this);
  vostok::render::stage_lights::create_obb_geometry(v75, (int)this);
  vostok::shared_string::shared_string(v76, &name.m_pointer, "view_to_light_matrix");
  this->m_c_view_to_light_matrix = vostok::render::backend::register_constant_host(
                                     v77,
                                     SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                     &name,
                                     0);
  if ( name.m_pointer.m_object )
  {
    v78 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v78 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v78, &name.m_pointer, "shadow_z_bias");
  this->m_c_shadow_z_bias = vostok::render::backend::register_constant_host(
                              v79,
                              SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                              &name,
                              0);
  if ( name.m_pointer.m_object )
  {
    v80 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v80 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v80, &name.m_pointer, "shadow_map_size");
  this->m_c_shadow_map_size = vostok::render::backend::register_constant_host(
                                v81,
                                SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                &name,
                                0);
  if ( name.m_pointer.m_object )
  {
    v82 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v82 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v82, &name.m_pointer, "shadow_transparency");
  this->m_c_shadow_transparency = vostok::render::backend::register_constant_host(
                                    v83,
                                    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                    &name,
                                    0);
  if ( name.m_pointer.m_object )
  {
    v84 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v84 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v84, &name.m_pointer, "num_lights");
  this->m_c_num_lights = vostok::render::backend::register_constant_host(
                           v85,
                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                           &name,
                           (vostok::strings::shared::profile *)1);
  if ( name.m_pointer.m_object )
  {
    v86 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v86 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v86, &name.m_pointer, "sun_color");
  this->m_sun_color = vostok::render::backend::register_constant_host(
                        v87,
                        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                        &name,
                        0);
  if ( name.m_pointer.m_object )
  {
    v88 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v88 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v88, &name.m_pointer, "light_color");
  this->m_c_light_color = vostok::render::backend::register_constant_host(
                            v89,
                            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                            &name,
                            0);
  if ( name.m_pointer.m_object )
  {
    v90 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v90 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v90, &name.m_pointer, "light_intensity");
  this->m_c_light_intensity = vostok::render::backend::register_constant_host(
                                v91,
                                SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                &name,
                                0);
  if ( name.m_pointer.m_object )
  {
    v92 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v92 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v92, &name.m_pointer, "light_position");
  this->m_c_light_position = vostok::render::backend::register_constant_host(
                               v93,
                               SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                               &name,
                               0);
  if ( name.m_pointer.m_object )
  {
    v94 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v94 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v94, &name.m_pointer, "light_direction");
  this->m_c_light_direction = vostok::render::backend::register_constant_host(
                                v95,
                                SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                &name,
                                0);
  if ( name.m_pointer.m_object )
  {
    v96 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v96 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v96, &name.m_pointer, "light_attenuation_power");
  this->m_c_light_attenuation_power = vostok::render::backend::register_constant_host(
                                        v97,
                                        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                        &name,
                                        0);
  if ( name.m_pointer.m_object )
  {
    v98 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v98 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v98, &name.m_pointer, "light_range");
  this->m_c_light_range = vostok::render::backend::register_constant_host(
                            v99,
                            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                            &name,
                            0);
  if ( name.m_pointer.m_object )
  {
    v100 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v100 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v100, &name.m_pointer, "lighting_model");
  this->m_c_lighting_model = vostok::render::backend::register_constant_host(
                               v101,
                               SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                               &name,
                               (vostok::strings::shared::profile *)1);
  if ( name.m_pointer.m_object )
  {
    v102 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v102 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v102, &name.m_pointer, "light_diffuse_influence_factor");
  this->m_c_diffuse_influence_factor = vostok::render::backend::register_constant_host(
                                         v103,
                                         SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                         &name,
                                         0);
  if ( name.m_pointer.m_object )
  {
    v104 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v104 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v104, &name.m_pointer, "light_specular_influence_factor");
  this->m_c_specular_influence_factor = vostok::render::backend::register_constant_host(
                                          v105,
                                          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                          &name,
                                          0);
  if ( name.m_pointer.m_object )
  {
    v106 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v106 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v106, &name.m_pointer, "is_shadower");
  this->m_c_is_shadower = vostok::render::backend::register_constant_host(
                            v107,
                            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                            &name,
                            0);
  if ( name.m_pointer.m_object )
  {
    v108 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v108 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v108, &name.m_pointer, "light_spot_penumbra_half_angle_cosine");
  this->m_c_light_spot_penumbra_half_angle_cosine = vostok::render::backend::register_constant_host(
                                                      v109,
                                                      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                                      &name,
                                                      0);
  if ( name.m_pointer.m_object )
  {
    v110 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v110 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v110, &name.m_pointer, "light_spot_umbra_half_angle_cosine");
  this->m_c_light_spot_umbra_half_angle_cosine = vostok::render::backend::register_constant_host(
                                                   v111,
                                                   SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                                   &name,
                                                   0);
  if ( name.m_pointer.m_object )
  {
    v112 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v112 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(
    v112,
    &name.m_pointer,
    "light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine");
  this->m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine = vostok::render::backend::register_constant_host(
                                                                                             v113,
                                                                                             SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                                                                             &name,
                                                                                             0);
  if ( name.m_pointer.m_object )
  {
    v114 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v114 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v114, &name.m_pointer, "light_spot_falloff");
  this->m_c_light_spot_falloff = vostok::render::backend::register_constant_host(
                                   v115,
                                   SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                   &name,
                                   0);
  if ( name.m_pointer.m_object )
  {
    v116 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v116 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v116, &name.m_pointer, "light_type");
  this->m_c_light_type = vostok::render::backend::register_constant_host(
                           v117,
                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                           &name,
                           (vostok::strings::shared::profile *)1);
  if ( name.m_pointer.m_object )
  {
    v118 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v118 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v118, &name.m_pointer, "light_capsule_half_width");
  this->m_c_light_capsule_half_width = vostok::render::backend::register_constant_host(
                                         v119,
                                         SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                         &name,
                                         0);
  if ( name.m_pointer.m_object )
  {
    v120 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v120 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v120, &name.m_pointer, "light_capsule_radius");
  this->m_c_light_capsule_radius = vostok::render::backend::register_constant_host(
                                     v121,
                                     SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                     &name,
                                     0);
  if ( name.m_pointer.m_object )
  {
    v122 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v122 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v122, &name.m_pointer, "light_local_to_world");
  this->m_c_light_local_to_world = vostok::render::backend::register_constant_host(
                                     v123,
                                     SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                     &name,
                                     0);
  if ( name.m_pointer.m_object )
  {
    v124 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v124 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v124, &name.m_pointer, "s_eye_ray_corner");
  this->m_c_eye_ray_corner = vostok::render::backend::register_constant_host(
                               v125,
                               SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                               &name,
                               0);
  if ( name.m_pointer.m_object )
  {
    v126 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v126 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v126, &name.m_pointer, "s_near_far");
  this->m_c_near_far = vostok::render::backend::register_constant_host(
                         v127,
                         SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                         &name,
                         0);
  if ( name.m_pointer.m_object )
  {
    v128 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v128 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v128, &name.m_pointer, "far_fog_color_and_distance");
  this->m_far_fog_color_and_distance = vostok::render::backend::register_constant_host(
                                         v129,
                                         SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                         &name,
                                         0);
  if ( name.m_pointer.m_object )
  {
    v130 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v130 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v130, &name.m_pointer, "near_fog_distance");
  this->m_near_fog_distance = vostok::render::backend::register_constant_host(
                                v131,
                                SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                &name,
                                0);
  if ( name.m_pointer.m_object )
  {
    v132 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v132 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v132, &name.m_pointer, "is_unwrap_pass");
  this->m_c_is_unwrap_pass = vostok::render::backend::register_constant_host(
                               v133,
                               SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                               &name,
                               0);
  if ( name.m_pointer.m_object )
  {
    v134 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v134 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v134, &name.m_pointer, "offsets_weights");
  this->m_blur_offsets_weights = vostok::render::backend::register_constant_host(
                                   v135,
                                   SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                   &name,
                                   0);
  if ( name.m_pointer.m_object )
  {
    v136 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v136 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v136, &name.m_pointer, "kernel_offsets");
  this->m_kernel_offsets = vostok::render::backend::register_constant_host(
                             v137,
                             SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                             &name,
                             0);
  if ( name.m_pointer.m_object )
  {
    v138 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v138 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v138, &name.m_pointer, "use_shadows");
  this->m_c_use_shadows = vostok::render::backend::register_constant_host(
                            v139,
                            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                            &name,
                            (vostok::strings::shared::profile *)1);
  if ( name.m_pointer.m_object )
  {
    v140 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v140 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v140, &name.m_pointer, "ambient_color");
  this->m_ambient_color = vostok::render::backend::register_constant_host(
                            v141,
                            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                            &name,
                            0);
  if ( name.m_pointer.m_object )
  {
    v142 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v142 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v142, &name.m_pointer, "gamma_correction_factor");
  this->m_gamma_correction_factor = vostok::render::backend::register_constant_host(
                                      v143,
                                      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                      &name,
                                      0);
  if ( name.m_pointer.m_object )
  {
    v144 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v144 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v144, &name.m_pointer, "probe_parameters0");
  this->m_probe_parameters0 = vostok::render::backend::register_constant_host(
                                v145,
                                SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                &name,
                                0);
  if ( name.m_pointer.m_object )
  {
    v146 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v146 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v146, &name.m_pointer, "probe_parameters1");
  this->m_probe_parameters1 = vostok::render::backend::register_constant_host(
                                v147,
                                SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                &name,
                                0);
  if ( name.m_pointer.m_object )
  {
    v148 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v148 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v148, &name.m_pointer, "probe_parameters2");
  this->m_probe_parameters2 = vostok::render::backend::register_constant_host(
                                v149,
                                SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                &name,
                                0);
  if ( name.m_pointer.m_object )
  {
    v150 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v150 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v150, &name.m_pointer, "probe_parameters3");
  this->m_probe_parameters3 = vostok::render::backend::register_constant_host(
                                v151,
                                SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                &name,
                                0);
  if ( name.m_pointer.m_object )
  {
    v152 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v152 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v152, &name.m_pointer, "world_to_outer_probe");
  this->m_world_to_outer_probe = vostok::render::backend::register_constant_host(
                                   v153,
                                   SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                   &name,
                                   0);
  if ( name.m_pointer.m_object )
  {
    v154 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v154 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v154, &name.m_pointer, "probe_geometry_type");
  this->m_probe_geometry_type = vostok::render::backend::register_constant_host(
                                  v155,
                                  SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                  &name,
                                  (vostok::strings::shared::profile *)1);
  if ( name.m_pointer.m_object )
  {
    v156 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v156 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v156, &name.m_pointer, "ambient_light_particle_multiplier");
  this->m_c_ambient_light_particle_mult = vostok::render::backend::register_constant_host(
                                            v157,
                                            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                            &name,
                                            0);
  if ( name.m_pointer.m_object )
  {
    v158 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v158 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v158, &name.m_pointer, "particle_screen_divider");
  this->m_c_particle_screen_divider = vostok::render::backend::register_constant_host(
                                        v159,
                                        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                        &name,
                                        0);
  if ( name.m_pointer.m_object )
  {
    v160 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v160 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v160, &name.m_pointer, "m_shadow0");
  this->m_shadow[0] = vostok::render::backend::register_constant_host(
                        v161,
                        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                        &name,
                        0);
  if ( name.m_pointer.m_object )
  {
    v162 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v162 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v162, &name.m_pointer, "m_shadow1");
  this->m_shadow[1] = vostok::render::backend::register_constant_host(
                        v163,
                        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                        &name,
                        0);
  if ( name.m_pointer.m_object )
  {
    v164 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v164 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v164, &name.m_pointer, "m_shadow2");
  this->m_shadow[2] = vostok::render::backend::register_constant_host(
                        v165,
                        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                        &name,
                        0);
  if ( name.m_pointer.m_object )
  {
    v166 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v166 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v166, &name.m_pointer, "m_shadow3");
  this->m_shadow[3] = vostok::render::backend::register_constant_host(
                        v167,
                        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                        &name,
                        0);
  if ( name.m_pointer.m_object && !_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::strings::shared::detail::intrusive_base::destroy(
      0,
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  v193 = 16;
  v195 = 16;
  data[0] = 0;
  data[1] = 1;
  data[2] = 2;
  data[3] = 3;
  data[4] = 2;
  decl_size.SemanticIndex = 0;
  memset(&decl_size.InputSlot, 0, 16);
  v192 = 0;
  v194 = 0;
  v196 = 0;
  v197 = 0;
  decl_size.SemanticName = "POSITION";
  decl_size.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
  v191 = "TEXCOORD";
  data[5] = 1;
  vostok::render::resource_manager::create_buffer(
    0xCu,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)2,
    (vostok::render::enum_buffer_type)data,
    1,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v168,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&this->m_screen_vertex_ib,
    (vostok::render::hw_buffer_pool *)2);
  v170 = vostok::render::resource_manager::create_geometry(
           v169,
           (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
           &decl_size,
           2u,
           (vostok::render::untyped_buffer *)0x18,
           *(vostok::render::untyped_buffer **)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
           (int)this->m_screen_vertex_ib.m_object);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &this->m_screen_vertex_geometry,
    v170);
  v171 = vostok::render::g_allocator;
  v172 = type_info::raw_name(&vostok::render::shader_buffer `RTTI Type Descriptor');
  v174 = vostok::memory::doug_lea_allocator::malloc_impl(v173, (int)v171, 0x10u, v172, v183, v185, v187);
  if ( v174 )
  {
    num_max_lights_per_particle = vostok::render::options::get_num_max_lights_per_particle(
                                    (vostok::render::options *)v174,
                                    (int)vostok::quasi_singleton<vostok::render::options>::pinst);
    vostok::render::shader_buffer::shader_buffer(80 * num_max_lights_per_particle, v176, v184, v186);
  }
  else
  {
    v177 = 0;
  }
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &this->m_light_parameters_buffer,
    v177);
}
