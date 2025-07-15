void __thiscall vostok::strings::text_tree::~text_tree(vostok::strings::text_tree *this)
{
  vostok::memory::stack_allocator *p_m_allocator; // esi

  p_m_allocator = &this->m_allocator;
  this->m_allocator.finalize_impl(&this->m_allocator);
  p_m_allocator->m_arena_start = 0;
  p_m_allocator->m_arena_end = 0;
  p_m_allocator->m_arena_id = 0;
  p_m_allocator->__vftable = (vostok::memory::stack_allocator_vtbl *)&vostok::memory::base_allocator::`vftable';
  vostok::strings::text_tree_item::~text_tree_item(&this->m_root);
}
