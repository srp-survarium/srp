void __thiscall vostok::render::resource_manager::on_texture_loaded(
        vostok::render::resource_manager *this,
        vostok::resources::queries_result *data,
        unsigned int mip_level_cut,
        bool use_converter,
        vostok::resources::managed_resource *num_last_mips_used)
{
  char *m_requery_path; // eax
  void (__cdecl *v7)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  char v8; // bl
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::fs_new::virtual_path_string *v10; // eax
  vostok::fs_new::virtual_path_string *M_finish; // edx
  char *m_request_path; // eax
  vostok::render::resource_manager *v13; // ecx
  HRESULT ImageInfoFromMemory; // eax
  const char *d3d11_error_string; // eax
  HRESULT TextureFromMemory; // eax
  const char *v17; // eax
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v18; // [esp-Ch] [ebp-1CCh] BYREF
  char *v19; // [esp-8h] [ebp-1C8h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v20; // [esp-4h] [ebp-1C4h] BYREF
  bool v21; // [esp+0h] [ebp-1C0h]
  bool v22; // [esp+4h] [ebp-1BCh]
  bool do_debug_break; // [esp+12h] [ebp-1AEh] BYREF
  bool v24; // [esp+13h] [ebp-1ADh] BYREF
  vostok::render::res_texture *tex; // [esp+14h] [ebp-1ACh]
  ID3D11Resource *base_tex; // [esp+18h] [ebp-1A8h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> object; // [esp+1Ch] [ebp-1A4h] BYREF
  vostok::resources::pinned_ptr_const<unsigned char> ptr_man; // [esp+20h] [ebp-1A0h] BYREF
  char *other; // [esp+2Ch] [ebp-194h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+30h] [ebp-190h] BYREF
  D3DX11_IMAGE_LOAD_INFO load_info; // [esp+50h] [ebp-170h] BYREF
  D3DX11_IMAGE_INFO dds_info; // [esp+84h] [ebp-13Ch] BYREF
  vostok::fs_new::virtual_path_string name; // [esp+A8h] [ebp-118h] BYREF

  m_requery_path = data->m_queries[0].m_requery_path;
  tex = 0;
  if ( !m_requery_path )
    m_requery_path = data->m_queries[0].m_request_path;
  other = m_requery_path;
  vostok::fs_new::virtual_path_string::virtual_path_string(&name, (const char **)&other);
  if ( data->m_result == 1 )
  {
    vostok::render::fix_texture_name(&name);
    v10 = stlp_std::priv::__find<vostok::fs_new::virtual_path_string *,vostok::fs_new::virtual_path_string>(
            this->m_textures_to_reload._M_impl._M_start,
            this->m_textures_to_reload._M_impl._M_finish,
            &name);
    if ( v10 != this->m_textures_to_reload._M_impl._M_finish )
    {
      M_finish = this->m_textures_to_reload._M_impl._M_finish;
      if ( &v10[1] != M_finish )
        stlp_std::priv::__copy<vostok::fs_new::virtual_path_string *,vostok::fs_new::virtual_path_string *,int>(
          v10 + 1,
          M_finish,
          v10);
      v20.m_object = (vostok::resources::managed_resource *)--this->m_textures_to_reload._M_impl._M_finish;
      stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
    }
    tex = vostok::render::resource_manager::create_texture(this, name.m_string.m_begin, 0, 0, 0, 1, 1, 0xFFFFFFFF);
    if ( use_converter )
    {
      m_request_path = data->m_queries[0].m_requery_path;
      if ( !m_request_path )
        m_request_path = data->m_queries[0].m_request_path;
      v20.m_object = num_last_mips_used;
      v19 = m_request_path;
      v18.m_object = 0;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
        &v18,
        &data->m_queries[0].m_managed_resource);
      vostok::render::resource_manager::on_texture_loaded(v13, this, v18.m_object, v19, (unsigned int)v20.m_object);
    }
    else
    {
      object.m_object = 0;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
        &object,
        &data->m_queries[0].m_managed_resource);
      v20.m_object = 0;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
        &v20,
        &object);
      vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
        &ptr_man,
        (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v20.m_object);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&object);
      memset(&dds_info, 0, sizeof(dds_info));
      if ( !*(&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_is_active
            + 2)
        && D3DX11GetImageInfoFromMemory((int)ptr_man.m_data, ptr_man.m_size, 0, (int)&dds_info, 0) < 0 )
      {
        v20.m_object = (vostok::resources::managed_resource *)2169;
        do_debug_break = 1;
        ImageInfoFromMemory = D3DX11GetImageInfoFromMemory((int)ptr_man.m_data, ptr_man.m_size, 0, (int)&dds_info, 0);
        d3d11_error_string = make_d3d11_error_string(ImageInfoFromMemory);
        vostok::debug::on_error(
          &do_debug_break,
          process_error_true,
          &`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_is_active
        + 2,
          assert_untyped,
          "assertion_failed",
          d3d11_error_string,
          ".\\resource_manager.cpp",
          "vostok::render::resource_manager::on_texture_loaded",
          (unsigned int)v20.m_object);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
      memset(&load_info, 255, 20);
      load_info.CpuAccessFlags = -1;
      load_info.MiscFlags = -1;
      load_info.Format = -3;
      load_info.Filter = -1;
      load_info.MipFilter = -1;
      load_info.pSrcInfo = 0;
      load_info.Usage = D3D11_USAGE_DEFAULT;
      load_info.BindFlags = 8;
      base_tex = 0;
      TextureFromMemory = D3DX11CreateTextureFromMemory(
                            `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
                            (int)ptr_man.m_data,
                            ptr_man.m_size,
                            (int)&load_info,
                            0,
                            (int)&base_tex,
                            0);
      if ( !*(&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_is_active
            + 3)
        && TextureFromMemory < 0 )
      {
        v20.m_object = (vostok::resources::managed_resource *)2195;
        v24 = 1;
        v17 = make_d3d11_error_string(TextureFromMemory);
        vostok::debug::on_error(
          &v24,
          process_error_true,
          &`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_is_active
        + 3,
          assert_untyped,
          "assertion_failed",
          v17,
          ".\\resource_manager.cpp",
          "vostok::render::resource_manager::on_texture_loaded",
          (unsigned int)v20.m_object);
        if ( vostok::debug::is_debugger_present() || v24 )
          __debugbreak();
      }
      vostok::render::res_texture::set_hw_texture(
        (vostok::render::res_texture *)base_tex,
        (int)tex,
        base_tex,
        mip_level_cut,
        0,
        v21,
        v22);
      base_tex->Release(base_tex);
      vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&ptr_man);
    }
  }
  else
  {
    if ( vostok::core::g_log_filter_tree
      && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
    {
      v8 = (char)tex;
    }
    else
    {
      v7 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v7 )
      {
        log_callback.functor.obj_ptr = v7;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v8 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\resource_manager.cpp",
        0x864u,
        "void __thiscall vostok::render::resource_manager::on_texture_loaded(class vostok::resources::queries_result &,un"
        "signed int,bool,unsigned int)",
        "render:",
        error,
        "Texture %s was not found!",
        name.m_string.m_begin);
    }
    if ( (v8 & 1) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
    {
      v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v9 )
        v9(&log_callback.functor, &log_callback.functor, 2);
    }
  }
}


void __thiscall vostok::render::resource_manager::on_texture_loaded(
        vostok::render::resource_manager *this,
        vostok::render::resource_manager *data,
        vostok::resources::managed_resource *in_name,
        const char *num_last_mips_used,
        unsigned int num_last_mips_useda)
{
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned int *m_data; // ebx
  vostok::sound::encoded_sound_interface *v8; // edi
  vostok::vfs::base_node<1> *v9; // esi
  HRESULT v10; // esi
  DXGI_FORMAT Format; // edi
  unsigned int Height; // ebp
  unsigned int v13; // esi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // edx
  unsigned int v17; // edi
  unsigned int v18; // ebp
  int v19; // eax
  int v20; // eax
  bool v21; // al
  char v22; // cl
  unsigned int MipLevels; // ebx
  unsigned int v24; // edi
  unsigned int v25; // ebx
  unsigned int v26; // eax
  float v27; // xmm0_4
  float v28; // xmm0_4
  DXGI_FORMAT v29; // ebp
  unsigned int v30; // edi
  unsigned int v31; // edi
  unsigned int v32; // eax
  unsigned int ArraySize; // edx
  DXGI_FORMAT srgb_format; // eax
  unsigned int i; // ebx
  unsigned int v36; // ebp
  unsigned int v37; // eax
  unsigned int v38; // edi
  unsigned int v39; // ebp
  unsigned __int8 *v40; // ebp
  const char *d3d11_error_string; // eax
  unsigned int j; // ebx
  unsigned int v43; // ebp
  unsigned int v44; // eax
  unsigned int v45; // edi
  unsigned int v46; // ebp
  unsigned __int8 *v47; // ebp
  DXGI_FORMAT v48; // eax
  HRESULT v49; // eax
  const char *v50; // eax
  unsigned int v51; // ebp
  unsigned int v52; // edi
  unsigned int v53; // ecx
  unsigned __int8 *v54; // ebp
  int v55; // ebx
  vostok::render::res_texture *v56; // ecx
  vostok::render::res_texture *v57; // esi
  const unsigned __int8 *v58; // eax
  volatile signed __int32 *v59; // ecx
  unsigned int v60; // [esp+10h] [ebp-1FCh]
  unsigned int v61; // [esp+10h] [ebp-1FCh]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v62; // [esp+14h] [ebp-1F8h] BYREF
  bool v63; // [esp+18h] [ebp-1F4h]
  bool v64; // [esp+1Ch] [ebp-1F0h]
  int use_cutting; // [esp+28h] [ebp-1E4h] BYREF
  unsigned int cut_diff; // [esp+2Ch] [ebp-1E0h]
  unsigned __int8 *copy_ptr; // [esp+30h] [ebp-1DCh]
  unsigned int block_bytes; // [esp+34h] [ebp-1D8h] BYREF
  __int64 mip_index; // [esp+38h] [ebp-1D4h]
  ID3D11Resource *base_tex; // [esp+44h] [ebp-1C8h] BYREF
  unsigned int array_slice; // [esp+48h] [ebp-1C4h]
  unsigned int mem_usage; // [esp+4Ch] [ebp-1C0h]
  unsigned int num_orig_mips; // [esp+50h] [ebp-1BCh]
  D3DX11_IMAGE_INFO dds_info; // [esp+54h] [ebp-1B8h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> managed_ptr; // [esp+78h] [ebp-194h] BYREF
  HRESULT creation_result; // [esp+7Ch] [ebp-190h]
  vostok::mutable_buffer orig_width; // [esp+80h] [ebp-18Ch] BYREF
  vostok::render::res_texture *tex; // [esp+88h] [ebp-184h]
  vostok::resources::pinned_ptr_const<vostok::render::texture_data_resource> managed_typed_ptr; // [esp+8Ch] [ebp-180h] BYREF
  D3D11_TEXTURE2D_DESC desc; // [esp+98h] [ebp-174h] BYREF
  _DWORD v81[9]; // [esp+C4h] [ebp-148h] BYREF
  vostok::mutable_buffer v82; // [esp+E8h] [ebp-124h] BYREF
  vostok::fs_new::virtual_path_string name; // [esp+F0h] [ebp-11Ch] BYREF

  vostok::fs_new::virtual_path_string::virtual_path_string(&name, &num_last_mips_used);
  vostok::render::fix_texture_name(&name);
  tex = vostok::render::resource_manager::create_texture(data, name.m_string.m_begin, 0, 0, 0, 1, 1, 0xFFFFFFFF);
  managed_ptr.m_object = 0;
  if ( in_name )
  {
    managed_ptr.m_object = in_name;
    _InterlockedExchangeAdd(&in_name->m_reference_count, 1u);
  }
  block_bytes = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&block_bytes,
    &managed_ptr);
  v62.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v62,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&block_bytes);
  vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
    v5,
    &managed_typed_ptr.m_resource,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v62.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&block_bytes);
  v6 = (unsigned __int8 *)(managed_typed_ptr.m_data + 4);
  m_data = (unsigned int *)managed_typed_ptr.m_data;
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    &v82,
    (unsigned __int8 *)managed_typed_ptr.m_data + 4,
    *(_DWORD *)managed_typed_ptr.m_data);
  v8 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v82);
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    &orig_width,
    v6,
    *m_data);
  v9 = vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&orig_width);
  if ( s_no_srgb_textures_result.m_type == type_unset )
  {
    LOBYTE(mip_index) = 0;
    v62.m_object = (vostok::resources::managed_resource *)mip_index;
    s_no_srgb_textures_result.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( s_no_srgb_textures_result.m_type == type_recursive )
    HIBYTE(use_cutting) = *((_BYTE *)v8 + (_DWORD)v9 - 1);
  else
    HIBYTE(use_cutting) = 0;
  v10 = (HRESULT)v9 - 1;
  creation_result = v10;
  memset(&dds_info, 0, sizeof(dds_info));
  if ( D3DX11GetImageInfoFromMemory((int)v8, v10, 0, (int)&dds_info, 0) < 0 )
  {
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&managed_typed_ptr);
    goto LABEL_102;
  }
  copy_ptr = (unsigned __int8 *)&v8->m_target_quality_level;
  Format = dds_info.Format;
  base_tex = 0;
  mem_usage = 0;
  Height = dds_info.Height;
  if ( dds_info.Format == DXGI_FORMAT_R8G8B8A8_UNORM )
  {
    Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    dds_info.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    goto LABEL_13;
  }
  if ( dds_info.Format == DXGI_FORMAT_B8G8R8A8_UNORM )
  {
LABEL_13:
    if ( v10 == dds_info.Width * dds_info.Height + 128 )
    {
      Format = DXGI_FORMAT_R8_UNORM;
      dds_info.Format = DXGI_FORMAT_R8_UNORM;
    }
  }
  v13 = vostok::render::calc_block_size(Format);
  v14 = vostok::render::calc_bytes_per_block(Format);
  v15 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
        + 45);
  block_bytes = v14;
  v17 = Height + (v16 < Height ? v16 - Height : 0);
  v18 = 0;
  LODWORD(mip_index) = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_block_btn_time;
  strstr((unsigned __int8 *)name.m_string.m_begin, "weapons/");
  v21 = 1;
  if ( !v19 )
  {
    strstr((unsigned __int8 *)name.m_string.m_begin, "flora/");
    if ( !v20 )
      v21 = 0;
  }
  if ( s_debug_clip_texture_quality
    && !`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_is_active )
  {
    if ( v15 == 1 )
    {
      v15 = v21;
    }
    else if ( v15 == 2 )
    {
      if ( (unsigned int)mip_index > 0x200 )
      {
        if ( (unsigned int)mip_index <= 0x400 )
          v15 = v21 + 1;
      }
      else
      {
        v15 = 0;
      }
    }
  }
  if ( dds_info.Depth == 1 && v15 < 2 )
  {
    v22 = 1;
    if ( v17 > 0x80 )
      v18 = v15 != 0 ? v15 - 2 : -2;
  }
  else
  {
    v22 = 0;
  }
  MipLevels = dds_info.MipLevels;
  if ( dds_info.ArraySize == 1 && dds_info.MipLevels > v18 && v22 )
  {
    v24 = 0;
    if ( v18 )
    {
      do
      {
        v25 = vostok::math::max(dds_info.Width >> v24, v13);
        v26 = vostok::math::max(dds_info.Height >> v24++, v13);
        copy_ptr += block_bytes * (v25 + v13 - 1) / v13 * ((v13 - 1 + v26) / v13);
      }
      while ( v24 < v18 );
      MipLevels = dds_info.MipLevels;
    }
    MipLevels -= v18;
    dds_info.MipLevels = MipLevels;
    if ( v18 )
      v27 = vostok::math::pow_impl(v18, 2.0);
    else
      v27 = *(float *)&clear_value;
    cut_diff = LODWORD(v27);
    mip_index = (__int64)v27;
    dds_info.Width /= (unsigned int)mip_index;
    if ( v18 )
      v28 = vostok::math::pow_impl(v18, 2.0);
    else
      v28 = *(float *)&clear_value;
    cut_diff = LODWORD(v28);
    mip_index = (__int64)v28;
    num_last_mips_useda -= v18;
    dds_info.Height /= (unsigned int)mip_index;
  }
  v29 = dds_info.Format;
  if ( dds_info.Format != DXGI_FORMAT_BC1_UNORM && dds_info.Format != DXGI_FORMAT_BC3_UNORM
    || num_last_mips_useda == -1
    || num_last_mips_useda >= MipLevels
    || (LOBYTE(use_cutting) = 1, dds_info.Depth != 1) )
  {
    LOBYTE(use_cutting) = 0;
  }
  v30 = 0;
  cut_diff = 0;
  num_orig_mips = MipLevels;
  orig_width.m_data = (char *)dds_info.Width;
  LODWORD(mip_index) = dds_info.Height;
  if ( (_BYTE)use_cutting )
  {
    v31 = MipLevels;
    MipLevels = num_last_mips_useda;
    v30 = v31 - num_last_mips_useda;
    cut_diff = v30;
    dds_info.Width = vostok::math::max(dds_info.Width >> v30, v13);
    v32 = vostok::math::max(dds_info.Height >> v30, v13);
    v29 = dds_info.Format;
    dds_info.Height = v32;
    dds_info.MipLevels = MipLevels;
  }
  if ( dds_info.Depth == 1 )
  {
    memset((int)&desc, 0, sizeof(desc));
    ArraySize = dds_info.ArraySize;
    desc.ArraySize = dds_info.ArraySize;
    desc.BindFlags = 8;
    srgb_format = v29;
    if ( HIBYTE(use_cutting) )
      srgb_format = vostok::render::find_srgb_format(v29);
    desc.Format = srgb_format;
    desc.Width = dds_info.Width;
    desc.Height = dds_info.Height;
    desc.MipLevels = MipLevels;
    desc.MiscFlags = dds_info.MiscFlags;
    desc.SampleDesc.Count = 1;
    desc.SampleDesc.Quality = 0;
    desc.CPUAccessFlags = 0;
    desc.Usage = D3D11_USAGE_DEFAULT;
    if ( ArraySize == 1 )
    {
      creation_result = (*(int (__stdcall **)(int, D3D11_TEXTURE2D_DESC *, _DWORD, ID3D11Resource **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x + 20))(
                          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
                          &desc,
                          0,
                          &base_tex);
      for ( array_slice = 0; array_slice < dds_info.ArraySize; ++array_slice )
      {
        for ( i = 0; i < num_orig_mips; ++i )
        {
          v36 = (vostok::math::max((unsigned int)orig_width.m_data >> i, v13) + v13 - 1) / v13;
          v37 = vostok::math::max((unsigned int)mip_index >> i, v13);
          v38 = block_bytes * v36 * ((v13 - 1 + v37) / v13);
          v39 = block_bytes * v36;
          if ( (_BYTE)use_cutting && num_last_mips_useda < num_orig_mips - i )
          {
            copy_ptr += v38;
          }
          else
          {
            v60 = v39;
            v40 = copy_ptr;
            (*(void (__stdcall **)(int, ID3D11Resource *, unsigned int, _DWORD, unsigned __int8 *, unsigned int, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y + 192))(
              `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
              base_tex,
              i + desc.MipLevels * array_slice - cut_diff,
              0,
              copy_ptr,
              v60,
              0);
            mem_usage += v38;
            copy_ptr = &v40[v38];
          }
        }
      }
    }
    else
    {
      creation_result = (*(int (__stdcall **)(int, D3D11_TEXTURE2D_DESC *, _DWORD, ID3D11Resource **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x + 20))(
                          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
                          &desc,
                          0,
                          &base_tex);
    }
    if ( !`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_is_active
      && creation_result < 0 )
    {
      v62.m_object = (vostok::resources::managed_resource *)name.m_string.m_begin;
      HIBYTE(use_cutting) = 1;
      d3d11_error_string = make_d3d11_error_string(creation_result);
      vostok::debug::on_error(
        (bool *)&use_cutting + 3,
        process_error_true,
        &`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_is_active,
        assert_untyped,
        "assertion_failed",
        d3d11_error_string,
        ".\\resource_manager.cpp",
        "vostok::render::resource_manager::on_texture_loaded",
        0x7F5u,
        "texture creation failed: %s",
        (const char *)v62.m_object);
      if ( vostok::debug::is_debugger_present() || HIBYTE(use_cutting) )
        __debugbreak();
    }
    if ( dds_info.ArraySize != 1 )
    {
      for ( array_slice = 0; array_slice < dds_info.ArraySize; ++array_slice )
      {
        for ( j = 0; j < num_orig_mips; ++j )
        {
          v43 = (vostok::math::max((unsigned int)orig_width.m_data >> j, v13) + v13 - 1) / v13;
          v44 = vostok::math::max((unsigned int)mip_index >> j, v13);
          v45 = block_bytes * v43 * ((v13 - 1 + v44) / v13);
          v46 = block_bytes * v43;
          if ( (_BYTE)use_cutting && num_last_mips_useda < num_orig_mips - j )
          {
            copy_ptr += v45;
          }
          else
          {
            v61 = v46;
            v47 = copy_ptr;
            (*(void (__stdcall **)(int, ID3D11Resource *, unsigned int, _DWORD, unsigned __int8 *, unsigned int, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y + 192))(
              `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
              base_tex,
              j + desc.MipLevels * array_slice - cut_diff,
              0,
              copy_ptr,
              v61,
              0);
            mem_usage += v45;
            copy_ptr = &v47[v45];
          }
        }
      }
    }
  }
  else
  {
    v81[6] = 8;
    v81[7] = 0;
    v48 = v29;
    if ( HIBYTE(use_cutting) )
      v48 = vostok::render::find_srgb_format(v29);
    v81[4] = v48;
    v81[1] = dds_info.Height;
    v81[0] = dds_info.Width;
    v81[2] = dds_info.Depth;
    v81[3] = MipLevels;
    v81[8] = dds_info.MiscFlags;
    v81[5] = 0;
    v49 = (*(int (__stdcall **)(int, _DWORD *, _DWORD, ID3D11Resource **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x
                                                                         + 24))(
            `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
            v81,
            0,
            &base_tex);
    if ( !*(&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_is_active
          + 1)
      && v49 < 0 )
    {
      v62.m_object = (vostok::resources::managed_resource *)2093;
      LOBYTE(use_cutting) = 1;
      v50 = make_d3d11_error_string(v49);
      vostok::debug::on_error(
        (bool *)&use_cutting,
        process_error_true,
        &`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_is_active
      + 1,
        assert_untyped,
        "assertion_failed",
        v50,
        ".\\resource_manager.cpp",
        "vostok::render::resource_manager::on_texture_loaded",
        (unsigned int)v62.m_object);
      if ( vostok::debug::is_debugger_present() || (_BYTE)use_cutting )
        __debugbreak();
    }
    LODWORD(mip_index) = v30;
    if ( v30 < dds_info.MipLevels )
    {
      cut_diff = 0;
      do
      {
        v51 = ((dds_info.Width >> cut_diff) + v13 - 1) / v13;
        v52 = block_bytes * dds_info.Depth * v51 * (((dds_info.Height >> cut_diff) + v13 - 1) / v13);
        v53 = v51 * block_bytes * v51;
        v54 = copy_ptr;
        v55 = mip_index;
        (*(void (__stdcall **)(int, ID3D11Resource *, _DWORD, _DWORD, unsigned __int8 *, unsigned int, unsigned int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y + 192))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
          base_tex,
          mip_index,
          0,
          copy_ptr,
          block_bytes * (((dds_info.Width >> cut_diff++) + v13 - 1) / v13),
          v53);
        copy_ptr = &v54[v52];
        LODWORD(mip_index) = v55 + 1;
      }
      while ( v55 + 1 < dds_info.MipLevels );
    }
    mem_usage = creation_result - 128;
  }
  v56 = (vostok::render::res_texture *)mem_usage;
  v57 = tex;
  LOBYTE(v62.m_object) = 0;
  tex->m_mem_usage = mem_usage;
  vostok::render::res_texture::set_hw_texture(v56, (int)v57, base_tex, 0, (bool)v62.m_object, v63, v64);
  v57->m_loaded = 1;
  if ( base_tex )
    base_tex->Release(base_tex);
  if ( managed_typed_ptr.m_resource.m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v58 = managed_typed_ptr.m_data - 52;
      v59 = (volatile signed __int32 *)(managed_typed_ptr.m_data - 8);
      _InterlockedExchangeAdd(v59, 0xFFFFFFFF);
      if ( *((_DWORD *)v58 + 4) )
      {
        if ( !*v59 )
        {
          _InterlockedExchangeAdd((volatile signed __int32 *)(*((_DWORD *)v58 + 4) + 40), 1u);
          *((_DWORD *)v58 + 4) = 0;
        }
      }
    }
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&managed_typed_ptr.m_resource);
LABEL_102:
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&managed_ptr);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&in_name);
}
