void __thiscall vostok::render::stage_clouds::~stage_clouds(
        vostok::render::stage_clouds *this,
        vostok::render::stage_clouds *thisa)
{
  boost::detail::function::vtable_base *vtable; // eax
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::render::res_geometry *m_object; // eax
  bool v6; // zf
  vostok::render::untyped_buffer *v7; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned int *p_target_key_index; // eax
  vostok::render::box_geometry *v10; // ecx
  vostok::render::res_texture *v11; // ecx
  vostok::render::res_effect *v12; // eax
  vostok::render::res_effect *v13; // eax
  vostok::render::res_effect *v14; // eax
  vostok::render::res_effect *v15; // eax
  vostok::render::res_texture *v16; // eax
  vostok::render::res_texture *v17; // eax
  vostok::render::stage_clouds *p_m_3d_clouds_density_texture_left; // esi
  int v19; // eax
  vostok::render::stage_clouds_vtbl *v20; // ebp
  survarium::options_tab *v21; // edi
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v22; // eax
  stlp_std::priv::_Rb_tree_node_base *v23; // eax
  void *v24; // esi
  vostok::render::grass_render_model *v25; // edi
  _BYTE *v26; // esi
  void *v27; // eax
  void *v28; // esi
  int i; // [esp+10h] [ebp-8h]
  void (__thiscall *v30)(struct vostok::render::stage_clouds *); // [esp+14h] [ebp-4h] BYREF
  vostok::render::stage_clouds *thisb; // [esp+1Ch] [ebp+4h]

  thisa->__vftable = (vostok::render::stage_clouds_vtbl *)&stru_965008.m_rescale_min.elements[3];
  vostok::tasks::thread_pool::wait_for_task_list((vostok::tasks::thread_pool *)this, &thisa->m_parent_task);
  vtable = thisa->m_parent_task.m_function.vtable;
  if ( vtable )
  {
    if ( ((unsigned __int8)vtable & 1) == 0 )
    {
      v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((unsigned int)vtable & 0xFFFFFFFE);
      if ( v4 )
        v4(&thisa->m_parent_task.m_function.functor, &thisa->m_parent_task.m_function.functor, 2);
    }
    thisa->m_parent_task.m_function.vtable = 0;
  }
  m_object = thisa->m_screen_vertex_geometry.m_object;
  if ( m_object )
  {
    v6 = m_object->m_reference_count-- == 1;
    if ( v6 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_screen_vertex_geometry.m_object);
  }
  v7 = thisa->m_screen_vertex_ib.m_object;
  if ( v7 )
  {
    v6 = v7->m_reference_count-- == 1;
    if ( v6 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)thisa->m_screen_vertex_ib.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  p_target_key_index = &thisa->m_environment.keys[-1].target_key_index;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(m_reconstruction_info_actuality_tick_high, p_target_key_index);
  vostok::render::box_geometry::~box_geometry(v10, (int)&thisa->m_evaluate_geometry);
  v12 = thisa->m_ss_god_rays_effect.m_object;
  if ( v12 && !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_ss_god_rays_effect.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_ss_god_rays_effect.m_object);
  v13 = thisa->m_god_rays_effect.m_object;
  if ( v13 )
  {
    v11 = (vostok::render::res_texture *)_InterlockedExchangeAdd(&v13->m_reference_count, 0xFFFFFFFF);
    if ( !v11 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &thisa->m_god_rays_effect.m_object->vostok::resources::unmanaged_intrusive_base,
        thisa->m_god_rays_effect.m_object);
  }
  v14 = thisa->m_read_cloud_base_effect.m_object;
  if ( v14 && !_InterlockedExchangeAdd(&v14->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_read_cloud_base_effect.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_read_cloud_base_effect.m_object);
  v15 = thisa->m_clouds_effect.m_object;
  if ( v15 )
  {
    v11 = (vostok::render::res_texture *)_InterlockedExchangeAdd(&v15->m_reference_count, 0xFFFFFFFF);
    if ( !v11 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &thisa->m_clouds_effect.m_object->vostok::resources::unmanaged_intrusive_base,
        thisa->m_clouds_effect.m_object);
  }
  v16 = thisa->m_3d_clouds_density_texture_right.m_object;
  if ( v16 )
  {
    v6 = v16->m_reference_count-- == 1;
    if ( v6 )
      vostok::render::res_texture::destroy_impl(v11, thisa->m_3d_clouds_density_texture_right.m_object);
  }
  v17 = thisa->m_3d_clouds_density_texture_left.m_object;
  if ( v17 )
  {
    v6 = v17->m_reference_count-- == 1;
    if ( v6 )
      vostok::render::res_texture::destroy_impl(v11, thisa->m_3d_clouds_density_texture_left.m_object);
  }
  p_m_3d_clouds_density_texture_left = (vostok::render::stage_clouds *)&thisa->m_3d_clouds_density_texture_left;
  for ( i = 1; i >= 0; --i )
  {
    v19 = *((_DWORD *)&p_m_3d_clouds_density_texture_left[-1].m_prev_up_vector + 3);
    p_m_3d_clouds_density_texture_left = (vostok::render::stage_clouds *)((char *)p_m_3d_clouds_density_texture_left - 4);
    thisb = p_m_3d_clouds_density_texture_left;
    if ( v19 )
    {
      v6 = (*(_DWORD *)(v19 + 4))-- == 1;
      if ( v6 )
      {
        v20 = p_m_3d_clouds_density_texture_left->__vftable;
        if ( HIBYTE(p_m_3d_clouds_density_texture_left->__vftable[18].execute) )
        {
          v21 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
          v30 = v20[6].~vostok::render::stage_clouds;
          v22 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>((stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v11, (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7], (const char **)&v30);
          if ( v22 != (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v21 )
          {
            v23 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
                    &v22->_M_header._M_data,
                    (stlp_std::priv::_Rb_tree_node_base **)&v21->m_options_count,
                    (stlp_std::priv::_Rb_tree_node_base **)&v21->m_type,
                    (stlp_std::priv::_Rb_tree_node_base **)&v21->m_game);
            if ( v23 )
            {
              v24 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(v24, v23);
            }
            --v21->m_movie;
            v25 = vostok::render::g_allocator.m_object;
            v26 = __RTCastToVoid((void **)&v20->~vostok::render::stage_clouds);
            (*(void (__thiscall **)(vostok::render::stage_clouds_vtbl *, _DWORD))v20->~vostok::render::stage_clouds)(
              v20,
              0);
            if ( v26 )
            {
              v27 = v26;
              v28 = (void *)HIDWORD(v25->m_reconstruction_info_actuality_tick);
              BYTE2(v25->m_children_resources.m_lock) = 0;
              vostok_mspace_free(v28, v27);
            }
            p_m_3d_clouds_density_texture_left = thisb;
          }
        }
      }
    }
  }
  thisa->__vftable = (vostok::render::stage_clouds_vtbl *)&vostok::render::stage::`vftable';
}
