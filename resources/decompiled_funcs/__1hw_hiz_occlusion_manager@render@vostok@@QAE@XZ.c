void __thiscall vostok::render::hw_hiz_occlusion_manager::~hw_hiz_occlusion_manager(
        vostok::render::hw_hiz_occlusion_manager *this,
        vostok::render::hw_hiz_occlusion_manager *thisa)
{
  vostok::render::hw_hiz_occlusion_manager *v2; // ebp
  vostok::render::untyped_buffer *m_object; // eax
  bool v4; // zf
  vostok::render::res_declaration *v5; // eax
  vostok::render::res_texture *v6; // eax
  vostok::render::res_texture *v7; // eax
  vostok::render::render_target *v8; // eax
  vostok::render::res_geometry *v9; // eax
  vostok::render::res_texture *v10; // eax
  vostok::render::res_texture *v11; // eax
  vostok::render::res_texture *v12; // eax
  vostok::render::render_target *v13; // eax
  const char **p_m_ds_occlusion_depth; // esi
  int i; // edi
  _DWORD *v16; // eax
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *m_rt_depth_mips; // ebx
  vostok::render::render_target *v18; // eax
  vostok::render::render_target *v19; // ebp
  survarium::options_tab *v20; // edi
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v21; // eax
  stlp_std::priv::_Rb_tree_node_base *v22; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::grass_render_model *v24; // edi
  char *v25; // esi
  char *v26; // eax
  malloc_state *v27; // esi
  vostok::render::resource_manager **m_t_depth_mips_work; // esi
  int k; // edi
  _DWORD *v30; // eax
  vostok::render::res_effect *v31; // eax
  int j; // [esp+10h] [ebp-8h]
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *m_rt; // [esp+14h] [ebp-4h] BYREF

  v2 = thisa;
  m_object = thisa->m_hw_hiz_point_list.m_vertex_buffer.m_object;
  if ( m_object )
  {
    v4 = m_object->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)thisa->m_hw_hiz_point_list.m_vertex_buffer.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v5 = thisa->m_hw_hiz_point_list.m_declaration.m_object;
  if ( v5 )
  {
    v4 = v5->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_hw_hiz_point_list.m_declaration.m_object);
  }
  v6 = thisa->m_t_culling_result_lockable.m_object;
  if ( v6 )
  {
    v4 = v6->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(
        (vostok::render::res_texture *)this,
        thisa->m_t_culling_result_lockable.m_object);
  }
  v7 = thisa->m_t_culling_result.m_object;
  if ( v7 )
  {
    v4 = v7->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this, thisa->m_t_culling_result.m_object);
  }
  v8 = thisa->m_rt_culling_result.m_object;
  if ( v8 )
  {
    v4 = v8->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)thisa->m_rt_culling_result.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_rt_culling_result.m_object);
  }
  v9 = thisa->m_sphere_occluder_geometry.m_geometry.m_object;
  if ( v9 )
  {
    v4 = v9->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_sphere_occluder_geometry.m_geometry.m_object);
  }
  v10 = thisa->m_t_depth_mips_lockable.m_object;
  if ( v10 )
  {
    v4 = v10->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(
        (vostok::render::res_texture *)this,
        thisa->m_t_depth_mips_lockable.m_object);
  }
  v11 = thisa->m_t_depth_mips_copy.m_object;
  if ( v11 )
  {
    v4 = v11->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(
        (vostok::render::res_texture *)this,
        thisa->m_t_depth_mips_copy.m_object);
  }
  v12 = thisa->m_t_depth_mips.m_object;
  if ( v12 )
  {
    v4 = v12->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this, thisa->m_t_depth_mips.m_object);
  }
  v13 = thisa->m_ds_occlusion_depth.m_object;
  p_m_ds_occlusion_depth = (const char **)&thisa->m_ds_occlusion_depth;
  if ( v13 )
  {
    v4 = v13->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *p_m_ds_occlusion_depth);
  }
  for ( i = 15; i >= 0; --i )
  {
    v16 = *--p_m_ds_occlusion_depth;
    if ( v16 )
    {
      v4 = (*v16)-- == 1;
      if ( v4 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)this,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          *p_m_ds_occlusion_depth);
    }
  }
  m_rt_depth_mips = thisa->m_rt_depth_mips;
  for ( j = 15; j >= 0; --j )
  {
    v18 = m_rt_depth_mips[-1].m_object;
    --m_rt_depth_mips;
    if ( v18 )
    {
      v4 = v18->m_name.m_pointer.m_object-- == (vostok::strings::shared::profile *)1;
      if ( v4 )
      {
        v19 = m_rt_depth_mips->m_object;
        if ( HIBYTE(m_rt_depth_mips->m_object[6].m_order) )
        {
          v20 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
          m_rt = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v19[2].m_rt;
          v21 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(m_rt, (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7], (const char **)&m_rt);
          if ( v21 != (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v20 )
          {
            v22 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
                    &v21->_M_header._M_data,
                    (stlp_std::priv::_Rb_tree_node_base **)&v20->m_options_count,
                    (stlp_std::priv::_Rb_tree_node_base **)&v20->m_type,
                    (stlp_std::priv::_Rb_tree_node_base **)&v20->m_game);
            if ( v22 )
            {
              m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (char *)&v22->_M_color);
            }
            --v20->m_movie;
            v24 = vostok::render::g_allocator.m_object;
            v25 = __RTCastToVoid((void **)v19);
            (*(void (__thiscall **)(vostok::render::render_target *, _DWORD))v19->m_reference_count)(v19, 0);
            if ( v25 )
            {
              v26 = v25;
              v27 = (malloc_state *)HIDWORD(v24->m_reconstruction_info_actuality_tick);
              BYTE2(v24->m_children_resources.m_lock) = 0;
              vostok_mspace_free(v27, v26);
            }
          }
        }
        v2 = thisa;
      }
    }
  }
  m_t_depth_mips_work = (vostok::render::resource_manager **)v2->m_t_depth_mips_work;
  for ( k = 15; k >= 0; --k )
  {
    v30 = *--m_t_depth_mips_work;
    if ( v30 )
    {
      v4 = (*v30)-- == 1;
      if ( v4 )
        vostok::render::resource_manager::release(
          *m_t_depth_mips_work,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)*m_t_depth_mips_work);
    }
  }
  v31 = v2->m_hiz_occlusion_effect.m_object;
  if ( v31 )
  {
    if ( !_InterlockedExchangeAdd(&v31->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &v2->m_hiz_occlusion_effect.m_object->vostok::resources::unmanaged_intrusive_base,
        v2->m_hiz_occlusion_effect.m_object);
  }
}
