void __usercall vostok::render::stage_view_mode::stage_view_mode(
        vostok::render::stage_view_mode *this@<esi>,
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *context@<eax>)
{
  vostok::render::effect_options_descriptor *v3; // ebp
  vostok::render::effect_options_descriptor *v4; // eax
  vostok::render::effect_options_descriptor *v5; // ecx
  vostok::render::effect_options_descriptor *v6; // eax
  bool v7; // zf
  const void **p_destroyer; // eax
  vostok::render::effect_options_descriptor *v9; // eax
  vostok::render::effect_options_descriptor *v10; // ecx
  const void **v11; // eax
  vostok::render::effect_options_descriptor *v12; // eax
  const void **v13; // eax
  vostok::render::effect_options_descriptor *v14; // eax
  int v15; // ecx
  const void **v16; // eax
  vostok::render::effect_options_descriptor *v17; // eax
  const void **v18; // eax
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v19; // eax
  vostok::render::backend *v20; // ecx
  vostok::strings::shared::manager *v21; // edi
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v22; // eax
  vostok::render::backend *v23; // ecx
  vostok::strings::shared::manager *v24; // edi
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v25; // eax
  vostok::render::backend *v26; // ecx
  vostok::strings::shared::manager *v27; // edi
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v28; // eax
  vostok::render::backend *v29; // ecx
  vostok::strings::shared::manager *v30; // edi
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v31; // eax
  vostok::render::backend *v32; // ecx
  vostok::strings::shared::manager *v33; // edi
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v34; // eax
  vostok::render::backend *v35; // ecx
  vostok::strings::shared::manager *v36; // edi
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v37; // eax
  vostok::render::backend *v38; // ecx
  vostok::strings::shared::manager *v39; // edi
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v40; // eax
  vostok::render::backend *v41; // ecx
  volatile signed __int32 *v42; // edi
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *out_effect; // [esp+Ch] [ebp-420h] BYREF
  vostok::render::effect_options_descriptor desc; // [esp+10h] [ebp-41Ch] BYREF
  unsigned __int8 data[1024]; // [esp+28h] [ebp-404h] BYREF

  this->m_context = context;
  this->m_renderer = in_renderer;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->__vftable = (vostok::render::stage_view_mode_vtbl *)&vostok::render::stage_view_mode::`vftable';
  `vector constructor iterator'(
    (char *)this->m_editor_wireframe_accumulation_effect,
    4u,
    15,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  `vector constructor iterator'(
    (char *)this->m_editor_texture_density_effect,
    4u,
    15,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  `vector constructor iterator'(
    (char *)this->m_editor_shader_complexity_effect,
    4u,
    15,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  `vector constructor iterator'(
    (char *)this->m_editor_show_miplevel_effect,
    4u,
    15,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  `vector constructor iterator'(
    (char *)this->m_editor_geometry_complexity_effect,
    4u,
    15,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  this->m_editor_show_geometry_effect.m_object = 0;
  `vector constructor iterator'(
    (char *)this->m_editor_accumulate_overdraw_effect,
    4u,
    15,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  this->m_editor_vertex_alpha_effect.m_object = 0;
  this->m_editor_apply_wireframe_shader.m_object = 0;
  this->m_editor_show_overdraw_shader.m_object = 0;
  v3 = 0;
  out_effect = this->m_editor_texture_density_effect;
  do
  {
    if ( v3 != (vostok::render::effect_options_descriptor *)12 )
    {
      desc.data = &data[24];
      desc.type = 3;
      desc.bytes = 0;
      desc.count = 0;
      desc.id = 0;
      desc.destroyer = 0;
      desc.memory_size = 1024;
      v4 = vostok::render::effect_options_descriptor::operator[](
             (vostok::render::effect_options_descriptor *)0x400,
             (int)&desc,
             (const char *)&key);
      vostok::render::effect_options_descriptor::operator=<enum vostok::render::enum_vertex_input_type>(v3, v4);
      v6 = vostok::render::effect_options_descriptor::operator[](v5, (int)&desc, (const char *)&stru_960A14);
      v7 = (`vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::`local static guard' & 1) == 0;
      v6->data = (unsigned __int8 *)3;
      v6->count = 4;
      if ( v7 )
      {
        `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::`local static guard' |= 1u;
        `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::current_id = ++vostok::render::static_type::type_id_counter;
      }
      v6->type = `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::current_id;
      p_destroyer = &v6->destroyer;
      if ( p_destroyer )
        *p_destroyer = &vostok::render::destroy_data_helper<enum D3D11_CULL_MODE const>::`vftable';
      vostok::render::effect_manager::create_effect<vostok::render::effect_editor_wireframe_accumulation>(
        (vostok::render::effect_options_descriptor *)&out_effect[-15],
        &desc,
        (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind);
      vostok::render::effect_manager::create_effect<vostok::render::effect_editor_texture_density>(
        (vostok::render::effect_options_descriptor *)out_effect,
        &desc,
        (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind);
      vostok::render::effect_manager::create_effect<vostok::render::effect_editor_shader_complexity>(
        (vostok::render::effect_options_descriptor *)&out_effect[15],
        &desc,
        (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind);
      vostok::render::effect_manager::create_effect<vostok::render::effect_editor_show_miplevel>(
        (vostok::render::effect_options_descriptor *)&out_effect[30],
        &desc,
        (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind);
      vostok::render::effect_manager::create_effect<vostok::render::effect_editor_accumulate_overdraw>(
        (vostok::render::effect_options_descriptor *)&out_effect[61],
        &desc,
        (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind);
      vostok::render::effect_manager::create_effect<vostok::render::effect_editor_geometry_complexity>(
        (vostok::render::effect_options_descriptor *)&out_effect[45],
        &desc,
        (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind);
    }
    ++out_effect;
    v3 = (vostok::render::effect_options_descriptor *)((char *)v3 + 1);
  }
  while ( (unsigned int)v3 < 0xF );
  desc.data = &data[24];
  desc.type = 3;
  desc.bytes = 0;
  desc.count = 0;
  desc.id = 0;
  desc.destroyer = 0;
  desc.memory_size = 1024;
  v9 = vostok::render::effect_options_descriptor::operator[](
         (vostok::render::effect_options_descriptor *)0x400,
         (int)&desc,
         (const char *)&key);
  v7 = (`vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::`local static guard'
      & 1) == 0;
  v9->data = (unsigned __int8 *)1;
  v9->count = 4;
  if ( v7 )
  {
    `vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::`local static guard' |= 1u;
    LOWORD(`vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::current_id) = ++vostok::render::static_type::type_id_counter;
  }
  LOWORD(v10) = (_WORD)`vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::current_id;
  v9->type = (unsigned __int16)`vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::current_id;
  v11 = &v9->destroyer;
  if ( v11 )
    *v11 = &vostok::render::destroy_data_helper<enum vostok::render::enum_vertex_input_type const>::`vftable';
  v12 = vostok::render::effect_options_descriptor::operator[](v10, (int)&desc, (const char *)&stru_960A14);
  v7 = (`vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::`local static guard' & 1) == 0;
  v12->data = (unsigned __int8 *)1;
  v12->count = 4;
  if ( v7 )
  {
    `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::`local static guard' |= 1u;
    `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::current_id = ++vostok::render::static_type::type_id_counter;
  }
  v12->type = `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::current_id;
  v13 = &v12->destroyer;
  if ( v13 )
    *v13 = &vostok::render::destroy_data_helper<enum D3D11_CULL_MODE const>::`vftable';
  vostok::render::effect_manager::create_effect<vostok::render::effect_editor_show_batched_geometry>(
    (vostok::render::effect_options_descriptor *)&this->m_editor_show_geometry_effect,
    &desc,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind);
  desc.data = &data[24];
  desc.type = 3;
  desc.bytes = 0;
  desc.count = 0;
  desc.id = 0;
  desc.destroyer = 0;
  desc.memory_size = 1024;
  v14 = vostok::render::effect_options_descriptor::operator[](
          (vostok::render::effect_options_descriptor *)3,
          (int)&desc,
          (const char *)&key);
  v7 = (`vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::`local static guard'
      & 1) == 0;
  v15 = 4;
  v14->data = (unsigned __int8 *)2;
  v14->count = 4;
  if ( v7 )
  {
    `vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::`local static guard' |= 1u;
    LOWORD(v15) = vostok::render::static_type::type_id_counter + 1;
    vostok::render::static_type::type_id_counter = v15;
    LOWORD(`vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::current_id) = v15;
  }
  v14->type = (unsigned __int16)`vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::current_id;
  v16 = &v14->destroyer;
  if ( v16 )
    *v16 = &vostok::render::destroy_data_helper<enum vostok::render::enum_vertex_input_type const>::`vftable';
  v17 = vostok::render::effect_options_descriptor::operator[](
          (vostok::render::effect_options_descriptor *)v15,
          (int)&desc,
          (const char *)&stru_960A14);
  v7 = (`vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::`local static guard' & 1) == 0;
  v17->data = (unsigned __int8 *)1;
  v17->count = 4;
  if ( v7 )
  {
    `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::`local static guard' |= 1u;
    `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::current_id = ++vostok::render::static_type::type_id_counter;
  }
  v17->type = `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::current_id;
  v18 = &v17->destroyer;
  if ( v18 )
    *v18 = &vostok::render::destroy_data_helper<enum D3D11_CULL_MODE const>::`vftable';
  vostok::render::effect_manager::create_effect<vostok::render::effect_editor_vertex_alpha>(
    (vostok::render::effect_options_descriptor *)&this->m_editor_vertex_alpha_effect,
    &desc,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind);
  vostok::render::effect_manager::create_effect<vostok::render::effect_editor_apply_wireframe>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_editor_apply_wireframe_shader);
  vostok::render::effect_manager::create_effect<vostok::render::effect_editor_show_overdraw>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_editor_show_overdraw_shader);
  v19 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v21 = 0;
  out_effect = 0;
  if ( v19 )
  {
    v21 = (vostok::strings::shared::manager *)v19;
    out_effect = v19;
    _InterlockedExchangeAdd((volatile signed __int32 *)v19, 1u);
  }
  this->m_show_lpv_geometry_component_index_parameter = vostok::render::backend::register_constant_host(
                                                          v20,
                                                          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                          (const vostok::shared_string *)&out_effect,
                                                          rc_int);
  if ( v21 && !_InterlockedExchangeAdd((volatile signed __int32 *)v21, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v21, (vostok::strings::shared::profile *)s_manager.m_variable);
  v22 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v24 = 0;
  out_effect = 0;
  if ( v22 )
  {
    v24 = (vostok::strings::shared::manager *)v22;
    out_effect = v22;
    _InterlockedExchangeAdd((volatile signed __int32 *)v22, 1u);
  }
  this->m_debug_color_parameter = vostok::render::backend::register_constant_host(
                                    v23,
                                    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                    (const vostok::shared_string *)&out_effect,
                                    rc_float);
  if ( v24 && !_InterlockedExchangeAdd((volatile signed __int32 *)v24, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v24, (vostok::strings::shared::profile *)s_manager.m_variable);
  v25 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v27 = 0;
  out_effect = 0;
  if ( v25 )
  {
    v27 = (vostok::strings::shared::manager *)v25;
    out_effect = v25;
    _InterlockedExchangeAdd((volatile signed __int32 *)v25, 1u);
  }
  this->m_shader_complexity_parameter = vostok::render::backend::register_constant_host(
                                          v26,
                                          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                          (const vostok::shared_string *)&out_effect,
                                          rc_float);
  if ( v27 && !_InterlockedExchangeAdd((volatile signed __int32 *)v27, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v27, (vostok::strings::shared::profile *)s_manager.m_variable);
  v28 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v30 = 0;
  out_effect = 0;
  if ( v28 )
  {
    v30 = (vostok::strings::shared::manager *)v28;
    out_effect = v28;
    _InterlockedExchangeAdd((volatile signed __int32 *)v28, 1u);
  }
  this->m_shader_complexity_min_parameter = vostok::render::backend::register_constant_host(
                                              v29,
                                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                              (const vostok::shared_string *)&out_effect,
                                              rc_float);
  if ( v30 && !_InterlockedExchangeAdd((volatile signed __int32 *)v30, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v30, (vostok::strings::shared::profile *)s_manager.m_variable);
  v31 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v33 = 0;
  out_effect = 0;
  if ( v31 )
  {
    v33 = (vostok::strings::shared::manager *)v31;
    out_effect = v31;
    _InterlockedExchangeAdd((volatile signed __int32 *)v31, 1u);
  }
  this->m_shader_complexity_max_parameter = vostok::render::backend::register_constant_host(
                                              v32,
                                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                              (const vostok::shared_string *)&out_effect,
                                              rc_float);
  if ( v33 && !_InterlockedExchangeAdd((volatile signed __int32 *)v33, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v33, (vostok::strings::shared::profile *)s_manager.m_variable);
  v34 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v36 = 0;
  out_effect = 0;
  if ( v34 )
  {
    v36 = (vostok::strings::shared::manager *)v34;
    out_effect = v34;
    _InterlockedExchangeAdd((volatile signed __int32 *)v34, 1u);
  }
  this->m_geometry_complexity_parameters = vostok::render::backend::register_constant_host(
                                             v35,
                                             (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                             (const vostok::shared_string *)&out_effect,
                                             rc_float);
  if ( v36 && !_InterlockedExchangeAdd((volatile signed __int32 *)v36, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v36, (vostok::strings::shared::profile *)s_manager.m_variable);
  v37 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v39 = 0;
  out_effect = 0;
  if ( v37 )
  {
    v39 = (vostok::strings::shared::manager *)v37;
    out_effect = v37;
    _InterlockedExchangeAdd((volatile signed __int32 *)v37, 1u);
  }
  this->m_current_max_texture_dimension_parameter = vostok::render::backend::register_constant_host(
                                                      v38,
                                                      (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                      (const vostok::shared_string *)&out_effect,
                                                      rc_float);
  if ( v39 && !_InterlockedExchangeAdd((volatile signed __int32 *)v39, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v39, (vostok::strings::shared::profile *)s_manager.m_variable);
  v40 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v42 = 0;
  out_effect = 0;
  if ( v40 )
  {
    v42 = (volatile signed __int32 *)v40;
    out_effect = v40;
    _InterlockedExchangeAdd((volatile signed __int32 *)v40, 1u);
  }
  this->m_c_start_corner = vostok::render::backend::register_constant_host(
                             v41,
                             (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                             (const vostok::shared_string *)&out_effect,
                             rc_float);
  if ( v42 )
  {
    if ( !_InterlockedExchangeAdd(v42, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
}
