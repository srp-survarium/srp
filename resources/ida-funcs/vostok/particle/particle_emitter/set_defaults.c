void __usercall vostok::particle::particle_emitter::set_defaults(
        vostok::particle::particle_emitter *this@<ecx>,
        int a2@<esi>)
{
  float v2; // xmm1_4

  v2 = s_bm_current_air_resistance;
  *(_DWORD *)(a2 + 348) = 0;
  *(float *)(a2 + 352) = v2;
  *(_DWORD *)(a2 + 356) = 0;
  *(_DWORD *)(a2 + 344) = 0;
  *(_DWORD *)(a2 + 364) = 0;
  *(_DWORD *)(a2 + 360) = 500;
  *(_DWORD *)(a2 + 272) = 0;
  *(_DWORD *)(a2 + 280) = 0;
  *(_DWORD *)(a2 + 288) = 0;
  *(_BYTE *)(a2 + 369) = 0;
  *(_BYTE *)(a2 + 368) = 0;
  *(_DWORD *)(a2 + 320) = 0;
  *(_DWORD *)(a2 + 340) = 0;
  *(_DWORD *)(a2 + 296) = 0;
  *(_DWORD *)(a2 + 336) = 0;
  *(_BYTE *)(a2 + 370) = 1;
  *(_BYTE *)(a2 + 371) = 0;
  *(_DWORD *)(a2 + 376) = 0;
  *(_DWORD *)(a2 + 328) = 0;
  *(_DWORD *)(a2 + 312) = 0;
  memset(a2, 0, 0x80u);
  vostok::math::curve_line_ranged_base::set_defaults((vostok::math::curve_line_ranged_base *)(a2 + 128));
  *(_DWORD *)(a2 + 192) = 0;
  vostok::math::curve_line_ranged_base::set_defaults((vostok::math::curve_line_ranged_base *)(a2 + 200));
  *(_DWORD *)(a2 + 264) = 0;
  *(_BYTE *)(a2 + 372) = 0;
  *(_WORD *)(a2 + 380) = 0;
}
