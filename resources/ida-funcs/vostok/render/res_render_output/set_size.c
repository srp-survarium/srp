void __userpurge vostok::render::res_render_output::set_size(
        vostok::render::res_render_output *this@<esi>,
        unsigned int in_height@<edi>,
        unsigned int *in_width,
        const bool in_fullscreen,
        const char *force_resize,
        bool modify_style)
{
  bool m_windowed; // bl
  unsigned int X; // [esp+4h] [ebp-8h]
  unsigned int Y; // [esp+8h] [ebp-4h]

  m_windowed = this->m_windowed;
  X = (vostok::quasi_singleton<vostok::render::device>::pinst->m_screen_size_x
     - (vostok::quasi_singleton<vostok::render::device>::pinst->m_screen_size_x < (unsigned int)in_width
      ? vostok::quasi_singleton<vostok::render::device>::pinst->m_screen_size_x - (_DWORD)in_width
      : 0)
     - (unsigned int)in_width) >> 1;
  Y = (vostok::quasi_singleton<vostok::render::device>::pinst->m_screen_size_y
     - (vostok::quasi_singleton<vostok::render::device>::pinst->m_screen_size_y < in_height
      ? vostok::quasi_singleton<vostok::render::device>::pinst->m_screen_size_y - in_height
      : 0)
     - in_height) >> 1;
  if ( in_fullscreen )
  {
    vostok::render::res_render_output::resize(in_width, in_height, this, 0, force_resize);
    if ( m_windowed )
      SetWindowLongA(this->m_window, -16, this->m_fullscreen_window_style);
    SetWindowPos(this->m_window, HWND_MESSAGE|0x2, 0, 0, (int)in_width, in_height, 0x60u);
  }
  else
  {
    vostok::render::res_render_output::resize(in_width, in_height, this, (HWND__ *)1, force_resize);
    if ( !m_windowed )
      SetWindowLongA(this->m_window, -16, this->m_windowed_window_style);
    SetWindowPos(this->m_window, (HWND)0xFFFFFFFE, X, Y, (int)in_width, in_height, 0x60u);
  }
  ShowWindow(this->m_window, 5);
}
