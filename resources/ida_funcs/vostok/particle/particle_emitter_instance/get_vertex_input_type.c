int __thiscall vostok::particle::particle_emitter_instance::get_vertex_input_type(
        vostok::particle::particle_emitter_instance *this)
{
  bool use_subuv; // [esp+1Fh] [ebp-9h]
  vostok::render::enum_vertex_input_type vertex_input_type; // [esp+24h] [ebp-4h]

  vertex_input_type = null_vertex_input_type;
  if ( this->m_billboard_parameters )
  {
    vertex_input_type = particle_vertex_input_type;
    if ( this->m_data_type_action )
    {
      use_subuv = 0;
      if ( !((int (__thiscall *)(vostok::particle::particle_action_data_type *, vostok::particle::particle_action_data_type *))this->m_data_type_action->get_data_type)(
              this->m_data_type_action,
              this->m_data_type_action) )
        use_subuv = this->m_data_type_action[5].m_visibility;
      if ( use_subuv )
        return 8;
    }
  }
  else if ( this->m_beamtrail_parameters )
  {
    return 9;
  }
  return vertex_input_type;
}
