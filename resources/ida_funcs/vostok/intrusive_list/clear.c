void __thiscall vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::clear(
        vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this)
{
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v1; // ecx
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+Ch] [ebp-8h] BYREF

  if ( this )
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->vostok::threading::mutex,
      (int)&raii);
  else
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      0,
      (int)&raii);
  this->m_first = 0;
  this->m_last = 0;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
    this);
  vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
    v1,
    (int)&raii);
}


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


void __thiscall vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::clear(
        vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this)
{
  vostok::threading::mutex *v2; // [esp+4h] [ebp-Ch]

  if ( this )
    v2 = &this->vostok::threading::mutex;
  else
    v2 = 0;
  vostok::threading::mutex::lock(v2);
  this->m_first = 0;
  this->m_last = 0;
  this->m_size = 0;
  vostok::threading::mutex::unlock(v2);
}
