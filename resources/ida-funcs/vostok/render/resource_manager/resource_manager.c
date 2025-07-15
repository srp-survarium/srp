void __usercall vostok::render::resource_manager::resource_manager(
        vostok::render::resource_manager *this@<esi>,
        const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *in_config@<eax>)
{
  stlp_std::priv::_Impl_vector<vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record,vostok::render::std_allocator<vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record> > *v2; // ecx
  stlp_std::priv::_Impl_vector<vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record,vostok::render::std_allocator<vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record> > *v3; // ecx
  stlp_std::priv::_Impl_vector<vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record,vostok::render::std_allocator<vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record> > *v4; // ecx
  stlp_std::priv::_Impl_vector<vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record,vostok::render::std_allocator<vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record> > *v5; // ecx
  vostok::render::shader_binary_source_cook *v6; // ecx
  bool v7; // zf
  _QWORD *v8; // eax
  _QWORD *v9; // eax
  char v10; // [esp+9h] [ebp-7Bh]
  char v11; // [esp+Ch] [ebp-78h]
  char v12; // [esp+Dh] [ebp-77h]
  char v13; // [esp+Eh] [ebp-76h]
  char v14; // [esp+Fh] [ebp-75h]

  this->m_deferred_context = 0;
  this->m_render_target_video_memory = 0;
  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] = (survarium::options_tab *)this;
  this->shader_name_to_mask_config.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &this->shader_name_to_mask_config,
    in_config);
  this->m_num_bytes_of_texture_video_memory = 0;
  this->m_num_bytes_of_buffers_video_memory = 0;
  this->m_vs_hw_registry._M_t._M_key_compare.gap0 = v14;
  this->m_vs_hw_registry._M_t._M_node_count = 0;
  *(_QWORD *)&this->m_vs_hw_registry._M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&this->m_vs_hw_registry._M_t._M_header._M_data._M_left = 0;
  this->m_vs_hw_registry._M_t._M_header._M_data._M_color = 0;
  this->m_vs_hw_registry._M_t._M_header._M_data._M_parent = 0;
  this->m_vs_hw_registry._M_t._M_header._M_data._M_left = &this->m_vs_hw_registry._M_t._M_header._M_data;
  this->m_vs_hw_registry._M_t._M_header._M_data._M_right = &this->m_vs_hw_registry._M_t._M_header._M_data;
  this->m_gs_hw_registry._M_t._M_node_count = 0;
  this->m_gs_hw_registry._M_t._M_key_compare.gap0 = v13;
  *(_QWORD *)&this->m_gs_hw_registry._M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&this->m_gs_hw_registry._M_t._M_header._M_data._M_left = 0;
  this->m_gs_hw_registry._M_t._M_header._M_data._M_color = 0;
  this->m_gs_hw_registry._M_t._M_header._M_data._M_parent = 0;
  this->m_gs_hw_registry._M_t._M_header._M_data._M_left = &this->m_gs_hw_registry._M_t._M_header._M_data;
  this->m_gs_hw_registry._M_t._M_header._M_data._M_right = &this->m_gs_hw_registry._M_t._M_header._M_data;
  this->m_ps_hw_registry._M_t._M_node_count = 0;
  this->m_ps_hw_registry._M_t._M_key_compare.gap0 = v11;
  *(_QWORD *)&this->m_ps_hw_registry._M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&this->m_ps_hw_registry._M_t._M_header._M_data._M_left = 0;
  this->m_ps_hw_registry._M_t._M_header._M_data._M_color = 0;
  this->m_ps_hw_registry._M_t._M_header._M_data._M_parent = 0;
  this->m_ps_hw_registry._M_t._M_header._M_data._M_left = &this->m_ps_hw_registry._M_t._M_header._M_data;
  this->m_ps_hw_registry._M_t._M_header._M_data._M_right = &this->m_ps_hw_registry._M_t._M_header._M_data;
  this->m_rt_registry._M_t._M_node_count = 0;
  *(_QWORD *)&this->m_rt_registry._M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&this->m_rt_registry._M_t._M_header._M_data._M_left = 0;
  this->m_rt_registry._M_t._M_header._M_data._M_color = 0;
  this->m_rt_registry._M_t._M_header._M_data._M_parent = 0;
  this->m_rt_registry._M_t._M_header._M_data._M_left = &this->m_rt_registry._M_t._M_header._M_data;
  this->m_rt_registry._M_t._M_header._M_data._M_right = &this->m_rt_registry._M_t._M_header._M_data;
  *(_QWORD *)&this->m_texture_registry._M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&this->m_texture_registry._M_t._M_header._M_data._M_left = 0;
  this->m_texture_registry._M_t._M_header._M_data._M_color = 0;
  this->m_texture_registry._M_t._M_header._M_data._M_parent = 0;
  this->m_texture_registry._M_t._M_header._M_data._M_left = &this->m_texture_registry._M_t._M_header._M_data;
  this->m_texture_registry._M_t._M_header._M_data._M_right = &this->m_texture_registry._M_t._M_header._M_data;
  this->m_texture_registry._M_t._M_node_count = 0;
  this->m_const_tables._M_t._M_node_count = 0;
  *(_QWORD *)&this->m_const_tables._M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&this->m_const_tables._M_t._M_header._M_data._M_left = 0;
  this->m_const_tables._M_t._M_header._M_data._M_color = 0;
  this->m_const_tables._M_t._M_header._M_data._M_parent = 0;
  this->m_const_tables._M_t._M_header._M_data._M_left = &this->m_const_tables._M_t._M_header._M_data;
  this->m_const_tables._M_t._M_header._M_data._M_right = &this->m_const_tables._M_t._M_header._M_data;
  *(_QWORD *)&this->m_const_buffers._M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&this->m_const_buffers._M_t._M_header._M_data._M_left = 0;
  this->m_const_buffers._M_t._M_header._M_data._M_color = 0;
  this->m_const_buffers._M_t._M_header._M_data._M_parent = 0;
  this->m_const_buffers._M_t._M_header._M_data._M_left = &this->m_const_buffers._M_t._M_header._M_data;
  this->m_const_buffers._M_t._M_header._M_data._M_right = &this->m_const_buffers._M_t._M_header._M_data;
  this->m_const_buffers._M_t._M_node_count = 0;
  this->m_buffers._M_impl._M_start = 0;
  this->m_buffers._M_impl._M_finish = 0;
  this->m_buffers._M_impl._M_end_of_storage._M_data = 0;
  this->m_tasks_type = vostok::tasks::create_new_task_type("texture_create_task", 0);
  this->m_parent_task.m_next_task_in_allocator = 0;
  this->m_parent_task.m_next_task_in_full_queue = 0;
  this->m_parent_task.m_children.m_size = 0;
  this->m_parent_task.m_children.m_first = 0;
  this->m_parent_task.m_children.m_last = 0;
  this->m_parent_task.m_child_counter = 0;
  this->m_parent_task.m_event_wait_for_children = 0;
  this->m_parent_task.m_function.vtable = 0;
  this->m_parent_task.m_ordinal = 0;
  this->m_parent_task.m_type = 0;
  this->m_parent_task.m_parent = 0;
  this->m_parent_task.m_state = 1;
  this->m_parent_task.m_reference_counter = 4;
  this->m_v_shaders._M_t._M_node_count = 0;
  *(_QWORD *)&this->m_v_shaders._M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&this->m_v_shaders._M_t._M_header._M_data._M_left = 0;
  this->m_v_shaders._M_t._M_header._M_data._M_color = 0;
  this->m_v_shaders._M_t._M_header._M_data._M_parent = 0;
  this->m_v_shaders._M_t._M_header._M_data._M_left = &this->m_v_shaders._M_t._M_header._M_data;
  this->m_v_shaders._M_t._M_header._M_data._M_right = &this->m_v_shaders._M_t._M_header._M_data;
  this->m_g_shaders._M_t._M_node_count = 0;
  *(_QWORD *)&this->m_g_shaders._M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&this->m_g_shaders._M_t._M_header._M_data._M_left = 0;
  this->m_g_shaders._M_t._M_header._M_data._M_color = 0;
  this->m_g_shaders._M_t._M_header._M_data._M_parent = 0;
  this->m_g_shaders._M_t._M_header._M_data._M_left = &this->m_g_shaders._M_t._M_header._M_data;
  this->m_g_shaders._M_t._M_header._M_data._M_right = &this->m_g_shaders._M_t._M_header._M_data;
  this->m_p_shaders._M_t._M_node_count = 0;
  *(_QWORD *)&this->m_p_shaders._M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&this->m_p_shaders._M_t._M_header._M_data._M_left = 0;
  this->m_p_shaders._M_t._M_header._M_data._M_color = 0;
  this->m_p_shaders._M_t._M_header._M_data._M_parent = 0;
  this->m_p_shaders._M_t._M_header._M_data._M_left = &this->m_p_shaders._M_t._M_header._M_data;
  this->m_p_shaders._M_t._M_header._M_data._M_right = &this->m_p_shaders._M_t._M_header._M_data;
  this->m_states._M_impl._M_start = 0;
  this->m_states._M_impl._M_finish = 0;
  this->m_states._M_impl._M_end_of_storage._M_data = 0;
  this->m_rs_cache.states._M_impl._M_start = 0;
  this->m_rs_cache.states._M_impl._M_finish = 0;
  this->m_rs_cache.states._M_impl._M_end_of_storage._M_data = 0;
  stlp_std::priv::_Impl_vector<vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::state_record,vostok::render::std_allocator<vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::state_record>>::reserve(
    v2,
    (unsigned int)&this->m_rs_cache);
  this->m_dss_cache.states._M_impl._M_start = 0;
  this->m_dss_cache.states._M_impl._M_finish = 0;
  this->m_dss_cache.states._M_impl._M_end_of_storage._M_data = 0;
  stlp_std::priv::_Impl_vector<vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::state_record,vostok::render::std_allocator<vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::state_record>>::reserve(
    v3,
    (unsigned int)&this->m_dss_cache);
  this->m_bs_cache.states._M_impl._M_start = 0;
  this->m_bs_cache.states._M_impl._M_finish = 0;
  this->m_bs_cache.states._M_impl._M_end_of_storage._M_data = 0;
  stlp_std::priv::_Impl_vector<vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::state_record,vostok::render::std_allocator<vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::state_record>>::reserve(
    v4,
    (unsigned int)&this->m_bs_cache);
  this->m_sampler_cache.states._M_impl._M_start = 0;
  this->m_sampler_cache.states._M_impl._M_finish = 0;
  this->m_sampler_cache.states._M_impl._M_end_of_storage._M_data = 0;
  stlp_std::priv::_Impl_vector<vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::state_record,vostok::render::std_allocator<vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::state_record>>::reserve(
    v5,
    (unsigned int)&this->m_sampler_cache);
  this->m_declarations._M_t._M_node_count = 0;
  *(_QWORD *)&this->m_declarations._M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&this->m_declarations._M_t._M_header._M_data._M_left = 0;
  this->m_declarations._M_t._M_header._M_data._M_color = 0;
  this->m_declarations._M_t._M_header._M_data._M_parent = 0;
  this->m_declarations._M_t._M_header._M_data._M_left = &this->m_declarations._M_t._M_header._M_data;
  this->m_declarations._M_t._M_header._M_data._M_right = &this->m_declarations._M_t._M_header._M_data;
  this->m_signatures._M_t._M_node_count = 0;
  *(_QWORD *)&this->m_signatures._M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&this->m_signatures._M_t._M_header._M_data._M_left = 0;
  this->m_signatures._M_t._M_header._M_data._M_color = 0;
  this->m_signatures._M_t._M_header._M_data._M_parent = 0;
  this->m_signatures._M_t._M_header._M_data._M_left = &this->m_signatures._M_t._M_header._M_data;
  this->m_signatures._M_t._M_header._M_data._M_right = &this->m_signatures._M_t._M_header._M_data;
  this->m_input_layouts._M_t._M_node_count = 0;
  *(_QWORD *)&this->m_input_layouts._M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&this->m_input_layouts._M_t._M_header._M_data._M_left = 0;
  this->m_input_layouts._M_t._M_header._M_data._M_color = 0;
  this->m_input_layouts._M_t._M_header._M_data._M_parent = 0;
  this->m_input_layouts._M_t._M_header._M_data._M_left = &this->m_input_layouts._M_t._M_header._M_data;
  this->m_input_layouts._M_t._M_header._M_data._M_right = &this->m_input_layouts._M_t._M_header._M_data;
  this->m_texture_lists._M_t._M_node_count = 0;
  *(_QWORD *)&this->m_texture_lists._M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&this->m_texture_lists._M_t._M_header._M_data._M_left = 0;
  this->m_texture_lists._M_t._M_header._M_data._M_color = 0;
  this->m_texture_lists._M_t._M_header._M_data._M_parent = 0;
  this->m_texture_lists._M_t._M_header._M_data._M_left = &this->m_texture_lists._M_t._M_header._M_data;
  this->m_texture_lists._M_t._M_header._M_data._M_right = &this->m_texture_lists._M_t._M_header._M_data;
  this->m_sampler_lists._M_t._M_node_count = 0;
  *(_QWORD *)&this->m_sampler_lists._M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&this->m_sampler_lists._M_t._M_header._M_data._M_left = 0;
  this->m_sampler_lists._M_t._M_header._M_data._M_color = 0;
  this->m_sampler_lists._M_t._M_header._M_data._M_parent = 0;
  this->m_sampler_lists._M_t._M_header._M_data._M_left = &this->m_sampler_lists._M_t._M_header._M_data;
  this->m_sampler_lists._M_t._M_header._M_data._M_right = &this->m_sampler_lists._M_t._M_header._M_data;
  this->m_render_outputs._M_impl._M_start = 0;
  this->m_render_outputs._M_impl._M_finish = 0;
  this->m_render_outputs._M_impl._M_end_of_storage._M_data = 0;
  this->m_samplers_registry._M_impl._M_start = 0;
  this->m_samplers_registry._M_impl._M_finish = 0;
  this->m_samplers_registry._M_impl._M_end_of_storage._M_data = 0;
  this->m_vs_ids._M_impl._M_start = 0;
  this->m_vs_ids._M_impl._M_finish = 0;
  this->m_vs_ids._M_impl._M_end_of_storage._M_data = 0;
  this->m_ps_ids._M_impl._M_start = 0;
  this->m_ps_ids._M_impl._M_finish = 0;
  this->m_ps_ids._M_impl._M_end_of_storage._M_data = 0;
  this->m_gs_ids._M_impl._M_start = 0;
  this->m_gs_ids._M_impl._M_finish = 0;
  this->m_gs_ids._M_impl._M_end_of_storage._M_data = 0;
  this->m_geometries._M_t._M_node_count = 0;
  *(_QWORD *)&this->m_geometries._M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&this->m_geometries._M_t._M_header._M_data._M_left = 0;
  this->m_geometries._M_t._M_header._M_data._M_color = 0;
  this->m_geometries._M_t._M_header._M_data._M_parent = 0;
  this->m_geometries._M_t._M_header._M_data._M_left = &this->m_geometries._M_t._M_header._M_data;
  this->m_geometries._M_t._M_header._M_data._M_right = &this->m_geometries._M_t._M_header._M_data;
  this->m_loading_incomplete = 0;
  this->m_const_bindings.m_bindings._M_impl._M_start = 0;
  this->m_const_bindings.m_bindings._M_impl._M_finish = 0;
  this->m_const_bindings.m_bindings._M_impl._M_end_of_storage._M_data = 0;
  this->m_texture_storage = 0;
  this->m_texture_storage_staging = 0;
  this->m_compile_error_handler.m_Closure.m_pFunction = 0;
  this->m_compile_error_handler.m_Closure.m_pthis = 0;
  this->m_is_shader_reloading = 0;
  this->m_need_recompile_shader_if_source_reloaded = 1;
  this->m_textures_to_reload._M_impl._M_start = 0;
  this->m_textures_to_reload._M_impl._M_finish = 0;
  this->m_textures_to_reload._M_impl._M_end_of_storage._M_data = 0;
  this->m_color_grading_base_lut.m_object = 0;
  memset((int)s_command_lists, 0, sizeof(s_command_lists));
  v7 = (_S3_12 & 1) == 0;
  this->sh_returned = 0;
  this->sh_created = 0;
  this->tl_created = 0;
  this->cb_created = 0;
  this->sl_created = 0;
  if ( v7 )
  {
    _S3_12 |= 1u;
    vostok::render::shader_binary_source_cook::shader_binary_source_cook(v6);
    atexit(vostok::render::resource_manager::resource_manager_::_2_::_dynamic_atexit_destructor_for__shader_binary_source_cooker__);
  }
  vostok::resources::resources_manager::register_cook(&shader_binary_source_cooker);
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0x1Cu);
  if ( v8 )
  {
    *v8 = 0;
    v8[1] = 0;
    *(_BYTE *)v8 = 0;
    *((_DWORD *)v8 + 1) = 0;
    *((_DWORD *)v8 + 2) = v8;
    *((_DWORD *)v8 + 3) = v8;
    *((_DWORD *)v8 + 4) = 0;
    *((_BYTE *)v8 + 20) = v12;
    *((_BYTE *)v8 + 24) = 0;
  }
  else
  {
    v8 = 0;
  }
  this->m_texture_storage = (vostok::render::texture_storage *)v8;
  v9 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0x1Cu);
  if ( v9 )
  {
    *v9 = 0;
    v9[1] = 0;
    *(_BYTE *)v9 = 0;
    *((_DWORD *)v9 + 1) = 0;
    *((_DWORD *)v9 + 2) = v9;
    *((_DWORD *)v9 + 3) = v9;
    *((_DWORD *)v9 + 4) = 0;
    *((_BYTE *)v9 + 20) = v10;
    *((_BYTE *)v9 + 24) = 0;
    this->m_texture_storage_staging = (vostok::render::texture_storage *)v9;
  }
  else
  {
    this->m_texture_storage_staging = 0;
  }
}
