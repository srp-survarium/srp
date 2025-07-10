void __thiscall vostok::vfs::vfs_locked_iterator::unlock_and_decref_if_needed(vostok::vfs::vfs_locked_iterator *this)
{
  if ( this->m_node )
    vostok::vfs::unlock_and_decref_recursively(
      this->m_node,
      lock_type_read,
      (vostok::vfs::find_enum)(this->m_type == type_recursive),
      this->m_hashset,
      this->mount_operation_id);
}
