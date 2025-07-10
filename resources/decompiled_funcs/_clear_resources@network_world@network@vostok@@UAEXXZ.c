void __thiscall vostok::network::network_world::clear_resources(vostok::network::network_world *this)
{
  vostok::network::response *response; // [esp+48h] [ebp-4h]

  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::owner_delete_processed_items((vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4> > *)&this->m_channel.orders);
  while ( 1 )
  {
    response = vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::user_pop_front(&this->m_channel.responses);
    if ( !response )
      break;
    response->execute(response);
  }
}
