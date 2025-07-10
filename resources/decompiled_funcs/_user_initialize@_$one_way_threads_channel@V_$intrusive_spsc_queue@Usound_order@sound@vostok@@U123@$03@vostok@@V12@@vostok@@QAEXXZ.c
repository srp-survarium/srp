void __thiscall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>>::user_initialize(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> > *this)
{
  _InterlockedExchange(&this->m_forward_queue.m_pop_thread_id, vostok::threading::current_thread_id());
  _InterlockedExchange(&this->m_backward_queue.m_push_thread_id, vostok::threading::current_thread_id());
}
