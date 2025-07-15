void __usercall vostok::render::scene::update_streaming_texture_parameters(
        vostok::render::scene *this@<ecx>,
        int a2@<eax>)
{
  int v2; // ecx
  int v3; // esi
  int v4; // edx
  unsigned int v5; // eax
  int v6; // ecx
  int v7; // edx
  unsigned int v8; // eax
  int v9; // ecx
  int v10; // edx

  v2 = *(int *)((char *)&dword_96154 + a2);
  v3 = *(int *)((char *)&dword_96158 + a2);
  while ( v2 != v3 )
  {
    v4 = *(_DWORD *)(v2 + 276);
    *(float *)(v2 + 280) = *(float *)(v4 + 24);
    *(_DWORD *)(v2 + 284) = *(_DWORD *)(v4 + 72);
    *(_DWORD *)(v2 + 288) = *(_DWORD *)(v4 + 76);
    *(_DWORD *)(v2 + 292) = *(_DWORD *)(v4 + 16);
    *(_DWORD *)(v2 + 296) = *(_DWORD *)(v4 + 68);
    *(_DWORD *)(v2 + 300) = *(_DWORD *)(v4 + 80);
    v5 = vostok::render::res_texture::width((vostok::render::res_texture *)v2, v4);
    *(_DWORD *)(v6 + 304) = v5;
    v8 = vostok::render::res_texture::height((vostok::render::res_texture *)v6, v7);
    *(_DWORD *)(v9 + 308) = v8;
    *(_DWORD *)(v9 + 312) = *(_DWORD *)(v10 + 96);
    *(_DWORD *)(v9 + 316) = *(_DWORD *)(v10 + 20);
    *(_DWORD *)(v9 + 320) = *(_DWORD *)(v10 + 12);
    *(_BYTE *)(v9 + 324) = *(_BYTE *)(v10 + 61);
    v2 = v9 + 328;
  }
}
