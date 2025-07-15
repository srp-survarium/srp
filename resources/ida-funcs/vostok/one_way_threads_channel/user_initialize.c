void __thiscall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>>::user_initialize(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> > *this)
{
  _InterlockedExchange(&this->m_forward_queue.m_pop_thread_id, vostok::threading::current_thread_id());
  _InterlockedExchange(&this->m_backward_queue.m_push_thread_id, vostok::threading::current_thread_id());
}


void __thiscall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::user_initialize(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4> > *this)
{
  DWORD v1; // eax
  DWORD v2; // eax

  v1 = vostok::threading::current_thread_id();
  vostok::threading::interlocked_exchange_pointer(&this->m_forward_queue.m_pop_thread_id, v1);
  v2 = vostok::threading::current_thread_id();
  vostok::threading::interlocked_exchange_pointer(&this->m_backward_queue.m_push_thread_id, v2);
}
