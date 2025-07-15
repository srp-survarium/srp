void __usercall vostok::render::render_surface_instance::render_surface_instance(
        vostok::render::render_surface_instance *this@<ecx>,
        int a2@<eax>)
{
  float v2; // xmm1_4

  v2 = s_bm_current_air_resistance;
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 24) = -1;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(float *)(a2 + 44) = v2;
  *(_DWORD *)(a2 + 48) = 0;
  *(_BYTE *)(a2 + 52) = 0;
  *(_BYTE *)(a2 + 53) = 0;
  *(_BYTE *)(a2 + 54) = 0;
}
