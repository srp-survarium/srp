void __userpurge vostok::render::stage_forward::stage_forward(
        vostok::render::stage_forward *this@<esi>,
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *context@<eax>,
        vostok::render::stage_forward::stage_type type)
{
  vostok::strings::shared::manager *v4; // ecx
  vostok::strings::shared::profile *v5; // eax
  vostok::render::backend *v6; // ecx
  volatile signed __int32 *p_m_reference_count; // edi
  vostok::strings::shared::manager *v8; // ecx
  vostok::strings::shared::profile *v9; // eax
  vostok::render::backend *v10; // ecx
  volatile signed __int32 *v11; // edi
  vostok::strings::shared::manager *v12; // ecx
  vostok::strings::shared::profile *v13; // eax
  vostok::render::backend *v14; // ecx
  volatile signed __int32 *v15; // edi
  vostok::strings::shared::manager *v16; // ecx
  vostok::strings::shared::profile *v17; // eax
  vostok::render::backend *v18; // ecx
  volatile signed __int32 *v19; // edi
  vostok::strings::shared::manager *v20; // ecx
  vostok::strings::shared::profile *v21; // eax
  vostok::render::backend *v22; // ecx
  volatile signed __int32 *v23; // edi
  vostok::strings::shared::manager *v24; // ecx
  vostok::strings::shared::profile *v25; // eax
  vostok::render::backend *v26; // ecx
  volatile signed __int32 *v27; // edi
  vostok::strings::shared::manager *v28; // ecx
  vostok::strings::shared::profile *v29; // eax
  vostok::render::backend *v30; // ecx
  volatile signed __int32 *v31; // edi
  vostok::strings::shared::manager *v32; // ecx
  vostok::strings::shared::profile *v33; // eax
  vostok::render::backend *v34; // ecx
  volatile signed __int32 *v35; // edi
  vostok::strings::shared::manager *v36; // ecx
  vostok::strings::shared::profile *v37; // eax
  vostok::render::backend *v38; // ecx
  volatile signed __int32 *v39; // edi
  vostok::strings::shared::manager *v40; // ecx
  vostok::strings::shared::profile *v41; // eax
  vostok::render::backend *v42; // ecx
  volatile signed __int32 *v43; // edi
  vostok::strings::shared::manager *v44; // ecx
  vostok::strings::shared::profile *v45; // eax
  vostok::render::backend *v46; // ecx
  volatile signed __int32 *v47; // edi
  vostok::render::effect_options_descriptor *v48; // eax
  vostok::render::effect_options_descriptor *v49; // ecx
  vostok::render::effect_options_descriptor *v50; // eax
  vostok::render::effect_options_descriptor *v51; // ecx
  vostok::render::effect_options_descriptor *v52; // ebp
  vostok::render::effect_options_descriptor *v53; // eax
  vostok::render::effect_options_descriptor *v54; // ecx
  vostok::render::effect_options_descriptor *v55; // eax
  const void **p_destroyer; // eax
  vostok::shared_string name; // [esp+Ch] [ebp-81Ch] BYREF
  vostok::render::effect_options_descriptor desc; // [esp+10h] [ebp-818h] BYREF
  unsigned __int8 tracer_data[1024]; // [esp+28h] [ebp-800h] BYREF
  unsigned __int8 data[1024]; // [esp+428h] [ebp-400h] BYREF

  this->m_context = context;
  this->m_renderer = in_renderer;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->__vftable = (vostok::render::stage_forward_vtbl *)&stru_965008.m_name.m_string.m_buffer[204];
  this->m_debug_tracer_effect.m_object = 0;
  this->m_opaque_geometry_mask_effect.m_object = 0;
  `vector constructor iterator'(
    (char *)this->m_gbuffer_depth_effect,
    4u,
    15,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  this->m_type = type;
  v5 = vostok::strings::shared::manager::string(v4, (const char *)s_manager.m_variable);
  p_m_reference_count = 0;
  name.m_pointer.m_object = 0;
  if ( v5 )
  {
    p_m_reference_count = &v5->m_reference_count;
    name.m_pointer.m_object = v5;
    v6 = (vostok::render::backend *)_InterlockedExchangeAdd(&v5->m_reference_count, 1u);
  }
  this->m_tree_position_and_scale_parameter = vostok::render::backend::register_constant_host(
                                                v6,
                                                (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                &name,
                                                rc_float);
  if ( p_m_reference_count )
  {
    v8 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(p_m_reference_count, 0xFFFFFFFF);
    if ( !v8 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v9 = vostok::strings::shared::manager::string(v8, (const char *)s_manager.m_variable);
  v11 = 0;
  name.m_pointer.m_object = 0;
  if ( v9 )
  {
    v11 = &v9->m_reference_count;
    name.m_pointer.m_object = v9;
    v10 = (vostok::render::backend *)_InterlockedExchangeAdd(&v9->m_reference_count, 1u);
  }
  this->m_tree_rotation_parameter = vostok::render::backend::register_constant_host(
                                      v10,
                                      (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                      &name,
                                      rc_float);
  if ( v11 )
  {
    v12 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v11, 0xFFFFFFFF);
    if ( !v12 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v13 = vostok::strings::shared::manager::string(v12, (const char *)s_manager.m_variable);
  v15 = 0;
  name.m_pointer.m_object = 0;
  if ( v13 )
  {
    v15 = &v13->m_reference_count;
    name.m_pointer.m_object = v13;
    v14 = (vostok::render::backend *)_InterlockedExchangeAdd(&v13->m_reference_count, 1u);
  }
  this->m_far_fog_color_and_distance = vostok::render::backend::register_constant_host(
                                         v14,
                                         (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                         &name,
                                         rc_float);
  if ( v15 )
  {
    v16 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v15, 0xFFFFFFFF);
    if ( !v16 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v17 = vostok::strings::shared::manager::string(v16, (const char *)s_manager.m_variable);
  v19 = 0;
  name.m_pointer.m_object = 0;
  if ( v17 )
  {
    v19 = &v17->m_reference_count;
    name.m_pointer.m_object = v17;
    v18 = (vostok::render::backend *)_InterlockedExchangeAdd(&v17->m_reference_count, 1u);
  }
  this->m_fog_alpha = vostok::render::backend::register_constant_host(
                        v18,
                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                        &name,
                        rc_float);
  if ( v19 )
  {
    v20 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v19, 0xFFFFFFFF);
    if ( !v20 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v21 = vostok::strings::shared::manager::string(v20, (const char *)s_manager.m_variable);
  v23 = 0;
  name.m_pointer.m_object = 0;
  if ( v21 )
  {
    v23 = &v21->m_reference_count;
    name.m_pointer.m_object = v21;
    v22 = (vostok::render::backend *)_InterlockedExchangeAdd(&v21->m_reference_count, 1u);
  }
  this->m_near_fog_distance = vostok::render::backend::register_constant_host(
                                v22,
                                (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                &name,
                                rc_float);
  if ( v23 )
  {
    v24 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v23, 0xFFFFFFFF);
    if ( !v24 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v25 = vostok::strings::shared::manager::string(v24, (const char *)s_manager.m_variable);
  v27 = 0;
  name.m_pointer.m_object = 0;
  if ( v25 )
  {
    v27 = &v25->m_reference_count;
    name.m_pointer.m_object = v25;
    v26 = (vostok::render::backend *)_InterlockedExchangeAdd(&v25->m_reference_count, 1u);
  }
  this->m_eye_ray_corner_parameter = vostok::render::backend::register_constant_host(
                                       v26,
                                       (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                       &name,
                                       rc_float);
  if ( v27 )
  {
    v28 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v27, 0xFFFFFFFF);
    if ( !v28 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v29 = vostok::strings::shared::manager::string(v28, (const char *)s_manager.m_variable);
  v31 = 0;
  name.m_pointer.m_object = 0;
  if ( v29 )
  {
    v31 = &v29->m_reference_count;
    name.m_pointer.m_object = v29;
    v30 = (vostok::render::backend *)_InterlockedExchangeAdd(&v29->m_reference_count, 1u);
  }
  this->m_view_to_shadow_parameter = vostok::render::backend::register_constant_host(
                                       v30,
                                       (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                       &name,
                                       rc_float);
  if ( v31 )
  {
    v32 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v31, 0xFFFFFFFF);
    if ( !v32 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v33 = vostok::strings::shared::manager::string(v32, (const char *)s_manager.m_variable);
  v35 = 0;
  name.m_pointer.m_object = 0;
  if ( v33 )
  {
    v35 = &v33->m_reference_count;
    name.m_pointer.m_object = v33;
    v34 = (vostok::render::backend *)_InterlockedExchangeAdd(&v33->m_reference_count, 1u);
  }
  this->m_rain_offset_parameter = vostok::render::backend::register_constant_host(
                                    v34,
                                    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                    &name,
                                    rc_float);
  if ( v35 )
  {
    v36 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v35, 0xFFFFFFFF);
    if ( !v36 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v37 = vostok::strings::shared::manager::string(v36, (const char *)s_manager.m_variable);
  v39 = 0;
  name.m_pointer.m_object = 0;
  if ( v37 )
  {
    v39 = &v37->m_reference_count;
    name.m_pointer.m_object = v37;
    v38 = (vostok::render::backend *)_InterlockedExchangeAdd(&v37->m_reference_count, 1u);
  }
  this->m_use_rain_parameter = vostok::render::backend::register_constant_host(
                                 v38,
                                 (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                 &name,
                                 rc_float);
  if ( v39 )
  {
    v40 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v39, 0xFFFFFFFF);
    if ( !v40 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v41 = vostok::strings::shared::manager::string(v40, (const char *)s_manager.m_variable);
  v43 = 0;
  name.m_pointer.m_object = 0;
  if ( v41 )
  {
    v43 = &v41->m_reference_count;
    name.m_pointer.m_object = v41;
    v42 = (vostok::render::backend *)_InterlockedExchangeAdd(&v41->m_reference_count, 1u);
  }
  this->m_tracer_debug_color_parameter = vostok::render::backend::register_constant_host(
                                           v42,
                                           (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                           &name,
                                           rc_float);
  if ( v43 )
  {
    v44 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v43, 0xFFFFFFFF);
    if ( !v44 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v45 = vostok::strings::shared::manager::string(v44, (const char *)s_manager.m_variable);
  v47 = 0;
  name.m_pointer.m_object = 0;
  if ( v45 )
  {
    v47 = &v45->m_reference_count;
    name.m_pointer.m_object = v45;
    v46 = (vostok::render::backend *)_InterlockedExchangeAdd(&v45->m_reference_count, 1u);
  }
  this->m_c_inscatter_parameters = vostok::render::backend::register_constant_host(
                                     v46,
                                     (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                     &name,
                                     rc_float);
  if ( v47 && !_InterlockedExchangeAdd(v47, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  vostok::render::effect_manager::create_effect<vostok::render::effect_decal_mask>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_opaque_geometry_mask_effect);
  desc.data = &tracer_data[24];
  desc.type = 3;
  desc.bytes = 0;
  desc.count = 0;
  desc.id = 0;
  desc.destroyer = 0;
  desc.memory_size = 1024;
  v48 = vostok::render::effect_options_descriptor::operator[](
          (vostok::render::effect_options_descriptor *)3,
          (int)&desc,
          (const char *)&key);
  vostok::render::effect_options_descriptor::operator=<enum vostok::render::enum_vertex_input_type>(
    (vostok::render::effect_options_descriptor *)1,
    v48);
  v50 = vostok::render::effect_options_descriptor::operator[](
          v49,
          (int)&desc,
          (const char *)&stru_960AE0.m_techniques._M_t._M_header._M_data._M_left);
  vostok::render::effect_options_descriptor::operator=<int>(v51, v50);
  vostok::render::effect_manager::create_effect<vostok::render::effect_debug_tracer>(
    (vostok::render::effect_options_descriptor *)&this->m_debug_tracer_effect,
    &desc,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind);
  this->m_enabled = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                    + 253);
  this->m_rain_offset = 0.0;
  this->m_rain_offset_counter = 0.0;
  v52 = 0;
  name.m_pointer.m_object = (vostok::strings::shared::profile *)this->m_gbuffer_depth_effect;
  do
  {
    if ( v52 != (vostok::render::effect_options_descriptor *)12 )
    {
      desc.data = &data[24];
      desc.type = 3;
      desc.bytes = 0;
      desc.count = 0;
      desc.id = 0;
      desc.destroyer = 0;
      desc.memory_size = 1024;
      v53 = vostok::render::effect_options_descriptor::operator[](
              (vostok::render::effect_options_descriptor *)0x400,
              (int)&desc,
              (const char *)&key);
      vostok::render::effect_options_descriptor::operator=<enum vostok::render::enum_vertex_input_type>(v52, v53);
      v55 = vostok::render::effect_options_descriptor::operator[](v54, (int)&desc, (const char *)&stru_960A14);
      v55->data = (unsigned __int8 *)1;
      v55->count = 4;
      if ( (`vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::`local static guard' & 1) == 0 )
      {
        `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::`local static guard' |= 1u;
        `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::current_id = ++vostok::render::static_type::type_id_counter;
      }
      v55->type = `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::current_id;
      p_destroyer = &v55->destroyer;
      if ( p_destroyer )
        *p_destroyer = &vostok::render::destroy_data_helper<enum D3D11_CULL_MODE const>::`vftable';
      vostok::render::effect_manager::create_effect<vostok::render::effect_gbuffer_depth>(
        (vostok::render::effect_options_descriptor *)name.m_pointer.m_object,
        &desc,
        (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind);
    }
    name.m_pointer.m_object = (vostok::strings::shared::profile *)((char *)name.m_pointer.m_object + 4);
    v52 = (vostok::render::effect_options_descriptor *)((char *)v52 + 1);
  }
  while ( (unsigned int)v52 < 0xF );
}
