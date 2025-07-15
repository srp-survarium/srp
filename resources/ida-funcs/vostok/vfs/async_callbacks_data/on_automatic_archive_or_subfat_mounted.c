void __thiscall vostok::vfs::async_callbacks_data::on_automatic_archive_or_subfat_mounted(
        vostok::vfs::async_callbacks_data *this,
        vostok::vfs::mount_result mount,
        int increment)
{
  vostok::vfs::base_node<1> *m_mount_root; // eax

  if ( mount.result == result_success )
  {
    m_mount_root = (vostok::vfs::base_node<1> *)mount.mount.m_object->m_mount_root;
    if ( m_mount_root )
      m_mount_root = *(vostok::vfs::base_node<1> **)&m_mount_root->m_name[13];
    vostok::vfs::change_subfat_ref_for_node(
      (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)increment,
      m_mount_root,
      &this->env.mount_operation_id);
  }
  vostok::vfs::async_callbacks_data::on_callback_may_destroy_this(this, (int)this, mount.result);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&mount.mount);
}
