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


void __thiscall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>>::owner_initialize(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4> > *this,
        vostok::network::response *const forward_queue_initial_value,
        vostok::network::response *const backward_queue_initial_value)
{
  DWORD v3; // eax
  DWORD v4; // eax

  v3 = vostok::threading::current_thread_id();
  vostok::threading::interlocked_exchange_pointer(&this->m_forward_queue.m_push_thread_id, v3);
  vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>::push_null_node(
    &this->m_forward_queue,
    backward_queue_initial_value);
  v4 = vostok::threading::current_thread_id();
  vostok::threading::interlocked_exchange_pointer(&this->m_backward_queue.m_pop_thread_id, v4);
  vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>::push_null_node(
    &this->m_backward_queue,
    forward_queue_initial_value);
}
