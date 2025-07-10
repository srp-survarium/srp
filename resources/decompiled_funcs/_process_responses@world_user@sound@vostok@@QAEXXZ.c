void __thiscall vostok::sound::world_user::process_responses(vostok::sound::world_user *this)
{
  vostok::sound::sound_response *response; // [esp+4Ch] [ebp-4h]

  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>>::owner_delete_processed_items(&this->m_channel.orders);
  while ( 1 )
  {
    response = (vostok::sound::sound_response *)vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>>::user_pop_front((vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> > *)this);
    if ( !response )
      break;
    response->execute(response);
  }
}
