unsigned int __usercall vostok::render::render_particle_emitter_instance::get_num_particles@<eax>(
        vostok::render::render_particle_emitter_instance *this@<ecx>,
        int a2@<eax>)
{
  int v2; // ecx
  unsigned int result; // eax

  v2 = *(_DWORD *)(*(_DWORD *)(a2 + 1100) + 36);
  for ( result = 0; v2; ++result )
    v2 = *(_DWORD *)(v2 + 128);
  return result;
}
