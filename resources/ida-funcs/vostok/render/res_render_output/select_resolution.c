void __thiscall vostok::render::res_render_output::select_resolution(
        unsigned int *width,
        unsigned int *height,
        _DWORD *windowed,
        HWND__ *window,
        HWND hWnd)
{
  BOOL ClientRect; // eax
  tagRECT Rect; // [esp+0h] [ebp-10h] BYREF

  if ( (_BYTE)window )
    ClientRect = GetClientRect(hWnd, &Rect);
  else
    ClientRect = GetWindowRect(hWnd, &Rect);
  if ( ClientRect )
  {
    *height = Rect.right - Rect.left;
    *windowed = Rect.bottom - Rect.top;
  }
  else
  {
    GetLastError();
  }
}
