void __thiscall vostok::resources::queries_result::on_fs_iterator_ready(
        vostok::resources::queries_result *this,
        const vostok::vfs::vfs_locked_iterator *it,
        vostok::resources::query_result *query)
{
  char v5; // al
  vostok::resources::queries_result *v6; // ecx

  vostok::vfs::vfs_locked_iterator::grab(&query->m_result_iterator, it, (vostok::vfs::vfs_locked_iterator *)this);
  _InterlockedOr(&query->m_flags, 0x200u);
  _InterlockedAnd(&query->m_flags, 0xFFFDFFFF);
  if ( this->m_fs_iterator_requests_left-- == 1 )
  {
    v5 = vostok::resources::queries_result::calculate_result_from_children(
           (vostok::resources::queries_result *)0xFFFDFFFF,
           (int)this);
    vostok::resources::queries_result::on_query_end(v6, v5);
  }
}
