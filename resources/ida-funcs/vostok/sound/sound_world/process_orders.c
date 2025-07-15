void __thiscall vostok::sound::sound_world::process_orders(vostok::sound::sound_world *this)
{
  vostok::sound::sound_order *order; // [esp+1Ch] [ebp-8h]
  vostok::sound::sound_order *to_delete; // [esp+20h] [ebp-4h] BYREF

  while ( this->m_xaudio_callback_orders.m_tail->m_next_for_orders )
  {
    order = vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>::pop_front(
              &this->m_xaudio_callback_orders,
              &to_delete);
    order->execute(order);
    vostok::memory::detail::delete_helper_impl<vostok::memory::pthreads3_allocator,vostok::particle::particle_system_instance,vostok::memory::detail::call_destructor_predicate>(
      &vostok::memory::g_mt_allocator,
      &to_delete);
  }
  vostok::sound::world_user::process_orders(this->m_logic_world_user);
}
