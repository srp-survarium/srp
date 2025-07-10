vostok::strings::text_tree_item *__thiscall vostok::strings::text_tree_item::new_child(
        vostok::strings::text_tree_item *this,
        vostok::strings::text_tree_item *s,
        bool is_page_breaker)
{
  vostok::memory::stack_allocator *m_allocator; // eax
  int m_arena_current_position; // esi
  vostok::strings::text_tree_item *v6; // eax
  vostok::strings::text_tree_item *v7; // ebx
  vostok::intrusive_list<vostok::strings::text_tree_item_base,vostok::strings::text_tree_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v8; // ecx
  bool *v10; // [esp+0h] [ebp-Ch]

  m_allocator = this->m_allocator;
  m_arena_current_position = (int)m_allocator->m_arena_current_position;
  m_allocator->m_arena_current_position = (void *)(m_arena_current_position + 120);
  if ( m_arena_current_position )
  {
    vostok::strings::text_tree_item::text_tree_item(
      s,
      m_arena_current_position,
      this->m_allocator,
      (char *)s,
      is_page_breaker);
    v7 = v6;
    vostok::intrusive_list<vostok::strings::text_tree_column_item,vostok::strings::text_tree_column_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v8,
      (int)&this->m_sub_items,
      v6,
      v10);
    return v7;
  }
  else
  {
    vostok::intrusive_list<vostok::strings::text_tree_column_item,vostok::strings::text_tree_column_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      (vostok::intrusive_list<vostok::strings::text_tree_item_base,vostok::strings::text_tree_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)0x78,
      (int)&this->m_sub_items,
      0,
      v10);
    return 0;
  }
}
