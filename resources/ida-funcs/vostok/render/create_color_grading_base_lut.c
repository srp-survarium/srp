vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__usercall vostok::render::create_color_grading_base_lut@<eax>(
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *a1@<eax>,
        vostok::render::resource_manager *a2@<ecx>)
{
  void *v3; // esp
  char *v4; // eax
  unsigned int v5; // edx
  char v6; // bl
  vostok::render::res_texture *v7; // eax
  unsigned int v9[4100]; // [esp-4000h] [ebp-4028h] BYREF
  D3D11_SUBRESOURCE_DATA width; // [esp+10h] [ebp-18h] BYREF
  unsigned int v11; // [esp+1Ch] [ebp-Ch]
  unsigned int v12; // [esp+20h] [ebp-8h]
  char v13; // [esp+27h] [ebp-1h]

  v3 = alloca(0x4000);
  v11 = 0;
  v4 = (char *)v9 + 1;
  do
  {
    v12 = 0;
    v13 = 16 * v11;
    do
    {
      v5 = 0;
      LOBYTE(a2) = 16 * v12;
      do
      {
        v4[1] = 16 * v5;
        v6 = v13;
        *v4 = (char)a2;
        *(v4 - 1) = v6;
        v4[2] = -1;
        ++v5;
        v4 += 4;
      }
      while ( v5 < 0x10 );
      ++v12;
    }
    while ( v12 < 0x10 );
    ++v11;
  }
  while ( v11 < 0x10 );
  width.pSysMem = v9;
  width.SysMemPitch = 64;
  width.SysMemSlicePitch = 1024;
  v7 = vostok::render::resource_manager::create_texture3d(
         a2,
         (const char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
         &width,
         v9[0],
         v9[1],
         (const D3D11_SUBRESOURCE_DATA *)v9[2],
         (DXGI_FORMAT)v9[3],
         v9[4],
         v9[5]);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    a1,
    v7);
  return a1;
}
