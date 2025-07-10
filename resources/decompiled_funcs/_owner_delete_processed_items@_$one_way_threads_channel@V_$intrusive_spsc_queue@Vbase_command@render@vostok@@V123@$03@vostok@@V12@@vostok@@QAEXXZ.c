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
