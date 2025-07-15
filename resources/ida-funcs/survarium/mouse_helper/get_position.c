void __userpurge survarium::mouse_helper::get_position(survarium::mouse_helper *this@<eax>, int *y@<edi>, int *x)
{
  vostok::render::base_output_window *m_object; // eax
  vostok::render::base_output_window *v5; // esi
  int left; // eax
  int top; // ecx
  int v8; // edx
  int v9; // eax
  tagRECT Rect; // [esp+8h] [ebp-18h] BYREF
  tagPOINT Point; // [esp+18h] [ebp-8h] BYREF

  GetCursorPos(&Point);
  if ( (_S9 & 1) == 0 )
  {
    m_object = this->m_output_window->m_object;
    _S9 |= 1u;
    if ( m_object->m_windowed )
      cap_height = GetSystemMetrics(4);
    else
      cap_height = 0;
  }
  v5 = this->m_output_window->m_object;
  if ( v5->m_windowed && GetWindowRect(v5->m_window, &Rect) )
  {
    left = Rect.left;
    top = Rect.top;
  }
  else
  {
    left = 0;
    top = 0;
  }
  v8 = Point.x - left;
  v9 = Point.y - cap_height;
  *x = v8;
  *y = v9 - top;
  vostok::math::clamp<int>(v5->m_current_size.x);
  vostok::math::clamp<int>(v5->m_current_size.y);
}
