void __thiscall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>>::owner_delete_processed_items(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> > *this)
{
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+Fh] [ebp-1Dh] BYREF
  vostok::memory::base_allocator *allocator; // [esp+10h] [ebp-1Ch]
  vostok::sound::sound_order *pointer; // [esp+14h] [ebp-18h] BYREF
  vostok::sound::sound_order *v5; // [esp+24h] [ebp-8h] BYREF
  vostok::sound::sound_order *item_to_delete; // [esp+28h] [ebp-4h]

  while ( 1 )
  {
    item_to_delete = vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>::pop_front(
                       &this->m_backward_queue,
                       &v5)
                   ? v5
                   : 0;
    if ( !item_to_delete )
      break;
    pointer = item_to_delete;
    allocator = this->m_owner_allocator;
    call_destructor_predicate = 0;
    vostok::memory::detail::delete_helper_impl<vostok::memory::base_allocator,vostok::sound::sound_order,vostok::memory::detail::call_destructor_predicate>(
      allocator,
      &pointer,
      &call_destructor_predicate);
  }
}


void __thiscall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>>::owner_delete_processed_items(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4> > *this,
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4> > *thisa)
{
  vostok::render::base_command *m_tail; // esi
  vostok::render::base_command *next; // eax
  vostok::memory::base_allocator *m_owner_allocator; // edi
  void *v5; // ebp

  while ( 1 )
  {
    m_tail = thisa->m_backward_queue.m_tail;
    next = m_tail->next;
    if ( !next )
      break;
    thisa->m_backward_queue.m_tail = next;
    m_owner_allocator = thisa->m_owner_allocator;
    v5 = __RTCastToVoid(m_tail);
    ((void (__thiscall *)(vostok::render::base_command *, _DWORD))m_tail->~vostok::render::base_command)(m_tail, 0);
    m_owner_allocator->call_free(m_owner_allocator, v5);
  }
}


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
