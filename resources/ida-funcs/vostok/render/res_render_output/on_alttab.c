void __userpurge vostok::render::res_render_output::on_alttab(
        vostok::render::res_render_output *this@<ecx>,
        int a2@<esi>,
        bool activate)
{
  char v3; // cl
  int v4; // ecx
  HRESULT v5; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  bool *v7; // eax
  int *v8; // eax
  int v9; // ecx
  BOOL v10; // edx
  HRESULT v11; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v12; // ecx
  bool *d3d11_error_string; // eax
  int v14; // [esp-Eh] [ebp-30h]
  char v15; // [esp+19h] [ebp-9h] BYREF
  IDXGIOutput *v16; // [esp+1Ah] [ebp-8h]

  v3 = *(_BYTE *)(a2 + 237);
  if ( v3 || activate )
  {
    if ( *(_DWORD *)(a2 + 212) && *(_DWORD *)(a2 + 228) )
    {
      v16 = v3
          ? 0
          : vostok::quasi_singleton<vostok::render::device>::pinst->m_outputs[vostok::quasi_singleton<vostok::render::options>::pinst->current.m_monitor_index];
      if ( !ignore_always_28
        && (*(int (__stdcall **)(_DWORD, bool, IDXGIOutput *))(**(_DWORD **)(a2 + 212) + 40))(
             *(_DWORD *)(a2 + 212),
             v3 == 0,
             v16) < 0 )
      {
        v8 = *(int **)(a2 + 212);
        v9 = *v8;
        v10 = *(_BYTE *)(a2 + 237) == 0;
        v15 = 1;
        v11 = (*(int (__stdcall **)(int *, BOOL, IDXGIOutput *))(v9 + 40))(v8, v10, v16);
        d3d11_error_string = (bool *)make_d3d11_error_string(v11, v12);
        vostok::debug::on_error(
          (bool *)&v15,
          process_error_true,
          d3d11_error_string,
          ".\\res_render_output.cpp",
          "vostok::render::res_render_output::on_alttab",
          (const char *)0x18D);
        if ( vostok::debug::is_debugger_present() || v15 )
          __debugbreak();
      }
    }
  }
  else
  {
    ShowWindow(*(HWND *)(a2 + 228), 6);
    if ( !ignore_always_27
      && (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(a2 + 212) + 40))(*(_DWORD *)(a2 + 212), 0, 0) < 0 )
    {
      v4 = **(_DWORD **)(a2 + 212);
      v14 = *(_DWORD *)(a2 + 212);
      v15 = 1;
      v5 = (*(int (__stdcall **)(int, _DWORD, _DWORD))(v4 + 40))(v14, 0, 0);
      v7 = (bool *)make_d3d11_error_string(v5, v6);
      vostok::debug::on_error(
        (bool *)&v15,
        process_error_true,
        v7,
        ".\\res_render_output.cpp",
        "vostok::render::res_render_output::on_alttab",
        (const char *)0x17B);
      if ( vostok::debug::is_debugger_present() || v15 )
        __debugbreak();
    }
    UpdateWindow(*(HWND *)(a2 + 228));
  }
}
