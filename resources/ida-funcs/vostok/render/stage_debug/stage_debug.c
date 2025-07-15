void __userpurge vostok::render::stage_debug::stage_debug(
        vostok::render::stage_debug *this@<edi>,
        vostok::render::renderer_context *context@<ecx>,
        vostok::render::renderer *in_renderer)
{
  vostok::render::sphere_geometry *v3; // ecx
  vostok::render::box_geometry *v4; // ecx
  vostok::render::effect_manager *v5; // ecx
  vostok::shared_string *v6; // ecx
  vostok::render::backend *v7; // ecx
  vostok::shared_string *v8; // ecx
  vostok::render::backend *v9; // ecx
  vostok::shared_string *v10; // ecx
  vostok::render::backend *v11; // ecx

  vostok::render::stage::stage(this, context, in_renderer);
  this->__vftable = (vostok::render::stage_debug_vtbl *)&vostok::render::stage_debug::`vftable';
  this->m_debug_environment_probe_preview_effect.m_object = 0;
  vostok::render::sphere_geometry::sphere_geometry(
    v3,
    &this->m_sphere_geometry.m_vertext_declaration.m_object,
    COERCE_FLOAT(32),
    COERCE_FLOAT(32));
  vostok::render::box_geometry::box_geometry(v4, (int)&this->m_box_geometry);
  vostok::render::effect_manager::create_effect<vostok::render::effect_debug_environment_probe_preview>(
    v5,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_debug_environment_probe_preview_effect);
  vostok::shared_string::shared_string(
    v6,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&in_renderer,
    "preview_mip_index");
  this->m_preview_mip_index_parameter = vostok::render::backend::register_constant_host(
                                          v7,
                                          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                          (const vostok::shared_string *)&in_renderer,
                                          (vostok::strings::shared::profile *)1);
  if ( in_renderer )
  {
    v8 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)in_renderer, 0xFFFFFFFF);
    if ( !v8 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)in_renderer);
  }
  vostok::shared_string::shared_string(
    v8,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&in_renderer,
    "face_average_colors");
  this->m_c_face_average_colors = vostok::render::backend::register_constant_host(
                                    v9,
                                    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                    (const vostok::shared_string *)&in_renderer,
                                    0);
  if ( in_renderer )
  {
    v10 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)in_renderer, 0xFFFFFFFF);
    if ( !v10 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)in_renderer);
  }
  vostok::shared_string::shared_string(
    v10,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&in_renderer,
    "preview_geometry_type");
  this->m_preview_geometry_type_parameter = vostok::render::backend::register_constant_host(
                                              v11,
                                              SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                              (const vostok::shared_string *)&in_renderer,
                                              (vostok::strings::shared::profile *)1);
  if ( in_renderer )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)in_renderer, 0xFFFFFFFF) )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)in_renderer);
  }
}
