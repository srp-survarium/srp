void __thiscall vostok::render::stage_pre_rain::stage_pre_rain(
        vostok::render::renderer_context *context,
        vostok::render::stage_pre_rain *this,
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
  vostok::render::resource_manager *v11; // ecx
  stlp_std::priv::_Rb_tree_node_base *render_target; // eax
  const char *v13; // edi
  const char *v14; // esi
  int v15; // ecx
  bool v16; // cf
  bool v17; // zf
  int v18; // edx
  vostok::render::res_texture *texture; // eax
  vostok::render::effect_manager *v20; // ecx
  vostok::render::effect_manager *v21; // ecx
  unsigned int v22; // [esp+0h] [ebp-10h]
  vostok::shared_string name; // [esp+Ch] [ebp-4h] BYREF

  vostok::render::stage::stage(this, context, in_renderer);
  this->__vftable = (vostok::render::stage_pre_rain_vtbl *)&vostok::render::stage_pre_rain::`vftable';
  this->m_rt_rain_shadow_map.m_object = 0;
  this->m_t_rain_shadow_map.m_object = 0;
  this->m_wet_surface_effect.m_object = 0;
  this->m_effect_shadow_direct.m_object = 0;
  this->m_rain_offset = 0.0;
  this->m_rain_offset_counter = 0.0;
  vostok::shared_string::shared_string(v3, &name.m_pointer, "view_to_shadow");
  this->m_view_to_shadow_parameter = vostok::render::backend::register_constant_host(
                                       v4,
                                       SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                       &name,
                                       0);
  if ( name.m_pointer.m_object )
  {
    v5 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v5 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v5, &name.m_pointer, "s_eye_ray_corner");
  this->m_eye_ray_corner_parameter = vostok::render::backend::register_constant_host(
                                       v6,
                                       SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                       &name,
                                       0);
  if ( name.m_pointer.m_object )
  {
    v7 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v7 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v7, &name.m_pointer, "rain_offset");
  this->m_rain_offset_parameter = vostok::render::backend::register_constant_host(
                                    v8,
                                    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                    &name,
                                    0);
  if ( name.m_pointer.m_object )
  {
    v9 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v9 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v9, &name.m_pointer, "rain_density");
  this->m_rain_density_parameter = vostok::render::backend::register_constant_host(
                                     v10,
                                     SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                     &name,
                                     0);
  if ( name.m_pointer.m_object )
  {
    v11 = (vostok::render::resource_manager *)_InterlockedExchangeAdd(
                                                &name.m_pointer.m_object->m_reference_count,
                                                0xFFFFFFFF);
    if ( !v11 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  this->m_shadow_map_size = 128;
  render_target = vostok::render::resource_manager::create_render_target(
                    v11,
                    (const char **)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                    "$user$rain_shadow_map",
                    this->m_shadow_map_size,
                    this->m_shadow_map_size,
                    (char *)0x35,
                    DXGI_FORMAT_UNKNOWN,
                    0,
                    0,
                    0,
                    v22);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &this->m_rt_rain_shadow_map,
    (vostok::render::render_target *)render_target);
  v13 = "null";
  v14 = "$user$rain_shadow_map";
  v15 = 22;
  v18 = 0;
  v16 = 0;
  v17 = 1;
  do
  {
    if ( !v15 )
      break;
    v16 = *v14 < (unsigned int)*v13;
    v17 = *v14++ == *v13++;
    --v15;
  }
  while ( v17 );
  name.m_pointer.m_object = (vostok::strings::shared::profile *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  if ( !v17 )
    v18 = -v16 - (v16 - 1);
  if ( v18 )
  {
    texture = (vostok::render::res_texture *)vostok::render::resource_manager::find_texture(
                                               (vostok::render::resource_manager *)v15,
                                               (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                               "$user$rain_shadow_map");
    if ( !texture )
      texture = vostok::render::resource_manager::load_texture(
                  (vostok::render::resource_manager *)name.m_pointer.m_object,
                  "$user$rain_shadow_map",
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
    (vostok::render::res_texture *)&this->m_t_rain_shadow_map);
  vostok::render::effect_manager::create_effect<vostok::render::effect_wet_surface>(
    v20,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_wet_surface_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_shadow_map>(
    v21,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_effect_shadow_direct);
}
