void __userpurge vostok::particle::particle_world::deallocate_particle(
        vostok::particle::particle_world *this@<ecx>,
        int a2@<eax>,
        vostok::particle::base_particle *P)
{
  --*(_DWORD *)(a2 + 420);
  if ( P )
    (*(void (__thiscall **)(int, vostok::particle::base_particle *, const char *, const char *, int))(*(_DWORD *)(a2 + 264) + 24))(
      a2 + 264,
      P,
      "vostok::particle::particle_world::deallocate_particle",
      ".\\particle_world.cpp",
      104);
}
