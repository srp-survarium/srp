void __userpurge vostok::render::render_particle_emitter_instance::render_beams(
        vostok::render::render_particle_emitter_instance *this@<ecx>,
        int a2@<esi>,
        vostok::particle::base_particle *view_location,
        unsigned int num_particles)
{
  unsigned int v4; // edi
  unsigned int v5; // ebx
  unsigned int v6; // eax
  vostok::render::render_particle_emitter_instance *i; // ecx
  vostok::render::render_particle_emitter_instance *v8; // [esp+14h] [ebp+Ch]

  v4 = 0;
  v5 = num_particles / *(_DWORD *)(*(_DWORD *)(a2 + 352) + 8);
  v8 = 0;
  do
  {
    v6 = *(_DWORD *)(*(_DWORD *)(a2 + 340) + 36);
    for ( i = 0; v6 && i != v8; i = (vostok::render::render_particle_emitter_instance *)((char *)i + 1) )
      v6 = *(_DWORD *)(v6 + 208);
    vostok::render::render_particle_emitter_instance::render_trails(
      i,
      (const vostok::math::float3 *)a2,
      view_location,
      v6,
      v5);
    v8 = (vostok::render::render_particle_emitter_instance *)((char *)v8 + v5);
    ++v4;
  }
  while ( v4 < *(_DWORD *)(*(_DWORD *)(a2 + 352) + 8) );
}
