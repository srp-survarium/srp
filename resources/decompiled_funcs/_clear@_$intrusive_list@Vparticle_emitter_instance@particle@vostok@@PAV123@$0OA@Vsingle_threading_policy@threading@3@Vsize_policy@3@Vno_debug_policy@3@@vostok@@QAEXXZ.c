void __thiscall vostok::intrusive_list<vostok::particle::particle_emitter_instance,vostok::particle::particle_emitter_instance *,224,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::clear(
        vostok::intrusive_list<vostok::particle::particle_emitter_instance,vostok::particle::particle_emitter_instance *,224,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_first = 0;
  this->m_last = 0;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
    this);
  survarium::weapon_user_dead_state::finalize(v1);
}
