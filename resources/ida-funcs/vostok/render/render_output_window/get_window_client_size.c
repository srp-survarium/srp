vostok::math::uint2 *__cdecl vostok::render::render_output_window::get_window_client_size(
        vostok::math::uint2 *result,
        HWND__ *window,
        bool windowed)
{
  vostok::math::uint2 *v3; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  DWORD LastError; // ebx
  bool has_passed_filters; // al
  bool v7; // zf
  DWORD v8; // ebx
  bool v9; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // [esp-4h] [ebp-50h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // [esp-4h] [ebp-50h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v12; // [esp+10h] [ebp-3Ch] BYREF
  tagRECT Rect; // [esp+34h] [ebp-18h] BYREF
  int v14; // [esp+44h] [ebp-8h]

  v14 = 0;
  if ( windowed )
  {
    if ( GetClientRect(window, &Rect) )
    {
LABEL_3:
      v3 = result;
      result->x = Rect.right - Rect.left;
      result->y = Rect.bottom - Rect.top;
      return v3;
    }
    LastError = GetLastError();
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"render_pc_dx11",
                                 (const char *)2),
          v4 = v10,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v4,
        &v12);
      v14 = 1;
      vostok::logging::append(
        &v12,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\render_output_window.cpp",
        0x89u,
        "class vostok::math::uint2 __cdecl vostok::render::render_output_window::get_window_client_size(struct HWND__ *,bool)",
        "render_pc_dx11",
        error,
        "GetClientRect returned error code %d, hwnd=%d",
        LastError,
        window);
    }
    v7 = (v14 & 1) == 0;
  }
  else
  {
    if ( GetWindowRect(window, &Rect) )
      goto LABEL_3;
    v8 = GetLastError();
    if ( !vostok::core::g_log_filter_tree
      || (v9 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"render_pc_dx11", (const char *)2),
          v4 = v11,
          v9) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v4,
        &v12);
      v14 = 2;
      vostok::logging::append(
        &v12,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\render_output_window.cpp",
        0x94u,
        "class vostok::math::uint2 __cdecl vostok::render::render_output_window::get_window_client_size(struct HWND__ *,bool)",
        "render_pc_dx11",
        error,
        "GetWindowRect returned error code %d, hwnd=%d",
        v8,
        window);
    }
    v7 = (v14 & 2) == 0;
  }
  if ( !v7 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
      (int *)&v12);
  v3 = result;
  result->y = 720;
  result->x = 1280;
  return v3;
}
