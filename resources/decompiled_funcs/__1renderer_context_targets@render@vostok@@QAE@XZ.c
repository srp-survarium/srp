void __thiscall vostok::render::renderer_context_targets::~renderer_context_targets(
        vostok::render::renderer_context_targets *this,
        vostok::render::renderer_context_targets *thisa)
{
  char *v2; // ebx
  int v3; // eax
  bool v4; // zf
  int v5; // ebp
  survarium::options_tab *v6; // edi
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v7; // eax
  stlp_std::priv::_Rb_tree_node_base *v8; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::grass_render_model *m_object; // edi
  _BYTE *v11; // esi
  void *v12; // eax
  void *v13; // esi
  const char *v14; // eax
  int v15; // [esp+10h] [ebp-4h]

  v15 = 69;
  v2 = &thisa[1].m_family[0].name.m_buffer[48];
  do
  {
    v3 = *((_DWORD *)v2 - 39);
    v2 -= 160;
    if ( v3 )
    {
      v4 = (*(_DWORD *)(v3 + 4))-- == 1;
      if ( v4 )
      {
        v5 = *((_DWORD *)v2 + 1);
        if ( *(_BYTE *)(v5 + 439) )
        {
          v6 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
          thisa = *(vostok::render::renderer_context_targets **)(v5 + 144);
          v7 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>((stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&thisa, (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7], (const char **)&thisa);
          if ( v7 != (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v6 )
          {
            v8 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
                   &v7->_M_header._M_data,
                   (stlp_std::priv::_Rb_tree_node_base **)&v6->m_options_count,
                   (stlp_std::priv::_Rb_tree_node_base **)&v6->m_type,
                   (stlp_std::priv::_Rb_tree_node_base **)&v6->m_game);
            if ( v8 )
            {
              m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v8);
            }
            --v6->m_movie;
            m_object = vostok::render::g_allocator.m_object;
            v11 = __RTCastToVoid((void **)v5);
            (**(void (__thiscall ***)(int, _DWORD))v5)(v5, 0);
            if ( v11 )
            {
              v12 = v11;
              v13 = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
              BYTE2(m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(v13, v12);
            }
          }
        }
      }
    }
    v14 = *(const char **)v2;
    if ( *(_DWORD *)v2 )
    {
      v4 = (*(_DWORD *)v14)-- == 1;
      if ( v4 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          *(const char **)v2);
    }
    --v15;
  }
  while ( v15 >= 0 );
}
