void __userpurge vostok::render::stage_postprocess::stage_postprocess(
        vostok::render::renderer_context *context@<ecx>,
        vostok::render::surface_effect_parameters this)
{
  unsigned int vertex_input_type; // ebx
  vostok::math::float4x4 *v3; // ecx
  vostok::render::dof_shader_constants *v4; // ecx
  vostok::render::scene_shader_constants *v5; // ecx
  float v6; // xmm0_4
  char *v7; // ecx
  char vertex_input_type_high; // al
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *color_grading_base_lut; // eax
  vostok::render::resource_manager *v10; // ecx
  bool v11; // zf
  vostok::render::resource_manager *v12; // ecx
  stlp_std::priv::_Rb_tree_node_base *volume_render_target; // eax
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v14; // eax
  vostok::render::res_texture *cull_mode; // esi
  vostok::render::resource_manager *v16; // ecx
  vostok::render::res_texture *v17; // eax
  vostok::render::effect_manager *v18; // ecx
  vostok::render::effect_manager *v19; // ecx
  vostok::render::effect_manager *v20; // ecx
  vostok::render::effect_manager *v21; // ecx
  vostok::render::effect_manager *v22; // ecx
  vostok::render::effect_manager *v23; // ecx
  vostok::render::effect_manager *v24; // ecx
  vostok::render::effect_manager *v25; // ecx
  vostok::render::effect_manager *v26; // ecx
  vostok::render::effect_manager *v27; // ecx
  vostok::render::effect_manager *v28; // ecx
  vostok::render::effect_manager *v29; // ecx
  vostok::render::effect_manager *v30; // ecx
  vostok::render::effect_manager *v31; // ecx
  vostok::render::effect_manager *v32; // ecx
  vostok::render::effect_manager *v33; // ecx
  vostok::render::effect_manager *v34; // ecx
  vostok::render::effect_manager *v35; // ecx
  vostok::render::effect_manager *v36; // ecx
  vostok::render::effect_manager *v37; // ecx
  vostok::render::effect_manager *v38; // ecx
  vostok::render::effect_manager *v39; // ecx
  vostok::render::effect_manager *v40; // ecx
  vostok::render::effect_manager *v41; // ecx
  vostok::render::effect_manager *v42; // ecx
  vostok::render::effect_manager *v43; // ecx
  vostok::render::effect_manager *v44; // ecx
  vostok::render::effect_manager *v45; // ecx
  vostok::render::effect_manager *v46; // ecx
  vostok::render::effect_manager *v47; // ecx
  vostok::render::effect_manager *v48; // ecx
  vostok::render::effect_manager *v49; // ecx
  vostok::render::effect_manager *v50; // ecx
  vostok::render::effect_manager *v51; // ecx
  vostok::render::effect_manager *v52; // ecx
  vostok::render::effect_manager *v53; // ecx
  vostok::render::effect_manager *v54; // ecx
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v55; // esi
  vostok::render::effect_descriptor *v56; // eax
  vostok::shared_string *v57; // ecx
  vostok::render::backend *v58; // ecx
  vostok::shared_string *v59; // ecx
  vostok::render::backend *v60; // ecx
  vostok::shared_string *v61; // ecx
  vostok::render::backend *v62; // ecx
  vostok::shared_string *v63; // ecx
  vostok::render::backend *v64; // ecx
  vostok::shared_string *v65; // ecx
  vostok::render::backend *v66; // ecx
  vostok::shared_string *v67; // ecx
  vostok::render::backend *v68; // ecx
  vostok::shared_string *v69; // ecx
  vostok::render::backend *v70; // ecx
  vostok::shared_string *v71; // ecx
  vostok::render::backend *v72; // ecx
  vostok::shared_string *v73; // ecx
  vostok::render::backend *v74; // ecx
  vostok::shared_string *v75; // ecx
  vostok::render::backend *v76; // ecx
  vostok::shared_string *v77; // ecx
  vostok::render::backend *v78; // ecx
  vostok::shared_string *v79; // ecx
  vostok::render::backend *v80; // ecx
  vostok::shared_string *v81; // ecx
  vostok::render::backend *v82; // ecx
  vostok::shared_string *v83; // ecx
  vostok::render::backend *v84; // ecx
  vostok::shared_string *v85; // ecx
  vostok::render::backend *v86; // ecx
  vostok::shared_string *v87; // ecx
  vostok::render::backend *v88; // ecx
  vostok::shared_string *v89; // ecx
  vostok::render::backend *v90; // ecx
  vostok::shared_string *v91; // ecx
  vostok::render::backend *v92; // ecx
  vostok::shared_string *v93; // ecx
  vostok::render::backend *v94; // ecx
  vostok::shared_string *v95; // ecx
  vostok::render::backend *v96; // ecx
  vostok::shared_string *v97; // ecx
  vostok::render::backend *v98; // ecx
  vostok::shared_string *v99; // ecx
  vostok::render::backend *v100; // ecx
  vostok::shared_string *v101; // ecx
  vostok::render::backend *v102; // ecx
  vostok::shared_string *v103; // ecx
  vostok::render::backend *v104; // ecx
  vostok::shared_string *v105; // ecx
  vostok::render::backend *v106; // ecx
  vostok::shared_string *v107; // ecx
  vostok::render::backend *v108; // ecx
  vostok::shared_string *v109; // ecx
  vostok::render::backend *v110; // ecx
  vostok::shared_string *v111; // ecx
  vostok::render::backend *v112; // ecx
  vostok::shared_string *v113; // ecx
  vostok::render::backend *v114; // ecx
  vostok::shared_string *v115; // ecx
  vostok::render::backend *v116; // ecx
  vostok::shared_string *v117; // ecx
  vostok::render::backend *v118; // ecx
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v119; // eax
  vostok::render::resource_manager *v120; // ecx
  vostok::render::res_geometry *v121; // eax
  __int64 v122; // [esp-14h] [ebp-B4h]
  vostok::render::effect_manager *v123; // [esp-4h] [ebp-A4h]
  unsigned int v124; // [esp+0h] [ebp-A0h]
  unsigned int v125; // [esp+4h] [ebp-9Ch]
  unsigned int v126; // [esp+8h] [ebp-98h]
  vostok::math::float4x4 v127; // [esp+Ch] [ebp-94h] BYREF
  D3D11_INPUT_ELEMENT_DESC decl_size; // [esp+4Ch] [ebp-54h] BYREF
  const char *v129; // [esp+68h] [ebp-38h]
  int v130; // [esp+6Ch] [ebp-34h]
  int v131; // [esp+70h] [ebp-30h]
  int v132; // [esp+74h] [ebp-2Ch]
  int v133; // [esp+78h] [ebp-28h]
  int v134; // [esp+7Ch] [ebp-24h]
  int v135; // [esp+80h] [ebp-20h]
  vostok::render::surface_effect_parameters v136; // [esp+84h] [ebp-1Ch] BYREF
  _WORD data[2]; // [esp+94h] [ebp-Ch] BYREF
  int v138; // [esp+98h] [ebp-8h]
  int v139; // [esp+9Ch] [ebp-4h]

  vertex_input_type = this.vertex_input_type;
  this.vertex_input_type = 0;
  vostok::render::stage::stage(
    (vostok::render::stage *)vertex_input_type,
    context,
    (vostok::render::renderer *)this.cull_mode);
  *(_DWORD *)vertex_input_type = &vostok::render::stage_postprocess::`vftable';
  qmemcpy((void *)(vertex_input_type + 16), vostok::math::float4x4::identity(v3, &v127), 0x40u);
  vostok::render::sliced_cube_geometry::sliced_cube_geometry(
    0,
    (vostok::render::resource_manager *)(vertex_input_type + 80));
  *(_DWORD *)(vertex_input_type + 100) = 0;
  *(_DWORD *)(vertex_input_type + 108) = 0;
  *(_DWORD *)(vertex_input_type + 112) = 0;
  *(_DWORD *)(vertex_input_type + 116) = 0;
  *(_DWORD *)(vertex_input_type + 120) = 0;
  *(_DWORD *)(vertex_input_type + 124) = 0;
  *(_DWORD *)(vertex_input_type + 128) = 0;
  memset((void *)(vertex_input_type + 132), 0, 0x20u);
  *(_DWORD *)(vertex_input_type + 164) = 0;
  *(_DWORD *)(vertex_input_type + 168) = 0;
  *(_DWORD *)(vertex_input_type + 172) = 0;
  *(_DWORD *)(vertex_input_type + 176) = 0;
  *(_DWORD *)(vertex_input_type + 180) = 0;
  *(_DWORD *)(vertex_input_type + 184) = 0;
  *(_DWORD *)(vertex_input_type + 188) = 0;
  *(_DWORD *)(vertex_input_type + 192) = 0;
  *(_DWORD *)(vertex_input_type + 196) = 0;
  *(_DWORD *)(vertex_input_type + 200) = 0;
  *(_DWORD *)(vertex_input_type + 204) = 0;
  *(_DWORD *)(vertex_input_type + 208) = 0;
  *(_DWORD *)(vertex_input_type + 212) = 0;
  *(_DWORD *)(vertex_input_type + 216) = 0;
  *(_DWORD *)(vertex_input_type + 220) = 0;
  *(_DWORD *)(vertex_input_type + 224) = 0;
  *(_DWORD *)(vertex_input_type + 228) = 0;
  *(_DWORD *)(vertex_input_type + 232) = 0;
  memset((void *)(vertex_input_type + 236), 0, 0x20u);
  *(_DWORD *)(vertex_input_type + 268) = 0;
  *(_DWORD *)(vertex_input_type + 272) = 0;
  *(_DWORD *)(vertex_input_type + 276) = 0;
  *(_DWORD *)(vertex_input_type + 528) = 0;
  *(_DWORD *)(vertex_input_type + 532) = vertex_input_type + 544;
  *(_DWORD *)(vertex_input_type + 536) = vertex_input_type + 544;
  *(_DWORD *)(vertex_input_type + 540) = vertex_input_type + 800;
  *(_BYTE *)(vertex_input_type + 800) = 0;
  *(_DWORD *)(vertex_input_type + 804) = 0;
  *(_DWORD *)(vertex_input_type + 808) = 0;
  vostok::render::bloom_shader_constants::bloom_shader_constants(
    (vostok::render::bloom_shader_constants *)(vertex_input_type + 800),
    (vostok::render::shader_constant_host **)(vertex_input_type + 812));
  vostok::render::dof_shader_constants::dof_shader_constants(
    v4,
    (vostok::render::shader_constant_host **)(vertex_input_type + 820));
  vostok::render::scene_shader_constants::scene_shader_constants(
    v5,
    (vostok::render::shader_constant_host **)(vertex_input_type + 836));
  *(_DWORD *)(vertex_input_type + 880) = vertex_input_type + 892;
  *(_DWORD *)(vertex_input_type + 884) = vertex_input_type + 892;
  *(_DWORD *)(vertex_input_type + 888) = (char *)&loc_25FFF + vertex_input_type + 893;
  v6 = SNaN;
  memset(&v136, 0, 12);
  *(_DWORD *)((char *)&loc_2637C + vertex_input_type) = 0;
  *(float *)((char *)&loc_2637F + vertex_input_type + 1) = v6;
  *(float *)((char *)&loc_26383 + vertex_input_type + 1) = v6;
  v7 = (char *)&loc_26388 + vertex_input_type;
  *((_DWORD *)v7 + 4) = 0;
  v136.blend_mode = 0;
  vertex_input_type_high = HIBYTE(this.vertex_input_type);
  *(vostok::render::surface_effect_parameters *)((char *)&loc_26388 + vertex_input_type) = v136;
  *((_DWORD *)v7 + 1) = 0;
  v7[20] = vertex_input_type_high;
  *v7 = 0;
  *((_DWORD *)v7 + 2) = v7;
  *((_DWORD *)v7 + 3) = v7;
  color_grading_base_lut = vostok::render::create_color_grading_base_lut(
                             (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this,
                             (vostok::render::resource_manager *)((char *)&loc_26388 + vertex_input_type));
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    color_grading_base_lut,
    (vostok::render::res_texture *)(vertex_input_type + 804));
  if ( this.vertex_input_type )
  {
    v11 = (*(_DWORD *)(this.vertex_input_type + 4))-- == 1;
    if ( v11 )
      vostok::render::resource_manager::release(
        v10,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_texture *)this.vertex_input_type);
  }
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(vertex_input_type + 804),
    (vostok::render::res_texture *)(vertex_input_type + 808));
  volume_render_target = vostok::render::resource_manager::create_volume_render_target(
                           v12,
                           (char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                           v124,
                           v125,
                           v126,
                           SLODWORD(v127.i.x),
                           SLODWORD(v127.i.y),
                           SLODWORD(v127.i.z));
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(vertex_input_type + 108),
    (vostok::render::render_target *)volume_render_target);
  v14 = *(const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(vertex_input_type + 108);
  if ( v14
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    this.vertex_input_type = 1;
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this.cull_mode,
      v14 + 7);
    cull_mode = (vostok::render::res_texture *)this.cull_mode;
  }
  else
  {
    cull_mode = 0;
    this.vertex_input_type = 2;
    this.cull_mode = 0;
  }
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this.cull_mode,
    (vostok::render::res_texture *)(vertex_input_type + 112));
  if ( (this.vertex_input_type & 2) != 0 )
  {
    this.vertex_input_type &= ~2u;
    if ( cull_mode )
    {
      v11 = cull_mode->m_reference_count-- == 1;
      if ( v11 )
        vostok::render::resource_manager::release(
          v16,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          cull_mode);
    }
  }
  if ( (this.vertex_input_type & 1) != 0 )
  {
    v17 = (vostok::render::res_texture *)this.cull_mode;
    if ( this.cull_mode )
    {
      v11 = (*(_DWORD *)(this.cull_mode + 4))-- == 1;
      if ( v11 )
        vostok::render::resource_manager::release(
          v16,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v17);
    }
  }
  vostok::render::effect_manager::create_effect<vostok::render::effect_gather_bloom>(
    (vostok::render::effect_manager *)v16,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 116));
  vostok::render::effect_manager::create_effect<vostok::render::effect_gather_luminance>(
    v18,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 120));
  vostok::render::effect_manager::create_effect<vostok::render::effect_gather_luminance_histogram>(
    v19,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 124));
  vostok::render::effect_manager::create_effect<vostok::render::effect_eye_adaptation>(
    v20,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 128));
  vostok::render::effect_manager::create_effect<vostok::render::effect_color_grading_lut_blending>(
    v21,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 100));
  vostok::render::effect_manager::create_effect<vostok::render::effect_blur<3>>(
    v22,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 132));
  vostok::render::effect_manager::create_effect<vostok::render::effect_blur<5>>(
    v23,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 136));
  vostok::render::effect_manager::create_effect<vostok::render::effect_blur<7>>(
    v24,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 140));
  vostok::render::effect_manager::create_effect<vostok::render::effect_blur<9>>(
    v25,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 144));
  vostok::render::effect_manager::create_effect<vostok::render::effect_blur<13>>(
    v26,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 148));
  vostok::render::effect_manager::create_effect<vostok::render::effect_blur<17>>(
    v27,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 152));
  vostok::render::effect_manager::create_effect<vostok::render::effect_blur<21>>(
    v28,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 156));
  vostok::render::effect_manager::create_effect<vostok::render::effect_blur<25>>(
    v29,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 160));
  vostok::render::effect_manager::create_effect<vostok::render::effect_complex_post_process_blend<0,0>>(
    v30,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 164));
  vostok::render::effect_manager::create_effect<vostok::render::effect_complex_post_process_blend<1,0>>(
    v31,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 172));
  vostok::render::effect_manager::create_effect<vostok::render::effect_complex_post_process_blend<1,1>>(
    v32,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 176));
  vostok::render::effect_manager::create_effect<vostok::render::effect_copy_image>(
    v33,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 180));
  vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_mlaa>(
    v34,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 184));
  vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_fxaa>(
    v35,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 188));
  vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_sraa>(
    v36,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 192));
  vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_sharpen>(
    v37,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 196));
  vostok::render::effect_manager::create_effect<vostok::render::effect_god_rays>(
    v38,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 200));
  vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_downsample_frame>(
    v39,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 204));
  vostok::render::effect_manager::create_effect<vostok::render::effect_image_space_reflections>(
    v40,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 208));
  vostok::render::effect_manager::create_effect<vostok::render::effect_lens_flares>(
    v41,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 212));
  vostok::render::effect_manager::create_effect<vostok::render::effect_motion_blur>(
    v42,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 216));
  vostok::render::effect_manager::create_effect<vostok::render::effect_radial_motion_blur>(
    v43,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 220));
  vostok::render::effect_manager::create_effect<vostok::render::effect_channel_blur>(
    v44,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 224));
  vostok::render::effect_manager::create_effect<vostok::render::effect_temporal_antialiasing>(
    v45,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 232));
  vostok::render::effect_manager::create_effect<vostok::render::effect_aberration_and_sharpen<0,0,0>>(
    v46,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 236));
  vostok::render::effect_manager::create_effect<vostok::render::effect_aberration_and_sharpen<0,0,1>>(
    v47,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 240));
  vostok::render::effect_manager::create_effect<vostok::render::effect_aberration_and_sharpen<0,1,0>>(
    v48,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 244));
  vostok::render::effect_manager::create_effect<vostok::render::effect_aberration_and_sharpen<0,1,1>>(
    v49,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 248));
  vostok::render::effect_manager::create_effect<vostok::render::effect_aberration_and_sharpen<1,0,0>>(
    v50,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 252));
  vostok::render::effect_manager::create_effect<vostok::render::effect_aberration_and_sharpen<1,0,1>>(
    v51,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 256));
  vostok::render::effect_manager::create_effect<vostok::render::effect_aberration_and_sharpen<1,1,0>>(
    v52,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 260));
  vostok::render::effect_manager::create_effect<vostok::render::effect_aberration_and_sharpen<1,1,1>>(
    v53,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 264));
  v136.draw_to_gbuffer = -1;
  v136.blend_mode = -1;
  v55 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
  v136.vertex_input_type = 3;
  v136.cull_mode = 3;
  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_motion_vectors_accumulation>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_motion_vectors_accumulation>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_motion_vectors_accumulation>'::`2'::descriptor_object.m_object = (vostok::configs::binary_config *)&vostok::render::effect_motion_vectors_accumulation::`vftable';
    atexit((int (__cdecl *)())`vostok::render::effect_manager::create_effect<vostok::render::effect_motion_vectors_accumulation>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
    v54 = v123;
  }
  if ( LOBYTE(v55->m_object) )
  {
    this.vertex_input_type = 0;
    v56 = vostok::render::effect_manager::create_new_effect(
            v54,
            v55,
            (vostok::render::effect_descriptor *)&this.cull_mode,
            (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_motion_vectors_accumulation>'::`2'::descriptor_object,
            (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
            &v136);
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v56,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(vertex_input_type + 268));
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this.cull_mode);
  }
  else
  {
    HIDWORD(v122) = vertex_input_type + 268;
    LODWORD(v122) = v55;
    this.vertex_input_type = 0;
    vostok::render::effect_manager::create_new_effect(
      v54,
      v122,
      (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_motion_vectors_accumulation>'::`2'::descriptor_object,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
      &v136);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
  vostok::shared_string::shared_string(
    v57,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "offsets_weights");
  *(_DWORD *)(vertex_input_type + 284) = vostok::render::backend::register_constant_host(
                                           v58,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v59 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v59 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v59,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "kernel_offsets");
  *(_DWORD *)(vertex_input_type + 280) = vostok::render::backend::register_constant_host(
                                           v60,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v61 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v61 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v61,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "elapsed_time");
  *(_DWORD *)(vertex_input_type + 304) = vostok::render::backend::register_constant_host(
                                           v62,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v63 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v63 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v63,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "adaptation_factor");
  *(_DWORD *)(vertex_input_type + 308) = vostok::render::backend::register_constant_host(
                                           v64,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v65 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v65 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v65,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "sun_direction_parameter");
  *(_DWORD *)(vertex_input_type + 388) = vostok::render::backend::register_constant_host(
                                           v66,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v67 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v67 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v67,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "frame_luminance_parameter");
  *(_DWORD *)(vertex_input_type + 392) = vostok::render::backend::register_constant_host(
                                           v68,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v69 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v69 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v69,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "luminance_range_parameter");
  *(_DWORD *)(vertex_input_type + 300) = vostok::render::backend::register_constant_host(
                                           v70,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v71 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v71 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v71,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "gamma_correction_factor");
  *(_DWORD *)(vertex_input_type + 312) = vostok::render::backend::register_constant_host(
                                           v72,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v73 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v73 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v73,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "fxaa_parameters");
  *(_DWORD *)(vertex_input_type + 396) = vostok::render::backend::register_constant_host(
                                           v74,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v75 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v75 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v75,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "god_rays_parameters0");
  *(_DWORD *)(vertex_input_type + 328) = vostok::render::backend::register_constant_host(
                                           v76,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v77 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v77 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v77,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "god_rays_parameters1");
  *(_DWORD *)(vertex_input_type + 332) = vostok::render::backend::register_constant_host(
                                           v78,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v79 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v79 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v79,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "god_rays_parameters2");
  *(_DWORD *)(vertex_input_type + 336) = vostok::render::backend::register_constant_host(
                                           v80,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v81 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v81 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v81,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "s_eye_ray_corner");
  *(_DWORD *)(vertex_input_type + 340) = vostok::render::backend::register_constant_host(
                                           v82,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v83 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v83 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v83,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "frame_index");
  *(_DWORD *)(vertex_input_type + 344) = vostok::render::backend::register_constant_host(
                                           v84,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           (vostok::strings::shared::profile *)1);
  if ( this.vertex_input_type )
  {
    v85 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v85 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v85,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "blur_target_size");
  *(_DWORD *)(vertex_input_type + 380) = vostok::render::backend::register_constant_host(
                                           v86,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v87 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v87 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v87,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "lens_flares_parameters");
  *(_DWORD *)(vertex_input_type + 384) = vostok::render::backend::register_constant_host(
                                           v88,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v89 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v89 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v89,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "prev_view_matrix_parameter");
  *(_DWORD *)(vertex_input_type + 316) = vostok::render::backend::register_constant_host(
                                           v90,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v91 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v91 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v91,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "prev_world_view_matrix_parameter");
  *(_DWORD *)(vertex_input_type + 320) = vostok::render::backend::register_constant_host(
                                           v92,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v93 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v93 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v93,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "inverse_world_matrix_parameter");
  *(_DWORD *)(vertex_input_type + 324) = vostok::render::backend::register_constant_host(
                                           v94,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v95 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v95 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v95,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "frame_delta_parameter");
  *(_DWORD *)(vertex_input_type + 348) = vostok::render::backend::register_constant_host(
                                           v96,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v97 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v97 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v97,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "motion_blur_scale_parameter");
  *(_DWORD *)(vertex_input_type + 352) = vostok::render::backend::register_constant_host(
                                           v98,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v99 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v99 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v99,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "radial_blur_amount");
  *(_DWORD *)(vertex_input_type + 356) = vostok::render::backend::register_constant_host(
                                           v100,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v101 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                      (volatile signed __int32 *)this.vertex_input_type,
                                      0xFFFFFFFF);
    if ( !v101 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v101,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "radial_blur_intensity");
  *(_DWORD *)(vertex_input_type + 360) = vostok::render::backend::register_constant_host(
                                           v102,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v103 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                      (volatile signed __int32 *)this.vertex_input_type,
                                      0xFFFFFFFF);
    if ( !v103 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v103,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "radial_blur_power");
  *(_DWORD *)(vertex_input_type + 364) = vostok::render::backend::register_constant_host(
                                           v104,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v105 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                      (volatile signed __int32 *)this.vertex_input_type,
                                      0xFFFFFFFF);
    if ( !v105 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v105,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "channel_blur_amount");
  *(_DWORD *)(vertex_input_type + 368) = vostok::render::backend::register_constant_host(
                                           v106,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v107 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                      (volatile signed __int32 *)this.vertex_input_type,
                                      0xFFFFFFFF);
    if ( !v107 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v107,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "channel_blur_power");
  *(_DWORD *)(vertex_input_type + 372) = vostok::render::backend::register_constant_host(
                                           v108,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v109 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                      (volatile signed __int32 *)this.vertex_input_type,
                                      0xFFFFFFFF);
    if ( !v109 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v109,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "aberration_parameters");
  *(_DWORD *)(vertex_input_type + 376) = vostok::render::backend::register_constant_host(
                                           v110,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v111 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                      (volatile signed __int32 *)this.vertex_input_type,
                                      0xFFFFFFFF);
    if ( !v111 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v111,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "bloom_multiplier");
  *(_DWORD *)(vertex_input_type + 288) = vostok::render::backend::register_constant_host(
                                           v112,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v113 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                      (volatile signed __int32 *)this.vertex_input_type,
                                      0xFFFFFFFF);
    if ( !v113 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v113,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "downsample_parameters");
  *(_DWORD *)(vertex_input_type + 292) = vostok::render::backend::register_constant_host(
                                           v114,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v115 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                      (volatile signed __int32 *)this.vertex_input_type,
                                      0xFFFFFFFF);
    if ( !v115 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v115,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "image_grain_parameters");
  *(_DWORD *)(vertex_input_type + 296) = vostok::render::backend::register_constant_host(
                                           v116,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type )
  {
    v117 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                      (volatile signed __int32 *)this.vertex_input_type,
                                      0xFFFFFFFF);
    if ( !v117 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  }
  vostok::shared_string::shared_string(
    v117,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "color_grading_lut_weight");
  *(_DWORD *)(vertex_input_type + 104) = vostok::render::backend::register_constant_host(
                                           v118,
                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                           (const vostok::shared_string *)&this,
                                           0);
  if ( this.vertex_input_type && !_InterlockedExchangeAdd((volatile signed __int32 *)this.vertex_input_type, 0xFFFFFFFF) )
    vostok::strings::shared::detail::intrusive_base::destroy(
      0,
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type);
  this.vertex_input_type = 0;
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::resize(
    (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)0xA,
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(vertex_input_type + 532),
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this);
  v131 = 16;
  v133 = 16;
  data[0] = 0;
  data[1] = 1;
  v138 = 196610;
  v139 = 65538;
  decl_size.SemanticIndex = 0;
  memset(&decl_size.InputSlot, 0, 16);
  v130 = 0;
  v132 = 0;
  v134 = 0;
  v135 = 0;
  decl_size.SemanticName = "POSITION";
  decl_size.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
  v129 = "TEXCOORD";
  vostok::render::resource_manager::create_buffer(
    0xCu,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)2,
    (vostok::render::enum_buffer_type)data,
    1,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v119,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(vertex_input_type + 272),
    (vostok::render::hw_buffer_pool *)2);
  v121 = vostok::render::resource_manager::create_geometry(
           v120,
           (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
           &decl_size,
           2u,
           (vostok::render::untyped_buffer *)0x18,
           *(vostok::render::untyped_buffer **)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
           *(_DWORD *)(vertex_input_type + 272));
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(vertex_input_type + 276),
    v121);
  *(_DWORD *)((char *)&loc_2637F + vertex_input_type + 1) = 0;
  *(_DWORD *)((char *)&loc_26383 + vertex_input_type + 1) = 0;
}
