vostok::render::res_texture *__thiscall vostok::render::resource_manager::create_texture2d(
        vostok::render::resource_manager *this,
        const char *const *user_name,
        char *width,
        unsigned int height,
        const D3D11_SUBRESOURCE_DATA *data,
        const D3D11_SUBRESOURCE_DATA *format,
        DXGI_FORMAT usage,
        D3D11_USAGE mip_levels,
        unsigned int array_size,
        unsigned int use_as_render_target)
{
  char *v10; // esi
  vostok::fs_new::virtual_path_string *v11; // ecx
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v13; // ecx
  vostok::render::res_texture *v14; // esi
  stlp_std::priv::_Rb_tree_node_base *v15; // eax
  vostok::render::resource_manager *v16; // ecx
  vostok::render::res_texture *texture2d_impl; // edi
  vostok::fixed_string<260> *v18; // ecx
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v19; // ecx
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > v20; // [esp-4h] [ebp-24Ch] BYREF
  vostok::buffer_string __val_8[22]; // [esp+18h] [ebp-230h] BYREF
  char v22; // [esp+128h] [ebp-120h]
  vostok::render::res_texture *v23; // [esp+12Ch] [ebp-11Ch]
  char *v24; // [esp+130h] [ebp-118h] BYREF

  v10 = width;
  if ( vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_no_render_targets) )
    return 0;
  vostok::render::resource_manager::create_unique_user_name(v11, &v24);
  if ( !v10 || !*v10 || !height || !data )
  {
    v10 = v24;
    width = v24;
  }
  if ( v10 )
  {
    v15 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
            v13,
            user_name + 139305,
            (const char **)&width);
    if ( v15 == (stlp_std::priv::_Rb_tree_node_base *)(user_name + 139305) )
    {
      texture2d_impl = vostok::render::resource_manager::create_texture2d_impl(
                         v16,
                         height,
                         (unsigned int)data,
                         format,
                         usage,
                         mip_levels,
                         array_size,
                         use_as_render_target,
                         (bool)v20._M_header._M_data._M_parent);
      vostok::render::res_texture::set_name(texture2d_impl, v10);
      vostok::fixed_string<260>::fixed_string<260>(v18, __val_8, texture2d_impl->m_name.m_string.m_begin);
      *(_DWORD *)&v20._M_header._M_data._M_color = __val_8;
      v22 = 47;
      v23 = texture2d_impl;
      stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::insert_unique(
        v19,
        (stlp_std::priv::_Rb_tree_node_base *)(user_name + 139305),
        (const stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> *)&v20._M_key_compare,
        v20);
      texture2d_impl->m_is_registered = 1;
      return texture2d_impl;
    }
    else
    {
      return (vostok::render::res_texture *)v15[18]._M_parent;
    }
  }
  else
  {
    v14 = vostok::render::resource_manager::create_texture2d_impl(
            (vostok::render::resource_manager *)v13,
            height,
            (unsigned int)data,
            format,
            usage,
            mip_levels,
            array_size,
            use_as_render_target,
            (bool)v20._M_header._M_data._M_parent);
    vostok::render::res_texture::set_name(v14, 0);
    v14->m_is_registered = 1;
    return v14;
  }
}
