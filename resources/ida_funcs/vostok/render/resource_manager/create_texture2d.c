vostok::render::res_texture *__userpurge vostok::render::resource_manager::create_texture2d@<eax>(
        D3D11_USAGE usage@<eax>,
        vostok::render::resource_manager *this,
        const char *user_name,
        vostok::render::resource_manager *width,
        unsigned int height,
        ID3D11Texture2D *data,
        const D3D11_SUBRESOURCE_DATA *format,
        DXGI_FORMAT mip_levels,
        unsigned int array_size,
        bool use_as_render_target)
{
  const D3D11_SUBRESOURCE_DATA *v10; // ebx
  ID3D11Texture2D *v11; // ebp
  DXGI_FORMAT v12; // esi
  vostok::render::res_texture *texture2d_impl; // edi
  const char *v15; // eax
  vostok::render::resource_manager *v16; // eax
  vostok::render::res_texture *result; // eax
  const char *m_begin; // eax
  const char *v19; // [esp-4h] [ebp-144h]
  const char *v20; // [esp-4h] [ebp-144h]
  unsigned int v21; // [esp+0h] [ebp-140h]
  unsigned int v22; // [esp+4h] [ebp-13Ch]
  bool v23; // [esp+8h] [ebp-138h]
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> > >,bool> res; // [esp+18h] [ebp-128h] BYREF
  char *other; // [esp+20h] [ebp-120h] BYREF
  vostok::render::render_target *v26; // [esp+24h] [ebp-11Ch]
  stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> v27; // [esp+28h] [ebp-118h] BYREF

  v10 = format;
  v11 = data;
  v12 = mip_levels;
  if ( user_name )
  {
    res.first._M_node = &this->m_texture_registry._M_t._M_header._M_data;
    v16 = (vostok::render::resource_manager *)stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                                                (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&user_name,
                                                &this->m_texture_registry._M_t,
                                                &user_name);
    if ( v16 != (vostok::render::resource_manager *)&this->m_texture_registry )
      return (vostok::render::res_texture *)v16->m_parent_task.m_function.functor.vostok_pointer_size_alignment[3];
    texture2d_impl = vostok::render::resource_manager::create_texture2d_impl(
                       usage,
                       width,
                       height,
                       v11,
                       v10,
                       v12,
                       v21,
                       v22,
                       v23);
    m_begin = texture2d_impl->m_name.m_string.m_begin;
    if ( m_begin != user_name )
    {
      v20 = user_name;
      texture2d_impl->m_name.m_string.m_end = (char *)m_begin;
      *m_begin = 0;
      vostok::buffer_string::operator+=(&texture2d_impl->m_name.m_string, v20);
    }
    other = texture2d_impl->m_name.m_string.m_begin;
    v26 = (vostok::render::render_target *)texture2d_impl;
    vostok::fs_new::virtual_path_string::virtual_path_string(
      (vostok::fs_new::virtual_path_string *)&v27.first,
      (const char **)&other);
    v27.second = v26;
    stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::render_target *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::render_target *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::render_target *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *>>>::insert_unique(
      &v27,
      (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)res.first._M_node,
      (stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >,bool> *)&res);
  }
  else
  {
    texture2d_impl = vostok::render::resource_manager::create_texture2d_impl(
                       usage,
                       width,
                       height,
                       data,
                       format,
                       mip_levels,
                       v21,
                       v22,
                       v23);
    v15 = texture2d_impl->m_name.m_string.m_begin;
    if ( v15 != user_name )
    {
      v19 = user_name;
      texture2d_impl->m_name.m_string.m_end = (char *)v15;
      *v15 = 0;
      vostok::buffer_string::operator+=(&texture2d_impl->m_name.m_string, v19);
    }
  }
  result = texture2d_impl;
  texture2d_impl->m_is_registered = 1;
  return result;
}
