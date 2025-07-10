void __thiscall vostok::resources::fs_task_iterator::execute_may_destroy_this(
        vostok::resources::fs_task_iterator *this)
{
  vostok::resources::fs_task *v2; // ecx
  bool v3; // zf

  this->m_in_sync_call = 1;
  do
    vostok::resources::fs_task_iterator::try_async_query(this);
  while ( this->m_vfs_result == result_requery );
  v3 = !this->m_iterator_ready;
  this->m_in_sync_call = 0;
  if ( !v3 )
    vostok::resources::fs_task::on_task_ready_may_destroy_this(v2, this);
}
