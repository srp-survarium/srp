vostok::render::functor_command *__thiscall vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::ambient_light_properties>::`scalar deleting destructor'(
        vostok::render::functor_command *this,
        char a2)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx

  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)&this->m_on_defer_execution);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&this->m_on_execute);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::decal_properties> *__thiscall vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::decal_properties>::`scalar deleting destructor'(
        vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::decal_properties> *this,
        char a2)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx

  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_data.material);
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


vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::game::renderer::draw_scene_params> *__thiscall vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::game::renderer::draw_scene_params>::`scalar deleting destructor'(
        vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::game::renderer::draw_scene_params> *this,
        char a2)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx

  vostok::render::game::renderer::draw_scene_params::~draw_scene_params(
    (vostok::render::game::renderer::draw_scene_params *)this,
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


vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::environment_probe_properties> *__thiscall vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::environment_probe_properties>::`scalar deleting destructor'(
        vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::environment_probe_properties> *this,
        char a2)
{
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *p_m_data; // esi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx

  p_m_data = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_data;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_data.cooked_render_texture_diffuse);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(p_m_data);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&this->m_on_defer_execution);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v5,
    (int *)&this->m_on_execute);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
