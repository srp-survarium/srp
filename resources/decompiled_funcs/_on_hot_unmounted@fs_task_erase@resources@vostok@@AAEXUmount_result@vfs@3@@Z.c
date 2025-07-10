void __thiscall vostok::resources::fs_task_erase::on_hot_unmounted(
        vostok::resources::fs_task_erase *this,
        vostok::vfs::mount_result result)
{
  vostok::resources::fs_task *v3; // ecx

  _unlink(this->m_physical_path.m_string.m_begin);
  this->m_result = 1;
  vostok::resources::fs_task::on_task_ready_may_destroy_this(v3, this);
  vostok::vfs::mount_result::~mount_result(&result);
}
