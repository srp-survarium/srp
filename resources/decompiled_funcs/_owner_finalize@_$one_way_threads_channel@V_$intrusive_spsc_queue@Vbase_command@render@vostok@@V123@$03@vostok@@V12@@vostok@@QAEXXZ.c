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
