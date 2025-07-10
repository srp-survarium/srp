void __userpurge vostok::strings::text_tree_item::text_tree_item(
        vostok::strings::text_tree_item *this@<ecx>,
        int a2@<esi>,
        vostok::memory::stack_allocator *allocator,
        char *value,
        bool is_page_breaker)
{
  unsigned int v5; // eax
  unsigned __int8 *m_arena_current_position; // edi

  *(_DWORD *)(a2 + 8) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 16), 0x2710u);
  *(_DWORD *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 56) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 64), 0x2710u);
  *(_DWORD *)(a2 + 92) = 0;
  *(_DWORD *)(a2 + 96) = 0;
  *(_BYTE *)(a2 + 113) = is_page_breaker;
  *(_DWORD *)(a2 + 104) = 0;
  *(_DWORD *)(a2 + 108) = allocator;
  *(_BYTE *)(a2 + 112) = 1;
  if ( value )
  {
    v5 = strlen(value);
    m_arena_current_position = (unsigned __int8 *)allocator->m_arena_current_position;
    allocator->m_arena_current_position = &m_arena_current_position[v5 + 1];
    memcpy(m_arena_current_position, (unsigned __int8 *)value, v5 + 1);
    *(_DWORD *)(a2 + 104) = m_arena_current_position;
  }
}
