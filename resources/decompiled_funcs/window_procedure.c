HGDIOBJ __stdcall window_procedure(HWND__ *window_handle, unsigned int msg, HDC wp, int lp)
{
  if ( msg == 2 )
  {
    PostQuitMessage(0);
  }
  else if ( msg == 312 )
  {
    SetTextColor(wp, (COLORREF)&vostok::memory::s_CRT_arena[5574199]);
    SetBkMode(wp, 1);
    return GetStockObject(5);
  }
  return 0;
}
