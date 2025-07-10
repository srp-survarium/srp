vostok::network::response *__thiscall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::user_pop_front(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4> > *this)
{
  vostok::network::response *v3; // [esp+14h] [ebp-Ch]
  vostok::network::response *item_to_delete; // [esp+18h] [ebp-8h] BYREF
  char v5; // [esp+1Fh] [ebp-1h]

  v5 = 0;
  v3 = vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>::pop_front(
         &this->m_forward_queue,
         &item_to_delete);
  if ( v3 )
    vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>::push_back(
      &this->m_backward_queue,
      item_to_delete);
  return v3;
}
