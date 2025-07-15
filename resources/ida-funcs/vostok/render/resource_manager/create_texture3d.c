vostok::render::res_texture *__userpurge vostok::render::resource_manager::create_texture3d@<eax>(
        vostok::render::resource_manager *this@<ecx>,
        const char *user_name,
        const D3D11_SUBRESOURCE_DATA *width,
        unsigned int height,
        unsigned int depth,
        const D3D11_SUBRESOURCE_DATA *data,
        DXGI_FORMAT format,
        unsigned int usage,
        unsigned int mip_levels)
{
  ID3D11Device_vtbl *v10; // ecx
  HRESULT v11; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v12; // ecx
  bool *d3d11_error_string; // eax
  void *v14; // eax
  vostok::render::res_texture *v15; // ecx
  vostok::render::res_texture *v16; // ebx
  vostok::render::res_texture *v17; // eax
  vostok::fixed_string<260> *v18; // ecx
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v19; // ecx
  vostok::render::res_texture *v20; // ecx
  ID3D11Device *m_device; // [esp-1Ch] [ebp-174h]
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > v22[12]; // [esp-4h] [ebp-15Ch] BYREF
  char v23; // [esp+11Ch] [ebp-3Ch]
  vostok::render::res_texture *v24; // [esp+120h] [ebp-38h]
  char v25; // [esp+124h] [ebp-34h] BYREF
  _DWORD v26[9]; // [esp+12Ch] [ebp-2Ch] BYREF
  ID3D11Resource *surface; // [esp+150h] [ebp-8h] BYREF
  char v28; // [esp+157h] [ebp-1h] BYREF

  if ( vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_no_render_targets) )
    return 0;
  v26[0] = 16;
  v26[1] = 16;
  v26[2] = 16;
  v26[3] = 1;
  v26[5] = 1;
  v26[4] = 87;
  v26[6] = 8;
  v26[7] = 0;
  v26[8] = 0;
  surface = 0;
  if ( !ignore_always_10
    && vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateTexture3D(
         vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
         (const D3D11_TEXTURE3D_DESC *)v26,
         width,
         (ID3D11Texture3D **)&surface) < 0 )
  {
    v10 = vostok::quasi_singleton<vostok::render::device>::pinst->m_device->lpVtbl;
    *(_DWORD *)&v22[0]._M_header._M_data._M_color = 3435;
    m_device = vostok::quasi_singleton<vostok::render::device>::pinst->m_device;
    v28 = 1;
    v11 = v10->CreateTexture3D(m_device, (const D3D11_TEXTURE3D_DESC *)v26, width, (ID3D11Texture3D **)&surface);
    d3d11_error_string = (bool *)make_d3d11_error_string(v11, v12);
    vostok::debug::on_error(
      (bool *)&v28,
      process_error_true,
      d3d11_error_string,
      ".\\resource_manager.cpp",
      "vostok::render::resource_manager::create_texture3d",
      (const char *)0xD6B);
    if ( vostok::debug::is_debugger_present() || v28 )
      __debugbreak();
  }
  v14 = vostok::memory::new_helper<vostok::render::res_texture>::call<vostok::memory::doug_lea_allocator>(
          vostok::render::g_allocator,
          (const char *const)&v22[0]._M_header._M_data._M_parent->_M_color,
          (const char *const)&v22[0]._M_header._M_data._M_left->_M_color,
          (const unsigned int)v22[0]._M_header._M_data._M_right);
  v16 = 0;
  if ( v14 )
  {
    vostok::render::res_texture::res_texture(v15, (int)v14, 0);
    v16 = v17;
  }
  v16->m_mem_usage = 16
                   * vostok::render::utils::calc_surface_size(
                       0x10u,
                       0x10u,
                       DXGI_FORMAT_B8G8R8A8_UNORM,
                       (unsigned int *)&width);
  vostok::render::res_texture::set_name(v16, "$user$color_grading_base_3d_lut");
  vostok::fixed_string<260>::fixed_string<260>(
    v18,
    (vostok::buffer_string *)&v22[0]._M_node_count,
    v16->m_name.m_string.m_begin);
  *(_DWORD *)&v22[0]._M_header._M_data._M_color = &v22[0]._M_node_count;
  v23 = 47;
  v24 = v16;
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::insert_unique(
    v19,
    (stlp_std::priv::_Rb_tree_node_base *)(user_name + 557220),
    (const stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> *)&v25,
    v22[0]);
  v16->m_is_registered = 1;
  vostok::render::res_texture::set_hw_texture(v20, (int)v16, surface, 0, 0, 0, (bool)v22[0]._M_header._M_data._M_parent);
  surface->Release(surface);
  return v16;
}
