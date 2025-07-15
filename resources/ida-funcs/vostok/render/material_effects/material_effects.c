void __fastcall vostok::render::material_effects::material_effects(vostok::render::material_effects *this, int a2)
{
  float v2; // xmm0_4

  v2 = s_bm_current_air_resistance;
  memset((void *)(a2 + 40), 0, 0x70u);
  *(_DWORD *)(a2 + 36) = -1;
  ++num_me_count;
  *(float *)(a2 + 20) = v2;
  *(float *)(a2 + 24) = v2;
  *(float *)(a2 + 28) = v2;
  *(float *)(a2 + 32) = v2;
  *(_BYTE *)(a2 + 1) = 0;
  *(_BYTE *)(a2 + 5) = 0;
  *(_BYTE *)(a2 + 8) = 0;
  *(_BYTE *)(a2 + 6) = 0;
  *(_BYTE *)(a2 + 4) = 0;
  *(_BYTE *)a2 = 0;
  *(_BYTE *)(a2 + 7) = 0;
  *(_BYTE *)(a2 + 11) = 0;
  *(_BYTE *)(a2 + 12) = 0;
  *(_BYTE *)(a2 + 2) = 0;
  *(_BYTE *)(a2 + 9) = 0;
  *(_BYTE *)(a2 + 10) = 0;
  *(_BYTE *)(a2 + 13) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_BYTE *)(a2 + 3) = 1;
}
