void __cdecl vostok::render::create_quad_ib()
{
  int v0; // ebx
  _WORD *v1; // eax
  _WORD *v2; // eax
  _BYTE data[49156]; // [esp+10h] [ebp-C008h] BYREF
  int v4; // [esp+C014h] [ebp-4h]

  v0 = 0;
  v1 = data;
  v4 = 4096;
  do
  {
    *v1 = v0;
    v2 = v1 + 1;
    *v2++ = v0 + 1;
    *v2++ = v0 + 2;
    *v2++ = v0 + 3;
    *v2++ = v0 + 2;
    *v2 = v0 + 1;
    v1 = v2 + 1;
    v0 += 4;
    --v4;
  }
  while ( v4 );
  vostok::render::resource_manager::create_buffer(
    0xC000u,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)2,
    (vostok::render::enum_buffer_type)data,
    1,
    1,
    0);
}
