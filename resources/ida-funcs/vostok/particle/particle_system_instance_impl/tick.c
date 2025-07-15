bool __userpurge vostok::particle::particle_system_instance_impl::tick@<al>(
        vostok::particle::particle_system_instance_impl *this@<ecx>,
        int a2@<esi>,
        float time_delta)
{
  _DWORD *i; // edi
  float v5; // xmm0_4

  if ( *(_BYTE *)(a2 + 769) )
    *(float *)(a2 + 776) = *(float *)(a2 + 776) - time_delta;
  if ( *(_BYTE *)(a2 + 770) )
    return 0;
  *(float *)(a2 + 748) = time_delta + *(float *)(a2 + 748);
  if ( !*(_BYTE *)(a2 + 756) )
    vostok::particle::particle_system_instance_impl::process_lods_lerping(this, a2, time_delta);
  for ( i = *(_DWORD **)(32 * *(_DWORD *)(a2 + 732) + a2 + 276); i; i = (_DWORD *)i[123] )
  {
    if ( *(_BYTE *)(a2 + 756) )
      v5 = s_bm_current_air_resistance;
    else
      v5 = *(float *)(a2 + 752);
    (*(void (__thiscall **)(_DWORD *, _DWORD, bool, float))(*i + 8))(
      i,
      LODWORD(time_delta),
      *(_BYTE *)(a2 + 769) == 0,
      COERCE_FLOAT(LODWORD(v5)));
  }
  return (*(int (__thiscall **)(int))(*(_DWORD *)a2 + 28))(a2);
}
