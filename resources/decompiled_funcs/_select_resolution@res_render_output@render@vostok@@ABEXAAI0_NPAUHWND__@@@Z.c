void __userpurge vostok::render::res_render_output::select_resolution(
        HWND window@<eax>,
        unsigned int *width,
        unsigned int *height,
        bool windowed)
{
  BOOL ClientRect; // eax
  int v5; // edx
  tagRECT rect; // [esp+0h] [ebp-10h] BYREF

  if ( windowed )
    ClientRect = GetClientRect(window, &rect);
  else
    ClientRect = GetWindowRect(window, &rect);
  if ( ClientRect )
  {
    v5 = rect.bottom - rect.top;
    *width = rect.right - rect.left;
    *height = v5;
  }
  else
  {
    GetLastError();
  }
}
