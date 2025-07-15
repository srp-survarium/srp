signed __int32 __thiscall vostok::vfs::vfs_mount::change_reference_count_change_may_destroy_this(
        vostok::vfs::vfs_mount *this,
        int change)
{
  signed __int32 v4; // [esp+8h] [ebp-10h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> holder; // [esp+14h] [ebp-4h] BYREF

  if ( change > 0 )
    return change + _InterlockedExchangeAdd(&this->m_reference_count, change);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &holder,
    this);
  v4 = vostok::threading::multi_threading_policy::intrusive_ptr_decrement<vostok::resources::unmanaged_intrusive_base>((vostok::resources::unmanaged_intrusive_base *)this)
     - 1;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&holder);
  return v4;
}
