BOOL __userpurge vostok::render::render_particle_emitter_instance::sort_particles_::_4_::particle_sort_predicate::operator()@<eax>(
        const vostok::render::render_particle_emitter_instance::sort_particles::__l2::particle_entry *left@<ecx>,
        const vostok::render::render_particle_emitter_instance::sort_particles::__l2::particle_entry *right@<eax>,
        vostok::render::render_particle_emitter_instance::sort_particles::__l4::particle_sort_predicate *this)
{
  float distance; // xmm0_4
  BOOL result; // eax

  if ( this->m_front_to_back )
  {
    distance = right->distance;
    result = 0;
    if ( distance <= left->distance )
      return result;
    return 1;
  }
  return left->distance > right->distance;
}
