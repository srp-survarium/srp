void __thiscall vostok::network::network_world::finalize(vostok::network::network_world *this)
{
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8> > *p_orders; // edi
  DWORD CurrentThreadId; // eax
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8> > *p_m_pop_thread_id; // ecx
  vostok::network::order *m_tail; // eax
  vostok::network::order *next_for_orders; // ecx
  vostok::network::order *m_head; // esi
  vostok::network::order *v7; // esi
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8> > *v8; // [esp+0h] [ebp-10h]
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8> > *v9; // [esp+0h] [ebp-10h]
  vostok::network::order *value; // [esp+Ch] [ebp-4h]

  p_orders = &this->m_channel.orders;
  CurrentThreadId = GetCurrentThreadId();
  p_m_pop_thread_id = (vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8> > *)&p_orders->m_forward_queue.m_pop_thread_id;
  _InterlockedExchange(&p_orders->m_forward_queue.m_pop_thread_id, CurrentThreadId);
  while ( 1 )
  {
    m_tail = p_orders->m_forward_queue.m_tail;
    if ( !m_tail->next_for_orders )
      break;
    next_for_orders = m_tail->next_for_orders;
    if ( next_for_orders )
    {
      value = p_orders->m_forward_queue.m_tail;
      p_orders->m_forward_queue.m_tail = next_for_orders;
    }
    vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>>::delete_value(
      value,
      v8);
  }
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>>::owner_delete_processed_items(
    p_m_pop_thread_id,
    (int)p_orders);
  m_head = p_orders->m_backward_queue.m_head;
  p_orders->m_backward_queue.m_tail = 0;
  p_orders->m_backward_queue.m_head = 0;
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>>::delete_value(
    m_head,
    v8);
  v7 = p_orders->m_forward_queue.m_head;
  p_orders->m_forward_queue.m_tail = 0;
  p_orders->m_forward_queue.m_head = 0;
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>>::delete_value(
    v7,
    v9);
}
