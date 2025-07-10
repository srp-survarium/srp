void __thiscall vostok::sound::sound_world::try_process_order(
        vostok::sound::sound_world *this,
        vostok::sound::sound_instance_proxy_order *order)
{
  boost::function0<void>::operator()(&order->m_functor);
}
