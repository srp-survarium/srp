void __userpurge vostok::sound::sound_instance_proxy_order::sound_instance_proxy_order(
        vostok::sound::sound_instance_proxy_order *this@<esi>,
        vostok::sound::world_user *user@<eax>,
        vostok::sound::sound_instance_proxy_internal *proxy,
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *functor_order)
{
  vostok::memory::base_allocator *m_orders_allocator; // ecx

  m_orders_allocator = user->m_orders_allocator;
  this->m_next_for_orders = 0;
  this->m_next_for_postponed_orders = 0;
  this->allocator = m_orders_allocator;
  this->m_world_user_base = user;
  this->m_proxy = proxy;
  this->__vftable = (vostok::sound::sound_instance_proxy_order_vtbl *)&vostok::sound::sound_instance_proxy_order::`vftable';
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    functor_order,
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&this->m_functor);
}
