void __thiscall vostok::strings::text_tree::text_tree(
        vostok::strings::text_tree *this,
        void *buffer,
        unsigned int buffer_size,
        char *root_name)
{
  vostok::strings::text_tree_item *v5; // ecx

  this->m_root.m_sub_items.m_size = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&this->m_root.m_sub_items.vostok::threading::mutex, 0x2710u);
  this->m_root.m_sub_items.m_first = 0;
  this->m_root.m_sub_items.m_last = 0;
  this->m_root.m_column_items.m_size = 0;
  InitializeCriticalSectionAndSpinCount(
    (LPCRITICAL_SECTION)&this->m_root.m_column_items.vostok::threading::mutex,
    0x2710u);
  this->m_root.m_column_items.m_first = 0;
  this->m_root.m_column_items.m_last = 0;
  this->m_root.m_column_value = 0;
  this->m_root.m_allocator = &this->m_allocator;
  this->m_root.m_is_visible = 1;
  this->m_root.m_is_page_breaker = 0;
  this->m_allocator.m_arena_start = 0;
  this->m_allocator.m_arena_end = 0;
  this->m_allocator.m_arena_id = 0;
  this->m_allocator.__vftable = (vostok::memory::stack_allocator_vtbl *)&vostok::memory::stack_allocator::`vftable';
  this->m_allocator.m_arena_current_position = 0;
  ((void (__thiscall *)(vostok::memory::stack_allocator *, void *, unsigned int, _DWORD, const char *))this->m_allocator.initialize)(
    &this->m_allocator,
    buffer,
    buffer_size,
    0,
    "text_tree");
  vostok::strings::text_tree_item::set_name(v5, (int)this, root_name);
}
