void __thiscall vostok::render::stage_ambient_lighting::stage_ambient_lighting(
        vostok::render::renderer_context *context,
        vostok::render::stage_ambient_lighting *this,
        vostok::render::renderer *in_renderer)
{
  vostok::render::stage_ambient_lighting *v3; // ebx
  float v4; // xmm0_4
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v5; // esi
  vostok::render::effect_manager *v6; // ecx
  vostok::render::effect_manager *v7; // ecx
  vostok::render::effect_manager *v8; // ecx
  vostok::render::effect_manager *v9; // ecx
  vostok::render::effect_manager *v10; // ecx
  vostok::render::effect_manager *v11; // ecx
  vostok::render::effect_manager *v12; // ecx
  vostok::render::effect_manager *v13; // ecx
  vostok::render::effect_manager *v14; // ecx
  vostok::render::effect_manager *v15; // ecx
  vostok::render::effect_manager *v16; // ecx
  vostok::render::effect_manager *v17; // ecx
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
  vostok::shared_string *v30; // ecx
  vostok::render::backend *v31; // ecx
  vostok::shared_string *v32; // ecx
  vostok::render::backend *v33; // ecx
  vostok::shared_string *v34; // ecx
  vostok::render::backend *v35; // ecx
  vostok::shared_string *v36; // ecx
  vostok::render::backend *v37; // ecx
  vostok::shared_string *v38; // ecx
  vostok::render::backend *v39; // ecx
  vostok::shared_string *v40; // ecx
  vostok::render::backend *v41; // ecx
  vostok::shared_string *v42; // ecx
  vostok::render::backend *v43; // ecx
  vostok::shared_string *v44; // ecx
  vostok::render::backend *v45; // ecx
  vostok::shared_string *v46; // ecx
  vostok::render::backend *v47; // ecx
  vostok::shared_string *v48; // ecx
  vostok::render::backend *v49; // ecx
  vostok::shared_string *v50; // ecx
  vostok::render::backend *v51; // ecx
  vostok::shared_string *v52; // ecx
  vostok::render::backend *v53; // ecx
  vostok::shared_string *v54; // ecx
  vostok::render::backend *v55; // ecx
  vostok::shared_string *v56; // ecx
  vostok::render::backend *v57; // ecx
  vostok::shared_string *v58; // ecx
  vostok::render::backend *v59; // ecx
  vostok::shared_string *v60; // ecx
  vostok::render::backend *v61; // ecx
  vostok::shared_string *v62; // ecx
  vostok::render::backend *v63; // ecx
  vostok::shared_string *v64; // ecx
  vostok::render::backend *v65; // ecx
  vostok::shared_string *v66; // ecx
  vostok::render::backend *v67; // ecx
  vostok::shared_string *v68; // ecx
  vostok::render::backend *v69; // ecx
  vostok::shared_string *v70; // ecx
  vostok::render::backend *v71; // ecx
  vostok::shared_string *v72; // ecx
  vostok::render::backend *v73; // ecx
  vostok::shared_string *v74; // ecx
  vostok::render::backend *v75; // ecx
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
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v86; // eax
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v87; // eax
  vostok::render::untyped_buffer *m_object; // esi
  vostok::render::resource_manager *v89; // ecx
  vostok::render::res_geometry *v90; // eax
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v91; // eax
  void *v92; // esp
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v93; // eax
  vostok::render::resource_manager *v94; // ecx
  vostok::render::res_geometry *v95; // eax
  unsigned __int8 v96[68]; // [esp-48h] [ebp-70h] BYREF
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *p_m_effect_accum_mask; // [esp-4h] [ebp-2Ch]
  D3D11_INPUT_ELEMENT_DESC decl_size; // [esp+Ch] [ebp-1Ch] BYREF

  v3 = this;
  vostok::render::stage::stage(this, context, in_renderer);
  v3->__vftable = (vostok::render::stage_ambient_lighting_vtbl *)&vostok::render::stage_ambient_lighting::`vftable';
  v4 = s_bm_current_air_resistance;
  v3->m_effect_accum_mask.m_object = 0;
  v3->m_environment_probe_lighting_effect[0][0].m_object = 0;
  v3->m_environment_probe_lighting_effect[0][1].m_object = 0;
  v3->m_environment_probe_lighting_effect[1][0].m_object = 0;
  v3->m_environment_probe_lighting_effect[1][1].m_object = 0;
  v3->m_environment_probe_index_effect.m_object = 0;
  v3->m_skylight_effect.m_object = 0;
  v3->m_sky_ambient_occlusion_effect.m_object = 0;
  v3->m_ambient_volume_effect.m_object = 0;
  memset(v3->m_ambient_light_effect, 0, sizeof(v3->m_ambient_light_effect));
  v3->m_apply_ambient_lights_effect.m_object = 0;
  v3->m_reflection_mask_effect.m_object = 0;
  v3->m_apply_ssao_effect.m_object = 0;
  v3->m_sh_ssao_downsample_position_and_normal.m_object = 0;
  v3->m_ambient_multiplier = v4;
  v3->m_probes_generating = 0;
  v3->m_use_probes = 1;
  v3->m_sphere_vertex_buffer.m_object = 0;
  v3->m_sphere_index_buffer.m_object = 0;
  v3->m_sphere_geometry.m_object = 0;
  v3->m_box_vertex_buffer.m_object = 0;
  p_m_effect_accum_mask = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_effect_accum_mask;
  v5 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
  v3->m_box_index_buffer.m_object = 0;
  v3->m_box_geometry.m_object = 0;
  vostok::render::effect_manager::create_effect<vostok::render::effect_light_mask>(0, v5, p_m_effect_accum_mask);
  vostok::render::effect_manager::create_effect<vostok::render::effect_sky_ambient_occlusion>(
    v6,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_sky_ambient_occlusion_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_volume>(
    v7,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_ambient_volume_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_light<0,0,0>>(
    v8,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v3->m_ambient_light_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_light<1,0,0>>(
    v9,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v3->m_ambient_light_effect[1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_light<2,0,0>>(
    v10,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v3->m_ambient_light_effect[2]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_light<0,1,0>>(
    v11,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v3->m_ambient_light_effect[0][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_light<1,1,0>>(
    v12,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v3->m_ambient_light_effect[1][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_light<2,1,0>>(
    v13,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v3->m_ambient_light_effect[2][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_light<0,0,1>>(
    v14,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_ambient_light_effect[0][0][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_light<1,0,1>>(
    v15,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_ambient_light_effect[1][0][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_light<2,0,1>>(
    v16,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_ambient_light_effect[2][0][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_light<0,1,1>>(
    v17,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_ambient_light_effect[0][1][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_light<1,1,1>>(
    v18,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_ambient_light_effect[1][1][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_light<2,1,1>>(
    v19,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_ambient_light_effect[2][1][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_apply_ambient_lights>(
    v20,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_apply_ambient_lights_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_reflection_mask>(
    v21,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_reflection_mask_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_apply_ssao>(
    v22,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_apply_ssao_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_environment_probe_lighting<0,0>>(
    v23,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v3->m_environment_probe_lighting_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_environment_probe_lighting<1,0>>(
    v24,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v3->m_environment_probe_lighting_effect[1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_environment_probe_lighting<0,1>>(
    v25,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_environment_probe_lighting_effect[0][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_environment_probe_lighting<1,1>>(
    v26,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_environment_probe_lighting_effect[1][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_environment_probe_index>(
    v27,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_environment_probe_index_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_downsample_position_and_normal>(
    v28,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_sh_ssao_downsample_position_and_normal);
  vostok::render::effect_manager::create_effect<vostok::render::effect_skylight>(
    v29,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_skylight_effect);
  vostok::shared_string::shared_string(
    v30,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "ambient_light_location_and_radius");
  v3->m_c_ambient_light_location_and_radius = vostok::render::backend::register_constant_host(
                                                v31,
                                                SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                                (const vostok::shared_string *)&this,
                                                0);
  if ( this )
  {
    v32 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v32 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v32,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "ambient_light_color_and_power");
  v3->ambient_light_color_and_power = vostok::render::backend::register_constant_host(
                                        v33,
                                        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                        (const vostok::shared_string *)&this,
                                        0);
  if ( this )
  {
    v34 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v34 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v34,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "s_eye_ray_corner");
  v3->m_c_eye_ray_corner = vostok::render::backend::register_constant_host(
                             v35,
                             SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                             (const vostok::shared_string *)&this,
                             0);
  if ( this )
  {
    v36 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v36 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v36,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "hba_parameters");
  v3->m_c_hba_parameters = vostok::render::backend::register_constant_host(
                             v37,
                             SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                             (const vostok::shared_string *)&this,
                             0);
  if ( this )
  {
    v38 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v38 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v38,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "hba_low_color");
  v3->m_c_hba_low_color = vostok::render::backend::register_constant_host(
                            v39,
                            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                            (const vostok::shared_string *)&this,
                            0);
  if ( this )
  {
    v40 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v40 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v40,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "hba_high_color");
  v3->m_c_hba_high_color = vostok::render::backend::register_constant_host(
                             v41,
                             SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                             (const vostok::shared_string *)&this,
                             0);
  if ( this )
  {
    v42 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v42 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v42,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "light_range");
  v3->m_c_light_range = vostok::render::backend::register_constant_host(
                          v43,
                          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                          (const vostok::shared_string *)&this,
                          0);
  if ( this )
  {
    v44 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v44 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v44,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "inner_radius");
  v3->m_c_inner_radius = vostok::render::backend::register_constant_host(
                           v45,
                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                           (const vostok::shared_string *)&this,
                           0);
  if ( this )
  {
    v46 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v46 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v46,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "num_mips");
  v3->m_c_num_mips = vostok::render::backend::register_constant_host(
                       v47,
                       SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                       (const vostok::shared_string *)&this,
                       (vostok::strings::shared::profile *)1);
  if ( this )
  {
    v48 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v48 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v48,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "skylight_parameters0");
  v3->m_c_skylight_parameters0 = vostok::render::backend::register_constant_host(
                                   v49,
                                   SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                   (const vostok::shared_string *)&this,
                                   0);
  if ( this )
  {
    v50 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v50 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v50,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "skylight_parameters1");
  v3->m_c_skylight_parameters1 = vostok::render::backend::register_constant_host(
                                   v51,
                                   SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                   (const vostok::shared_string *)&this,
                                   0);
  if ( this )
  {
    v52 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v52 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v52,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "skylight_parameters2");
  v3->m_c_skylight_parameters2 = vostok::render::backend::register_constant_host(
                                   v53,
                                   SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                   (const vostok::shared_string *)&this,
                                   0);
  if ( this )
  {
    v54 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v54 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v54,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "skylight_parameters3");
  v3->m_c_skylight_parameters3 = vostok::render::backend::register_constant_host(
                                   v55,
                                   SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                   (const vostok::shared_string *)&this,
                                   0);
  if ( this )
  {
    v56 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v56 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v56,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "skylight_parameters4");
  v3->m_c_skylight_parameters4 = vostok::render::backend::register_constant_host(
                                   v57,
                                   SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                   (const vostok::shared_string *)&this,
                                   0);
  if ( this )
  {
    v58 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v58 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v58,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "skylight_parameters5");
  v3->m_c_skylight_parameters5 = vostok::render::backend::register_constant_host(
                                   v59,
                                   SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                   (const vostok::shared_string *)&this,
                                   0);
  if ( this )
  {
    v60 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v60 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v60,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "skylight_parameters6");
  v3->m_c_skylight_parameters6 = vostok::render::backend::register_constant_host(
                                   v61,
                                   SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                   (const vostok::shared_string *)&this,
                                   0);
  if ( this )
  {
    v62 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v62 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v62,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "skylight_parameters7");
  v3->m_c_skylight_parameters7 = vostok::render::backend::register_constant_host(
                                   v63,
                                   SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                   (const vostok::shared_string *)&this,
                                   0);
  if ( this )
  {
    v64 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v64 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v64,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "outer_cube_side_sizes");
  v3->m_c_outer_cube_side_sizes = vostok::render::backend::register_constant_host(
                                    v65,
                                    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                    (const vostok::shared_string *)&this,
                                    0);
  if ( this )
  {
    v66 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v66 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v66,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "inner_cube_side_sizes");
  v3->m_c_inner_cube_side_sizes = vostok::render::backend::register_constant_host(
                                    v67,
                                    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                    (const vostok::shared_string *)&this,
                                    0);
  if ( this )
  {
    v68 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v68 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v68,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "view_to_local");
  v3->m_c_view_to_local = vostok::render::backend::register_constant_host(
                            v69,
                            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                            (const vostok::shared_string *)&this,
                            0);
  if ( this )
  {
    v70 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v70 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v70,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "local_side_width");
  v3->m_c_local_side_width = vostok::render::backend::register_constant_host(
                               v71,
                               SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                               (const vostok::shared_string *)&this,
                               0);
  if ( this )
  {
    v72 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v72 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v72,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "color_parameters");
  v3->m_c_color_parameters = vostok::render::backend::register_constant_host(
                               v73,
                               SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                               (const vostok::shared_string *)&this,
                               0);
  if ( this )
  {
    v74 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v74 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v74,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "world_to_ao_map");
  v3->m_c_world_to_ao_map = vostok::render::backend::register_constant_host(
                              v75,
                              SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                              (const vostok::shared_string *)&this,
                              0);
  if ( this )
  {
    v76 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v76 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v76,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "ambient_volume_multiplier");
  v3->m_c_ambient_volume_multiplier = vostok::render::backend::register_constant_host(
                                        v77,
                                        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                        (const vostok::shared_string *)&this,
                                        0);
  if ( this )
  {
    v78 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v78 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v78,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "world_to_inner_probe");
  v3->m_c_world_to_inner_probe = vostok::render::backend::register_constant_host(
                                   v79,
                                   SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                   (const vostok::shared_string *)&this,
                                   0);
  if ( this )
  {
    v80 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v80 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v80,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "world_to_outer_probe");
  v3->m_c_world_to_outer_probe = vostok::render::backend::register_constant_host(
                                   v81,
                                   SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                   (const vostok::shared_string *)&this,
                                   0);
  if ( this )
  {
    v82 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v82 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v82,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "probe_index");
  v3->m_c_probe_index = vostok::render::backend::register_constant_host(
                          v83,
                          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                          (const vostok::shared_string *)&this,
                          (vostok::strings::shared::profile *)1);
  if ( this )
  {
    v84 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v84 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v84,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "face_average_colors");
  v3->m_c_face_average_colors = vostok::render::backend::register_constant_host(
                                  v85,
                                  SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                  (const vostok::shared_string *)&this,
                                  0);
  if ( this && !_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF) )
    vostok::strings::shared::detail::intrusive_base::destroy(
      0,
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  vostok::render::resource_manager::create_buffer(
    0x450u,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)0xC,
    (vostok::render::enum_buffer_type)du_sphere_vertices,
    0,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v86,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&v3->m_sphere_vertex_buffer,
    (vostok::render::hw_buffer_pool *)&v3->m_sphere_vertex_buffer);
  vostok::render::resource_manager::create_buffer(
    0x438u,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)2,
    (vostok::render::enum_buffer_type)du_sphere_faces,
    1,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v87,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&v3->m_sphere_index_buffer,
    (vostok::render::hw_buffer_pool *)&v3->m_sphere_vertex_buffer);
  m_object = v3->m_sphere_vertex_buffer.m_object;
  p_m_effect_accum_mask = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v3->m_sphere_index_buffer.m_object;
  decl_size.SemanticIndex = 0;
  memset(&decl_size.InputSlot, 0, 16);
  decl_size.SemanticName = "POSITION";
  decl_size.Format = DXGI_FORMAT_R32G32B32_FLOAT;
  v90 = vostok::render::resource_manager::create_geometry(
          v89,
          (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          &decl_size,
          1u,
          (vostok::render::untyped_buffer *)0xC,
          m_object,
          (int)p_m_effect_accum_mask);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &v3->m_sphere_geometry,
    v90);
  vostok::render::resource_manager::create_buffer(
    0x60u,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)0xC,
    (vostok::render::enum_buffer_type)vostok::geometry_utils::cube_solid::vertices,
    0,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v91,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&v3->m_box_vertex_buffer,
    (vostok::render::hw_buffer_pool *)&v3->m_box_vertex_buffer);
  v92 = alloca(72);
  stlp_std::priv::__copy_trivial(
    (unsigned __int8 *)vostok::geometry_utils::cube_solid::faces,
    (unsigned __int8 *)vostok::geometry_utils::rectangle_solid::vertices,
    v96);
  vostok::render::resource_manager::create_buffer(
    0x48u,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)2,
    (vostok::render::enum_buffer_type)v96,
    1,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v93,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&v3->m_box_index_buffer,
    (vostok::render::hw_buffer_pool *)&v3->m_box_vertex_buffer);
  v95 = vostok::render::resource_manager::create_geometry(
          v94,
          (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          &decl_size,
          1u,
          (vostok::render::untyped_buffer *)0xC,
          v3->m_box_vertex_buffer.m_object,
          (int)v3->m_box_index_buffer.m_object);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &v3->m_box_geometry,
    v95);
}
