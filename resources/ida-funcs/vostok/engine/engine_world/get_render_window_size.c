vostok::math::float2 *__thiscall vostok::engine::engine_world::get_render_window_size(
        vostok::engine::engine_world *this,
        vostok::math::float2 *result)
{
  int v2; // ecx
  vostok::math::float2 *v3; // eax
  float v4; // xmm0_4
  tagRECT Rect; // [esp+0h] [ebp-10h] BYREF

  if ( GetClientRect(this->m_main_window_handle, &Rect) )
  {
    v2 = Rect.bottom - Rect.top;
    v3 = result;
    result->x = (float)(Rect.right - Rect.left);
    v4 = (float)v2;
  }
  else
  {
    v3 = result;
    v4 = FLOAT_10_0;
    result->x = FLOAT_10_0;
  }
  v3->y = v4;
  return v3;
}
