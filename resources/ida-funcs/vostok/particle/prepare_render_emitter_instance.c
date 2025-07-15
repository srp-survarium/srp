void __cdecl vostok::particle::prepare_render_emitter_instance(
        vostok::particle::particle_emitter_instance *em_instance)
{
  bool use_subuv; // [esp+1Bh] [ebp-5h]
  vostok::particle::enum_particle_data_type datatype; // [esp+1Ch] [ebp-4h] BYREF

  if ( em_instance->m_data_type_action )
  {
    datatype = ((int (__thiscall *)(vostok::particle::particle_action_data_type *, vostok::particle::particle_action_data_type *))em_instance->m_data_type_action->get_data_type)(
                 em_instance->m_data_type_action,
                 em_instance->m_data_type_action);
    use_subuv = 0;
    if ( datatype == particle_data_type_billboard )
      use_subuv = em_instance->m_data_type_action[5].m_visibility;
    vostok::particle::particle_emitter_instance::update_render_buffers(em_instance, &datatype, use_subuv);
  }
}
