void __thiscall vostok::render::renderer::renderer(
        vostok::render::renderer *this,
        vostok::render::renderer_context *renderer_context,
        vostok::render::engine::world *engine_world)
{
  vostok::timing::timer *v4; // ecx
  vostok::render::options *v5; // eax
  vostok::threading::mutex_tasks_unaware *v6; // ecx
  vostok::render::statistics *v7; // ecx
  vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC,32> *v8; // ecx
  vostok::math::float4x4 *v9; // ecx
  vostok::render::effect_manager *v10; // ecx
  vostok::render::effect_manager *v11; // ecx
  vostok::render::effect_manager *v12; // ecx
  vostok::render::effect_manager *v13; // ecx
  vostok::render::effect_manager *v14; // ecx
  vostok::render::effect_manager *v15; // ecx
  vostok::render::effect_manager *v16; // ecx
  vostok::render::effect_manager *v17; // ecx
  vostok::render::effect_manager *v18; // ecx
  vostok::shared_string *v19; // ecx
  vostok::render::backend *v20; // ecx
  vostok::render::shader_constant_host *v21; // eax
  vostok::shared_string *v22; // ecx
  bool v23; // zf
  vostok::render::backend *v24; // ecx
  vostok::shared_string *v25; // ecx
  vostok::render::backend *v26; // ecx
  vostok::shared_string *v27; // ecx
  vostok::render::backend *v28; // ecx
  vostok::shared_string *v29; // ecx
  vostok::render::backend *v30; // ecx
  vostok::shared_string *v31; // ecx
  vostok::render::backend *v32; // ecx
  vostok::shared_string name; // [esp+Ch] [ebp-54h] BYREF
  int v34; // [esp+10h] [ebp-50h]
  vostok::render::render_target *v35; // [esp+14h] [ebp-4Ch]
  vostok::render::res_texture *v36; // [esp+18h] [ebp-48h]
  char *v37; // [esp+1Ch] [ebp-44h]
  vostok::math::float4x4 v38; // [esp+20h] [ebp-40h] BYREF

  *(_DWORD *)&renderer_context->m_family[0].orig_name.m_buffer[12] = 0;
  *(float *)&renderer_context->m_family[0].texture.m_object = FLOAT_0_029999999;
  *(float *)&renderer_context->m_family[1].orig_name.m_begin = FLOAT_40_0;
  *(float *)&renderer_context->m_family[1].orig_name.m_end = FLOAT_0_12;
  renderer_context->m_family[0].orig_name.m_buffer[8] = 0;
  renderer_context->m_family[0].orig_name.m_buffer[9] = 0;
  *(_DWORD *)&renderer_context->m_family[1].orig_name.m_buffer[12] = 0;
  vostok::timing::timer::timer(
    (vostok::timing::timer *)this,
    (LARGE_INTEGER *)&renderer_context->m_family[1].orig_name.m_buffer[16]);
  *(_DWORD *)&renderer_context->m_family[1].orig_name.m_buffer[56] = 0;
  *(_DWORD *)&renderer_context->m_family[1].orig_name.m_buffer[60] = 0;
  renderer_context->m_family[1].name.m_begin = 0;
  renderer_context->m_family[1].name.m_end = 0;
  renderer_context->m_family[1].name.m_max_end = 0;
  *(_DWORD *)renderer_context->m_family[1].name.m_buffer = 0;
  *(_DWORD *)&renderer_context->m_family[1].name.m_buffer[4] = 0;
  *(_DWORD *)&renderer_context->m_family[1].name.m_buffer[8] = 0;
  *(_DWORD *)&renderer_context->m_family[1].name.m_buffer[12] = 0;
  *(_DWORD *)&renderer_context->m_family[1].name.m_buffer[16] = 0;
  *(_DWORD *)&renderer_context->m_family[1].name.m_buffer[20] = 0;
  *(_DWORD *)&renderer_context->m_family[1].name.m_buffer[24] = 0;
  *(_DWORD *)&renderer_context->m_family[2].orig_name.m_buffer[8] = &renderer_context->m_family[2].orig_name.m_buffer[20];
  *(_DWORD *)&renderer_context->m_family[2].orig_name.m_buffer[12] = &renderer_context->m_family[2].orig_name.m_buffer[20];
  *(_DWORD *)&renderer_context->m_family[2].orig_name.m_buffer[16] = &renderer_context->m_family[2].name.m_buffer[56];
  *(_DWORD *)&renderer_context->m_family[2].name.m_buffer[56] = 0;
  *(_DWORD *)&renderer_context->m_family[2].name.m_buffer[60] = 0;
  renderer_context->m_family[2].texture.m_object = (vostok::render::res_texture *)&s_system_renderer_buffer.m_family[2].name;
  renderer_context->m_family[3].orig_name.m_begin = (char *)engine_world;
  vostok::timing::timer::timer(
    (vostok::timing::timer *)&renderer_context->m_family[2].name.m_buffer[56],
    (LARGE_INTEGER *)&renderer_context->m_family[3].orig_name.m_buffer[8]);
  vostok::timing::timer::timer(v4, (LARGE_INTEGER *)&renderer_context->m_family[3].orig_name.m_buffer[32]);
  v5 = vostok::quasi_singleton<vostok::render::options>::pinst;
  *(_DWORD *)&renderer_context->m_family[3].orig_name.m_buffer[56] = 0;
  *(_DWORD *)&renderer_context->m_family[3].name.m_buffer[20] = 0;
  *(_DWORD *)&renderer_context->m_family[3].name.m_buffer[24] = 0;
  *(_DWORD *)&renderer_context->m_family[3].name.m_buffer[28] = 0;
  *(_DWORD *)&renderer_context->m_family[3].name.m_buffer[32] = 0;
  *(_DWORD *)&renderer_context->m_family[3].name.m_buffer[36] = 0;
  *(_DWORD *)&renderer_context->m_family[3].name.m_buffer[40] = 0;
  *(_DWORD *)&renderer_context->m_family[3].name.m_buffer[44] = 0;
  *(_DWORD *)&renderer_context->m_family[3].name.m_buffer[48] = 0;
  *(_DWORD *)&renderer_context->m_family[3].name.m_buffer[52] = 0;
  *(_DWORD *)&renderer_context->m_family[3].name.m_buffer[56] = 0;
  *(_DWORD *)&renderer_context->m_family[3].name.m_buffer[60] = 0;
  renderer_context->m_family[3].target.m_object = 0;
  renderer_context->m_family[3].texture.m_object = 0;
  vostok::render::cloud_simulation::cloud_simulation(
    v5->current.m_clouds_grid_width,
    v5->current.m_clouds_grid_height,
    (vostok::render::cloud_simulation *)&renderer_context->m_family[4],
    v5->current.m_clouds_grid_width);
  *(_DWORD *)&renderer_context->m_family[4].name.m_buffer[12] = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    v6,
    (_RTL_CRITICAL_SECTION *)&renderer_context->m_family[4].name.m_buffer[20]);
  *(_DWORD *)&renderer_context->m_family[4].name.m_buffer[48] = 0;
  *(_DWORD *)&renderer_context->m_family[4].name.m_buffer[52] = 0;
  LOBYTE(renderer_context->m_family[5].orig_name.m_end) = 0;
  vostok::render::statistics::statistics(v7, (vostok::render::statistics *)s_statistics_buffer);
  vostok::render::register_samplers(v8);
  v35 = 0;
  v36 = 0;
  v37 = 0;
  qmemcpy(&renderer_context->m_family[0].orig_name.m_buffer[16], vostok::math::float4x4::identity(v9, &v38), 0x40u);
  *(_DWORD *)&renderer_context->m_family[1].name.m_buffer[28] = 0;
  *(_DWORD *)&renderer_context->m_family[1].name.m_buffer[32] = v35;
  *(_DWORD *)&renderer_context->m_family[1].name.m_buffer[36] = v36;
  *(_DWORD *)&renderer_context->m_family[1].name.m_buffer[40] = v37;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  *(_DWORD *)&renderer_context->m_family[1].name.m_buffer[44] = 0;
  *(_DWORD *)&renderer_context->m_family[1].name.m_buffer[48] = v35;
  *(_DWORD *)&renderer_context->m_family[1].name.m_buffer[52] = v36;
  *(_DWORD *)&renderer_context->m_family[1].name.m_buffer[56] = v37;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  *(_DWORD *)&renderer_context->m_family[1].name.m_buffer[60] = 0;
  renderer_context->m_family[1].target.m_object = v35;
  renderer_context->m_family[1].texture.m_object = v36;
  renderer_context->m_family[2].orig_name.m_begin = v37;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  renderer_context->m_family[2].orig_name.m_end = 0;
  renderer_context->m_family[2].orig_name.m_max_end = (char *)v35;
  *(_DWORD *)renderer_context->m_family[2].orig_name.m_buffer = v36;
  *(_DWORD *)&renderer_context->m_family[2].orig_name.m_buffer[4] = v37;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  *(_DWORD *)&renderer_context->m_family[4].name.m_buffer[60] = 0;
  renderer_context->m_family[4].target.m_object = v35;
  renderer_context->m_family[4].texture.m_object = v36;
  renderer_context->m_family[0].orig_name.m_buffer[10] = 0;
  renderer_context->m_family[5].orig_name.m_begin = v37;
  vostok::render::material::initialize_nomaterial_material();
  vostok::render::effect_manager::create_effect<vostok::render::effect_pick_light_luminance>(
    v10,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&renderer_context->m_family[3].name.m_buffer[36]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_editor_view_mode>(
    v11,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&renderer_context->m_family[3].name.m_buffer[20]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_fill_environment_probe_face>(
    v12,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&renderer_context->m_family[3].name.m_buffer[24]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_fill_sky_ao_map>(
    v13,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&renderer_context->m_family[3].name.m_buffer[32]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_grass_trample>(
    v14,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&renderer_context->m_family[3].name.m_buffer[44]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_downsample>(
    v15,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&renderer_context->m_family[3].name.m_buffer[52]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_copy>(
    v16,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&renderer_context->m_family[3].name.m_buffer[56]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_editor_show_overdraw>(
    v17,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&renderer_context->m_family[3].name.m_buffer[60]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_editor_show_cascaded_shadow_map_depth>(
    v18,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&renderer_context->m_family[3].name.m_buffer[48]);
  vostok::shared_string::shared_string(v19, &name.m_pointer, "pick_lighting_luminance_position");
  v21 = vostok::render::backend::register_constant_host(
          v20,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          &name,
          0);
  v23 = name.m_pointer.m_object == 0;
  *(_DWORD *)&renderer_context->m_family[3].name.m_buffer[16] = v21;
  if ( !v23 )
  {
    v22 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v22 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v22, &name.m_pointer, "view_mode_type");
  *(_DWORD *)&renderer_context->m_family[3].orig_name.m_buffer[60] = vostok::render::backend::register_constant_host(
                                                                       v24,
                                                                       SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                                                       &name,
                                                                       (vostok::strings::shared::profile *)1);
  if ( name.m_pointer.m_object )
  {
    v25 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v25 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v25, &name.m_pointer, "eye_ray_corner");
  renderer_context->m_family[3].name.m_begin = (char *)vostok::render::backend::register_constant_host(
                                                         v26,
                                                         SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                                         &name,
                                                         0);
  if ( name.m_pointer.m_object )
  {
    v27 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v27 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v27, &name.m_pointer, "probe_position");
  renderer_context->m_family[3].name.m_end = (char *)vostok::render::backend::register_constant_host(
                                                       v28,
                                                       SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                                       &name,
                                                       0);
  if ( name.m_pointer.m_object )
  {
    v29 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v29 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v29, &name.m_pointer, "probe_inverted_view_matrix");
  renderer_context->m_family[3].name.m_max_end = (char *)vostok::render::backend::register_constant_host(
                                                           v30,
                                                           SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                                           &name,
                                                           0);
  if ( name.m_pointer.m_object )
  {
    v31 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v31 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v31, &name.m_pointer, "downsample_parameters");
  vostok::render::backend::register_constant_host(
    v32,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    &name,
    0);
  JUMPOUT(0xE815D);
}
