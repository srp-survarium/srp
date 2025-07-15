void __thiscall vostok::network::network_world::dispatch_callbacks(vostok::network::network_world *this)
{
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8> > *v2; // ecx
  unsigned int i; // ebx
  vostok::network::response *v4; // eax
  int v5; // ecx

  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>>::owner_delete_processed_items(
    (vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8> > *)this,
    (int)&this->m_channel.orders);
  for ( i = 0; i < 0xA; ++i )
  {
    v4 = vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>>::user_pop_front(
           v2,
           (int)&this->m_channel);
    if ( !v4 )
      break;
    v4->execute(v4);
  }
  v5 = -(this->m_on_dispatch_callbacks.vtable != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v5) != 0 )
    boost::function0<void>::operator()((boost::function0<bool> *)v5, &this->m_on_dispatch_callbacks.vtable);
}
