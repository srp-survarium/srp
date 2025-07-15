HWND __cdecl new_window()
{
  HMODULE ModuleHandleA; // eax
  HINSTANCE__ *v1; // eax
  int SystemMetrics; // esi
  int v3; // edi
  HWND DesktopWindow; // eax
  HINSTANCE__ *hInstance; // [esp-8h] [ebp-5Ch]
  tagRECT window_size; // [esp+10h] [ebp-44h] BYREF
  tagWNDCLASSEXA temp; // [esp+20h] [ebp-34h]

  ModuleHandleA = GetModuleHandleA(0);
  g_app_icon = LoadIconA(ModuleHandleA, (LPCSTR)0x68);
  *(_QWORD *)&temp.cbSize = 0x4000000030LL;
  temp.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))message_processor;
  temp.cbClsExtra = 0;
  temp.cbWndExtra = 0;
  v1 = GetModuleHandleA(0);
  *(_QWORD *)&s_window_class.cbSize = 0x4000000030LL;
  *(_QWORD *)&s_window_class.lpfnWndProc = (unsigned int)message_processor;
  temp.hInstance = v1;
  *(_QWORD *)&s_window_class.cbWndExtra = *(_QWORD *)&temp.cbWndExtra;
  *(_QWORD *)&temp.hIcon = (unsigned int)g_app_icon;
  *(_QWORD *)&s_window_class.hIcon = (unsigned int)g_app_icon;
  *(_QWORD *)&temp.hbrBackground = 0;
  *(_QWORD *)&s_window_class.hbrBackground = 0;
  temp.lpszClassName = &stru_954D10.m_string.m_buffer[160];
  temp.hIconSm = 0;
  *(_QWORD *)&s_window_class.lpszClassName = (unsigned int)&stru_954D10.m_string.m_buffer[160];
  RegisterClassExA(&s_window_class);
  SystemMetrics = GetSystemMetrics(0);
  v3 = GetSystemMetrics(1);
  window_size.left = 0;
  window_size.top = 0;
  window_size.right = 1280;
  window_size.bottom = 720;
  AdjustWindowRect(&window_size, (DWORD)&vostok::memory::s_CRT_arena[2166328], 0);
  hInstance = s_window_class.hInstance;
  DesktopWindow = GetDesktopWindow();
  return CreateWindowExA(
           0,
           &stru_954D10.m_string.m_buffer[160],
           &stru_954D10.m_string.m_buffer[212],
           (DWORD)&vostok::memory::s_CRT_arena[2166328],
           (unsigned int)(SystemMetrics - window_size.right) >> 1,
           (unsigned int)(v3 - window_size.bottom) >> 1,
           window_size.right - window_size.left,
           window_size.bottom - window_size.top,
           DesktopWindow,
           0,
           hInstance,
           0);
}
