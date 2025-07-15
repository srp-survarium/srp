void __thiscall vostok::render::stage_atmosphere::stage_atmosphere(
        vostok::render::renderer_context *context,
        vostok::render::stage_atmosphere *this,
        vostok::render::renderer *in_renderer,
        vostok::render::stage_atmosphere::stage_type type)
{
  vostok::render::stage_atmosphere *v4; // ebx
  vostok::render::sky_dome_geometry *v5; // ecx
  vostok::render::sphere_geometry *v6; // ecx
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v7; // esi
  vostok::render::stage_atmosphere::stage_type v8; // eax
  vostok::render::effect_manager *v9; // ecx
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
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v30; // eax
  vostok::render::resource_manager *v31; // ecx
  vostok::render::res_geometry *v32; // eax
  vostok::render::hw_buffer_pool *v33; // ecx
  int **m_vertices_pool; // eax
  int **m_indices_pool; // eax
  D3D11_INPUT_ELEMENT_DESC decl_size; // [esp+Ch] [ebp-48h] BYREF
  const char *v37; // [esp+28h] [ebp-2Ch]
  int v38; // [esp+2Ch] [ebp-28h]
  int v39; // [esp+30h] [ebp-24h]
  int v40; // [esp+34h] [ebp-20h]
  int v41; // [esp+38h] [ebp-1Ch]
  int v42; // [esp+3Ch] [ebp-18h]
  int v43; // [esp+40h] [ebp-14h]
  _WORD data[8]; // [esp+44h] [ebp-10h] BYREF

  v4 = this;
  vostok::render::stage::stage(this, context, in_renderer);
  v4->__vftable = (vostok::render::stage_atmosphere_vtbl *)&vostok::render::stage_atmosphere::`vftable';
  vostok::render::sky_dome_geometry::sky_dome_geometry(v5, (int)&v4->m_sky_dome_geometry);
  vostok::render::sphere_geometry::sphere_geometry(
    v6,
    &v4->m_clouds_geometry.m_vertext_declaration.m_object,
    COERCE_FLOAT(16),
    COERCE_FLOAT(16));
  v7 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
  v4->m_atmospheric_scattering_effect[0].m_object = 0;
  v4->m_atmospheric_scattering_effect[1].m_object = 0;
  v8 = type;
  v4->m_screen_vertex_ib.m_object = 0;
  v4->m_screen_vertex_geometry.m_object = 0;
  v4->m_type = v8;
  vostok::render::effect_manager::create_effect<vostok::render::effect_atmospheric_scattering<0>>(
    (vostok::render::effect_manager *)v4->m_atmospheric_scattering_effect,
    v7,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v4->m_atmospheric_scattering_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_atmospheric_scattering<1>>(
    v9,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v4->m_atmospheric_scattering_effect[1]);
  vostok::shared_string::shared_string(
    v10,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "to_sun_direction_parameter");
  v4->m_to_sun_direction_parameter = vostok::render::backend::register_constant_host(
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
    "inverted_view_projection_matrix");
  v4->m_c_inverted_view_projection_matrix = vostok::render::backend::register_constant_host(
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
    "atmosphere_parameters");
  v4->m_c_atmosphere_parameters = vostok::render::backend::register_constant_host(
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
    "inscatter_parameters");
  v4->m_c_inscatter_parameters = vostok::render::backend::register_constant_host(
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
    "s_eye_ray_corner");
  v4->m_c_eye_ray_corner = vostok::render::backend::register_constant_host(
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
    "sky_clouds_parameters0");
  v4->m_sky_clouds_parameters0 = vostok::render::backend::register_constant_host(
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
    "sky_clouds_parameters1");
  v4->m_sky_clouds_parameters1 = vostok::render::backend::register_constant_host(
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
    "sky_clouds_parameters2");
  v4->m_sky_clouds_parameters2 = vostok::render::backend::register_constant_host(
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
    "sky_clouds_parameters3");
  v4->m_sky_clouds_parameters3 = vostok::render::backend::register_constant_host(
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
    "sun_moon_parameters");
  v4->m_sun_moon_parameters = vostok::render::backend::register_constant_host(
                                v29,
                                SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                (const vostok::shared_string *)&this,
                                0);
  if ( this && !_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF) )
    vostok::strings::shared::detail::intrusive_base::destroy(
      0,
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  v39 = 16;
  v41 = 16;
  data[0] = 0;
  data[1] = 1;
  data[2] = 2;
  data[3] = 3;
  data[4] = 2;
  data[5] = 1;
  decl_size.SemanticIndex = 0;
  memset(&decl_size.InputSlot, 0, 16);
  v38 = 0;
  v40 = 0;
  v42 = 0;
  v43 = 0;
  decl_size.SemanticName = "POSITION";
  decl_size.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
  v37 = "TEXCOORD";
  vostok::render::resource_manager::create_buffer(
    0xCu,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)2,
    (vostok::render::enum_buffer_type)data,
    1,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v30,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&v4->m_screen_vertex_ib,
    (vostok::render::hw_buffer_pool *)2);
  v32 = vostok::render::resource_manager::create_geometry(
          v31,
          (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          &decl_size,
          2u,
          (vostok::render::untyped_buffer *)0x18,
          *(vostok::render::untyped_buffer **)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (int)v4->m_screen_vertex_ib.m_object);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &v4->m_screen_vertex_geometry,
    v32);
  m_vertices_pool = (int **)vostok::quasi_singleton<vostok::render::resource_manager>::pinst->m_vertices_pool;
  if ( m_vertices_pool )
    vostok::render::hw_buffer_pool::sync(v33, m_vertices_pool);
  m_indices_pool = (int **)vostok::quasi_singleton<vostok::render::resource_manager>::pinst->m_indices_pool;
  if ( m_indices_pool )
    vostok::render::hw_buffer_pool::sync(v33, m_indices_pool);
}
