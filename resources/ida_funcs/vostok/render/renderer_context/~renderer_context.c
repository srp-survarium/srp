void __thiscall vostok::render::renderer_context::~renderer_context(
        vostok::render::renderer_context *this,
        vostok::render::renderer_context *thisa)
{
  vostok::render::res_texture *m_begin; // ecx
  vostok::render::base_scene_view *m_object; // eax
  vostok::render::speedtree_forest::tree_render_info *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::sun_cascade *i; // eax
  vostok::render::res_texture *v8; // eax
  bool v9; // zf
  vostok::render::untyped_buffer *v10; // eax
  vostok::render::res_geometry *v11; // eax
  vostok::render::res_geometry *v12; // eax
  vostok::render::res_geometry *v13; // eax
  vostok::render::res_texture *v14; // eax
  char *v15; // ebx
  int v16; // eax
  _BYTE *v17; // ebp
  survarium::options_tab *v18; // edi
  stlp_std::priv::_Rb_tree_node_base *v19; // eax
  stlp_std::priv::_Rb_tree_node_base *v20; // eax
  void *v21; // esi
  vostok::render::grass_render_model *v22; // edi
  void *v23; // esi
  void *v24; // eax
  void *v25; // esi
  vostok::render::resource_manager *v26; // eax
  int thisb; // [esp+1Ch] [ebp+4h]

  thisa->m_p_stack.m_end = thisa->m_p_stack.m_begin;
  m_begin = (vostok::render::res_texture *)thisa->m_v_stack.m_begin;
  thisa->m_v_stack.m_end = (vostok::math::float4x4 *)m_begin;
  thisa->m_w_stack.m_end = thisa->m_w_stack.m_begin;
  m_object = thisa->m_scene_view.m_object;
  if ( m_object )
  {
    m_begin = (vostok::render::res_texture *)_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF);
    if ( !m_begin )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &thisa->m_scene_view.m_object->vostok::resources::unmanaged_intrusive_base,
        thisa->m_scene_view.m_object);
  }
  M_start = thisa->m_visible_trees._M_impl._M_start;
  if ( M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
  }
  for ( i = thisa->m_sun_cascades.m_begin; i != thisa->m_sun_cascades.m_end; ++i )
    i->rays.m_end = i->rays.m_begin;
  thisa->m_sun_cascades.m_end = thisa->m_sun_cascades.m_begin;
  v8 = thisa->m_t_shadow_cascade.m_object;
  if ( v8 )
  {
    v9 = v8->m_reference_count-- == 1;
    if ( v9 )
      vostok::render::res_texture::destroy_impl(m_begin);
  }
  v10 = thisa->m_quad_ib.m_object;
  if ( v10 )
  {
    v9 = v10->m_reference_count-- == 1;
    if ( v9 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_quad_ib.m_object);
  }
  v11 = thisa->m_g_quad_eye_ray.m_object;
  if ( v11 )
  {
    v9 = v11->m_reference_count-- == 1;
    if ( v9 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_g_quad_eye_ray.m_object);
  }
  v12 = thisa->m_g_quad_2uv.m_object;
  if ( v12 )
  {
    v9 = v12->m_reference_count-- == 1;
    if ( v9 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_g_quad_2uv.m_object);
  }
  v13 = thisa->m_g_quad_uv.m_object;
  if ( v13 )
  {
    v9 = v13->m_reference_count-- == 1;
    if ( v9 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_g_quad_uv.m_object);
  }
  v14 = thisa->m_t_null.m_object;
  if ( v14 )
  {
    v9 = v14->m_reference_count-- == 1;
    if ( v9 )
      vostok::render::res_texture::destroy_impl(m_begin);
  }
  thisb = 69;
  v15 = &thisa->m_sun_cascades.m_buffer[0].m_store[100];
  do
  {
    v16 = *((_DWORD *)v15 - 39);
    v15 -= 160;
    if ( v16 )
    {
      v9 = (*(_DWORD *)(v16 + 4))-- == 1;
      if ( v9 )
      {
        v17 = (_BYTE *)*((_DWORD *)v15 + 1);
        if ( v17[439] )
        {
          v18 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
          v19 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                  (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)m_begin,
                  (const char *const *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7]);
          if ( v19 != (stlp_std::priv::_Rb_tree_node_base *)v18 )
          {
            v20 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
                    v19,
                    (stlp_std::priv::_Rb_tree_node_base **)&v18->m_options_count,
                    (stlp_std::priv::_Rb_tree_node_base **)&v18->m_type,
                    (stlp_std::priv::_Rb_tree_node_base **)&v18->m_game);
            if ( v20 )
            {
              v21 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(v21, v20);
            }
            --v18->m_movie;
            v22 = vostok::render::g_allocator.m_object;
            v23 = __RTCastToVoid(v17);
            (**(void (__thiscall ***)(_BYTE *, _DWORD))v17)(v17, 0);
            if ( v23 )
            {
              v24 = v23;
              v25 = (void *)HIDWORD(v22->m_reconstruction_info_actuality_tick);
              BYTE2(v22->m_children_resources.m_lock) = 0;
              vostok_mspace_free(v25, v24);
            }
          }
        }
      }
    }
    v26 = *(vostok::render::resource_manager **)v15;
    if ( *(_DWORD *)v15 )
    {
      v9 = v26->sh_created-- == 1;
      if ( v9 )
        vostok::render::resource_manager::release(
          *(vostok::render::resource_manager **)v15,
          (const vostok::render::render_target *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
    }
    --thisb;
  }
  while ( thisb >= 0 );
}
