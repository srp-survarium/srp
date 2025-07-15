void __thiscall vostok::particle::particle_emitter_instance::reset(
        vostok::particle::particle_emitter_instance *this,
        int a2)
{
  int v2; // eax
  double v3; // st7
  float v4; // xmm0_4
  float v5; // eax
  float v6; // eax
  vostok::math::float4x4 *v7; // [esp+4h] [ebp-68h]
  vostok::math::float4x4 v8; // [esp+18h] [ebp-54h] BYREF
  float v9; // [esp+58h] [ebp-14h]
  float v10; // [esp+5Ch] [ebp-10h]
  float v11; // [esp+60h] [ebp-Ch]
  float v12; // [esp+64h] [ebp-8h]

  vostok::particle::particle_emitter_instance::remove_particles(this, a2, 0xFFFFFFFF);
  v2 = *(_DWORD *)(a2 + 488);
  *(_DWORD *)(a2 + 496) = 0;
  *(_DWORD *)(a2 + 500) = 0;
  *(_BYTE *)(a2 + 557) = 0;
  *(_DWORD *)(a2 + 508) = 0;
  *(_DWORD *)(a2 + 516) = 0;
  *(_BYTE *)(a2 + 558) = 0;
  *(_DWORD *)(a2 + 504) = 0;
  *(_DWORD *)(a2 + 520) = 0;
  *(_DWORD *)(a2 + 552) = *(_DWORD *)(v2 + 360);
  *(_DWORD *)(a2 + 528) = *(_DWORD *)(v2 + 360);
  *(_DWORD *)(a2 + 536) = 0;
  *(_DWORD *)(a2 + 540) = 0;
  *(_DWORD *)(a2 + 532) = 0;
  *(_DWORD *)(a2 + 524) = 0;
  *(_DWORD *)(a2 + 548) = 0;
  *(_BYTE *)(a2 + 559) = 1;
  *(_BYTE *)(a2 + 560) = 0;
  v3 = vostok::particle::calc_duration(*(float *)(v2 + 352), *(float *)(v2 + 356));
  v4 = s_bm_current_air_resistance;
  *(float *)(a2 + 544) = v3;
  v11 = v4;
  *(_DWORD *)(a2 + 436) = 0;
  v5 = v11;
  v12 = v4;
  *(_DWORD *)(a2 + 440) = 0;
  *(float *)(a2 + 444) = v5;
  v6 = v12;
  v9 = v4;
  v10 = v4;
  v11 = v4;
  v12 = v4;
  *(float *)(a2 + 356) = v4;
  *(float *)(a2 + 360) = v10;
  *(float *)(a2 + 364) = v11;
  *(float *)(a2 + 448) = v6;
  *(float *)(a2 + 368) = v12;
  qmemcpy((void *)(a2 + 12), vostok::math::float4x4::identity(v7, &v8), 0x40u);
  qmemcpy((void *)(a2 + 76), vostok::math::float4x4::identity(0, &v8), 0x40u);
  qmemcpy((void *)(a2 + 140), vostok::math::float4x4::identity(0, &v8), 0x40u);
  qmemcpy((void *)(a2 + 204), vostok::math::float4x4::identity(0, &v8), 0x40u);
}
