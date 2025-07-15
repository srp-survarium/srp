void __thiscall vostok::resources::vfs_sub_fat_cook::destroy_resource(
        vostok::resources::vfs_sub_fat_cook *this,
        vostok::resources::unmanaged_resource *resource)
{
  vostok::resources::unmanaged_resource *v2; // ebx
  int *v3; // esi
  vostok::vfs::vfs_mount *v4; // ecx
  vostok::vfs::vfs_mount *v5; // edi
  vostok::intrusive_double_linked_list<vostok::vfs::vfs_intrusive_mount_base,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,4,8,vostok::threading::simple_lock,vostok::size_policy,vostok::debug_policy> *v6; // ecx
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v7; // ecx
  _BYTE *v8; // esi
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v9; // [esp-4h] [ebp-10h] BYREF

  v2 = resource;
  v3 = (int *)&resource[1];
  _InterlockedExchange((volatile __int32 *)&resource[1].is_increasing_quality, 0);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&resource,
    *(vostok::vfs::vfs_mount **)(*v3 + 48));
  if ( resource )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v5 = (vostok::vfs::vfs_mount *)*v3;
      if ( *(_DWORD *)(*v3 + 48) )
      {
        v9.m_object = v4;
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
          &v9,
          v5);
        vostok::intrusive_double_linked_list<vostok::vfs::vfs_intrusive_mount_base,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,4,8,vostok::threading::simple_lock,vostok::size_policy,vostok::debug_policy>::erase(
          v6,
          (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)&v5->parent->children,
          v9);
        v5->parent = 0;
      }
    }
  }
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
    (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v4,
    v3,
    0);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
    v7,
    (int *)&resource,
    0);
  v8 = __RTCastToVoid((void **)&v2->__vftable);
  ((void (__thiscall *)(vostok::resources::unmanaged_resource *, _DWORD))v2->~vostok::resources::unmanaged_resource)(
    v2,
    0);
  vostok::memory::g_resources_helper_allocator.call_free(
    &vostok::memory::g_resources_helper_allocator,
    v8,
    "vostok::resources::vfs_sub_fat_cook::destroy_resource",
    ".\\vfs_sub_fat_cook.cpp",
    41u);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&resource);
}
