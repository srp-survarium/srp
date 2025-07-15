vostok::math::uint2 *__usercall vostok::render::render_output_window::get_window_client_size@<eax>(
        HWND window@<eax>,
        _DWORD *a2@<esi>,
        bool windowed)
{
  BOOL ClientRect; // eax
  int v4; // ecx
  tagRECT rect; // [esp+0h] [ebp-10h] BYREF

  if ( windowed )
    ClientRect = GetClientRect(window, &rect);
  else
    ClientRect = GetWindowRect(window, &rect);
  if ( ClientRect )
  {
    v4 = rect.bottom - rect.top;
    *a2 = rect.right - rect.left;
    a2[1] = v4;
  }
  else
  {
    *a2 = 0;
    a2[1] = 0;
  }
  return (vostok::math::uint2 *)a2;
}
