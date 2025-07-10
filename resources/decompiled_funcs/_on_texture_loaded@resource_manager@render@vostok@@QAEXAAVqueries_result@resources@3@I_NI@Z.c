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
