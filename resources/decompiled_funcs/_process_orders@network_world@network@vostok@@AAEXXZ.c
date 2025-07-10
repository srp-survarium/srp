void __thiscall vostok::network::network_world::process_orders(vostok::network::network_world *this)
{
  vostok::network::order *order; // [esp+48h] [ebp-4h]

  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::owner_delete_processed_items(&this->m_channel.responses);
  while ( 1 )
  {
    order = (vostok::network::order *)vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::user_pop_front((vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4> > *)&this->m_channel.orders);
    if ( !order )
      break;
    order->execute(order);
  }
}
