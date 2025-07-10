vostok::render::untyped_buffer *__thiscall vostok::render::system_renderer::create_quad_ib(
        vostok::render::system_renderer *this)
{
  __int16 v1; // di
  _WORD *v2; // eax
  int v3; // ebx
  _WORD *v4; // eax
  _BYTE data[49156]; // [esp+10h] [ebp-C004h] BYREF

  v1 = 0;
  v2 = data;
  v3 = 4096;
  do
  {
    *v2 = v1;
    v4 = v2 + 1;
    *v4++ = v1 + 1;
    *v4++ = v1 + 2;
    *v4++ = v1 + 3;
    *v4++ = v1 + 2;
    *v4 = v1 + 1;
    v2 = v4 + 1;
    v1 += 4;
    --v3;
  }
  while ( v3 );
  return vostok::render::resource_manager::create_buffer(
           0xC000u,
           v1,
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           data,
           enum_buffer_type_index,
           0,
           0);
}
