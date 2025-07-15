vostok::memory::managed_node *__usercall vostok::memory::managed_allocator_base::allocate@<eax>(
        vostok::memory::managed_allocator_base *this@<ecx>,
        vostok::memory::managed_node *a2@<edi>)
{
  unsigned int v2; // eax
  vostok::memory::managed_node *m_owner; // esi
  vostok::memory::managed_node *v4; // eax
  vostok::memory::managed_node *v5; // ebx
  vostok::memory::managed_node *result; // eax
  vostok::memory::managed_node *v7; // [esp+0h] [ebp-Ch]
  unsigned int v8; // [esp+8h] [ebp-4h]

  v2 = vostok::math::align_up<unsigned long>((unsigned int)a2->m_unpin_notify_allocator);
  m_owner = (vostok::memory::managed_node *)a2->m_owner;
  v8 = v2;
  v4 = 0;
  v5 = 0;
  while ( m_owner )
  {
    result = vostok::memory::managed_allocator_base::allocate_in_node(m_owner, a2, v8, v4, v7);
    if ( result )
      return result;
    if ( !v5 || v5->m_size < m_owner->m_size )
      v5 = m_owner;
    v4 = m_owner;
    m_owner = m_owner->m_next_free;
  }
  LOBYTE(a2->m_prev) = 1;
  a2->m_next_free = v5;
  return 0;
}
