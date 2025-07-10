vostok::memory::managed_allocator_base *__usercall vostok::memory::managed_allocator_base::deallocate@<eax>(
        vostok::memory::managed_allocator_base *this@<ecx>,
        int a2@<edi>)
{
  unsigned int v2; // eax
  unsigned int v3; // esi
  bool v4; // bl
  int v5; // edx
  unsigned int v6; // ebp
  int v7; // ecx
  vostok::memory::managed_allocator_base *result; // eax
  vostok::memory::managed_node *m_pinned; // ecx
  int v10; // edx
  vostok::memory::managed_allocator_base **v11; // eax
  bool can_join_prev; // [esp+Fh] [ebp-1h]

  *(_DWORD *)(a2 + 20) += this->m_num_unpinned_objects;
  v2 = *(_DWORD *)a2;
  v3 = 0;
  if ( !*(_DWORD *)a2 )
    goto LABEL_6;
  do
  {
    if ( v2 > (unsigned int)this )
      break;
    v3 = v2;
    v2 = *(_DWORD *)(v2 + 12);
  }
  while ( v2 );
  if ( !v3 || (can_join_prev = 1, *(vostok::memory::managed_allocator_base **)(v3 + 4) != this) )
LABEL_6:
    can_join_prev = 0;
  v4 = v2 && *(vostok::memory::managed_allocator_base **)(v2 + 8) == this;
  if ( *(_BYTE *)(a2 + 8) && (v5 = *(_DWORD *)(a2 + 12)) != 0 )
    v6 = *(_DWORD *)(v5 + 40);
  else
    v6 = 0;
  if ( can_join_prev )
  {
    if ( v4 )
    {
      *(_DWORD *)(v3 + 40) += this->m_num_unpinned_objects + *(_DWORD *)(v2 + 40);
      *(_DWORD *)(v3 + 4) = *(_DWORD *)(v2 + 4);
      v7 = *(_DWORD *)(v2 + 4);
      if ( v7 )
        *(_DWORD *)(v7 + 8) = v3;
      *(_DWORD *)(v3 + 12) = *(_DWORD *)(v2 + 12);
      result = (vostok::memory::managed_allocator_base *)v3;
    }
    else
    {
      *(_DWORD *)(v3 + 40) += this->m_num_unpinned_objects;
      *(_DWORD *)(v3 + 4) = this->m_pinned;
      m_pinned = this->m_pinned;
      if ( m_pinned )
        m_pinned->m_prev = (vostok::memory::managed_node *)v3;
      result = (vostok::memory::managed_allocator_base *)v3;
    }
  }
  else
  {
    LOBYTE(this[1].m_pinned) = 1;
    if ( v4 )
    {
      this->m_num_unpinned_objects += *(_DWORD *)(v2 + 40);
      this->m_pinned = *(vostok::memory::managed_node **)(v2 + 4);
      v10 = *(_DWORD *)(v2 + 4);
      if ( v10 )
        *(_DWORD *)(v10 + 8) = this;
      v2 = *(_DWORD *)(v2 + 12);
    }
    this->m_largest_free_block = (vostok::memory::managed_node *)v2;
    v11 = (vostok::memory::managed_allocator_base **)(v3 + 12);
    if ( !v3 )
      v11 = (vostok::memory::managed_allocator_base **)a2;
    *v11 = this;
    result = this;
  }
  if ( *(_BYTE *)(a2 + 8) )
  {
    if ( result->m_num_unpinned_objects > v6 )
      *(_DWORD *)(a2 + 12) = result;
  }
  return result;
}
