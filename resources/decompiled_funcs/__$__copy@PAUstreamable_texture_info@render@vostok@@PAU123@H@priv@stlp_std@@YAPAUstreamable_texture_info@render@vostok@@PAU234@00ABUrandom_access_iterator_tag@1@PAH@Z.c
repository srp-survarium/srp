vostok::render::streamable_texture_info *__usercall stlp_std::priv::__copy<vostok::render::streamable_texture_info *,vostok::render::streamable_texture_info *,int>@<eax>(
        vostok::render::streamable_texture_info *__last@<eax>,
        vostok::render::streamable_texture_info *__first,
        vostok::render::streamable_texture_info *__result)
{
  vostok::render::streamable_texture_info *v4; // edi
  stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *m_object; // ecx
  int i; // ebp
  vostok::render::res_texture *v7; // eax
  vostok::render::res_texture *v8; // esi
  stlp_std::priv::_Rb_tree_node_base *v10; // eax
  vostok::render::resource_manager *v12; // [esp+0h] [ebp-14h]
  stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *__pos; // [esp+10h] [ebp-4h]

  v4 = __first;
  m_object = (stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *)((char *)__last - (char *)__first);
  for ( i = __last - __first; i > 0; __first = v4 )
  {
    stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance>>::operator=(
      m_object,
      &__result->instances._M_impl);
    vostok::fixed_string<260>::operator=(&__result->path, &v4->path);
    m_object = (stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *)v4->texture.m_object;
    v7 = 0;
    if ( m_object )
    {
      v7 = v4->texture.m_object;
      ++m_object->_M_finish;
    }
    v8 = __result->texture.m_object;
    __result->texture.m_object = v7;
    if ( v8 )
    {
      if ( v8->m_reference_count-- == 1 && v8->m_is_registered )
      {
        __pos = (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7];
        v10 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v8->m_name.m_string.m_begin,
                (const char *const *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7]);
        m_object = (stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *)__pos;
        if ( v10 != (stlp_std::priv::_Rb_tree_node_base *)__pos )
        {
          stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
            __pos,
            (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v10);
          vostok::render::resource_manager::release_impl(v12, v8);
          v4 = __first;
        }
      }
    }
    ++v4;
    --i;
    ++__result;
  }
  return __result;
}
