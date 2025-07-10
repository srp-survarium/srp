void __thiscall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>>::owner_finalize(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4> > *this)
{
  DWORD v1; // eax
  vostok::network::response *v2; // eax
  vostok::network::response *v3; // eax
  vostok::network::response *value_to_delete; // [esp+7Ch] [ebp-4h] BYREF

  v1 = vostok::threading::current_thread_id();
  vostok::threading::interlocked_exchange_pointer(&this->m_forward_queue.m_pop_thread_id, v1);
  while ( !vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>::empty(&this->m_forward_queue) )
  {
    vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>::pop_front(
      &this->m_forward_queue,
      &value_to_delete);
    vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::delete_value(
      this,
      value_to_delete);
  }
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::owner_delete_processed_items(this);
  v2 = vostok::intrusive_spsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,4>::pop_null_node(&this->m_backward_queue);
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::delete_value(
    this,
    v2);
  v3 = vostok::intrusive_spsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,4>::pop_null_node(&this->m_forward_queue);
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::delete_value(
    this,
    v3);
}
