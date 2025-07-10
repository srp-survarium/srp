void __thiscall vostok::render::system_renderer::~system_renderer(
        vostok::render::system_renderer *this,
        vostok::render::system_renderer *thisa)
{
  vostok::render::res_state **p_m_grid_mode; // esi
  int i; // ebp
  _DWORD *v4; // eax
  bool v5; // zf
  vostok::render::res_texture *m_object; // eax
  vostok::render::res_texture *v7; // eax
  vostok::render::res_geometry *v8; // eax
  vostok::render::res_geometry *v9; // eax
  vostok::render::res_geometry *v10; // eax
  vostok::render::res_effect *v11; // eax
  vostok::render::res_effect *v12; // eax
  vostok::resources::unmanaged_resource **p_m_object; // esi
  int j; // edi
  int v15; // eax
  vostok::render::res_effect *v16; // eax
  vostok::render::res_effect *v17; // eax
  vostok::render::res_effect *v18; // eax
  vostok::render::res_effect *v19; // eax
  vostok::render::res_effect *v20; // eax
  vostok::render::res_effect *v21; // eax
  vostok::render::untyped_buffer *v22; // eax
  vostok::render::untyped_buffer *v23; // eax
  vostok::render::untyped_buffer *v24; // eax
  vostok::render::untyped_buffer *v25; // eax
  vostok::render::res_geometry *v26; // eax
  vostok::render::res_effect *v27; // eax
  vostok::render::res_geometry *v28; // eax
  vostok::render::untyped_buffer *v29; // eax

  p_m_grid_mode = (vostok::render::res_state **)&thisa->m_grid_mode;
  for ( i = 1; i >= 0; --i )
  {
    v4 = *--p_m_grid_mode;
    if ( v4 )
    {
      v5 = (*v4)-- == 1;
      if ( v5 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          *p_m_grid_mode);
    }
  }
  m_object = thisa->m_grid_texture_50.m_object;
  if ( m_object )
  {
    v5 = m_object->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this, thisa->m_grid_texture_50.m_object);
  }
  v7 = thisa->m_grid_texture_25.m_object;
  if ( v7 )
  {
    v5 = v7->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this, thisa->m_grid_texture_25.m_object);
  }
  v8 = thisa->m_ui_geom.m_object;
  if ( v8 )
  {
    v5 = v8->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_ui_geom.m_object);
  }
  v9 = thisa->m_grid_geom.m_object;
  if ( v9 )
  {
    v5 = v9->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_grid_geom.m_object);
  }
  v10 = thisa->m_colored_geom.m_object;
  if ( v10 )
  {
    v5 = v10->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_colored_geom.m_object);
  }
  v11 = thisa->m_editor_model_ghost_shader.m_object;
  if ( v11 && !_InterlockedExchangeAdd(&v11->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_editor_model_ghost_shader.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_editor_model_ghost_shader.m_object);
  v12 = thisa->m_speedtree_selection_shader.m_object;
  p_m_object = &thisa->m_speedtree_selection_shader.m_object;
  if ( v12 && !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &(*p_m_object)->vostok::resources::unmanaged_intrusive_base,
      *p_m_object);
  for ( j = 14; j >= 0; --j )
  {
    v15 = (int)*--p_m_object;
    if ( v15 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v15 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &(*p_m_object)->vostok::resources::unmanaged_intrusive_base,
        *p_m_object);
  }
  v16 = thisa->m_notexture_shader.m_object;
  if ( v16 && !_InterlockedExchangeAdd(&v16->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_notexture_shader.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_notexture_shader.m_object);
  v17 = thisa->m_sh_ui.m_object;
  if ( v17 && !_InterlockedExchangeAdd(&v17->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_sh_ui.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_sh_ui.m_object);
  v18 = thisa->m_sh_grid_50.m_object;
  if ( v18 && !_InterlockedExchangeAdd(&v18->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_sh_grid_50.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_sh_grid_50.m_object);
  v19 = thisa->m_sh_grid_25.m_object;
  if ( v19 && !_InterlockedExchangeAdd(&v19->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_sh_grid_25.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_sh_grid_25.m_object);
  v20 = thisa->m_sh_vcolor.m_object;
  if ( v20 && !_InterlockedExchangeAdd(&v20->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_sh_vcolor.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_sh_vcolor.m_object);
  v21 = thisa->m_sh_particle_selection.m_object;
  if ( v21 && !_InterlockedExchangeAdd(&v21->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_sh_particle_selection.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_sh_particle_selection.m_object);
  v22 = thisa->m_index_stream_quad.m_buffer.m_object;
  if ( v22 )
  {
    v5 = v22->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)thisa->m_index_stream_quad.m_buffer.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v23 = thisa->m_vertex_stream_quad.m_buffer.m_object;
  if ( v23 )
  {
    v5 = v23->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)thisa->m_vertex_stream_quad.m_buffer.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v24 = thisa->m_index_stream.m_buffer.m_object;
  if ( v24 )
  {
    v5 = v24->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)thisa->m_index_stream.m_buffer.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v25 = thisa->m_vertex_stream.m_buffer.m_object;
  if ( v25 )
  {
    v5 = v25->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)thisa->m_vertex_stream.m_buffer.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v26 = thisa->m_colored_geom_sl.m_object;
  if ( v26 )
  {
    v5 = v26->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_colored_geom_sl.m_object);
  }
  v27 = thisa->m_sh_sl.m_object;
  if ( v27 && !_InterlockedExchangeAdd(&v27->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_sh_sl.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_sh_sl.m_object);
  if ( thisa->m_render_model_to_material._M_t._M_node_count )
  {
    stlp_std::priv::_Rb_tree<vostok::render::render_model_instance *,stlp_std::less<vostok::render::render_model_instance *>,stlp_std::pair<vostok::render::render_model_instance * const,vostok::render::material_effects>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_model_instance * const,vostok::render::material_effects>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_model_instance * const,vostok::render::material_effects>>,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_model_instance *,vostok::render::material_effects>>>::_M_erase(
      &thisa->m_render_model_to_material._M_t,
      thisa->m_render_model_to_material._M_t._M_header._M_data._M_parent);
    thisa->m_render_model_to_material._M_t._M_header._M_data._M_left = &thisa->m_render_model_to_material._M_t._M_header._M_data;
    thisa->m_render_model_to_material._M_t._M_header._M_data._M_parent = 0;
    thisa->m_render_model_to_material._M_t._M_header._M_data._M_right = &thisa->m_render_model_to_material._M_t._M_header._M_data;
    thisa->m_render_model_to_material._M_t._M_node_count = 0;
  }
  v28 = thisa->m_screen_vertex_geometry.m_object;
  if ( v28 )
  {
    v5 = v28->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_screen_vertex_geometry.m_object);
  }
  v29 = thisa->m_screen_vertex_ib.m_object;
  if ( v29 && (v5 = v29->m_reference_count == 1, --v29->m_reference_count, v5) )
  {
    vostok::render::resource_manager::release(
      (vostok::render::res_state *)thisa->m_screen_vertex_ib.m_object,
      (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x = 0;
  }
  else
  {
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x = 0;
  }
}
