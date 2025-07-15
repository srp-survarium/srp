void __usercall vostok::particle::prepare_render_emitter_instance(
        vostok::particle::particle_emitter_instance *em_instance@<esi>,
        int a2@<ecx>,
        int a3@<edi>)
{
  vostok::particle::particle_action_data_type *m_data_type_action; // ecx
  int v4; // eax

  m_data_type_action = em_instance->m_data_type_action;
  if ( m_data_type_action )
  {
    v4 = ((int (__thiscall *)(vostok::particle::particle_action_data_type *, int))m_data_type_action->get_data_type)(
           m_data_type_action,
           a2);
    ((void (__thiscall *)(vostok::particle::render_particle_emitter_instance *, int, int, unsigned int))em_instance->m_render_instance->update_render_buffers)(
      em_instance->m_render_instance,
      v4,
      a3,
      em_instance->m_max_num_particles);
  }
}
