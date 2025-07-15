vostok::math::float2 *__thiscall vostok::engine::engine_world::get_render_window_size(
        vostok::engine::engine_world *this,
        vostok::math::float2 *result)
{
  bool v2; // zf
  vostok::math::float2 *v3; // eax
  int v4; // ecx
  tagRECT rect; // [esp+0h] [ebp-10h] BYREF

  v2 = !GetClientRect(this->m_main_window_handle, &rect);
  v3 = result;
  if ( v2 )
  {
    result->x = FLOAT_10_0;
    result->y = FLOAT_10_0;
  }
  else
  {
    v4 = rect.bottom - rect.top;
    result->x = (float)(rect.right - rect.left);
    result->y = (float)v4;
  }
  return v3;
}
