void __thiscall vostok::render::stage_composition::stage_composition(
        vostok::render::renderer_context *context,
        vostok::render::stage_composition *this,
        vostok::render::renderer *in_renderer)
{
  vostok::render::stage_composition *v3; // ebx
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v4; // esi
  vostok::render::effect_manager *v5; // ecx
  vostok::render::effect_manager *v6; // ecx
  vostok::shared_string *v7; // ecx
  vostok::render::backend *v8; // ecx
  vostok::shared_string *v9; // ecx
  vostok::render::backend *v10; // ecx
  vostok::shared_string *v11; // ecx
  vostok::render::backend *v12; // ecx
  vostok::shared_string *v13; // ecx
  vostok::render::backend *v14; // ecx
  vostok::shared_string *v15; // ecx
  vostok::render::backend *v16; // ecx
  vostok::shared_string *v17; // ecx
  vostok::render::backend *v18; // ecx
  vostok::shared_string *v19; // ecx
  vostok::render::backend *v20; // ecx
  vostok::shared_string *v21; // ecx
  vostok::render::backend *v22; // ecx
  vostok::shared_string *v23; // ecx
  vostok::render::backend *v24; // ecx
  vostok::shared_string *v25; // ecx
  vostok::render::backend *v26; // ecx
  vostok::shared_string *v27; // ecx
  vostok::render::backend *v28; // ecx

  v3 = this;
  vostok::render::stage::stage(this, context, in_renderer);
  v4 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
  v3->__vftable = (vostok::render::stage_composition_vtbl *)&vostok::render::stage_composition::`vftable';
  v3->m_composition_effect[0].m_object = 0;
  v3->m_composition_effect[1].m_object = 0;
  v3->m_debug_modify_gbuffer_effect.m_object = 0;
  v3->m_view_mode = lit_view_mode;
  vostok::render::effect_manager::create_effect<vostok::render::effect_composition<0>>(
    (vostok::render::effect_manager *)v3->m_composition_effect,
    v4,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v3->m_composition_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_composition<1>>(
    v5,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_composition_effect[1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_debug_modify_gbuffer>(
    v6,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_debug_modify_gbuffer_effect);
  vostok::shared_string::shared_string(
    v7,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "wind_info_parameters");
  v3->m_wind_info_parameters = vostok::render::backend::register_constant_host(
                                 v8,
                                 SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                 (const vostok::shared_string *)&this,
                                 0);
  if ( this )
  {
    v9 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v9 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v9,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "sun_light_parameters");
  v3->m_sun_light_parameters = vostok::render::backend::register_constant_host(
                                 v10,
                                 SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                 (const vostok::shared_string *)&this,
                                 0);
  if ( this )
  {
    v11 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v11 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v11,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "s_eye_ray_corner");
  v3->m_eye_ray_corner_parameter = vostok::render::backend::register_constant_host(
                                     v12,
                                     SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                     (const vostok::shared_string *)&this,
                                     0);
  if ( this )
  {
    v13 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v13 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v13,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "light_color");
  v3->m_c_light_color = vostok::render::backend::register_constant_host(
                          v14,
                          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                          (const vostok::shared_string *)&this,
                          0);
  if ( this )
  {
    v15 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v15 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v15,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "light_direction");
  v3->m_c_light_direction = vostok::render::backend::register_constant_host(
                              v16,
                              SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                              (const vostok::shared_string *)&this,
                              0);
  if ( this )
  {
    v17 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v17 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v17,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "light_intensity");
  v3->m_c_light_intensity = vostok::render::backend::register_constant_host(
                              v18,
                              SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                              (const vostok::shared_string *)&this,
                              0);
  if ( this )
  {
    v19 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v19 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v19,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "shadow_transparency");
  v3->m_c_shadow_transparency = vostok::render::backend::register_constant_host(
                                  v20,
                                  SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                  (const vostok::shared_string *)&this,
                                  0);
  if ( this )
  {
    v21 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v21 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v21,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "light_diffuse_influence_factor");
  v3->m_c_diffuse_influence_factor = vostok::render::backend::register_constant_host(
                                       v22,
                                       SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                       (const vostok::shared_string *)&this,
                                       0);
  if ( this )
  {
    v23 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v23 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v23,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "light_specular_influence_factor");
  v3->m_c_specular_influence_factor = vostok::render::backend::register_constant_host(
                                        v24,
                                        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                        (const vostok::shared_string *)&this,
                                        0);
  if ( this )
  {
    v25 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v25 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v25,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "inverted_view_projection_matrix");
  v3->m_c_inverted_view_projection_matrix = vostok::render::backend::register_constant_host(
                                              v26,
                                              SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                              (const vostok::shared_string *)&this,
                                              0);
  if ( this )
  {
    v27 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v27 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v27,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "debug_multipliers");
  v3->m_c_debug_multipliers = vostok::render::backend::register_constant_host(
                                v28,
                                SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                (const vostok::shared_string *)&this,
                                0);
  if ( this && !_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF) )
    vostok::strings::shared::detail::intrusive_base::destroy(
      0,
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  v3->m_enabled = 1;
}
