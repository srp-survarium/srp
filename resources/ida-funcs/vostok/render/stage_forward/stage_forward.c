void __userpurge vostok::render::stage_forward::stage_forward(
        vostok::render::renderer_context *context@<ecx>,
        vostok::render::stage_forward *this,
        vostok::render::renderer *in_renderer,
        vostok::render::surface_effect_parameters type)
{
  vostok::render::stage_forward *v4; // ebx
  vostok::render::backend *v5; // ecx
  vostok::shared_string *v6; // ecx
  vostok::render::backend *v7; // ecx
  vostok::shared_string *v8; // ecx
  vostok::render::backend *v9; // ecx
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
  vostok::render::effect_manager *v30; // ecx
  vostok::render::effect_manager *v31; // ecx
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v32; // edi
  vostok::render::effect_descriptor *v33; // eax
  vostok::render::effect_manager *v34; // ecx
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v35; // edi
  vostok::render::effect_descriptor *v36; // eax
  __int64 v37; // [esp-14h] [ebp-40h]
  vostok::render::effect_manager *v38; // [esp-4h] [ebp-30h]
  vostok::render::effect_manager *v39; // [esp-4h] [ebp-30h]
  vostok::render::surface_effect_parameters v40; // [esp+10h] [ebp-1Ch] BYREF
  vostok::render::effect_descriptor v41; // [esp+20h] [ebp-Ch] BYREF
  vostok::render::effect_descriptor descriptor; // [esp+24h] [ebp-8h] BYREF

  v4 = this;
  vostok::render::stage::stage(this, context, in_renderer);
  v4->__vftable = (vostok::render::stage_forward_vtbl *)&vostok::render::stage_forward::`vftable';
  v4->m_debug_tracer_effect.m_object = 0;
  v4->m_opaque_geometry_mask_effect.m_object = 0;
  memset(v4->m_gbuffer_depth_effect, 0, sizeof(v4->m_gbuffer_depth_effect));
  v4->m_type = type.vertex_input_type;
  vostok::shared_string::shared_string(
    0,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "tree_position_and_scale");
  v4->m_tree_position_and_scale_parameter = vostok::render::backend::register_constant_host(
                                              v5,
                                              SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                              (const vostok::shared_string *)&this,
                                              0);
  if ( this )
  {
    v6 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v6 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v6,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "tree_rotation");
  v4->m_tree_rotation_parameter = vostok::render::backend::register_constant_host(
                                    v7,
                                    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                    (const vostok::shared_string *)&this,
                                    0);
  if ( this )
  {
    v8 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v8 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v8,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "s_eye_ray_corner");
  v4->m_eye_ray_corner_parameter = vostok::render::backend::register_constant_host(
                                     v9,
                                     SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                     (const vostok::shared_string *)&this,
                                     0);
  if ( this )
  {
    v10 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v10 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::shared_string::shared_string(
    v10,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "view_to_shadow");
  v4->m_view_to_shadow_parameter = vostok::render::backend::register_constant_host(
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
    "rain_offset");
  v4->m_rain_offset_parameter = vostok::render::backend::register_constant_host(
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
    "use_rain");
  v4->m_use_rain_parameter = vostok::render::backend::register_constant_host(
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
    "tracer_debug_color");
  v4->m_tracer_debug_color_parameter = vostok::render::backend::register_constant_host(
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
    "inscatter_parameters");
  v4->m_c_inscatter_parameters = vostok::render::backend::register_constant_host(
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
    "to_sun_direction");
  v4->m_to_sun_direction = vostok::render::backend::register_constant_host(
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
    "m_shadow0");
  v4->m_shadow[0] = vostok::render::backend::register_constant_host(
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
    "m_shadow1");
  v4->m_shadow[1] = vostok::render::backend::register_constant_host(
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
    "m_shadow2");
  v4->m_shadow[2] = vostok::render::backend::register_constant_host(
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
    "m_shadow3");
  v4->m_shadow[3] = vostok::render::backend::register_constant_host(
                      v29,
                      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                      (const vostok::shared_string *)&this,
                      0);
  if ( this )
  {
    v30 = (vostok::render::effect_manager *)_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( !v30 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this);
  }
  vostok::render::effect_manager::create_effect<vostok::render::effect_decal_mask>(
    v30,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v4->m_opaque_geometry_mask_effect);
  v40.cull_mode = -1;
  v40.draw_to_gbuffer = -1;
  v32 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
  v40.vertex_input_type = 1;
  v40.blend_mode = 1;
  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_debug_tracer>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_debug_tracer>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_debug_tracer>'::`2'::descriptor_object.m_object = (vostok::configs::binary_config *)&vostok::render::effect_debug_tracer::`vftable';
    atexit((int (__cdecl *)())`vostok::render::effect_manager::create_effect<vostok::render::effect_debug_tracer>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
    v31 = v38;
  }
  this = 0;
  if ( LOBYTE(v32->m_object) )
  {
    v33 = vostok::render::effect_manager::create_new_effect(
            v31,
            v32,
            &descriptor,
            (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_debug_tracer>'::`2'::descriptor_object,
            (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
            &v40);
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v33,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v4->m_debug_tracer_effect);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&descriptor);
  }
  else
  {
    HIDWORD(v37) = &v4->m_debug_tracer_effect;
    LODWORD(v37) = v32;
    vostok::render::effect_manager::create_new_effect(
      v31,
      v37,
      (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_debug_tracer>'::`2'::descriptor_object,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
      &v40);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
  this = 0;
  v4->m_rain_offset = 0.0;
  v4->m_rain_offset_counter = 0.0;
  in_renderer = (vostok::render::renderer *)v4->m_gbuffer_depth_effect;
  do
  {
    if ( this != (vostok::render::stage_forward *)12 )
    {
      v40.draw_to_gbuffer = -1;
      v40.blend_mode = -1;
      v35 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
      v40.vertex_input_type = (unsigned int)this;
      v40.cull_mode = 1;
      if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_gbuffer_depth>'::`2'::`local static guard'
          & 1) == 0 )
      {
        `vostok::render::effect_manager::create_effect<vostok::render::effect_gbuffer_depth>'::`2'::`local static guard' |= 1u;
        `vostok::render::effect_manager::create_effect<vostok::render::effect_gbuffer_depth>'::`2'::descriptor_object.m_object = (vostok::configs::binary_config *)&vostok::render::effect_gbuffer_depth::`vftable';
        atexit((int (__cdecl *)())`vostok::render::effect_manager::create_effect<vostok::render::effect_gbuffer_depth>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
        v34 = v39;
      }
      type.vertex_input_type = 0;
      if ( LOBYTE(v35->m_object) )
      {
        v36 = vostok::render::effect_manager::create_new_effect(
                v34,
                v35,
                &v41,
                (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_gbuffer_depth>'::`2'::descriptor_object,
                (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&type,
                &v40);
        vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
          (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v36,
          (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)in_renderer);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v41);
      }
      else
      {
        vostok::render::effect_manager::create_new_effect(
          v34,
          __SPAIR64__((unsigned int)in_renderer, (unsigned int)v35),
          (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_gbuffer_depth>'::`2'::descriptor_object,
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&type,
          &v40);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&type);
    }
    this = (vostok::render::stage_forward *)((char *)this + 1);
    in_renderer = (vostok::render::renderer *)((char *)in_renderer + 4);
  }
  while ( (unsigned int)this < 0xF );
}
