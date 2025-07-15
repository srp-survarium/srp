void __thiscall vostok::render::stage_light_propagation_volumes::~stage_light_propagation_volumes(
        vostok::render::stage_light_propagation_volumes *this,
        vostok::render::stage_light_propagation_volumes *thisa)
{
  vostok::render::stage_light_propagation_volumes *v2; // ebp
  unsigned int v3; // esi
  int v4; // edi
  vostok::render::radiance_volume *m_radiance_volume; // eax
  vostok::render::resource_manager *m_object; // ecx
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::res_geometry *v8; // eax
  vostok::render::untyped_buffer *v9; // eax
  vostok::render::res_state *v10; // edi
  survarium::options_tab *v11; // ebx
  ID3D11RasterizerState *m_rasterizer_state; // eax
  vostok::render::grass_render_model *v13; // esi
  vostok::render::res_effect *v14; // eax
  vostok::render::res_effect *v15; // eax
  vostok::render::res_effect *v16; // eax
  vostok::resources::unmanaged_resource **p_m_object; // esi
  int i; // edi
  int v19; // eax
  const char **m_fill_rsm_effect; // esi
  int j; // edi
  _DWORD *v22; // eax
  void **v23; // edi
  int k; // ebx
  stlp_std::reverse_iterator<survarium::game_world::bullet_tracer *> v25; // ecx
  stlp_std::reverse_iterator<survarium::game_world::bullet_tracer *> v26; // eax
  void *v27; // eax
  void *v28; // esi
  vostok::render::res_texture *v29; // eax
  bool v30; // zf
  vostok::render::res_texture *v31; // esi
  survarium::options_tab *v32; // edi
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v33; // eax
  vostok::render::render_target *v34; // eax
  vostok::render::untyped_buffer *v35; // eax
  vostok::render::res_state *v36; // edi
  survarium::options_tab *v37; // ebx
  ID3D11RasterizerState *v38; // eax
  vostok::render::grass_render_model *v39; // esi
  vostok::render::untyped_buffer *v40; // eax
  vostok::render::res_state *v41; // edi
  survarium::options_tab *v42; // ebx
  ID3D11RasterizerState *v43; // eax
  vostok::render::grass_render_model *v44; // esi
  vostok::render::res_declaration *v45; // eax
  _BYTE v46[20]; // [esp-4h] [ebp-14h] BYREF

  v2 = thisa;
  v3 = 0;
  thisa->__vftable = (vostok::render::stage_light_propagation_volumes_vtbl *)&stru_964DF4.m_name;
  if ( v2->m_num_cascades )
  {
    v4 = 0;
    do
    {
      vostok::render::radiance_volume::~radiance_volume(
        (vostok::render::radiance_volume *)this,
        &v2->m_radiance_volume[v4]);
      ++v3;
      ++v4;
    }
    while ( v3 < v2->m_num_cascades );
  }
  m_radiance_volume = v2->m_radiance_volume;
  m_object = (vostok::render::resource_manager *)vostok::render::g_allocator.m_object;
  if ( m_radiance_volume )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, m_radiance_volume);
    v2->m_radiance_volume = 0;
  }
  v8 = v2->m_screen_vertex_geometry.m_object;
  if ( v8 )
  {
    if ( !--v8->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v2->m_screen_vertex_geometry.m_object);
  }
  v9 = v2->m_screen_vertex_ib.m_object;
  if ( v9 )
  {
    if ( !--v9->m_reference_count )
    {
      v10 = (vostok::render::res_state *)v2->m_screen_vertex_ib.m_object;
      v11 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      if ( vostok::render::reclaim<vostok::render::untyped_buffer>(
             (vostok::render::vector<vostok::render::res_state *> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_game,
             v10) )
      {
        v11[2].m_options = (survarium::options_item_base **)((char *)v11[2].m_options
                                                           - (unsigned int)v10->m_depth_stencil_state);
        m_rasterizer_state = v10->m_rasterizer_state;
        v13 = vostok::render::g_allocator.m_object;
        if ( m_rasterizer_state )
        {
          m_rasterizer_state->Release(v10->m_rasterizer_state);
          v10->m_rasterizer_state = 0;
        }
        BYTE2(v13->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v13->m_reconstruction_info_actuality_tick), v10);
      }
    }
  }
  v14 = v2->m_downsample_gbuffer_effect.m_object;
  if ( v14 )
  {
    m_object = (vostok::render::resource_manager *)_InterlockedExchangeAdd(&v14->m_reference_count, 0xFFFFFFFF);
    if ( !m_object )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &v2->m_downsample_gbuffer_effect.m_object->vostok::resources::unmanaged_intrusive_base,
        v2->m_downsample_gbuffer_effect.m_object);
  }
  v15 = v2->m_apply_indirect_lighting_effect.m_object;
  if ( v15 && !_InterlockedExchangeAdd(&v15->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &v2->m_apply_indirect_lighting_effect.m_object->vostok::resources::unmanaged_intrusive_base,
      v2->m_apply_indirect_lighting_effect.m_object);
  v16 = v2->m_downsample_rsm_effect.m_object;
  p_m_object = &v2->m_downsample_rsm_effect.m_object;
  if ( v16 )
  {
    m_object = (vostok::render::resource_manager *)_InterlockedExchangeAdd(&v16->m_reference_count, 0xFFFFFFFF);
    if ( !m_object )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &(*p_m_object)->vostok::resources::unmanaged_intrusive_base,
        *p_m_object);
  }
  for ( i = 14; i >= 0; --i )
  {
    v19 = (int)*--p_m_object;
    if ( v19 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v19 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &(*p_m_object)->vostok::resources::unmanaged_intrusive_base,
        *p_m_object);
  }
  m_fill_rsm_effect = (const char **)v2->m_fill_rsm_effect;
  for ( j = 3; j >= 0; --j )
  {
    v22 = *--m_fill_rsm_effect;
    if ( v22 )
    {
      if ( !--*v22 )
        vostok::render::resource_manager::release(
          m_object,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          *m_fill_rsm_effect);
    }
  }
  v23 = (void **)&v2->m_rms_depth_stencil_source[0].m_object;
  for ( k = 3; k >= 0; --k )
  {
    v25.current = (survarium::game_world::bullet_tracer *)*(v23 - 2);
    v26.current = (survarium::game_world::bullet_tracer *)*(v23 - 3);
    v23 -= 3;
    stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<survarium::game_world::bullet_tracer *>,survarium::game_world::bullet_tracer>(
      v25,
      v26);
    v27 = *v23;
    if ( *v23 )
    {
      v28 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v28, v27);
    }
  }
  v29 = v2->m_t_downsampled_scene.m_object;
  if ( v29 )
  {
    v30 = v29->m_reference_count-- == 1;
    if ( v30 )
    {
      v31 = v2->m_t_downsampled_scene.m_object;
      if ( v31->m_is_registered )
      {
        v32 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
        thisa = (vostok::render::stage_light_propagation_volumes *)v31->m_name.m_string.m_begin;
        v33 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)thisa,
                (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7],
                (const char **)&thisa);
        if ( v33 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v32 )
        {
          stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
            (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)v46,
            (int)v32,
            (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v33);
          vostok::render::resource_manager::release_impl(v31, *(vostok::render::resource_manager **)&v46[4]);
        }
      }
    }
  }
  v34 = v2->m_rt_downsampled_scene.m_object;
  if ( v34 )
  {
    v30 = v34->m_reference_count-- == 1;
    if ( v30 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)v2->m_rt_downsampled_scene.m_object);
  }
  v35 = v2->m_box_geometry.m_index_buffer.m_object;
  if ( v35 )
  {
    v30 = v35->m_reference_count-- == 1;
    if ( v30 )
    {
      v36 = (vostok::render::res_state *)v2->m_box_geometry.m_index_buffer.m_object;
      v37 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      if ( vostok::render::reclaim<vostok::render::untyped_buffer>(
             (vostok::render::vector<vostok::render::res_state *> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_game,
             v36) )
      {
        v37[2].m_options = (survarium::options_item_base **)((char *)v37[2].m_options
                                                           - (unsigned int)v36->m_depth_stencil_state);
        v38 = v36->m_rasterizer_state;
        v39 = vostok::render::g_allocator.m_object;
        if ( v38 )
        {
          v38->Release(v36->m_rasterizer_state);
          v36->m_rasterizer_state = 0;
        }
        BYTE2(v39->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v39->m_reconstruction_info_actuality_tick), v36);
      }
    }
  }
  v40 = v2->m_box_geometry.m_vertex_buffer.m_object;
  if ( v40 )
  {
    v30 = v40->m_reference_count-- == 1;
    if ( v30 )
    {
      v41 = (vostok::render::res_state *)v2->m_box_geometry.m_vertex_buffer.m_object;
      v42 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      if ( vostok::render::reclaim<vostok::render::untyped_buffer>(
             (vostok::render::vector<vostok::render::res_state *> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_game,
             v41) )
      {
        v42[2].m_options = (survarium::options_item_base **)((char *)v42[2].m_options
                                                           - (unsigned int)v41->m_depth_stencil_state);
        v43 = v41->m_rasterizer_state;
        v44 = vostok::render::g_allocator.m_object;
        if ( v43 )
        {
          v43->Release(v41->m_rasterizer_state);
          v41->m_rasterizer_state = 0;
        }
        BYTE2(v44->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v44->m_reconstruction_info_actuality_tick), v41);
      }
    }
  }
  v45 = v2->m_box_geometry.m_vertext_declaration.m_object;
  if ( v45 )
  {
    v30 = v45->m_reference_count-- == 1;
    if ( v30 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v2->m_box_geometry.m_vertext_declaration.m_object);
  }
  v2->__vftable = (vostok::render::stage_light_propagation_volumes_vtbl *)&vostok::render::stage::`vftable';
}
