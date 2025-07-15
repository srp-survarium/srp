void __usercall vostok::particle::particle_system_instance_impl::remove_particles(
        vostok::particle::particle_system_instance_impl *this@<ecx>,
        int a2@<esi>)
{
  int *v2; // ebx
  int i; // edi
  unsigned int v4; // [esp+0h] [ebp-4h]

  v4 = 0;
  if ( *(_DWORD *)(a2 + 740) )
  {
    v2 = (int *)(a2 + 276);
    do
    {
      for ( i = *v2; i; i = *(_DWORD *)(i + 492) )
        vostok::particle::particle_emitter_instance::remove_particles(
          (vostok::particle::particle_emitter_instance *)this,
          i,
          0xFFFFFFFF);
      ++v4;
      v2 += 8;
    }
    while ( v4 < *(_DWORD *)(a2 + 740) );
  }
}
