void __usercall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>>::owner_delete_processed_items(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8> > *this@<ecx>,
        int a2@<eax>)
{
  vostok::network::order **v2; // edi
  vostok::network::order *v3; // esi
  vostok::network::order *next_for_orders; // eax
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8> > *v5; // [esp+0h] [ebp-8h]

  v2 = (vostok::network::order **)(a2 + 132);
  while ( 1 )
  {
    v3 = *v2;
    next_for_orders = (*v2)->next_for_orders;
    if ( !next_for_orders )
      break;
    *v2 = next_for_orders;
    vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>>::delete_value(
      v3,
      v5);
  }
}
