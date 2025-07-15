void __userpurge vostok::particle::particle_system_instance_impl::shrink_particles(
        vostok::particle::particle_system_instance_impl *this@<ecx>,
        int a2@<edi>,
        float time_delta,
        float limit_over_total,
        unsigned int num_need_particles)
{
  _DWORD *i; // esi
  int v6; // eax
  _DWORD *j; // esi

  for ( i = *(_DWORD **)(32 * *(_DWORD *)(a2 + 732) + a2 + 276); i; i = (_DWORD *)i[123] )
    (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD, unsigned int))(*i + 24))(
      i,
      LODWORD(time_delta),
      LODWORD(limit_over_total),
      num_need_particles);
  v6 = *(_DWORD *)(a2 + 736);
  if ( *(_DWORD *)(a2 + 732) != v6 )
  {
    for ( j = *(_DWORD **)(32 * v6 + a2 + 276); j; j = (_DWORD *)j[123] )
      (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD, unsigned int))(*j + 24))(
        j,
        LODWORD(time_delta),
        LODWORD(limit_over_total),
        num_need_particles);
  }
}
