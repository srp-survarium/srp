void __userpurge vostok::render::res_render_output::set_size(
        vostok::render::res_render_output *this@<ecx>,
        vostok::render::res_render_output *a2@<eax>,
        unsigned int in_width,
        unsigned int in_height,
        bool in_fullscreen,
        HWND force_resize)
{
  HWND DesktopWindow; // eax
  unsigned int SystemMetrics; // edi
  unsigned int v10; // eax
  unsigned int v11; // edi
  tagRECT desktop_rect; // [esp+10h] [ebp-14h] BYREF
  unsigned int pos_y; // [esp+28h] [ebp+4h]

  a2->m_windowed = !in_fullscreen;
  DesktopWindow = GetDesktopWindow();
  GetClientRect(DesktopWindow, &desktop_rect);
  SystemMetrics = GetSystemMetrics(0);
  v10 = GetSystemMetrics(1);
  v11 = (SystemMetrics - (SystemMetrics < in_width ? SystemMetrics - in_width : 0) - in_width) >> 1;
  pos_y = (v10 - (v10 < in_height ? v10 - in_height : 0) - in_height) >> 1;
  if ( in_fullscreen )
    SetWindowPos(a2->m_window, 0, 0, 0, in_width, in_height, 0x40u);
  vostok::render::res_render_output::resize(a2, in_width, in_height, !in_fullscreen, force_resize);
  if ( !in_fullscreen )
    vostok::render::set_client_rect(a2->m_window, v11, pos_y, in_width, in_height);
}
