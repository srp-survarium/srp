void __userpurge vostok::resources::fs_task::fs_task(
        vostok::resources::fs_task *this@<esi>,
        vostok::memory::base_allocator *allocator@<ecx>,
        vostok::resources::fs_task::type_enum type,
        vostok::resources::query_result_for_cook *parent_query)
{
  this->m_next = 0;
  this->m_result = 0;
  this->__vftable = (vostok::resources::fs_task_vtbl *)&vostok::resources::fs_task::`vftable';
  this->m_type = type;
  this->m_allocator = allocator;
  this->m_thread_id = GetCurrentThreadId();
  this->m_parent_query = parent_query;
}
