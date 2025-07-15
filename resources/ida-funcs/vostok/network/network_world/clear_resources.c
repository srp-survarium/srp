void __thiscall vostok::network::network_world::clear_resources(vostok::network::network_world *this)
{
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8> > *v2; // ecx
  vostok::network::two_way_threads_channel *p_m_channel; // esi
  vostok::network::response *v4; // eax

  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>>::owner_delete_processed_items(
    (vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8> > *)this,
    (int)&this->m_channel.orders);
  p_m_channel = &this->m_channel;
  while ( 1 )
  {
    v4 = vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>>::user_pop_front(
           v2,
           (int)p_m_channel);
    if ( !v4 )
      break;
    v4->execute(v4);
  }
}
