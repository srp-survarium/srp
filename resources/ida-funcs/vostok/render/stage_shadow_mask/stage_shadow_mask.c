void __thiscall vostok::render::stage_shadow_mask::stage_shadow_mask(
        vostok::render::renderer_context *context,
        vostok::render::stage_shadow_mask *this,
        vostok::render::renderer *in_renderer)
{
  vostok::render::stage_shadow_mask *v3; // ebx
  vostok::render::sphere_geometry *v4; // ecx
  vostok::render::effect_manager *v5; // ecx
  vostok::render::effect_manager *v6; // ecx
  vostok::render::effect_manager *v7; // ecx
  vostok::render::effect_manager *v8; // ecx
  vostok::render::effect_manager *v9; // ecx
  vostok::render::effect_manager *v10; // ecx
  vostok::render::effect_manager *v11; // ecx
  vostok::render::effect_manager *v12; // ecx
  vostok::render::effect_manager *v13; // ecx
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
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v28; // eax
  vostok::render::resource_manager *v29; // ecx
  vostok::render::res_geometry *v30; // eax
  _WORD data[38]; // [esp+10h] [ebp-68h] BYREF
  D3D11_INPUT_ELEMENT_DESC decl_size; // [esp+5Ch] [ebp-1Ch] BYREF

  v3 = this;
  vostok::render::stage::stage(this, context, in_renderer);
  v3->__vftable = (vostok::render::stage_shadow_mask_vtbl *)&vostok::render::stage_shadow_mask::`vftable';
  vostok::render::sphere_geometry::sphere_geometry(
    v4,
    &v3->m_sphere_geometry.m_vertext_declaration.m_object,
    COERCE_FLOAT(16),
    COERCE_FLOAT(16));
  v3->m_obb_index_buffer.m_object = 0;
  v3->m_obb_geometry.m_object = 0;
  v3->m_shadow_mask_effect.m_object = 0;
  memset(v3->m_sun_shadow_apply_effect, 0, sizeof(v3->m_sun_shadow_apply_effect));
  v3->m_far_plane_mask_effect.m_object = 0;
  vostok::render::effect_manager::create_effect<vostok::render::effect_shadow_mask>(
    0,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_shadow_mask_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_sun_shadows_apply<0,0>>(
    v5,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v3->m_sun_shadow_apply_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_sun_shadows_apply<0,1>>(
    v6,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_sun_shadow_apply_effect[0][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_sun_shadows_apply<0,2>>(
    v7,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_sun_shadow_apply_effect[0][2]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_sun_shadows_apply<0,3>>(
    v8,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_sun_shadow_apply_effect[0][3]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_sun_shadows_apply<1,0>>(
    v9,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v3->m_sun_shadow_apply_effect[1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_sun_shadows_apply<1,1>>(
    v10,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_sun_shadow_apply_effect[1][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_sun_shadows_apply<1,2>>(
    v11,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_sun_shadow_apply_effect[1][2]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_sun_shadows_apply<1,3>>(
    v12,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_sun_shadow_apply_effect[1][3]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_mask_far_plane>(
    v13,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v3->m_far_plane_mask_effect);
  vostok::shared_string::shared_string(
    v14,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "test_output_color");
  v3->m_test_output_color_parameter = vostok::render::backend::register_constant_host(
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
    "view_to_shadow");
  v3->m_view_to_shadow_parameter = vostok::render::backend::register_constant_host(
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
    "eye_ray_corner");
  v3->m_c_eye_ray_corner = vostok::render::backend::register_constant_host(
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
    "sky_shadow_parameters");
  v3->m_c_sky_shadow_parameters = vostok::render::backend::register_constant_host(
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
    "sun_fixed_matrix");
  v3->m_c_sun_fixed_matrix = vostok::render::backend::register_constant_host(
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
    "cascade_index");
  v3->m_c_cascade_index = vostok::render::backend::register_constant_host(
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
    "sun_direction_parameter");
  v3->m_c_sun_direction_parameter = vostok::render::backend::register_constant_host(
                                      v27,
                                      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                      (const vostok::shared_string *)&this,
                                      0);
  if ( this && !_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF) )
    vostok::strings::shared::detail::intrusive_base::destroy(
      0,
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  data[0] = 0;
  data[1] = 1;
  data[2] = 2;
  data[3] = 3;
  data[4] = 1;
  data[5] = 0;
  data[6] = 4;
  data[7] = 3;
  data[8] = 0;
  data[9] = 5;
  data[10] = 3;
  data[11] = 4;
  data[12] = 6;
  data[13] = 5;
  data[14] = 4;
  data[15] = 7;
  data[16] = 5;
  data[17] = 6;
  data[18] = 2;
  data[19] = 7;
  data[20] = 6;
  data[21] = 1;
  data[22] = 7;
  data[23] = 2;
  data[24] = 3;
  data[25] = 7;
  decl_size.SemanticName = "POSITION";
  decl_size.SemanticIndex = 0;
  decl_size.Format = DXGI_FORMAT_R32G32B32_FLOAT;
  memset(&decl_size.InputSlot, 0, 16);
  data[26] = 1;
  data[27] = 5;
  data[28] = 7;
  data[32] = 6;
  data[29] = 3;
  data[33] = 0;
  data[34] = 2;
  data[35] = 4;
  data[30] = 4;
  data[31] = 2;
  vostok::render::resource_manager::create_buffer(
    0x48u,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)2,
    (vostok::render::enum_buffer_type)data,
    1,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v28,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&v3->m_obb_index_buffer,
    (vostok::render::hw_buffer_pool *)1);
  v30 = vostok::render::resource_manager::create_geometry(
          v29,
          (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          &decl_size,
          1u,
          (vostok::render::untyped_buffer *)0xC,
          *(vostok::render::untyped_buffer **)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                             + 44),
          (int)v3->m_obb_index_buffer.m_object);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &v3->m_obb_geometry,
    v30);
  v3->m_enabled = 1;
}
