void __usercall survarium::simple_game_project::insert_game_objects(
        survarium::simple_game_project *this@<ecx>,
        _DWORD *a2@<eax>)
{
  int v3; // edi
  unsigned int i; // ebx
  int v5; // eax
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v6; // edx
  _DWORD *v7; // edi
  _DWORD *v8; // esi

  v3 = 0;
  for ( i = 0; i < a2[118]; v3 += 68 )
  {
    v5 = v3 + a2[117];
    v6 = *(const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(v5 + 64);
    if ( v6 )
      vostok::render::scene_renderer::add_model(
        v6 + 66,
        *(vostok::render::scene_renderer **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(a2[92] + 160) + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2[92] + 4),
        (const vostok::math::float4x4 *)v5,
        (const vostok::math::float4x4 *)(v3 + a2[117]));
    ++i;
  }
  v7 = (_DWORD *)a2[93];
  v8 = (_DWORD *)a2[94];
  while ( v7 != v8 )
  {
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*v7 + 32))(*v7);
    ++v7;
  }
}
