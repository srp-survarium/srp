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


void __usercall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>>::owner_finalize(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4> > *this@<ecx>,
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4> > *a2@<eax>)
{
  DWORD CurrentThreadId; // eax
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4> > *p_m_pop_thread_id; // ecx
  vostok::render::base_command *v5; // edi
  vostok::render::base_command *m_tail; // eax
  vostok::memory::base_allocator *m_owner_allocator; // ebx
  void *v8; // ebp
  vostok::render::base_command *m_head; // edi
  vostok::memory::base_allocator *v10; // ebx
  void *v11; // ebp
  vostok::render::base_command *v12; // edi
  vostok::memory::base_allocator *v13; // esi
  void *v14; // ebx
  vostok::render::base_command *value_to_delete; // [esp+10h] [ebp-4h]

  CurrentThreadId = GetCurrentThreadId();
  p_m_pop_thread_id = (vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4> > *)&a2->m_forward_queue.m_pop_thread_id;
  _InterlockedExchange(&a2->m_forward_queue.m_pop_thread_id, CurrentThreadId);
  v5 = value_to_delete;
  while ( 1 )
  {
    m_tail = a2->m_forward_queue.m_tail;
    if ( !m_tail->next )
      break;
    p_m_pop_thread_id = (vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4> > *)m_tail->next;
    if ( p_m_pop_thread_id )
    {
      v5 = a2->m_forward_queue.m_tail;
      a2->m_forward_queue.m_tail = (vostok::render::base_command *)p_m_pop_thread_id;
    }
    m_owner_allocator = a2->m_owner_allocator;
    if ( v5 )
    {
      v8 = __RTCastToVoid(v5);
      ((void (__thiscall *)(vostok::render::base_command *, _DWORD))v5->~vostok::render::base_command)(v5, 0);
      m_owner_allocator->call_free(m_owner_allocator, v8);
    }
  }
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>>::owner_delete_processed_items(
    p_m_pop_thread_id,
    a2);
  m_head = a2->m_backward_queue.m_head;
  a2->m_backward_queue.m_tail = 0;
  a2->m_backward_queue.m_head = 0;
  v10 = a2->m_owner_allocator;
  if ( m_head )
  {
    v11 = __RTCastToVoid(m_head);
    ((void (__thiscall *)(vostok::render::base_command *, _DWORD))m_head->~vostok::render::base_command)(m_head, 0);
    v10->call_free(v10, v11);
  }
  v12 = a2->m_forward_queue.m_head;
  a2->m_forward_queue.m_tail = 0;
  a2->m_forward_queue.m_head = 0;
  v13 = a2->m_owner_allocator;
  if ( v12 )
  {
    v14 = __RTCastToVoid(v12);
    ((void (__thiscall *)(vostok::render::base_command *, _DWORD))v12->~vostok::render::base_command)(v12, 0);
    v13->call_free(v13, v14);
  }
}


void __thiscall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>>::owner_finalize(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4> > *this)
{
  DWORD v1; // eax
  vostok::network::response *v2; // eax
  vostok::network::response *v3; // eax
  vostok::network::response *value_to_delete; // [esp+7Ch] [ebp-4h] BYREF

  v1 = vostok::threading::current_thread_id();
  vostok::threading::interlocked_exchange_pointer(&this->m_forward_queue.m_pop_thread_id, v1);
  while ( !vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>::empty(&this->m_forward_queue) )
  {
    vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>::pop_front(
      &this->m_forward_queue,
      &value_to_delete);
    vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::delete_value(
      this,
      value_to_delete);
  }
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::owner_delete_processed_items(this);
  v2 = vostok::intrusive_spsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,4>::pop_null_node(&this->m_backward_queue);
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::delete_value(
    this,
    v2);
  v3 = vostok::intrusive_spsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,4>::pop_null_node(&this->m_forward_queue);
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::delete_value(
    this,
    v3);
}
