void __userpurge vostok::particle::particle_system_instance_impl::process_lods_lerping(
        vostok::particle::particle_system_instance_impl *this@<ecx>,
        int a2@<eax>,
        float time_delta)
{
  float v3; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  _DWORD *v8; // edi
  int v9; // eax
  int i; // esi

  v3 = s_bm_current_air_resistance;
  v5 = *(float *)(a2 + 752);
  if ( s_bm_current_air_resistance <= v5 )
  {
    v9 = 32 * *(_DWORD *)(a2 + 736);
    *(_BYTE *)(a2 + 756) = 1;
    for ( i = *(_DWORD *)(v9 + a2 + 276); i; i = *(_DWORD *)(i + 492) )
      vostok::particle::particle_emitter_instance::remove_particles(
        (vostok::particle::particle_emitter_instance *)this,
        i,
        0xFFFFFFFF);
  }
  else
  {
    v6 = (float)(time_delta * 0.25) + v5;
    v7 = 0.0;
    *(float *)(a2 + 752) = v6;
    if ( v6 > 0.0 )
    {
      if ( v3 < v6 )
        v7 = v3;
      else
        v7 = v6;
    }
    *(float *)(a2 + 752) = v7;
    v8 = *(_DWORD **)(32 * *(_DWORD *)(a2 + 736) + a2 + 276);
    if ( v8 )
    {
      while ( 1 )
      {
        (*(void (__thiscall **)(_DWORD *, _DWORD, bool, _DWORD))(*v8 + 8))(
          v8,
          LODWORD(time_delta),
          *(_BYTE *)(a2 + 769) == 0,
          v3 - *(float *)(a2 + 752));
        v8 = (_DWORD *)v8[123];
        if ( !v8 )
          break;
        v3 = s_bm_current_air_resistance;
      }
    }
  }
}
