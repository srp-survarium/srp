void __thiscall vostok::sound::world_user::process_orders(vostok::sound::world_user *this)
{
  vostok::sound::sound_order *order; // [esp+4Ch] [ebp-4h]

  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>>::owner_delete_processed_items((vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> > *)this);
  while ( 1 )
  {
    order = vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>>::user_pop_front(&this->m_channel.orders);
    if ( !order )
      break;
    order->execute(order);
  }
}
