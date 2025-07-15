HWND __cdecl new_window()
{
  HMODULE ModuleHandleA; // eax
  int v1; // esi
  int v2; // edi
  HWND DesktopWindow; // eax
  HINSTANCE__ *hInstance; // [esp-8h] [ebp-5Ch]
  _DWORD v6[12]; // [esp+Ch] [ebp-48h] BYREF
  tagRECT Rect; // [esp+3Ch] [ebp-18h] BYREF
  int X; // [esp+4Ch] [ebp-8h]
  int Y; // [esp+50h] [ebp-4h]

  ModuleHandleA = GetModuleHandleA(0);
  g_app_icon = LoadIconA(ModuleHandleA, (LPCSTR)0x68);
  v6[0] = 48;
  v6[1] = 64;
  v6[2] = message_processor;
  v6[3] = 0;
  v6[4] = 0;
  v6[5] = GetModuleHandleA(0);
  v6[6] = g_app_icon;
  v6[7] = 0;
  v6[8] = GetStockObject(4);
  v6[9] = 0;
  v6[10] = "Vostok Engine v0.20e DX11 Renderer Window Class ID";
  v6[11] = 0;
  qmemcpy(&s_window_class, v6, sizeof(s_window_class));
  RegisterClassExA(&s_window_class);
  X = GetSystemMetrics(0);
  Y = GetSystemMetrics(1);
  Rect.left = 0;
  Rect.top = 0;
  Rect.right = 1280;
  Rect.bottom = 720;
  AdjustWindowRectEx(&Rect, (DWORD)&unk_C80000, 0, 0);
  v1 = Rect.right - Rect.left;
  v2 = Rect.bottom - Rect.top;
  if ( X == 1280 && Y == 720 )
  {
    Y = 0;
    X = 0;
  }
  else
  {
    Y = (unsigned int)(Y - v2) >> 1;
    X = (unsigned int)(X - v1) >> 1;
  }
  hInstance = s_window_class.hInstance;
  DesktopWindow = GetDesktopWindow();
  return CreateWindowExA(
           0,
           "Vostok Engine v0.20e DX11 Renderer Window Class ID",
           "Vostok Engine v0.20e DX11 Renderer Window",
           (DWORD)&unk_C80000,
           X,
           Y,
           v1,
           v2,
           DesktopWindow,
           0,
           hInstance,
           0);
}
