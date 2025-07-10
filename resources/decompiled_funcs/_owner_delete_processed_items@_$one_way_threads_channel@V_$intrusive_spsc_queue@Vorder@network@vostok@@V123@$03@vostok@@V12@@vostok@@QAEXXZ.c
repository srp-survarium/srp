void __thiscall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::owner_delete_processed_items(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4> > *this)
{
  vostok::network::response *v2; // [esp+24h] [ebp-8h] BYREF
  vostok::network::response *item_to_delete; // [esp+28h] [ebp-4h]

  while ( 1 )
  {
    item_to_delete = vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>::pop_front(
                       &this->m_backward_queue,
                       &v2)
                   ? v2
                   : 0;
    if ( !item_to_delete )
      break;
    vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::delete_value(
      this,
      item_to_delete);
  }
}
