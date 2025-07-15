void __userpurge vostok::render::res_texture::res_texture(
        vostok::render::res_texture *this@<ecx>,
        int a2@<esi>,
        bool pool_texture)
{
  float v3; // xmm0_4

  v3 = s_bm_current_air_resistance;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)a2 = &vostok::render::res_texture::`vftable';
  *(_BYTE *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(float *)(a2 + 24) = v3;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(float *)(a2 + 44) = v3;
  *(float *)(a2 + 48) = v3;
  *(float *)(a2 + 52) = v3;
  *(float *)(a2 + 56) = v3;
  *(_DWORD *)(a2 + 68) = 1;
  *(_DWORD *)(a2 + 72) = 1;
  *(_DWORD *)(a2 + 76) = 1;
  *(_BYTE *)(a2 + 60) = 0;
  *(_BYTE *)(a2 + 61) = 0;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 80) = 0;
  vostok::fs_new::virtual_path_string::virtual_path_string((vostok::fs_new::virtual_path_string *)this, a2 + 164);
  *(_BYTE *)(a2 + 458) = pool_texture;
  *(_DWORD *)(a2 + 440) = 0;
  *(_DWORD *)(a2 + 448) = 0;
  *(_DWORD *)(a2 + 452) = 0;
  *(_BYTE *)(a2 + 456) = 0;
  *(_BYTE *)(a2 + 459) = 0;
  memset(a2 + 84, 0, 0x2Cu);
}
