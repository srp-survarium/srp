void __thiscall vostok::resources::fs_task_iterator::execute_may_destroy_this(
        vostok::resources::fs_task_iterator *this)
{
  bool *p_m_in_sync_call; // edi
  vostok::resources::fs_task *v3; // ecx
  bool v4; // zf

  p_m_in_sync_call = &this->m_in_sync_call;
  this->m_in_sync_call = 1;
  do
    vostok::resources::fs_task_iterator::try_async_query(this);
  while ( this->m_vfs_result == result_cannot_lock );
  v4 = !this->m_iterator_ready;
  *p_m_in_sync_call = 0;
  if ( !v4 )
    vostok::resources::fs_task::on_task_ready_may_destroy_this(v3, (survarium::player_params_modifier *)this);
}
