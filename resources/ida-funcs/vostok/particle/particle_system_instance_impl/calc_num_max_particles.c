int __userpurge vostok::particle::particle_system_instance_impl::calc_num_max_particles@<eax>(
        vostok::particle::particle_system_instance_impl *this@<ecx>,
        int a2@<eax>,
        float time_delta)
{
  int v5; // ebx
  _DWORD *v6; // edi
  int v7; // eax
  int v8; // eax
  _DWORD *v9; // esi
  int v10; // eax

  if ( *(_BYTE *)(a2 + 770) )
    return 0;
  v5 = 0;
  v6 = *(_DWORD **)(32 * *(_DWORD *)(a2 + 732) + a2 + 276);
  while ( v6 )
  {
    v7 = (*(int (__thiscall **)(_DWORD *, _DWORD))(*v6 + 20))(v6, LODWORD(time_delta));
    v6 = (_DWORD *)v6[123];
    v5 += v7;
  }
  v8 = *(_DWORD *)(a2 + 736);
  if ( *(_DWORD *)(a2 + 732) != v8 )
  {
    v9 = *(_DWORD **)(32 * v8 + a2 + 276);
    while ( v9 )
    {
      v10 = (*(int (__thiscall **)(_DWORD *, _DWORD))(*v9 + 20))(v9, LODWORD(time_delta));
      v9 = (_DWORD *)v9[123];
      v5 += v10;
    }
  }
  return v5;
}
