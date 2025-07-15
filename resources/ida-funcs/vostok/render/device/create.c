void __usercall vostok::render::device::create(vostok::render::device *this@<ecx>, int a2@<edi>)
{
  char v2; // bl
  int v3; // eax
  HRESULT v4; // eax
  const char *d3d11_error_string; // eax
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  UINT v8; // ebp
  D3D_DRIVER_TYPE v9; // ecx
  void (__cdecl *v10)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  bool v12; // zf
  IDXGIAdapter *v13; // eax
  int Device; // eax
  const char *v15; // eax
  void (__cdecl *v16)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v17)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  bool do_debug_break; // [esp+11h] [ebp-15Dh] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+12h] [ebp-15Ch] BYREF
  vostok::command_line::key_initializator predicate[4]; // [esp+32h] [ebp-13Ch]
  D3D_FEATURE_LEVEL feature_levels[3]; // [esp+36h] [ebp-138h] BYREF
  DXGI_ADAPTER_DESC Desc; // [esp+42h] [ebp-12Ch] BYREF

  v2 = 0;
  *(_DWORD *)predicate = 0;
  vostok::render::device::create_d3d(this, a2);
  if ( !BYTE1(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_mouse_pos.elements[1])
    && (*(int (__stdcall **)(_DWORD, DXGI_ADAPTER_DESC *))(**(_DWORD **)(a2 + 296) + 32))(*(_DWORD *)(a2 + 296), &Desc) < 0 )
  {
    v3 = *(_DWORD *)(a2 + 296);
    do_debug_break = 1;
    v4 = (*(int (__stdcall **)(int, DXGI_ADAPTER_DESC *))(*(_DWORD *)v3 + 32))(v3, &Desc);
    d3d11_error_string = make_d3d11_error_string(v4);
    vostok::debug::on_error(
      &do_debug_break,
      process_error_true,
      (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_mouse_pos.elements[1]
    + 1,
      assert_untyped,
      "assertion_failed",
      d3d11_error_string,
      ".\\device.cpp",
      "vostok::render::device::create",
      0xAEu);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", info) )
  {
    v6 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v6 )
    {
      log_callback.functor.obj_ptr = v6;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v2 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\device.cpp",
      0xB0u,
      "void __thiscall vostok::render::device::create(void)",
      "render:",
      info,
      "* gpu [vendor:%X]-[device:%X]: %S",
      Desc.VendorId,
      Desc.DeviceId,
      Desc.Description);
  }
  if ( (v2 & 1) != 0 )
  {
    v2 &= ~1u;
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v7 )
          v7(&log_callback.functor, &log_callback.functor, 2);
      }
    }
  }
  v8 = 1;
  if ( g_debug_render_device.m_type == type_unset )
  {
    predicate[0] = 0;
    g_debug_render_device.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  v9 = D3D_DRIVER_TYPE_HARDWARE;
  if ( g_debug_render_device.m_type != type_recursive )
    v8 = 3;
  if ( *(_BYTE *)(a2 + 333) )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", warning) )
    {
      v10 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v10 )
      {
        log_callback.functor.obj_ptr = v10;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v2 |= 2u;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\device.cpp",
        0xBBu,
        "void __thiscall vostok::render::device::create(void)",
        "render:",
        warning,
        "using reference d3d device");
    }
    if ( (v2 & 2) != 0 )
    {
      v2 &= ~2u;
      if ( log_callback.vtable )
      {
        if ( ((int)log_callback.vtable & 1) == 0 )
        {
          v11 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
          if ( v11 )
            v11(&log_callback.functor, &log_callback.functor, 2);
        }
      }
    }
    v9 = D3D_DRIVER_TYPE_REFERENCE;
  }
  v12 = *(_BYTE *)(a2 + 333) == 0;
  feature_levels[0] = D3D_FEATURE_LEVEL_11_0;
  feature_levels[1] = D3D_FEATURE_LEVEL_10_1;
  feature_levels[2] = D3D_FEATURE_LEVEL_10_0;
  if ( v12 )
    v13 = 0;
  else
    v13 = *(IDXGIAdapter **)(a2 + 296);
  Device = D3D11CreateDevice(
             v13,
             v9,
             0,
             v8,
             feature_levels,
             3u,
             7u,
             (ID3D11Device **)(a2 + 300),
             (D3D_FEATURE_LEVEL *)(a2 + 292),
             (ID3D11DeviceContext **)(a2 + 304));
  if ( Device < 0
    && !BYTE2(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_mouse_pos.elements[1]) )
  {
    do_debug_break = 1;
    v15 = make_d3d11_error_string(Device);
    vostok::debug::on_error(
      &do_debug_break,
      process_error_true,
      (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_mouse_pos.elements[1]
    + 2,
      assert_untyped,
      "assertion_failed",
      v15,
      ".\\device.cpp",
      "vostok::render::device::create",
      0xDDu);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
  log_ref_count<ID3D11Device>(*(ID3D11Device **)(a2 + 300), "* create: deviceref:");
  *(_DWORD *)(a2 + 336) = Desc.DedicatedVideoMemory >> 20;
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", info) )
  {
    v16 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v16 )
    {
      log_callback.functor.obj_ptr = v16;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v2 |= 4u;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\device.cpp",
      0xE5u,
      "void __thiscall vostok::render::device::create(void)",
      "render:",
      info,
      "* texture memory: %d Mb",
      *(_DWORD *)(a2 + 336));
  }
  if ( (v2 & 4) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
  {
    v17 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
    if ( v17 )
      v17(&log_callback.functor, &log_callback.functor, 2);
  }
}
