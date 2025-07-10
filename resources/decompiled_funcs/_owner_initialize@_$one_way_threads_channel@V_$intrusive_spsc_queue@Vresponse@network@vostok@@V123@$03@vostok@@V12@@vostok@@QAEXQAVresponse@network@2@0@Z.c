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
