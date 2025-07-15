void __thiscall vostok::render::grass_patch::~grass_patch(
        vostok::render::grass_patch *this,
        vostok::render::grass_patch *thisa)
{
  vostok::render::grass_render_model *m_object; // ecx
  vostok::render::grass_patch *v3; // ebx
  vostok::render::grass_patch::sort_info **m_sort_info; // edi
  int v5; // ebp
  void *v6; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::grass_patch::sort_info *v8; // eax
  void *v9; // esi
  vostok::collision::object *m_collision_object; // esi
  vostok::render::grass_render_model *v11; // edi
  _BYTE *v12; // ebp
  void **v13; // esi
  vostok::render::grass_render_model *v14; // edi
  _BYTE *v15; // ebp
  vostok::render::resource_manager *v16; // ecx
  unsigned __int16 **m_merged_indices; // ebx
  _DWORD *v18; // eax
  bool v19; // zf
  void **M_start; // eax
  void **M_finish; // edx
  unsigned __int16 *v22; // esi
  void ***p_M_finish; // edi
  vostok::render::resource_manager *v24; // ebp
  int v25; // eax
  vostok::render::grass_render_model *v26; // edi
  unsigned __int16 *v27; // eax
  void *v28; // esi
  vostok::render::grass_patch *v29; // ebx
  vostok::render::res_geometry **m_vb_stream_1; // esi
  int j; // edi
  _DWORD *v32; // eax
  void **v33; // eax
  void *v34; // esi
  vostok::render::res_texture *v35; // eax
  vostok::render::res_texture *v36; // esi
  int p_m_texture_registry; // edi
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v38; // eax
  vostok::render::render_target *v39; // eax
  stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > v40; // [esp+4h] [ebp-1Ch] BYREF
  int i; // [esp+1Ch] [ebp-4h]

  m_object = vostok::render::g_allocator.m_object;
  v3 = thisa;
  m_sort_info = thisa->m_sort_info;
  v5 = 3;
  do
  {
    v6 = *(m_sort_info - 3);
    if ( v6 )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v6);
      *(m_sort_info - 3) = 0;
      m_object = vostok::render::g_allocator.m_object;
    }
    v8 = *m_sort_info;
    if ( *m_sort_info )
    {
      v9 = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v9, v8);
      *m_sort_info = 0;
      m_object = vostok::render::g_allocator.m_object;
    }
    ++m_sort_info;
    --v5;
  }
  while ( v5 );
  if ( v3->m_collision_tree && v3->m_collision_object )
  {
    v3->m_collision_tree->erase(v3->m_collision_tree, v3->m_collision_object);
    m_object = vostok::render::g_allocator.m_object;
  }
  m_collision_object = v3->m_collision_object;
  v11 = m_object;
  if ( m_collision_object )
  {
    v12 = __RTCastToVoid((void **)&v3->m_collision_object->__vftable);
    ((void (__thiscall *)(vostok::collision::object *, _DWORD))m_collision_object->~vostok::collision::object)(
      m_collision_object,
      0);
    ((void (__thiscall *)(vostok::render::grass_render_model *, _BYTE *))v11->is_increasing_quality)(v11, v12);
    m_object = vostok::render::g_allocator.m_object;
  }
  v13 = (void **)&v3->m_collision_geometry->__vftable;
  v14 = m_object;
  if ( v13 )
  {
    (*(void (__thiscall **)(void **, vostok::render::grass_render_model *))*v13)(v13, m_object);
    v15 = __RTCastToVoid(v13);
    (*((void (__thiscall **)(void **, _DWORD))*v13 + 32))(v13, 0);
    ((void (__thiscall *)(vostok::render::grass_render_model *, _BYTE *))v14->is_increasing_quality)(v14, v15);
  }
  v16 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  m_merged_indices = v3->m_merged_indices;
  for ( i = 2; i >= 0; --i )
  {
    v18 = *--m_merged_indices;
    if ( v18 )
    {
      v19 = (*v18)-- == 1;
      if ( v19 )
      {
        M_start = v16->m_buffers._M_impl._M_start;
        M_finish = v16->m_buffers._M_impl._M_finish;
        v22 = *m_merged_indices;
        p_M_finish = &v16->m_buffers._M_impl._M_finish;
        v24 = v16;
        if ( M_start != M_finish )
        {
          while ( *M_start != v22 )
          {
            if ( ++M_start == M_finish )
              goto LABEL_26;
          }
          if ( M_start + 1 != M_finish )
          {
            *(_DWORD *)&v40._M_t._M_header._M_data._M_color = &v40._M_t._M_key_compare + 3;
            *((_BYTE *)&v40._M_t._M_key_compare + 3) = 0;
            stlp_std::priv::__copy_ptrs<void * *,void * *>(M_start + 1, *p_M_finish, M_start);
          }
          --*p_M_finish;
          v24->m_num_bytes_of_buffers_video_memory -= *((_DWORD *)v22 + 2);
          v25 = *((_DWORD *)v22 + 1);
          v26 = vostok::render::g_allocator.m_object;
          if ( v25 )
          {
            (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v25 + 8))(*((_DWORD *)v22 + 1));
            *((_DWORD *)v22 + 1) = 0;
          }
          v27 = v22;
          v28 = (void *)HIDWORD(v26->m_reconstruction_info_actuality_tick);
          BYTE2(v26->m_children_resources.m_lock) = 0;
          vostok_mspace_free(v28, v27);
          v16 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
        }
      }
    }
LABEL_26:
    ;
  }
  v29 = thisa;
  m_vb_stream_1 = (vostok::render::res_geometry **)thisa->m_vb_stream_1;
  for ( j = 2; j >= 0; --j )
  {
    v32 = *--m_vb_stream_1;
    if ( v32 )
    {
      v19 = (*v32)-- == 1;
      if ( v19 )
      {
        vostok::render::resource_manager::release(v16, *m_vb_stream_1);
        v16 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      }
    }
  }
  v33 = v29->m_instances._M_impl._M_start;
  if ( v33 )
  {
    v34 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v34, v33);
    v16 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  }
  v35 = v29->m_movement_texture.m_object;
  if ( v35 )
  {
    v19 = v35->m_reference_count-- == 1;
    if ( v19 )
    {
      v36 = v29->m_movement_texture.m_object;
      if ( v36->m_is_registered )
      {
        p_m_texture_registry = (int)&v16->m_texture_registry;
        thisa = (vostok::render::grass_patch *)v36->m_name.m_string.m_begin;
        v38 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v16,
                &v16->m_texture_registry._M_t,
                (const char **)&thisa);
        if ( v38 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)p_m_texture_registry )
        {
          stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
            &v40,
            p_m_texture_registry,
            (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v38);
          vostok::render::resource_manager::release_impl(
            v36,
            (vostok::render::resource_manager *)v40._M_t._M_header._M_data._M_parent);
        }
        v16 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      }
    }
  }
  v39 = v29->m_movement_rt.m_object;
  if ( v39 )
  {
    v19 = v39->m_reference_count-- == 1;
    if ( v19 )
      vostok::render::resource_manager::release(v16, v16, (const char *)v29->m_movement_rt.m_object);
  }
}
