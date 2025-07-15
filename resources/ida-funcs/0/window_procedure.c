HGDIOBJ __stdcall window_procedure(HWND__ *a1, unsigned int a2, HDC hdc, int a4)
{
  if ( a2 == 2 )
  {
    PostQuitMessage(0);
  }
  else if ( a2 == 312 )
  {
    SetTextColor(hdc, 0xFFFFFFu);
    SetBkMode(hdc, 1);
    return GetStockObject(5);
  }
  return 0;
}
