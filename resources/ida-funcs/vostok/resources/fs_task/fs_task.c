void __userpurge vostok::resources::fs_task::fs_task(
        vostok::resources::fs_task *this@<esi>,
        vostok::resources::fs_task::type_enum type@<eax>,
        vostok::memory::base_allocator *allocator,
        vostok::resources::query_result_for_cook *parent_query)
{
  this->m_next = 0;
  this->m_type = type;
  this->__vftable = (vostok::resources::fs_task_vtbl *)&vostok::resources::fs_task::`vftable';
  this->m_result = 0;
  this->m_allocator = allocator;
  this->m_thread_id = GetCurrentThreadId();
  this->m_parent_query = parent_query;
}
