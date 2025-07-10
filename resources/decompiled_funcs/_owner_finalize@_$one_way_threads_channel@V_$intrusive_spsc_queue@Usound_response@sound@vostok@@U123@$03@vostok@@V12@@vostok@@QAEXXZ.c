void __thiscall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>>::owner_finalize(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> > *this)
{
  vostok::memory::detail::call_destructor_predicate v2; // [esp+13h] [ebp-7Dh] BYREF
  vostok::memory::base_allocator *v3; // [esp+14h] [ebp-7Ch]
  vostok::sound::sound_order *v4; // [esp+18h] [ebp-78h] BYREF
  vostok::sound::sound_order *v5; // [esp+24h] [ebp-6Ch]
  vostok::memory::detail::call_destructor_predicate v6; // [esp+33h] [ebp-5Dh] BYREF
  vostok::memory::base_allocator *m_owner_allocator; // [esp+34h] [ebp-5Ch]
  vostok::sound::sound_order *v8[13]; // [esp+38h] [ebp-58h] BYREF
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+6Fh] [ebp-21h] BYREF
  vostok::memory::base_allocator *allocator; // [esp+70h] [ebp-20h]
  vostok::sound::sound_order *pointer; // [esp+74h] [ebp-1Ch] BYREF
  char v12; // [esp+86h] [ebp-Ah]
  char v13; // [esp+87h] [ebp-9h]
  DWORD v14; // [esp+88h] [ebp-8h]
  vostok::sound::sound_order *value_to_delete; // [esp+8Ch] [ebp-4h] BYREF

  v14 = vostok::threading::current_thread_id();
  _InterlockedExchange(&this->m_forward_queue.m_pop_thread_id, v14);
  while ( 1 )
  {
    v13 = 0;
    v12 = 0;
    if ( !this->m_forward_queue.m_tail->m_next_for_orders )
      break;
    vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>::pop_front(
      &this->m_forward_queue,
      &value_to_delete);
    v8[10] = value_to_delete;
    pointer = value_to_delete;
    allocator = this->m_owner_allocator;
    call_destructor_predicate = 0;
    vostok::memory::detail::delete_helper_impl<vostok::memory::base_allocator,vostok::sound::sound_order,vostok::memory::detail::call_destructor_predicate>(
      allocator,
      &pointer,
      &call_destructor_predicate);
  }
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>>::owner_delete_processed_items(this);
  v5 = vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>::pop_null_node(&this->m_backward_queue);
  v8[0] = v5;
  m_owner_allocator = this->m_owner_allocator;
  v6 = 0;
  vostok::memory::detail::delete_helper_impl<vostok::memory::base_allocator,vostok::sound::sound_order,vostok::memory::detail::call_destructor_predicate>(
    m_owner_allocator,
    v8,
    &v6);
  v4 = vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>::pop_null_node(&this->m_forward_queue);
  v3 = this->m_owner_allocator;
  v2 = 0;
  vostok::memory::detail::delete_helper_impl<vostok::memory::base_allocator,vostok::sound::sound_order,vostok::memory::detail::call_destructor_predicate>(
    v3,
    &v4,
    &v2);
}
