int __userpurge vostok::particle::particle_system_instance_impl::calc_num_new_particles@<eax>(
        vostok::particle::particle_system_instance_impl *this@<ecx>,
        int a2@<esi>,
        float time_delta)
{
  _DWORD *i; // edi
  int v5; // eax
  _DWORD *j; // edi
  int v7; // [esp+14h] [ebp-4h]

  if ( *(_BYTE *)(a2 + 770) )
    return 0;
  v7 = 0;
  for ( i = *(_DWORD **)(32 * *(_DWORD *)(a2 + 732) + a2 + 276); i; i = (_DWORD *)i[123] )
    v7 += (*(int (__thiscall **)(_DWORD *, _DWORD, bool))(*i + 16))(i, LODWORD(time_delta), *(_BYTE *)(a2 + 769) == 0);
  v5 = *(_DWORD *)(a2 + 736);
  if ( *(_DWORD *)(a2 + 732) != v5 )
  {
    for ( j = *(_DWORD **)(32 * v5 + a2 + 276); j; j = (_DWORD *)j[123] )
      v7 += (*(int (__thiscall **)(_DWORD *, _DWORD, bool))(*j + 16))(j, LODWORD(time_delta), *(_BYTE *)(a2 + 769) == 0);
  }
  return v7;
}
