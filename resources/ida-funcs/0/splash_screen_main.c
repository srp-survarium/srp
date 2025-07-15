void __thiscall splash_screen_main(vostok::fixed_string<260> *this)
{
  vostok::buffer_string *v1; // ecx
  char *v2; // eax
  vostok::buffer_string *v3; // ecx
  HANDLE FileA; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  bool v6; // al
  unsigned int v7; // eax
  void *v8; // esp
  unsigned __int8 *v9; // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // ecx
  bool v11; // al
  bool v12; // zf
  vostok::threading::mutex *v13; // ecx
  unsigned int v14; // edi
  void *v15; // esp
  int v16; // ebx
  unsigned __int8 *v17; // ecx
  HBITMAP Bitmap; // ebx
  bool v19; // al
  HMODULE ModuleHandleA; // eax
  HWND DlgItem; // eax
  bool has_passed_filters; // al
  void *v23; // eax
  HWND DesktopWindow; // eax
  int v25; // ecx
  int v26; // [esp-Ch] [ebp-1B8h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v27; // [esp-4h] [ebp-1B0h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v28; // [esp-4h] [ebp-1B0h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v29; // [esp-4h] [ebp-1B0h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v30; // [esp-4h] [ebp-1B0h]
  bool v31[12]; // [esp+0h] [ebp-1ACh] BYREF
  vostok::fixed_string<260> file_name; // [esp+Ch] [ebp-1A0h] BYREF
  tagMSG message; // [esp+120h] [ebp-8Ch] BYREF
  tagRECT screen_rectangle; // [esp+13Ch] [ebp-70h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v35; // [esp+14Ch] [ebp-60h] BYREF
  unsigned __int8 *buffer; // [esp+16Ch] [ebp-40h]
  raii_buffer guard; // [esp+170h] [ebp-3Ch] BYREF
  unsigned __int8 *dynamic_allocation; // [esp+178h] [ebp-34h]
  int v39; // [esp+17Ch] [ebp-30h]
  unsigned __int8 *line; // [esp+180h] [ebp-2Ch]
  int i; // [esp+184h] [ebp-28h]
  unsigned __int8 *pixel_buffer; // [esp+188h] [ebp-24h]
  int v43; // [esp+18Ch] [ebp-20h]
  unsigned int buffer_size; // [esp+190h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+194h] [ebp-18h]

  v43 = 0;
  vostok::fixed_string<260>::fixed_string<260>(this, &file_name, "../../resources/sources/splash_screens/");
  v12 = !s_world_0.m_variable->command_line_editor(&s_world_0.m_variable->vostok::engine_user::engine);
  v2 = "development_editor";
  if ( v12 )
    v2 = "development_engine";
  vostok::buffer_string::append(v1, (int)&file_name, v2);
  vostok::buffer_string::append(v3, (int)&file_name, ".bmp");
  FileA = CreateFileA(file_name.m_begin, 0x80000000, 3u, 0, 3u, 0x60000080u, 0);
  i = (int)FileA;
  if ( FileA != (HANDLE)-1 )
  {
    GetFileSize(FileA, 0);
    v7 = vostok::math::align_up<unsigned long>(0x200u);
    buffer_size = v7;
    LOBYTE(dynamic_allocation) = 1;
    if ( v7 >= (unsigned int)&loc_E1000 )
    {
      v9 = allocate(buffer_size);
    }
    else
    {
      v8 = alloca(v7);
      ms_exc.old_esp = (DWORD)v31;
      v9 = (unsigned __int8 *)v31;
      buffer = (unsigned __int8 *)v31;
      LOBYTE(dynamic_allocation) = 0;
      ms_exc.registration.TryLevel = -1;
    }
    raii_buffer::raii_buffer((raii_buffer *)v9, &guard, dynamic_allocation, v31[0]);
    if ( load_splash_screen((HANDLE)i, v9, buffer_size) )
    {
      CloseHandle((HANDLE)i);
      vostok::threading::mutex::lock(v13, (_RTL_CRITICAL_SECTION *)s_process_heap_walk.m_variable);
      pixel_buffer = &v9[*(_DWORD *)(v9 + 10)];
      v14 = vostok::math::align_up<unsigned long>(0x20u) >> 3;
      v15 = alloca(v14);
      ms_exc.old_esp = (DWORD)v31;
      line = (unsigned __int8 *)v31;
      i = 0;
      v16 = *(_DWORD *)(v9 + 22) - 1;
      if ( v16 > 0 )
      {
        v39 = -v14;
        v17 = pixel_buffer;
        pixel_buffer += v14 * v16;
        buffer_size = (unsigned int)v17;
        do
        {
          memcpy(line, (unsigned __int8 *)buffer_size, v14);
          memcpy((unsigned __int8 *)buffer_size, pixel_buffer, v14);
          memcpy(pixel_buffer, line, v14);
          ++i;
          buffer_size += v14;
          --v16;
          pixel_buffer += v39;
        }
        while ( i < v16 );
      }
      Bitmap = CreateBitmap(
                 *(_DWORD *)(v9 + 18),
                 *(_DWORD *)(v9 + 22),
                 *((unsigned __int16 *)v9 + 13),
                 *((unsigned __int16 *)v9 + 14),
                 &v9[*(_DWORD *)(v9 + 10)]);
      if ( Bitmap )
      {
        ModuleHandleA = GetModuleHandleA(0);
        s_splash_screen = CreateDialogParamA(ModuleHandleA, (LPCSTR)9, 0, (DLGPROC)window_procedure, 0);
        SetDlgItemTextA(s_splash_screen, 1002, s_finger_print_0.m_begin);
        DlgItem = GetDlgItem(s_splash_screen, 1001);
        if ( DlgItem )
        {
          v23 = (void *)SendMessageA(DlgItem, 0x172u, 0, (LPARAM)Bitmap);
          if ( v23 )
            DeleteObject(v23);
          DesktopWindow = GetDesktopWindow();
          GetWindowRect(DesktopWindow, &screen_rectangle);
          v25 = *(_DWORD *)(v9 + 22);
          v26 = *(_DWORD *)(v9 + 18);
          line = (unsigned __int8 *)((screen_rectangle.bottom - screen_rectangle.top) / 2);
          SetWindowPos(
            s_splash_screen,
            HWND_MESSAGE|0x2,
            (screen_rectangle.right - screen_rectangle.left) / 2 - v26 / 2,
            (int)&line[-(v25 / 2)],
            v26,
            v25,
            0x40u);
          UpdateWindow(s_splash_screen);
          SetActiveWindow(s_splash_screen);
          SetForegroundWindow(s_splash_screen);
          UpdateWindow(s_splash_screen);
          while ( GetMessageA(&message, 0, 0, 0) )
          {
            TranslateMessage(&message);
            DispatchMessageA(&message);
          }
          DeleteObject(Bitmap);
          LeaveCriticalSection((LPCRITICAL_SECTION)s_process_heap_walk.m_variable);
          goto LABEL_38;
        }
        PostMessageA(s_splash_screen, 2u, 0, 0);
        if ( !vostok::core::g_log_filter_tree
          || (has_passed_filters = vostok::logging::has_passed_filters(
                                     (vostok::logging::filter_tree *)"survarium",
                                     (const char *)2),
              v10 = v30,
              has_passed_filters) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            v10,
            &v35);
          v43 = 8;
          vostok::logging::append(
            &v35,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\survarium_pc_application_win.cpp",
            0xCEu,
            "void __cdecl splash_screen_main(void)",
            "survarium",
            error,
            "cannot find picture control in splash screen dialog");
        }
        v12 = (v43 & 8) == 0;
      }
      else
      {
        if ( !vostok::core::g_log_filter_tree
          || (v19 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"survarium", (const char *)2),
              v10 = v29,
              v19) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            v10,
            &v35);
          v43 = 4;
          vostok::logging::append(
            &v35,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\survarium_pc_application_win.cpp",
            0xC3u,
            "void __cdecl splash_screen_main(void)",
            "survarium",
            error,
            "cannot create bitmap for splash screen from file \"%s\" ",
            file_name.m_begin);
        }
        v12 = (v43 & 4) == 0;
      }
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (v11 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"survarium", (const char *)2),
            v10 = v28,
            v11) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v35);
        v43 = 2;
        vostok::logging::append(
          &v35,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\survarium_pc_application_win.cpp",
          0xA7u,
          "void __cdecl splash_screen_main(void)",
          "survarium",
          error,
          "cannot load splash screen from file \"%s\" ",
          file_name.m_begin);
      }
      v12 = (v43 & 2) == 0;
    }
    if ( !v12 )
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::~function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v10);
LABEL_38:
    raii_buffer::~raii_buffer((raii_buffer *)v10, (int)&guard);
    return;
  }
  if ( !vostok::core::g_log_filter_tree
    || (v6 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"survarium", (const char *)2),
        v5 = v27,
        v6) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v5,
      &v35);
    v43 = 1;
    vostok::logging::append(
      &v35,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\survarium_pc_application_win.cpp",
      0x8Au,
      "void __cdecl splash_screen_main(void)",
      "survarium",
      error,
      "cannot open splash screen from file \"%s\" ",
      file_name.m_begin);
  }
  if ( (v43 & 1) != 0 )
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::~function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v5);
}
