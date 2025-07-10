char __usercall vostok::render::set_client_rect@<al>(
        HWND h_wnd@<esi>,
        int pos_x@<edi>,
        int pos_y,
        int size_x,
        int size_y)
{
  DWORD WindowLongA; // eax
  LONG v6; // eax
  tagRECT rect; // [esp+8h] [ebp-20h] BYREF
  tagRECT rect2; // [esp+18h] [ebp-10h] BYREF

  rect.left = pos_x;
  rect.top = pos_x;
  rect.right = pos_x + size_x;
  rect.bottom = size_y + pos_y;
  WindowLongA = GetWindowLongA(h_wnd, -16);
  AdjustWindowRect(&rect, WindowLongA, 0);
  GetWindowRect(h_wnd, &rect2);
  v6 = GetWindowLongA(h_wnd, -16);
  SetWindowLongA(h_wnd, -16, v6 | 0x10C80000);
  SetWindowPos(h_wnd, 0, pos_x, pos_y, size_x, size_y, 0x40u);
  return 1;
}
