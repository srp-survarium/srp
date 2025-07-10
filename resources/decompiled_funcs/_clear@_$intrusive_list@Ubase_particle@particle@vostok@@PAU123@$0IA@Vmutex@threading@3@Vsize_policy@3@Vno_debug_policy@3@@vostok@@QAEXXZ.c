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
