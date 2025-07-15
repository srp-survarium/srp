void __userpurge vostok::particle::particle_world::particle_world(
        vostok::particle::particle_world *this@<ecx>,
        int a2@<esi>,
        vostok::particle::engine *engine)
{
  vostok::threading::mutex_tasks_unaware *v3; // ecx

  vostok::resources::unmanaged_resource::unmanaged_resource(this, (_DWORD *)a2, fs_iterator_class);
  *(_DWORD *)a2 = &vostok::particle::particle_world::`vftable';
  *(_DWORD *)(a2 + 268) = 0;
  *(_DWORD *)(a2 + 272) = 0;
  *(_DWORD *)(a2 + 276) = 0;
  *(_BYTE *)(a2 + 280) = 0;
  *(_DWORD *)(a2 + 264) = &vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::`vftable';
  *(_DWORD *)(a2 + 344) = a2 + 288;
  *(_DWORD *)(a2 + 348) = 0;
  *(_DWORD *)(a2 + 352) = 0;
  *(_DWORD *)(a2 + 360) = 0;
  *(_DWORD *)(a2 + 368) = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(v3, (_RTL_CRITICAL_SECTION *)(a2 + 376));
  *(_DWORD *)(a2 + 404) = 0;
  *(_DWORD *)(a2 + 408) = 0;
  *(_DWORD *)(a2 + 416) = engine;
  *(_DWORD *)(a2 + 420) = 0;
  *(_DWORD *)(a2 + 424) = 50000;
}
