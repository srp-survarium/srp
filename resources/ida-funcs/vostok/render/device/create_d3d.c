void __usercall vostok::render::device::create_d3d(vostok::render::device *this@<ecx>, int a2@<eax>)
{
  int DXGIFactory; // eax
  const char *d3d11_error_string; // eax
  IDXGIFactory *v5; // eax
  HRESULT (__stdcall *EnumAdapters)(IDXGIFactory *, unsigned int, IDXGIAdapter **); // eax
  vostok::math::int2 *v7; // eax
  int v8; // ebx
  int v9; // ecx
  int *v10; // ecx
  _QWORD *v11; // esi
  int v12; // eax
  int (__stdcall *v13)(int, _DWORD, IDXGIOutput **); // edx
  IDXGIOutput *v14; // eax
  void *v15; // esp
  void (__cdecl *v16)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v17)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  int *v18; // ebx
  int v19; // esi
  int v20; // edi
  vostok::math::int2 *v21; // eax
  unsigned int v22; // ecx
  int v23; // eax
  void (__cdecl *v24)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  void (__cdecl *v25)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  HRESULT (__stdcall *GetDesc)(IDXGIOutput *, DXGI_OUTPUT_DESC *); // edx
  int v27; // eax
  int (__stdcall *v28)(int, unsigned int, IDXGIOutput **); // eax
  IDXGIFactory *v29; // [esp-Ch] [ebp-D4h]
  int v30; // [esp-Ch] [ebp-D4h]
  _BYTE v31[16]; // [esp+0h] [ebp-C8h] BYREF
  DXGI_OUTPUT_DESC output_desc; // [esp+10h] [ebp-B8h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+70h] [ebp-58h] BYREF
  unsigned int resolution_index; // [esp+94h] [ebp-34h]
  _QWORD *v35; // [esp+98h] [ebp-30h]
  IDXGIFactory *dxgi_factory; // [esp+9Ch] [ebp-2Ch] BYREF
  int *v37; // [esp+A0h] [ebp-28h]
  int *v38; // [esp+A4h] [ebp-24h]
  unsigned int real_resolution_index; // [esp+A8h] [ebp-20h]
  unsigned int monitor_index; // [esp+ACh] [ebp-1Ch]
  vostok::math::int2 *v41; // [esp+B0h] [ebp-18h]
  int v42; // [esp+B4h] [ebp-14h]
  unsigned int num_display_modes; // [esp+B8h] [ebp-10h] BYREF
  IDXGIOutput *output; // [esp+BCh] [ebp-Ch] BYREF
  int v45; // [esp+C0h] [ebp-8h]
  bool do_debug_break; // [esp+C7h] [ebp-1h] BYREF

  v45 = 0;
  DXGIFactory = CreateDXGIFactory(&_GUID_7b7166ec_21c7_44ae_b21a_c9ae321ae369, (void **)&dxgi_factory);
  if ( !LOBYTE(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_mouse_pos.elements[1])
    && DXGIFactory < 0 )
  {
    do_debug_break = 1;
    d3d11_error_string = make_d3d11_error_string(DXGIFactory);
    vostok::debug::on_error(
      &do_debug_break,
      process_error_true,
      (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_mouse_pos.elements[1],
      assert_untyped,
      "assertion_failed",
      d3d11_error_string,
      ".\\device.cpp",
      "vostok::render::device::create_d3d",
      0x46u);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
  v5 = dxgi_factory;
  *(_DWORD *)(a2 + 296) = 0;
  *(_BYTE *)(a2 + 333) = 0;
  v29 = v5;
  EnumAdapters = v5->EnumAdapters;
  v37 = (int *)(a2 + 296);
  EnumAdapters(v29, 0, (IDXGIAdapter **)(a2 + 296));
  vostok::render::g_num_monitors = 0;
  v7 = vostok::render::g_monitor_resolutions[0];
  v8 = 6;
  do
  {
    v9 = 512;
    do
    {
      v7->x = 0;
      v7->y = 0;
      ++v7;
      --v9;
    }
    while ( v9 );
    --v8;
  }
  while ( v8 );
  v10 = v37;
  v11 = (_QWORD *)(a2 + 308);
  *v11 = 0;
  v11[1] = 0;
  v11[2] = 0;
  v12 = *v10;
  output = 0;
  v13 = *(int (__stdcall **)(int, _DWORD, IDXGIOutput **))(*(_DWORD *)v12 + 28);
  monitor_index = 0;
  if ( v13(v12, 0, &output) != -2005270526 )
  {
    v42 = 0;
    v41 = vostok::render::g_monitor_resolutions[0];
    v35 = v11;
    do
    {
      v14 = output;
      *(_DWORD *)v11 = output;
      num_display_modes = 0;
      v14->GetDisplayModeList(v14, DXGI_FORMAT_R8G8B8A8_UNORM, 0, &num_display_modes, 0);
      v15 = alloca(28 * num_display_modes);
      output->GetDisplayModeList(output, DXGI_FORMAT_R8G8B8A8_UNORM, 0, &num_display_modes, (DXGI_MODE_DESC *)v31);
      real_resolution_index = 0;
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
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
        v45 |= 1u;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\device.cpp",
          0x87u,
          "void __thiscall vostok::render::device::create_d3d(void)",
          "render:",
          error,
          "monitor %d",
          monitor_index);
      }
      if ( (v45 & 1) != 0 )
      {
        v45 &= ~1u;
        if ( log_callback.vtable )
        {
          if ( ((int)log_callback.vtable & 1) == 0 )
          {
            v17 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
            if ( v17 )
              v17(&log_callback.functor, &log_callback.functor, 2);
          }
        }
      }
      resolution_index = 0;
      if ( num_display_modes )
      {
        v18 = (int *)v31;
        v38 = (int *)v31;
        while ( 2 )
        {
          v19 = *v18;
          v20 = v18[1];
          v21 = v41;
          v22 = 0;
          while ( v21->x != v19 || v21->y != v20 )
          {
            ++v22;
            ++v21;
            if ( v22 >= 0x200 )
            {
              v23 = real_resolution_index + v42;
              vostok::render::g_monitor_resolutions[0][v23].x = v19;
              dword_4C1EBFC[2 * v23] = v20;
              if ( !vostok::core::g_log_filter_tree
                || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
              {
                v24 = vostok::core::g_log_callback;
                log_callback.vtable = 0;
                if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
                  `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
                    &log_callback.functor,
                    &log_callback.functor,
                    destroy_functor_tag);
                if ( v24 )
                {
                  log_callback.functor.obj_ptr = v24;
                  log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                               + 1);
                }
                else
                {
                  log_callback.vtable = 0;
                }
                v45 |= 2u;
                vostok::logging::append(
                  &log_callback,
                  (void *const)vostok::core::g_log_flags,
                  &vostok::core::g_log_format,
                  ".\\device.cpp",
                  0x8Eu,
                  "void __thiscall vostok::render::device::create_d3d(void)",
                  "render:",
                  error,
                  "  %dx%d",
                  v19,
                  v20);
                v18 = v38;
              }
              if ( (v45 & 2) != 0 )
              {
                v45 &= ~2u;
                if ( log_callback.vtable )
                {
                  if ( ((int)log_callback.vtable & 1) == 0 )
                  {
                    v25 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
                    if ( v25 )
                      v25(&log_callback.functor, &log_callback.functor, 2);
                  }
                }
              }
              if ( ++real_resolution_index >= 0x200 )
                goto LABEL_46;
              break;
            }
          }
          v18 += 7;
          ++resolution_index;
          v38 = v18;
          if ( resolution_index < num_display_modes )
            continue;
          break;
        }
      }
LABEL_46:
      GetDesc = output->GetDesc;
      ++vostok::render::g_num_monitors;
      GetDesc(output, &output_desc);
      v27 = *v37;
      v41 += 512;
      v42 += 512;
      output = 0;
      v30 = v27;
      v28 = *(int (__stdcall **)(int, unsigned int, IDXGIOutput **))(*(_DWORD *)v27 + 28);
      v11 = (_QWORD *)((char *)v35 + 4);
      ++monitor_index;
      v35 = (_QWORD *)((char *)v35 + 4);
    }
    while ( v28(v30, monitor_index, &output) != -2005270526 );
  }
  dxgi_factory->Release(dxgi_factory);
}
