vostok::render::requested_streamable_texture *__usercall stlp_std::priv::__copy<vostok::render::requested_streamable_texture *,vostok::render::requested_streamable_texture *,int>@<eax>(
        vostok::render::requested_streamable_texture *__last@<eax>,
        vostok::render::requested_streamable_texture *__first,
        vostok::render::requested_streamable_texture *__result)
{
  vostok::render::requested_streamable_texture *v3; // ebx
  vostok::render::requested_streamable_texture *v4; // edi
  int i; // ebp
  vostok::render::res_texture *m_object; // ecx
  vostok::render::res_texture *v7; // eax
  const vostok::render::res_texture *v8; // esi
  stlp_std::priv::_Rb_tree_node_base *v10; // eax
  vostok::render::resource_manager *v12; // [esp+0h] [ebp-14h]
  stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *__pos; // [esp+10h] [ebp-4h]

  v3 = __result;
  v4 = __first;
  for ( i = __last - __first; i > 0; __first = v4 )
  {
    vostok::fixed_string<260>::operator=(&v3->path, &v4->path);
    m_object = v4->texture.m_object;
    v7 = 0;
    if ( m_object )
    {
      v7 = v4->texture.m_object;
      ++m_object->m_reference_count;
    }
    v8 = v3->texture.m_object;
    v3->texture.m_object = v7;
    if ( v8 )
    {
      if ( v8->m_reference_count-- == 1 && v8->m_is_registered )
      {
        __result = (vostok::render::requested_streamable_texture *)v8->m_name.m_string.m_begin;
        __pos = (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7];
        v10 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&__result,
                (const char *const *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7]);
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
    v3->num_mips = v4->num_mips;
    ++v4;
    --i;
    ++v3;
  }
  return v3;
}
