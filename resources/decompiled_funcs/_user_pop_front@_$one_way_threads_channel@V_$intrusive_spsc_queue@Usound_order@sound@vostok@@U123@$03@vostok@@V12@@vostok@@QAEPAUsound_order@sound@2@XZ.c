vostok::sound::sound_order *__thiscall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>>::user_pop_front(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> > *this)
{
  vostok::sound::sound_order *v3; // [esp+18h] [ebp-Ch]
  vostok::sound::sound_order *item_to_delete; // [esp+1Ch] [ebp-8h] BYREF
  char v5; // [esp+23h] [ebp-1h]

  v5 = 0;
  v3 = vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>::pop_front(
         &this->m_forward_queue,
         &item_to_delete);
  if ( v3 )
    vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>::push_back(
      &this->m_backward_queue,
      item_to_delete);
  return v3;
}
