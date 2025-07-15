void __userpurge vostok::render::stage_screen_space_reflections::stage_screen_space_reflections(
        vostok::render::stage_screen_space_reflections *this@<edi>,
        vostok::render::renderer_context *context@<ecx>,
        vostok::render::renderer *in_renderer)
{
  vostok::shared_string *v3; // ecx
  vostok::render::backend *v4; // ecx
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

  vostok::render::stage::stage(this, context, in_renderer);
  this->__vftable = (vostok::render::stage_screen_space_reflections_vtbl *)&vostok::render::stage_screen_space_reflections::`vftable';
  vostok::shared_string::shared_string(
    v3,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&in_renderer,
    "s_eye_ray_corner");
  this->m_eye_ray_corner_parameter = vostok::render::backend::register_constant_host(
                                       v4,
                                       SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                       (const vostok::shared_string *)&in_renderer,
                                       0);
  if ( in_renderer )
  {
    v5 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)in_renderer, 0xFFFFFFFF);
    if ( !v5 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)in_renderer);
  }
  vostok::shared_string::shared_string(
    v5,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&in_renderer,
    "view_to_shadow");
  this->m_view_to_shadow_parameter = vostok::render::backend::register_constant_host(
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
    "rain_offset");
  this->m_rain_offset_parameter = vostok::render::backend::register_constant_host(
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
    "use_rain");
  this->m_use_rain_parameter = vostok::render::backend::register_constant_host(
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
    "to_sun_direction");
  this->m_to_sun_direction = vostok::render::backend::register_constant_host(
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
    "m_shadow0");
  this->m_shadow[0] = vostok::render::backend::register_constant_host(
                        v14,
                        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                        (const vostok::shared_string *)&in_renderer,
                        0);
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
    "m_shadow1");
  this->m_shadow[1] = vostok::render::backend::register_constant_host(
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
    "m_shadow2");
  this->m_shadow[2] = vostok::render::backend::register_constant_host(
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
    "m_shadow3");
  this->m_shadow[3] = vostok::render::backend::register_constant_host(
                        v20,
                        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                        (const vostok::shared_string *)&in_renderer,
                        0);
  if ( in_renderer && !_InterlockedExchangeAdd((volatile signed __int32 *)in_renderer, 0xFFFFFFFF) )
    vostok::strings::shared::detail::intrusive_base::destroy(
      0,
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)in_renderer);
  this->m_enabled = 1;
}
