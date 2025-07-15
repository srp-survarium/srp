void __usercall survarium::simple_game_project::remove_game_objects(
        survarium::simple_game_project *this@<ecx>,
        _DWORD *a2@<esi>)
{
  _DWORD *v2; // ebx
  _DWORD *i; // edi
  unsigned int v4; // ebx
  int v5; // edi
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v6; // eax

  v2 = (_DWORD *)a2[94];
  for ( i = (_DWORD *)a2[93]; i != v2; ++i )
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*i + 36))(*i);
  v4 = 0;
  if ( a2[118] )
  {
    v5 = 0;
    do
    {
      v6 = *(const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(v5 + a2[117] + 64);
      if ( v6 )
        vostok::render::scene_renderer::remove_model(
          v6 + 66,
          *(vostok::render::scene_renderer **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(a2[92] + 160) + 172)),
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2[92] + 4));
      ++v4;
      v5 += 68;
    }
    while ( v4 < a2[118] );
  }
}
