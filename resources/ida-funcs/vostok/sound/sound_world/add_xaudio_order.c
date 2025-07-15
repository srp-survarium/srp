void __thiscall vostok::sound::sound_world::add_xaudio_order(
        vostok::sound::sound_world *this,
        vostok::sound::sound_order *order)
{
  if ( !s_initialized )
  {
    s_initialized = 1;
    _InterlockedExchange(&this->m_xaudio_callback_orders.m_push_thread_id, vostok::threading::current_thread_id());
  }
  vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>::push_back(
    &this->m_xaudio_callback_orders,
    order);
}
