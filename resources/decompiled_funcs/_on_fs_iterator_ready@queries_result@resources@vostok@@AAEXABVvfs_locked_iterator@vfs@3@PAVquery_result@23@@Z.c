void __thiscall vostok::resources::queries_result::on_fs_iterator_ready(
        vostok::resources::queries_result *this,
        const vostok::vfs::vfs_locked_iterator *it,
        vostok::resources::query_result *query)
{
  vostok::resources::queries_result *v4; // ecx
  vostok::resources::resources_manager *p_m_result; // ecx

  vostok::vfs::vfs_locked_iterator::grab(&query->m_result_iterator, it);
  vostok::threading::interlocked_or(&query->m_flags, 0x200u);
  vostok::threading::interlocked_and(&query->m_flags, 0xFFFDFFFF);
  vostok::vfs::vfs_iterator::operator bool(&query->m_result_iterator);
  if ( this->m_fs_iterator_requests_left-- == 1 )
  {
    if ( vostok::resources::queries_result::calculate_result_from_children(v4, (int)this) )
    {
      p_m_result = (vostok::resources::resources_manager *)_InterlockedExchange(&this->m_result, 1);
    }
    else
    {
      p_m_result = (vostok::resources::resources_manager *)&this->m_result;
      _InterlockedExchange(&this->m_result, 0);
    }
    if ( !_InterlockedExchangeAdd(&this->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::resources_manager::on_query_finished(
        p_m_result,
        vostok::resources::g_resources_manager.m_variable,
        this);
  }
}
