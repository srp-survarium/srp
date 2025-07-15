void __usercall vostok::sound::sound_world::add_xaudio_order(
        vostok::sound::sound_world *this@<esi>,
        vostok::sound::sound_order *order@<edi>)
{
  if ( !s_initialized_6 )
  {
    s_initialized_6 = 1;
    _InterlockedExchange(&this->m_xaudio_callback_orders.m_push_thread_id, GetCurrentThreadId());
  }
  order->m_next_for_orders = 0;
  _InterlockedExchange((volatile __int32 *)&this->m_xaudio_callback_orders.m_head->m_next_for_orders, (__int32)order);
  this->m_xaudio_callback_orders.m_head = order;
}
