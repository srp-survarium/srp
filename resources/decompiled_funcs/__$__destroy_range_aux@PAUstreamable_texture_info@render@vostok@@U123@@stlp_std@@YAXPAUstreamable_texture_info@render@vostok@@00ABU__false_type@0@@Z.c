void __cdecl stlp_std::__destroy_range_aux<vostok::render::streamable_texture_info *,vostok::render::streamable_texture_info>(
        vostok::render::streamable_texture_info *__first,
        vostok::render::streamable_texture_info *__last)
{
  vostok::render::streamable_texture_info *i; // ebp
  vostok::render::res_texture *m_object; // eax
  const vostok::render::res_texture *v5; // esi
  vostok::render::streamable_texture_info *m_begin; // eax
  survarium::options_tab *v7; // edi
  stlp_std::priv::_Rb_tree_node_base *v8; // eax
  vostok::render::streaming_texture_instance *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  _DWORD v11[4]; // [esp-4h] [ebp-10h] BYREF

  for ( i = __first; i != __last; ++i )
  {
    m_object = i->texture.m_object;
    if ( m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
      {
        v5 = i->texture.m_object;
        if ( v5->m_is_registered )
        {
          m_begin = (vostok::render::streamable_texture_info *)v5->m_name.m_string.m_begin;
          v11[0] = &__first;
          v7 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
          __first = m_begin;
          v8 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                 (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&__first,
                 (const char *const *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7]);
          if ( v8 != (stlp_std::priv::_Rb_tree_node_base *)v7 )
          {
            stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
              (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)v11,
              (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v8);
            vostok::render::resource_manager::release_impl((vostok::render::resource_manager *)v11[1], v5);
          }
        }
      }
    }
    M_start = i->instances._M_impl._M_start;
    if ( i->instances._M_impl._M_start )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
    }
  }
}
