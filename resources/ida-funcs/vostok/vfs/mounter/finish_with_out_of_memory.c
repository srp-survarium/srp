void __thiscall vostok::vfs::mounter::finish_with_out_of_memory(vostok::vfs::mounter *this, int a2)
{
  vostok::vfs::mount_result *v2; // ecx
  vostok::vfs::mounter *v3; // eax
  vostok::vfs::mounter *v4; // ecx
  vostok::vfs::mounter *v5; // ecx
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v6; // [esp-Ch] [ebp-28h] BYREF
  int v7; // [esp-8h] [ebp-24h]
  int v8; // [esp-4h] [ebp-20h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v9; // [esp+10h] [ebp-Ch] BYREF

  v8 = 0;
  v7 = 3;
  v6.m_object = (vostok::vfs::vfs_mount *)this;
  *(_DWORD *)(a2 + 68) = 3;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &v6,
    (const vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)(a2 + 64));
  vostok::vfs::mount_result::mount_result(v2, &v9, v6, (vostok::vfs::vfs_mount *)v7);
  vostok::vfs::mounter::finish(v4, (vostok::vfs::mount_result *)a2, v3, v8);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v9);
  vostok::vfs::mounter::destroy_this_if_needed(v5, (_DWORD *)a2);
}
