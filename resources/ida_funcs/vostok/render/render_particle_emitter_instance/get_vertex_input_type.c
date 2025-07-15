vostok::render::enum_vertex_input_type __usercall vostok::render::render_particle_emitter_instance::get_vertex_input_type@<eax>(
        vostok::render::render_particle_emitter_instance *this@<ecx>,
        int a2@<eax>)
{
  vostok::render::enum_vertex_input_type result; // eax

  switch ( *(_DWORD *)(a2 + 1120) )
  {
    case 0:
      result = particle_vertex_input_type;
      break;
    case 1:
      result = particle_subuv_vertex_input_type;
      break;
    case 2:
    case 3:
      result = particle_beamtrail_vertex_input_type;
      break;
    default:
      result = null_vertex_input_type;
      break;
  }
  return result;
}
