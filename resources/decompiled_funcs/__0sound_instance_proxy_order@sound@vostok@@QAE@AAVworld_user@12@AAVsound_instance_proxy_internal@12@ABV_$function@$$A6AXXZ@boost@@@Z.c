void __thiscall vostok::sound::sound_instance_proxy_order::sound_instance_proxy_order(
        vostok::sound::sound_instance_proxy_order *this,
        vostok::sound::world_user *user,
        vostok::sound::sound_instance_proxy_internal *proxy,
        const boost::function<void __cdecl(void)> *functor_order)
{
  vostok::sound::sound_order::sound_order(this);
  this->__vftable = (vostok::sound::sound_instance_proxy_order_vtbl *)&vostok::sound::sound_instance_proxy_order::`vftable';
  this->m_proxy = proxy;
  this->m_world_user_base = user;
  this->m_functor.vtable = 0;
  boost::function0<void>::assign_to_own(&this->m_functor, functor_order);
}
