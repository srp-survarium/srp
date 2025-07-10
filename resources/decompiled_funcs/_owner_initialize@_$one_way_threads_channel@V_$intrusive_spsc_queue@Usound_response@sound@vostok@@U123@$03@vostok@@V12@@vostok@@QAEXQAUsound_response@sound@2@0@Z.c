void __thiscall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>>::owner_initialize(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> > *this,
        vostok::sound::sound_order *const forward_queue_initial_value,
        vostok::sound::sound_order *const backward_queue_initial_value)
{
  _InterlockedExchange(&this->m_forward_queue.m_push_thread_id, vostok::threading::current_thread_id());
  backward_queue_initial_value->m_next_for_orders = 0;
  this->m_forward_queue.m_tail = backward_queue_initial_value;
  this->m_forward_queue.m_head = backward_queue_initial_value;
  _InterlockedExchange(&this->m_backward_queue.m_pop_thread_id, vostok::threading::current_thread_id());
  forward_queue_initial_value->m_next_for_orders = 0;
  this->m_backward_queue.m_tail = forward_queue_initial_value;
  this->m_backward_queue.m_head = forward_queue_initial_value;
}
