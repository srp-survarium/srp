vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__usercall vostok::render::create_color_grading_base_lut_0@<eax>(
        vostok::render::res_texture **a1@<edi>)
{
  void *v1; // esp
  unsigned int v2; // ecx
  char *v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // ecx
  char v6; // dl
  char v7; // bl
  vostok::render::res_texture *v8; // eax
  unsigned int v10[4098]; // [esp-4000h] [ebp-4020h] BYREF
  D3D11_SUBRESOURCE_DATA data; // [esp+8h] [ebp-18h] BYREF
  unsigned int v12; // [esp+14h] [ebp-Ch]
  unsigned int v13; // [esp+18h] [ebp-8h]
  char v14; // [esp+1Fh] [ebp-1h]

  v1 = alloca(0x4000);
  LOBYTE(v2) = 0;
  v12 = 0;
  v3 = (char *)v10 + 2;
  do
  {
    LOBYTE(v4) = 0;
    v13 = 0;
    v14 = 16 * v2;
    do
    {
      v5 = 0;
      v6 = 16 * v4;
      do
      {
        *(v3 - 2) = 16 * v5;
        v7 = v14;
        *(v3 - 1) = v6;
        *v3 = v7;
        v3[1] = -1;
        ++v5;
        v3 += 4;
      }
      while ( v5 < 0x10 );
      v4 = v13 + 1;
      v13 = v4;
    }
    while ( v4 < 0x10 );
    v2 = v12 + 1;
    v12 = v2;
  }
  while ( v2 < 0x10 );
  data.pSysMem = v10;
  data.SysMemSlicePitch = 1024;
  data.SysMemPitch = 64;
  v8 = vostok::render::resource_manager::create_texture3d(
         &data,
         DXGI_FORMAT_R8G8B8A8_UNORM,
         (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
         "$user$color_grading_base_3d_lut",
         0x10u,
         0x10u,
         0x10u,
         D3D11_USAGE_IMMUTABLE,
         v10[0]);
  *a1 = 0;
  if ( v8 )
  {
    ++v8->m_reference_count;
    *a1 = v8;
  }
  return (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a1;
}
