void __cdecl stlp_std::__destroy_range_aux<vostok::render::requested_streamable_texture *,vostok::render::requested_streamable_texture>(
        vostok::render::requested_streamable_texture *__first,
        vostok::render::requested_streamable_texture *__last)
{
  vostok::render::requested_streamable_texture *v2; // ebx
  vostok::render::requested_streamable_texture *i; // ebp
  vostok::render::res_texture *m_object; // eax
  const vostok::render::res_texture *v6; // esi
  vostok::render::requested_streamable_texture *m_begin; // eax
  survarium::options_tab *v8; // edi
  stlp_std::priv::_Rb_tree_node_base *v9; // eax
  _BYTE v10[20]; // [esp-4h] [ebp-14h] BYREF

  v2 = __first;
  for ( i = __last; v2 != i; ++v2 )
  {
    m_object = v2->texture.m_object;
    if ( m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
      {
        v6 = v2->texture.m_object;
        if ( v6->m_is_registered )
        {
          m_begin = (vostok::render::requested_streamable_texture *)v6->m_name.m_string.m_begin;
          *(_DWORD *)v10 = &__last;
          v8 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
          __last = m_begin;
          v9 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                 (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&__last,
                 (const char *const *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7]);
          if ( v9 != (stlp_std::priv::_Rb_tree_node_base *)v8 )
          {
            stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
              (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)v10,
              (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v9);
            vostok::render::resource_manager::release_impl(*(vostok::render::resource_manager **)&v10[4], v6);
          }
        }
      }
    }
  }
}
