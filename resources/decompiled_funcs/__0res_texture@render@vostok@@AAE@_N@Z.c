void __userpurge vostok::render::res_texture::res_texture(
        vostok::render::res_texture *this@<ecx>,
        int a2@<esi>,
        bool pool_texture)
{
  const vostok::math::float4x4 *v3; // xmm0_4

  *(_DWORD *)(a2 + 4) = 0;
  *(_BYTE *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)a2 = &vostok::render::res_texture::`vftable';
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  v3 = clear_value;
  *(_DWORD *)(a2 + 32) = clear_value;
  *(_DWORD *)(a2 + 36) = v3;
  *(_DWORD *)(a2 + 40) = v3;
  *(_DWORD *)(a2 + 44) = v3;
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 56) = 0;
  *(_DWORD *)(a2 + 60) = 0;
  *(_BYTE *)(a2 + 156) = 0;
  *(_DWORD *)(a2 + 144) = a2 + 156;
  *(_DWORD *)(a2 + 148) = a2 + 156;
  *(_BYTE *)(a2 + 416) = 47;
  *(_DWORD *)(a2 + 152) = a2 + 416;
  *(_DWORD *)(a2 + 420) = 0;
  *(_DWORD *)(a2 + 428) = 0;
  *(_DWORD *)(a2 + 432) = 0;
  *(_BYTE *)(a2 + 436) = 0;
  *(_BYTE *)(a2 + 439) = 0;
  *(_BYTE *)(a2 + 438) = pool_texture;
  *(_BYTE *)(a2 + 440) = 1;
  memset(a2 + 64, 0, 0x2Cu);
}
