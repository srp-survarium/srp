void __thiscall vostok::render::stage_gbuffer::stage_gbuffer(
        vostok::render::renderer_context *context,
        vostok::render::stage_gbuffer *this,
        vostok::render::renderer *in_renderer)
{
  vostok::render::stage_gbuffer *v3; // ebx
  vostok::shared_string *v4; // ecx
  vostok::render::backend *v5; // ecx
  vostok::shared_string *v6; // ecx
  vostok::render::backend *v7; // ecx
  vostok::shared_string *v8; // ecx
  vostok::render::backend *v9; // ecx
  vostok::shared_string *v10; // ecx
  vostok::render::backend *v11; // ecx
  vostok::shared_string *v12; // ecx
  vostok::render::backend *v13; // ecx
  vostok::shared_string *v14; // ecx
  vostok::render::backend *v15; // ecx
  vostok::shared_string *v16; // ecx
  vostok::render::backend *v17; // ecx
  vostok::shared_string *v18; // ecx
  vostok::render::backend *v19; // ecx
  vostok::shared_string *v20; // ecx
  vostok::render::backend *v21; // ecx
  vostok::shared_string *v22; // ecx
  vostok::render::backend *v23; // ecx
  vostok::shared_string *v24; // ecx
  vostok::render::backend *v25; // ecx
  vostok::shared_string *v26; // ecx
  vostok::render::backend *v27; // ecx
  vostok::shared_string *v28; // ecx
  vostok::render::backend *v29; // ecx
  vostok::shared_string *v30; // ecx
  vostok::render::backend *v31; // ecx
  vostok::shared_string *v32; // ecx
  vostok::render::backend *v33; // ecx
  vostok::shared_string *v34; // ecx
  vostok::render::backend *v35; // ecx
  vostok::render::effect_manager *v36; // ecx
  vostok::render::effect_manager *v37; // ecx
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v38; // esi
  bool v39; // zf
  vostok::render::effect_descriptor *v40; // eax
  __int64 v41; // [esp-14h] [ebp-34h]
  vostok::render::effect_manager *v42; // [esp-4h] [ebp-24h]
  vostok::render::surface_effect_parameters v43; // [esp+10h] [ebp-10h] BYREF

  v3 = this;
  vostok::render::stage::stage(this, context, in_renderer);
  v3->__vftable = (vostok::render::stage_gbuffer_vtbl *)&vostok::render::stage_gbuffer::`vftable';
  v3->m_state.m_object = 0;
  v3->m_copy_depth_rt.m_object = 0;
  v3->m_fill_depth_effect.m_object = 0;
  v3->m_debug_tech_pass_index = 0;
  v3->m_fill_view_space_depth = 0;
  vostok::shared_string::shared_string(
    v4,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "object_transparency_scale");
  v3->m_object_transparency_scale_parameter = vostok::render::backend::register_constant_host(
                                                v5,
                                                SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                                (const vostok::shared_string *)&this,
                                                0);
  if ( this )
  {
    v6 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v6 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v6,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "start_corner");
  v3->m_c_start_corner = vostok::render::backend::register_constant_host(
                           v7,
                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                           (const vostok::shared_string *)&this,
                           0);
  if ( this )
  {
    v8 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v8 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v8,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "bound_box_min");
  v3->m_c_bound_box_min = vostok::render::backend::register_constant_host(
                            v9,
                            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                            (const vostok::shared_string *)&this,
                            0);
  if ( this )
  {
    v10 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v10 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v10,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "bound_box_max");
  v3->m_c_bound_box_max = vostok::render::backend::register_constant_host(
                            v11,
                            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                            (const vostok::shared_string *)&this,
                            0);
  if ( this )
  {
    v12 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v12 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v12,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "sun_near_aabb_point");
  v3->m_c_sun_near_aabb_point = vostok::render::backend::register_constant_host(
                                  v13,
                                  SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                  (const vostok::shared_string *)&this,
                                  0);
  if ( this )
  {
    v14 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v14 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v14,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "ambient_color");
  v3->m_ambient_color = vostok::render::backend::register_constant_host(
                          v15,
                          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                          (const vostok::shared_string *)&this,
                          0);
  if ( this )
  {
    v16 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v16 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v16,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "gs_test_constant");
  v3->m_c_gs_test_constant = vostok::render::backend::register_constant_host(
                               v17,
                               SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                               (const vostok::shared_string *)&this,
                               0);
  if ( this )
  {
    v18 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v18 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v18,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "translucency_max_scatter");
  v3->m_c_translucency_max_scatter = vostok::render::backend::register_constant_host(
                                       v19,
                                       SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                       (const vostok::shared_string *)&this,
                                       0);
  if ( this )
  {
    v20 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v20 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v20,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "m_shadow0");
  v3->m_shadow[0] = vostok::render::backend::register_constant_host(
                      v21,
                      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                      (const vostok::shared_string *)&this,
                      0);
  if ( this )
  {
    v22 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v22 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v22,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "m_shadow1");
  v3->m_shadow[1] = vostok::render::backend::register_constant_host(
                      v23,
                      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                      (const vostok::shared_string *)&this,
                      0);
  if ( this )
  {
    v24 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v24 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v24,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "m_shadow2");
  v3->m_shadow[2] = vostok::render::backend::register_constant_host(
                      v25,
                      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                      (const vostok::shared_string *)&this,
                      0);
  if ( this )
  {
    v26 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v26 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v26,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "m_shadow3");
  v3->m_shadow[3] = vostok::render::backend::register_constant_host(
                      v27,
                      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                      (const vostok::shared_string *)&this,
                      0);
  if ( this )
  {
    v28 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v28 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v28,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "wind_info_parameters");
  v3->m_wind_info_parameters = vostok::render::backend::register_constant_host(
                                 v29,
                                 SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                 (const vostok::shared_string *)&this,
                                 0);
  if ( this )
  {
    v30 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v30 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v30,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "smoothness_multiplier");
  v3->m_smoothness_multiplier = vostok::render::backend::register_constant_host(
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
    "instansing_matrices");
  v3->m_instansing_matrices = vostok::render::backend::register_constant_host(
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
    "buffer_offset");
  v3->m_buffer_offset = vostok::render::backend::register_constant_host(
                          v35,
                          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                          (const vostok::shared_string *)&this,
                          (vostok::strings::shared::profile *)1);
  if ( this )
  {
    v36 = (vostok::render::effect_manager *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v36 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::render::effect_manager::create_effect<vostok::render::effect_copy_depth_rt>(
    v36,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_copy_depth_rt);
  memset(&v43.cull_mode, 255, 12);
  v38 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
  v43.vertex_input_type = 1;
  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_fill_reflective_shadow_map>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_fill_reflective_shadow_map>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_fill_reflective_shadow_map>'::`2'::descriptor_object.m_object = (vostok::configs::binary_config *)&vostok::render::effect_fill_reflective_shadow_map::`vftable';
    atexit((int (__cdecl *)())`vostok::render::effect_manager::create_effect<vostok::render::effect_fill_reflective_shadow_map>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
    v37 = v42;
  }
  v39 = LOBYTE(v38->m_object) == 0;
  this = 0;
  if ( v39 )
  {
    HIDWORD(v41) = &v3->m_fill_depth_effect;
    LODWORD(v41) = v38;
    vostok::render::effect_manager::create_new_effect(
      v37,
      v41,
      (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_fill_reflective_shadow_map>'::`2'::descriptor_object,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
      &v43);
  }
  else
  {
    v40 = vostok::render::effect_manager::create_new_effect(
            v37,
            v38,
            (vostok::render::effect_descriptor *)&in_renderer,
            (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_fill_reflective_shadow_map>'::`2'::descriptor_object,
            (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
            &v43);
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v40,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_fill_depth_effect);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&in_renderer);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
}
