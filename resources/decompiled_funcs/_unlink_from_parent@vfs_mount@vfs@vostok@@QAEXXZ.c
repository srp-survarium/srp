void __thiscall vostok::vfs::vfs_mount::unlink_from_parent(vostok::vfs::vfs_mount *this)
{
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v1; // [esp-4h] [ebp-60h] BYREF
  vostok::vfs::vfs_mount *thisa; // [esp+0h] [ebp-5Ch]

  thisa = this;
  if ( this->parent )
  {
    v1.m_object = this;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &v1,
      thisa);
    vostok::intrusive_double_linked_list<vostok::vfs::vfs_intrusive_mount_base,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,4,8,vostok::threading::simple_lock,vostok::size_policy,vostok::debug_policy>::erase(
      &thisa->parent->children,
      v1);
    thisa->parent = 0;
  }
}
