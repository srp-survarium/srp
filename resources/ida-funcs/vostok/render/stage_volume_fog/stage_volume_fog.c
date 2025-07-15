void __userpurge vostok::render::stage_volume_fog::stage_volume_fog(
        vostok::render::stage_volume_fog *this@<edi>,
        vostok::render::renderer_context *in_context@<ecx>,
        vostok::render::renderer *in_renderer)
{
  vostok::render::fog_box_geometry *v3; // ecx
  vostok::render::sphere_geometry *v4; // ecx
  vostok::shared_string *v5; // ecx
  vostok::render::backend *v6; // ecx
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
  vostok::render::effect_manager *v29; // ecx

  vostok::render::stage::stage(this, in_context, in_renderer);
  this->__vftable = (vostok::render::stage_volume_fog_vtbl *)&vostok::render::stage_volume_fog::`vftable';
  vostok::render::fog_box_geometry::fog_box_geometry(v3, &this->m_fog_box_geometry.m_geometry);
  vostok::render::sphere_geometry::sphere_geometry(
    v4,
    &this->m_fog_sphere_geometry.m_vertext_declaration.m_object,
    COERCE_FLOAT(32),
    COERCE_FLOAT(32));
  this->m_exponential_volume_fog_effect.m_object = 0;
  vostok::shared_string::shared_string(
    v5,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&in_renderer,
    "s_eye_ray_corner");
  this->m_eye_ray_corner_parameter = vostok::render::backend::register_constant_host(
                                       v6,
                                       SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                       (const vostok::shared_string *)&in_renderer,
                                       0);
  if ( in_renderer )
  {
    v7 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)in_renderer, 0xFFFFFFFF);
    if ( !v7 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)in_renderer);
  }
  vostok::shared_string::shared_string(
    v7,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&in_renderer,
    "inverted_world_matrix");
  this->m_inverted_world_matrix_parameter = vostok::render::backend::register_constant_host(
                                              v8,
                                              SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                              (const vostok::shared_string *)&in_renderer,
                                              0);
  if ( in_renderer )
  {
    v9 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)in_renderer, 0xFFFFFFFF);
    if ( !v9 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)in_renderer);
  }
  vostok::shared_string::shared_string(
    v9,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&in_renderer,
    "eye_pos_os");
  this->m_eye_pos_os_parameter = vostok::render::backend::register_constant_host(
                                   v10,
                                   SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                   (const vostok::shared_string *)&in_renderer,
                                   0);
  if ( in_renderer )
  {
    v11 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)in_renderer, 0xFFFFFFFF);
    if ( !v11 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)in_renderer);
  }
  vostok::shared_string::shared_string(
    v11,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&in_renderer,
    "eye_pos_ws");
  this->m_eye_pos_ws_parameter = vostok::render::backend::register_constant_host(
                                   v12,
                                   SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                   (const vostok::shared_string *)&in_renderer,
                                   0);
  if ( in_renderer )
  {
    v13 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)in_renderer, 0xFFFFFFFF);
    if ( !v13 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)in_renderer);
  }
  vostok::shared_string::shared_string(
    v13,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&in_renderer,
    "is_inside_volume");
  this->m_is_inside_volume_parameter = vostok::render::backend::register_constant_host(
                                         v14,
                                         SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                         (const vostok::shared_string *)&in_renderer,
                                         (vostok::strings::shared::profile *)1);
  if ( in_renderer )
  {
    v15 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)in_renderer, 0xFFFFFFFF);
    if ( !v15 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)in_renderer);
  }
  vostok::shared_string::shared_string(
    v15,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&in_renderer,
    "fog_parameters0");
  this->m_fog_parameters0 = vostok::render::backend::register_constant_host(
                              v16,
                              SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                              (const vostok::shared_string *)&in_renderer,
                              0);
  if ( in_renderer )
  {
    v17 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)in_renderer, 0xFFFFFFFF);
    if ( !v17 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)in_renderer);
  }
  vostok::shared_string::shared_string(
    v17,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&in_renderer,
    "fog_parameters1");
  this->m_fog_parameters1 = vostok::render::backend::register_constant_host(
                              v18,
                              SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                              (const vostok::shared_string *)&in_renderer,
                              0);
  if ( in_renderer )
  {
    v19 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)in_renderer, 0xFFFFFFFF);
    if ( !v19 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)in_renderer);
  }
  vostok::shared_string::shared_string(
    v19,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&in_renderer,
    "fog_parameters2");
  this->m_fog_parameters2 = vostok::render::backend::register_constant_host(
                              v20,
                              SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                              (const vostok::shared_string *)&in_renderer,
                              0);
  if ( in_renderer )
  {
    v21 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)in_renderer, 0xFFFFFFFF);
    if ( !v21 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)in_renderer);
  }
  vostok::shared_string::shared_string(
    v21,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&in_renderer,
    "fog_parameters3");
  this->m_fog_parameters3 = vostok::render::backend::register_constant_host(
                              v22,
                              SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                              (const vostok::shared_string *)&in_renderer,
                              0);
  if ( in_renderer )
  {
    v23 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)in_renderer, 0xFFFFFFFF);
    if ( !v23 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)in_renderer);
  }
  vostok::shared_string::shared_string(
    v23,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&in_renderer,
    "far_fog_color_and_distance");
  this->m_far_fog_color_and_distance = vostok::render::backend::register_constant_host(
                                         v24,
                                         SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                         (const vostok::shared_string *)&in_renderer,
                                         0);
  if ( in_renderer )
  {
    v25 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)in_renderer, 0xFFFFFFFF);
    if ( !v25 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)in_renderer);
  }
  vostok::shared_string::shared_string(
    v25,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&in_renderer,
    "near_fog_distance");
  this->m_near_fog_distance = vostok::render::backend::register_constant_host(
                                v26,
                                SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                (const vostok::shared_string *)&in_renderer,
                                0);
  if ( in_renderer )
  {
    v27 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)in_renderer, 0xFFFFFFFF);
    if ( !v27 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)in_renderer);
  }
  vostok::shared_string::shared_string(
    v27,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&in_renderer,
    "fog_alpha");
  this->m_fog_alpha = vostok::render::backend::register_constant_host(
                        v28,
                        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                        (const vostok::shared_string *)&in_renderer,
                        0);
  if ( in_renderer )
  {
    v29 = (vostok::render::effect_manager *)_InterlockedExchangeAdd((volatile signed __int32 *)in_renderer, 0xFFFFFFFF);
    if ( !v29 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)in_renderer);
  }
  vostok::render::effect_manager::create_effect<vostok::render::effect_exponential_volume_fog>(
    v29,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_exponential_volume_fog_effect);
  this->m_enabled = 1;
}
