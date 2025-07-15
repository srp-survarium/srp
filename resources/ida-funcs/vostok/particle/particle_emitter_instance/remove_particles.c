void __userpurge vostok::particle::particle_emitter_instance::remove_particles(
        vostok::particle::particle_emitter_instance *this@<ecx>,
        int a2@<edi>,
        unsigned int num)
{
  vostok::particle::base_particle *v3; // ebx
  unsigned int particle_light_id; // eax
  vostok::particle::base_particle *v5; // eax
  vostok::particle::particle_world *v6; // ecx
  int v7; // [esp+Ch] [ebp-4h]

  v7 = 0;
  v3 = *(vostok::particle::base_particle **)(a2 + 412);
  while ( v3 && v7 != num )
  {
    particle_light_id = v3->particle_light_id;
    ++v7;
    if ( particle_light_id )
      (*(void (__thiscall **)(_DWORD, unsigned int))(**(_DWORD **)(a2 + 428) + 20))(
        *(_DWORD *)(a2 + 428),
        particle_light_id);
    vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,208,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
      (vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,208,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this,
      a2 + 376,
      v3);
    v5 = v3;
    v3 = v3->next;
    --*(_DWORD *)(a2 + 496);
    vostok::particle::particle_world::deallocate_particle(v6, *(_DWORD *)(a2 + 456), v5);
  }
  if ( num == -1 )
    survarium::player_stamina::clear_subscribers(
      (vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,208,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this,
      (_DWORD *)(a2 + 376));
}
