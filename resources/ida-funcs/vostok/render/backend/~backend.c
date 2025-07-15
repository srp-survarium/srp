void __thiscall vostok::render::backend::~backend(vostok::render::backend *this, vostok::render::backend *thisa)
{
  void **i; // edi
  volatile signed __int32 **v3; // esi
  vostok::render::grass_render_model *m_object; // ebx
  volatile signed __int32 *v5; // eax
  volatile signed __int32 **v6; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  ID3D11Device *m_device; // eax
  const vostok::render::res_render_output *v9; // eax
  void **M_start; // eax
  void *v11; // esi
  const vostok::render::res_sampler_list *v12; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v13; // eax
  void *v14; // esi
  const vostok::render::res_texture_list *v15; // eax
  const vostok::render::shader_constant_table *v16; // eax
  const vostok::render::res_sampler_list *v17; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v18; // eax
  void *v19; // esi
  const vostok::render::res_texture_list *v20; // eax
  const vostok::render::shader_constant_table *v21; // eax
  const vostok::render::res_sampler_list *v22; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v23; // eax
  void *v24; // esi
  const vostok::render::res_texture_list *v25; // eax
  bool v26; // zf
  const vostok::render::shader_constant_table *v27; // eax
  vostok::render::untyped_buffer *v28; // eax
  vostok::render::res_state *v29; // edi
  survarium::options_tab *v30; // ebx
  ID3D11RasterizerState *m_rasterizer_state; // eax
  vostok::render::grass_render_model *v32; // esi
  vostok::render::untyped_buffer *v33; // eax
  vostok::render::res_state *v34; // ebp
  survarium::options_tab *v35; // edi
  ID3D11RasterizerState *v36; // eax
  vostok::render::grass_render_model *v37; // esi

  for ( i = thisa->m_constant_hosts._M_impl._M_start; i < thisa->m_constant_hosts._M_impl._M_finish; ++i )
  {
    v3 = (volatile signed __int32 **)*i;
    m_object = vostok::render::g_allocator.m_object;
    if ( *i )
    {
      v5 = v3[8];
      if ( v5 && !_InterlockedExchangeAdd(v5, 0xFFFFFFFF) )
        vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
      if ( v3 )
      {
        v6 = v3;
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
        BYTE2(m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v6);
      }
      *i = 0;
    }
  }
  m_device = thisa->m_device;
  if ( m_device )
  {
    m_device->Release(thisa->m_device);
    thisa->m_device = 0;
  }
  thisa->m_device = 0;
  v9 = thisa->m_render_output.m_object;
  if ( v9 )
  {
    if ( !--v9->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_render_output.m_object);
  }
  M_start = thisa->m_constant_hosts._M_impl._M_start;
  if ( M_start )
  {
    v11 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v11, M_start);
  }
  v12 = thisa->m_ps_samplers_handler.m_current.m_object;
  if ( v12 )
  {
    if ( !--v12->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_ps_samplers_handler.m_current.m_object);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>(
    (stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>)thisa->m_ps_textures_handler.m_custom_list.m_container._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>)thisa->m_ps_textures_handler.m_custom_list.m_container._M_impl._M_start);
  v13 = thisa->m_ps_textures_handler.m_custom_list.m_container._M_impl._M_start;
  if ( v13 )
  {
    v14 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v14, v13);
  }
  v15 = thisa->m_ps_textures_handler.m_current.m_object;
  if ( v15 )
  {
    if ( !--v15->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_ps_textures_handler.m_current.m_object);
  }
  v16 = thisa->m_ps_constants_handler.m_current.m_object;
  if ( v16 )
  {
    if ( !--v16->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_ps_constants_handler.m_current.m_object);
  }
  v17 = thisa->m_gs_samplers_handler.m_current.m_object;
  if ( v17 )
  {
    if ( !--v17->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_gs_samplers_handler.m_current.m_object);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>(
    (stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>)thisa->m_gs_textures_handler.m_custom_list.m_container._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>)thisa->m_gs_textures_handler.m_custom_list.m_container._M_impl._M_start);
  v18 = thisa->m_gs_textures_handler.m_custom_list.m_container._M_impl._M_start;
  if ( v18 )
  {
    v19 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v19, v18);
  }
  v20 = thisa->m_gs_textures_handler.m_current.m_object;
  if ( v20 )
  {
    if ( !--v20->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_gs_textures_handler.m_current.m_object);
  }
  v21 = thisa->m_gs_constants_handler.m_current.m_object;
  if ( v21 )
  {
    if ( !--v21->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_gs_constants_handler.m_current.m_object);
  }
  v22 = thisa->m_vs_samplers_handler.m_current.m_object;
  if ( v22 )
  {
    if ( !--v22->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_vs_samplers_handler.m_current.m_object);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>(
    (stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>)thisa->m_vs_textures_handler.m_custom_list.m_container._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>)thisa->m_vs_textures_handler.m_custom_list.m_container._M_impl._M_start);
  v23 = thisa->m_vs_textures_handler.m_custom_list.m_container._M_impl._M_start;
  if ( v23 )
  {
    v24 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v24, v23);
  }
  v25 = thisa->m_vs_textures_handler.m_current.m_object;
  if ( v25 )
  {
    v26 = v25->m_reference_count-- == 1;
    if ( v26 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_vs_textures_handler.m_current.m_object);
  }
  v27 = thisa->m_vs_constants_handler.m_current.m_object;
  if ( v27 )
  {
    v26 = v27->m_reference_count-- == 1;
    if ( v26 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_vs_constants_handler.m_current.m_object);
  }
  v28 = thisa->index.m_buffer.m_object;
  if ( v28 )
  {
    v26 = v28->m_reference_count-- == 1;
    if ( v26 )
    {
      v29 = (vostok::render::res_state *)thisa->index.m_buffer.m_object;
      v30 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      if ( vostok::render::reclaim<vostok::render::untyped_buffer>(
             (vostok::render::vector<vostok::render::res_state *> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_game,
             v29) )
      {
        v30[2].m_options = (survarium::options_item_base **)((char *)v30[2].m_options
                                                           - (unsigned int)v29->m_depth_stencil_state);
        m_rasterizer_state = v29->m_rasterizer_state;
        v32 = vostok::render::g_allocator.m_object;
        if ( m_rasterizer_state )
        {
          m_rasterizer_state->Release(v29->m_rasterizer_state);
          v29->m_rasterizer_state = 0;
        }
        BYTE2(v32->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v32->m_reconstruction_info_actuality_tick), v29);
      }
    }
  }
  v33 = thisa->vertex.m_buffer.m_object;
  if ( v33 )
  {
    v26 = v33->m_reference_count-- == 1;
    if ( v26 )
    {
      v34 = (vostok::render::res_state *)thisa->vertex.m_buffer.m_object;
      v35 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      if ( vostok::render::reclaim<vostok::render::untyped_buffer>(
             (vostok::render::vector<vostok::render::res_state *> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_game,
             v34) )
      {
        v35[2].m_options = (survarium::options_item_base **)((char *)v35[2].m_options
                                                           - (unsigned int)v34->m_depth_stencil_state);
        v36 = v34->m_rasterizer_state;
        v37 = vostok::render::g_allocator.m_object;
        if ( v36 )
        {
          v36->Release(v34->m_rasterizer_state);
          v34->m_rasterizer_state = 0;
        }
        BYTE2(v37->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v37->m_reconstruction_info_actuality_tick), v34);
      }
    }
  }
  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name = 0;
}
