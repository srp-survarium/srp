int __usercall vostok::render::render_particle_emitter_instance::get_vertex_input_type@<eax>(
        vostok::render::render_particle_emitter_instance *this@<ecx>,
        int a2@<eax>)
{
  int v2; // eax

  v2 = *(_DWORD *)(a2 + 364);
  if ( !v2 )
    return 128;
  if ( v2 == 1 )
    return 256;
  return (unsigned int)(v2 - 2) > 1 ? 1 : 512;
}
