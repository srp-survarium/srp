BOOL __usercall vostok::particle::particle_world::get_render_emitter_instances_::_2_::emitters_sort_by_priority_pridicate::operator()@<eax>(
        vostok::particle::render_particle_emitter_instance *left@<ecx>,
        vostok::particle::render_particle_emitter_instance *right@<esi>)
{
  unsigned int v2; // edi

  v2 = left->user_priority(left);
  return v2 < right->user_priority(right);
}
