BOOL __thiscall vostok::resources::fs_task_iterator::is_helper_query_for_mount(
        vostok::resources::fs_task_iterator *this)
{
  vostok::resources::query_result_for_cook *m_parent_query; // eax

  m_parent_query = this->m_parent_query;
  return m_parent_query
      && ((int)m_parent_query[1].m_memory_usage_self.vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::type
        & 0x8000000) != 0;
}
