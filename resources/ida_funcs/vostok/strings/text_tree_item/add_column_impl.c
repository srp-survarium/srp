void __thiscall vostok::strings::text_tree_item::add_column_impl(vostok::strings::text_tree_item *this, char *s)
{
  vostok::memory::stack_allocator *m_allocator; // ecx
  vostok::strings::text_tree_item *m_arena_current_position; // eax
  vostok::strings::text_tree_item *v5; // edi
  vostok::memory::stack_allocator *v6; // ecx
  unsigned int v7; // eax
  unsigned __int8 *v8; // esi
  vostok::intrusive_list<vostok::strings::text_tree_item_base,vostok::strings::text_tree_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v9; // ecx
  bool *v10; // [esp+0h] [ebp-10h]

  m_allocator = this->m_allocator;
  m_arena_current_position = (vostok::strings::text_tree_item *)m_allocator->m_arena_current_position;
  v5 = 0;
  m_allocator->m_arena_current_position = &m_arena_current_position->m_sub_items;
  if ( m_arena_current_position )
  {
    m_arena_current_position->m_next_brother = 0;
    *((_DWORD *)&m_arena_current_position->vostok::strings::text_tree_item_base + 1) = 0;
    v5 = m_arena_current_position;
  }
  v6 = this->m_allocator;
  v7 = strlen(s);
  v8 = (unsigned __int8 *)v6->m_arena_current_position;
  v6->m_arena_current_position = &v8[v7 + 1];
  memcpy(v8, (unsigned __int8 *)s, v7 + 1);
  *((_DWORD *)&v5->vostok::strings::text_tree_item_base + 1) = v8;
  vostok::intrusive_list<vostok::strings::text_tree_column_item,vostok::strings::text_tree_column_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    v9,
    (int)&this->m_column_items,
    v5,
    v10);
}
