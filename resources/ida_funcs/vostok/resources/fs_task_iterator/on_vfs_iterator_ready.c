void __thiscall vostok::resources::fs_task_iterator::on_vfs_iterator_ready(
        vostok::resources::fs_task_iterator *this,
        const vostok::vfs::vfs_locked_iterator *iterator,
        vostok::vfs::result_enum result)
{
  vostok::resources::fs_task *v4; // ecx
  bool v5; // zf

  this->m_vfs_result = result;
  if ( result == result_requery )
  {
    if ( !this->m_in_sync_call )
      vostok::resources::fs_task_iterator::try_async_query(this);
  }
  else
  {
    vostok::vfs::vfs_locked_iterator::grab(&this->m_iterator, iterator);
    v5 = !this->m_in_sync_call;
    this->m_iterator_ready = 1;
    if ( v5 )
      vostok::resources::fs_task::on_task_ready_may_destroy_this(v4, this);
  }
}
