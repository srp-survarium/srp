void __userpurge vostok::particle::particle_system_instance_impl::add_emitter_instance(
        unsigned int lod_index@<eax>,
        vostok::particle::particle_emitter_instance *new_instance@<ecx>,
        vostok::particle::particle_system_instance_impl *this)
{
  vostok::intrusive_list<vostok::particle::particle_emitter_instance,vostok::particle::particle_emitter_instance *,492,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *p_m_emitter_instance_list; // eax

  new_instance->m_next = 0;
  p_m_emitter_instance_list = &this->m_lods[lod_index].m_emitter_instance_list;
  new_instance->m_particle_system_instance = this;
  ++p_m_emitter_instance_list->m_size;
  if ( p_m_emitter_instance_list->m_first )
    p_m_emitter_instance_list->m_last->m_next = new_instance;
  else
    p_m_emitter_instance_list->m_first = new_instance;
  p_m_emitter_instance_list->m_last = new_instance;
  if ( this->m_is_playing )
    vostok::particle::particle_system_instance_impl::prepare_render_resources(
      (vostok::particle::particle_system_instance_impl *)new_instance,
      (int)this);
}
