void __userpurge vostok::strings::text_tree_item::text_tree_item(
        vostok::strings::text_tree_item *this@<esi>,
        vostok::memory::stack_allocator *allocator@<edi>,
        vostok::threading::mutex_tasks_unaware *a3@<ecx>,
        char *value,
        bool is_page_breaker)
{
  vostok::threading::mutex_tasks_unaware *v5; // ecx

  this->m_sub_items.m_size = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    a3,
    (_RTL_CRITICAL_SECTION *)&this->m_sub_items.vostok::threading::mutex);
  this->m_sub_items.m_first = 0;
  this->m_sub_items.m_last = 0;
  this->m_column_items.m_size = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    v5,
    (_RTL_CRITICAL_SECTION *)&this->m_column_items.vostok::threading::mutex);
  this->m_column_items.m_first = 0;
  this->m_column_items.m_last = 0;
  this->m_column_value = 0;
  this->m_is_page_breaker = 0;
  this->m_allocator = allocator;
  this->m_is_visible = 1;
  if ( value )
    this->m_column_value = vostok::strings::duplicate<vostok::memory::stack_allocator>(allocator, value);
}
