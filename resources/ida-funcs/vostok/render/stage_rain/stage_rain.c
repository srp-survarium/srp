void __thiscall vostok::render::stage_rain::stage_rain(
        vostok::render::renderer_context *context,
        vostok::render::stage_rain *this,
        vostok::render::renderer *in_renderer)
{
  vostok::render::sphere_geometry *v3; // ecx
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
  vostok::render::resource_manager *v14; // eax
  const char *v15; // edi
  const char *v16; // esi
  int v17; // ecx
  bool v18; // cf
  bool v19; // zf
  int v20; // edx
  unsigned int v21; // edi
  vostok::render::res_texture *texture; // eax
  vostok::render::effect_manager *v23; // ecx
  vostok::render::effect_manager *v24; // ecx
  vostok::memory::doug_lea_allocator *v25; // esi
  char *v26; // eax
  vostok::memory::doug_lea_allocator *v27; // ecx
  char *v28; // eax
  vostok::math::float2 *v29; // eax
  vostok::math::float2 *v30; // esi
  float v31; // xmm0_4
  float *m_rain_rotation_y; // esi
  double v33; // st7
  double v34; // st7
  vostok::math::float2 *m_rain_offsets; // eax
  const char *v36; // [esp+4h] [ebp-18h]
  const char *v37; // [esp+8h] [ebp-14h]
  unsigned int v38; // [esp+Ch] [ebp-10h]
  vostok::shared_string name; // [esp+10h] [ebp-Ch] BYREF
  vostok::render::resource_manager *v40; // [esp+14h] [ebp-8h]
  float v41; // [esp+18h] [ebp-4h]

  vostok::render::stage::stage(this, context, in_renderer);
  this->__vftable = (vostok::render::stage_rain_vtbl *)&vostok::render::stage_rain::`vftable';
  this->m_t_rain_shadow_map.m_object = 0;
  this->m_rain_effect.m_object = 0;
  this->m_effect_shadow_direct.m_object = 0;
  vostok::render::sphere_geometry::sphere_geometry(
    v3,
    &this->m_rain_geometry.m_vertext_declaration.m_object,
    COERCE_FLOAT(24),
    COERCE_FLOAT(3));
  this->m_camera_offset_view = 0.0;
  this->m_camera_offset_right = 0.0;
  *(_QWORD *)&this->m_previous_view_position.x = 0;
  this->m_previous_view_position.z = 0.0;
  vostok::shared_string::shared_string(v4, &name.m_pointer, "rain_radius");
  this->m_radius_parameter = vostok::render::backend::register_constant_host(
                               v5,
                               SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                               &name,
                               0);
  if ( name.m_pointer.m_object )
  {
    v6 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v6 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v6, &name.m_pointer, "rain_speed");
  this->m_rain_speed_parameter = vostok::render::backend::register_constant_host(
                                   v7,
                                   SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                   &name,
                                   0);
  if ( name.m_pointer.m_object )
  {
    v8 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v8 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v8, &name.m_pointer, "view_to_shadow");
  this->m_view_to_shadow_parameter = vostok::render::backend::register_constant_host(
                                       v9,
                                       SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                       &name,
                                       0);
  if ( name.m_pointer.m_object )
  {
    v10 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v10 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v10, &name.m_pointer, "rain_density");
  this->m_rain_density_parameter = vostok::render::backend::register_constant_host(
                                     v11,
                                     SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                     &name,
                                     0);
  if ( name.m_pointer.m_object )
  {
    v12 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v12 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v12, &name.m_pointer, "rain_uv_scales");
  this->m_rain_uv_scales_parameter = vostok::render::backend::register_constant_host(
                                       v13,
                                       SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                       &name,
                                       0);
  if ( name.m_pointer.m_object && !_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::strings::shared::detail::intrusive_base::destroy(
      0,
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  v14 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v15 = "null";
  v16 = "$user$rain_shadow_map";
  v17 = 22;
  v20 = 0;
  v18 = 0;
  v19 = 1;
  this->m_shadow_map_size = 128;
  do
  {
    if ( !v17 )
      break;
    v18 = *v16 < (unsigned int)*v15;
    v19 = *v16++ == *v15++;
    --v17;
  }
  while ( v19 );
  v40 = v14;
  if ( !v19 )
    v20 = -v18 - (v18 - 1);
  v21 = 0;
  if ( v20 )
  {
    texture = (vostok::render::res_texture *)vostok::render::resource_manager::find_texture(
                                               (vostok::render::resource_manager *)v17,
                                               (int)v14,
                                               "$user$rain_shadow_map");
    if ( !texture )
      texture = vostok::render::resource_manager::load_texture(
                  v40,
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
  vostok::render::effect_manager::create_effect<vostok::render::effect_rain>(
    v23,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_rain_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_shadow_map>(
    v24,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_effect_shadow_direct);
  v25 = vostok::render::g_allocator;
  v26 = type_info::raw_name(&vostok::math::float2 `RTTI Type Descriptor');
  v28 = vostok::memory::doug_lea_allocator::malloc_impl(v27, (int)v25, 0x328u, v26, v36, v37, v38);
  *(_DWORD *)v28 = 100;
  v28 += 4;
  *(_DWORD *)v28 = 8;
  v29 = (vostok::math::float2 *)(v28 + 4);
  v30 = v29;
  v31 = SNaN;
  do
  {
    if ( v30 )
    {
      v30->x = v31;
      v30->y = v31;
    }
    ++v30;
  }
  while ( v30 != &v29[100] );
  this->m_rain_offsets = v29;
  name.m_pointer.m_object = (vostok::strings::shared::profile *)1000;
  m_rain_rotation_y = this->m_rain_rotation_y;
  do
  {
    v33 = vostok::math::random32::random_f((vostok::math::random32 *)&name, 1.0);
    *(float *)&v40 = v33 + v33 - 1.0;
    v34 = vostok::math::random32::random_f((vostok::math::random32 *)&name, 1.0);
    m_rain_offsets = this->m_rain_offsets;
    m_rain_offsets[v21++].x = *(float *)&v40;
    v41 = v34 + v34 - s_bm_current_air_resistance;
    m_rain_offsets[v21 - 1].y = v41;
    *(m_rain_rotation_y - 100) = 0.0;
    *m_rain_rotation_y++ = 0.0;
  }
  while ( v21 < 100 );
}
