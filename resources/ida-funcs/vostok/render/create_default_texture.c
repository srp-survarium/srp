vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__cdecl vostok::render::create_default_texture(
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *result)
{
  vostok::render::resource_manager *v1; // ecx
  void *v2; // esp
  char *v3; // eax
  unsigned int v4; // edx
  vostok::render::res_texture *v5; // eax
  int v7; // [esp-400h] [ebp-41Ch] BYREF
  D3D11_SUBRESOURCE_DATA format; // [esp+Ch] [ebp-10h] BYREF
  unsigned int v9; // [esp+18h] [ebp-4h]

  v2 = alloca(1024);
  v9 = 0;
  v3 = (char *)&v7 + 2;
  do
  {
    v4 = 0;
    LOBYTE(v1) = 16 * v9;
    do
    {
      *(v3 - 2) = 16 * v4;
      *(v3 - 1) = (char)v1;
      *v3 = 0;
      v3[1] = -1;
      ++v4;
      v3 += 4;
    }
    while ( v4 < 0x10 );
    ++v9;
  }
  while ( v9 < 0x10 );
  format.SysMemSlicePitch = 0;
  format.pSysMem = &v7;
  format.SysMemPitch = 64;
  v5 = vostok::render::resource_manager::create_texture2d(
         v1,
         (const char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
         "$user$default_texture",
         0x10u,
         (const D3D11_SUBRESOURCE_DATA *)0x10,
         &format,
         DXGI_FORMAT_R8G8B8A8_UNORM,
         D3D11_USAGE_IMMUTABLE,
         1u,
         0);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    result,
    v5);
  return result;
}
