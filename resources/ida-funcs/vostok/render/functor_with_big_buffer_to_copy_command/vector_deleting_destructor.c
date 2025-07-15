vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::environment_properties> *__thiscall vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::environment_properties>::`vector deleting destructor'(
        vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::environment_properties> *this,
        char a2)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx

  vostok::render::environment_properties::~environment_properties(
    (vostok::render::environment_properties *)this,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_data);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&this->m_on_defer_execution);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&this->m_on_execute);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
