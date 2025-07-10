void __thiscall vostok::vfs::vfs_intrusive_mount_base::unlink_children(
        vostok::vfs::vfs_intrusive_mount_base *this,
        vostok::vfs::vfs_mount *object,
        vostok::vfs::virtual_file_system *__formal)
{
  survarium::game_camera *v3; // ecx
  vostok::vfs::vfs_mount *v4; // ecx
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> child; // [esp+4Ch] [ebp-4h] BYREF

  while ( !vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&object->children.m_first) )
  {
    vostok::intrusive_double_linked_list<vostok::vfs::vfs_intrusive_mount_base,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,4,8,vostok::threading::simple_lock,vostok::size_policy,vostok::debug_policy>::pop_back(
      &object->children,
      &child,
      0);
    survarium::weapon_user_dead_state::finalize(v3);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
      &child,
      0,
      v4);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&child);
  }
}
