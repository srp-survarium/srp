vostok::sound::sound_instance_proxy_internal *__thiscall vostok::sound::sound_instance_proxy_internal::`scalar deleting destructor'(
        vostok::sound::sound_instance_proxy_internal *this,
        char a2)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx

  this->__vftable = (vostok::sound::sound_instance_proxy_internal_vtbl *)&vostok::sound::sound_instance_proxy_internal::`vftable';
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_sound_emitter);
  this->__vftable = (vostok::sound::sound_instance_proxy_internal_vtbl *)&vostok::sound::sound_instance_proxy::`vftable';
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&this->m_finished_callback);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
