void splash_screen_main()
{
  char *m_buffer; // eax
  const char *v1; // ecx
  bool v2; // al
  char *v3; // ecx
  unsigned int v4; // esi
  HANDLE FileA; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  void *v7; // edi
  DWORD FileSize; // eax
  unsigned int v9; // esi
  void *v10; // esp
  unsigned __int8 *v11; // ebx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v12; // ecx
  unsigned int v13; // eax
  int v14; // eax
  unsigned int v15; // esi
  void *v16; // esp
  int v17; // ebx
  unsigned __int8 *v18; // edi
  unsigned __int8 *v19; // esi
  HBITMAP Bitmap; // edi
  char v21; // bl
  HMODULE ModuleHandleA; // eax
  HWND DlgItem; // eax
  char v24; // bl
  void *v25; // eax
  HWND DesktopWindow; // eax
  bool v27[16]; // [esp+0h] [ebp-1B0h] BYREF
  vostok::fixed_string<260> file_name; // [esp+10h] [ebp-1A0h] BYREF
  char v29; // [esp+120h] [ebp-90h] BYREF
  tagMSG message; // [esp+124h] [ebp-8Ch] BYREF
  tagRECT screen_rectangle; // [esp+140h] [ebp-70h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+150h] [ebp-60h] BYREF
  raii_buffer guard; // [esp+174h] [ebp-3Ch] BYREF
  unsigned __int8 *dst; // [esp+17Ch] [ebp-34h]
  unsigned __int8 *dynamic_allocation; // [esp+180h] [ebp-30h]
  HBITMAP__ *bitmap_handle; // [esp+184h] [ebp-2Ch]
  int i; // [esp+188h] [ebp-28h]
  unsigned __int8 *buffer; // [esp+18Ch] [ebp-24h]
  int v39; // [esp+190h] [ebp-20h]
  unsigned __int8 *pixel_buffer; // [esp+194h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+198h] [ebp-18h]

  v39 = 0;
  m_buffer = file_name.m_buffer;
  file_name.m_begin = file_name.m_buffer;
  file_name.m_end = file_name.m_buffer;
  file_name.m_max_end = &v29;
  file_name.m_buffer[0] = 0;
  v1 = "../../resources/sources/splash_screens/";
  do
  {
    if ( m_buffer >= file_name.m_max_end )
      break;
    *m_buffer = *v1;
    m_buffer = ++file_name.m_end;
    ++v1;
  }
  while ( *v1 );
  *m_buffer = 0;
  v2 = s_world.m_variable->command_line_editor(&s_world.m_variable->vostok::engine_user::engine);
  v3 = "development_editor";
  if ( !v2 )
    v3 = "development_engine";
  v4 = strlen(v3);
  memcpy((unsigned __int8 *)file_name.m_end, (unsigned __int8 *)v3, v4);
  file_name.m_end += v4;
  *file_name.m_end = 0;
  *(_DWORD *)file_name.m_end = *(_DWORD *)".bmp";
  file_name.m_end += 4;
  *file_name.m_end = 0;
  FileA = CreateFileA(file_name.m_begin, 0x80000000, 3u, 0, 3u, 0x60000080u, 0);
  v7 = FileA;
  i = (int)FileA;
  if ( FileA != (HANDLE)-1 )
  {
    FileSize = GetFileSize(FileA, 0);
    if ( (FileSize & 0x1FF) != 0 )
      FileSize = FileSize - (FileSize & 0x1FF) + 512;
    v9 = FileSize;
    pixel_buffer = (unsigned __int8 *)FileSize;
    LOBYTE(dynamic_allocation) = 1;
    if ( FileSize >= 0xE1000 )
    {
      buffer = allocate(FileSize);
      v11 = buffer;
    }
    else
    {
      v10 = alloca(FileSize);
      ms_exc.old_esp = (DWORD)v27;
      v11 = (unsigned __int8 *)v27;
      buffer = (unsigned __int8 *)v27;
      LOBYTE(dynamic_allocation) = 0;
      ms_exc.registration.TryLevel = -1;
    }
    raii_buffer::raii_buffer((raii_buffer *)v11, &guard, dynamic_allocation, v27[0]);
    if ( load_splash_screen(v7, v11, v9) )
    {
      CloseHandle(v7);
      vostok::threading::mutex::lock(s_process_heap_walk.m_variable);
      pixel_buffer = &v11[*(_DWORD *)(v11 + 10)];
      v13 = *(_DWORD *)(v11 + 18) * *((unsigned __int16 *)v11 + 14);
      if ( ((v11[18] * (unsigned __int8)*((_WORD *)v11 + 14)) & 0x1F) != 0 )
        v13 = v13 - ((v11[18] * (unsigned __int8)*((_WORD *)v11 + 14)) & 0x1F) + 32;
      v14 = v13 >> 3;
      v15 = v14;
      v16 = alloca(v14);
      ms_exc.old_esp = (DWORD)v27;
      dst = (unsigned __int8 *)v27;
      i = 0;
      v17 = *(_DWORD *)(v11 + 22) - 1;
      if ( v17 > 0 )
      {
        bitmap_handle = (HBITMAP__ *)-v14;
        v18 = &pixel_buffer[v14 * v17];
        do
        {
          memcpy(dst, pixel_buffer, v15);
          memcpy(pixel_buffer, v18, v15);
          memcpy(v18, dst, v15);
          ++i;
          pixel_buffer += v15;
          --v17;
          v18 = &v18[(_DWORD)bitmap_handle];
        }
        while ( i < v17 );
      }
      v19 = buffer;
      Bitmap = CreateBitmap(
                 *(_DWORD *)(buffer + 18),
                 *(_DWORD *)(buffer + 22),
                 *((unsigned __int16 *)buffer + 13),
                 *((unsigned __int16 *)buffer + 14),
                 &buffer[*(_DWORD *)(buffer + 10)]);
      bitmap_handle = Bitmap;
      if ( Bitmap )
      {
        ModuleHandleA = GetModuleHandleA(0);
        s_splash_screen = CreateDialogParamA(ModuleHandleA, (LPCSTR)9, 0, (DLGPROC)window_procedure, 0);
        SetDlgItemTextA(s_splash_screen, 1002, s_finger_print_0.m_begin);
        DlgItem = GetDlgItem(s_splash_screen, 1001);
        if ( DlgItem )
        {
          v25 = (void *)SendMessageA(DlgItem, 0x172u, 0, (LPARAM)Bitmap);
          if ( v25 )
            DeleteObject(v25);
          DesktopWindow = GetDesktopWindow();
          GetWindowRect(DesktopWindow, &screen_rectangle);
          SetWindowPos(
            s_splash_screen,
            HWND_MESSAGE|0x2,
            (screen_rectangle.right - screen_rectangle.left) / 2 - *(_DWORD *)(v19 + 18) / 2,
            (screen_rectangle.bottom - screen_rectangle.top) / 2 - *(_DWORD *)(v19 + 22) / 2,
            *(_DWORD *)(v19 + 18),
            *(_DWORD *)(v19 + 22),
            0x40u);
          SetActiveWindow(s_splash_screen);
          SetForegroundWindow(s_splash_screen);
          if ( GetMessageA(&message, 0, 0, 0) )
          {
            do
            {
              TranslateMessage(&message);
              DispatchMessageA(&message);
            }
            while ( GetMessageA(&message, 0, 0, 0) );
            Bitmap = bitmap_handle;
          }
          DeleteObject(Bitmap);
          LeaveCriticalSection((LPCRITICAL_SECTION)s_process_heap_walk.m_variable);
          goto LABEL_48;
        }
        PostMessageA(s_splash_screen, 2u, 0, 0);
        if ( vostok::core::g_log_filter_tree
          && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "survarium:", error) )
        {
          v24 = v39;
        }
        else
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v12);
          v24 = 8;
          vostok::logging::append(
            &log_callback,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\survarium_pc_application_win.cpp",
            0xC6u,
            "void __cdecl splash_screen_main(void)",
            "survarium:",
            error,
            "cannot find picture control in splash screen dialog");
        }
        if ( (v24 & 8) == 0 )
        {
LABEL_48:
          raii_buffer::~raii_buffer((raii_buffer *)v12, (int)&guard);
          return;
        }
      }
      else
      {
        if ( vostok::core::g_log_filter_tree
          && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "survarium:", error) )
        {
          v21 = v39;
        }
        else
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v12);
          v21 = 4;
          vostok::logging::append(
            &log_callback,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\survarium_pc_application_win.cpp",
            0xBBu,
            "void __cdecl splash_screen_main(void)",
            "survarium:",
            error,
            "cannot create bitmap for splash screen from file \"%s\" ",
            file_name.m_begin);
        }
        if ( (v21 & 4) == 0 )
          goto LABEL_48;
      }
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "survarium:", error) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v12);
        v39 = 2;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\survarium_pc_application_win.cpp",
          0x9Fu,
          "void __cdecl splash_screen_main(void)",
          "survarium:",
          error,
          "cannot load splash screen from file \"%s\" ",
          file_name.m_begin);
      }
      if ( (v39 & 2) == 0 )
        goto LABEL_48;
    }
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v12,
      (int *)&log_callback);
    goto LABEL_48;
  }
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "survarium:", error) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v6);
    v39 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\survarium_pc_application_win.cpp",
      0x82u,
      "void __cdecl splash_screen_main(void)",
      "survarium:",
      error,
      "cannot open splash screen from file \"%s\" ",
      file_name.m_begin);
  }
  if ( (v39 & 1) != 0 )
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v6,
      (int *)&log_callback);
}
