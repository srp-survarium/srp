void __userpurge vostok::render::stage_ambient_occlusion::stage_ambient_occlusion(
        vostok::render::stage_ambient_occlusion *this@<edi>,
        vostok::render::renderer_context *context@<ecx>,
        vostok::render::renderer *in_renderer)
{
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v3; // esi
  vostok::render::effect_manager *v4; // ecx
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

  vostok::render::stage::stage(this, context, in_renderer);
  v3 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
  this->__vftable = (vostok::render::stage_ambient_occlusion_vtbl *)&vostok::render::stage_ambient_occlusion::`vftable';
  this->m_sh_combine.m_object = 0;
  this->m_sh_ssao_accumulation.m_object = 0;
  this->m_sh_ssao_filter4x4.m_object = 0;
  this->m_sh_ssao_downsample_position_and_normal.m_object = 0;
  this->m_post_process_antialiasing_shader.m_object = 0;
  this->m_post_process_deferred_transparency_shader.m_object = 0;
  this->m_g_combine.m_object = 0;
  this->m_vb.m_object = 0;
  vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_accumulation>(
    v4,
    v3,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_sh_ssao_accumulation);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_filter4x4>(
    v5,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_sh_ssao_filter4x4);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_downsample_position_and_normal>(
    v6,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_sh_ssao_downsample_position_and_normal);
  vostok::shared_string::shared_string(
    v7,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&in_renderer,
    "s_eye_ray_corner");
  this->m_c_eye_ray_corner = vostok::render::backend::register_constant_host(
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
    "ao_parameters");
  this->m_ao_parameters = vostok::render::backend::register_constant_host(
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
    "prev_view");
  this->m_prev_view_parameter = vostok::render::backend::register_constant_host(
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
    "prev_ssao_valid");
  this->m_prev_ssao_valid_parameter = vostok::render::backend::register_constant_host(
                                        v14,
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
