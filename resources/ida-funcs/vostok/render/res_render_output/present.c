void __thiscall vostok::render::res_render_output::present(vostok::render::res_render_output *this, BOOL force_vsync)
{
  BOOL v2; // eax
  int v3; // ecx
  HRESULT v4; // eax
  vostok::render::device *v5; // ecx
  bool *d3d11_error_string; // eax

  v2 = vostok::render::res_render_output::select_presentation_interval(this, force_vsync);
  *(_DWORD *)(v3 + 232) = v2;
  v4 = (*(int (__stdcall **)(_DWORD, BOOL, _DWORD))(**(_DWORD **)(v3 + 212) + 32))(*(_DWORD *)(v3 + 212), v2, 0);
  if ( v4 == -2005270523 || v4 == -2005270521 || v4 == -2005270496 )
  {
    vostok::render::device::on_device_removed(v5, (int)vostok::quasi_singleton<vostok::render::device>::pinst);
  }
  else if ( !ignore_always_23 && v4 < 0 )
  {
    HIBYTE(force_vsync) = 1;
    d3d11_error_string = (bool *)make_d3d11_error_string(
                                   v4,
                                   (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v5);
    vostok::debug::on_error(
      (bool *)&force_vsync + 3,
      process_error_true,
      d3d11_error_string,
      ".\\res_render_output.cpp",
      "vostok::render::res_render_output::present",
      (const char *)0xAD);
    if ( vostok::debug::is_debugger_present() || HIBYTE(force_vsync) )
      __debugbreak();
  }
}
