void __thiscall vostok::vfs::physical_path_mounter::mount_lazy(vostok::vfs::physical_path_mounter *this, int a2)
{
  vostok::vfs::base_node<1> *v3; // esi
  vostok::vfs::base_node<1> *v4; // ecx
  vostok::vfs::physical_folder_mount_root_node<1> *mount_root; // eax
  bool v6; // zf
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v7; // ecx
  vostok::vfs::base_node<1> *v8; // edi
  vostok::vfs::base_node<1> *v9; // ecx
  unsigned int v10; // eax
  vostok::fs_new::native_path_string v11; // [esp+Ch] [ebp-230h] BYREF
  vostok::fixed_string<260> v12; // [esp+124h] [ebp-118h] BYREF
  char v13; // [esp+234h] [ebp-8h]
  vostok::vfs::physical_folder_node<1> *v14; // [esp+244h] [ebp+8h]

  v3 = *(vostok::vfs::base_node<1> **)(a2 + 1288);
  v14 = vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::base_node,1>(v3);
  mount_root = vostok::vfs::base_node<1>::get_mount_root(v4, (int)v3);
  v6 = *(_DWORD *)(a2 + 1228) == 1;
  *(_DWORD *)(a2 + 1312) = mount_root;
  if ( vostok::vfs::physical_folder_node<1>::set_is_scanned(v14, v6) )
  {
    vostok::fixed_string<260>::fixed_string<260>(&v12, (const vostok::fixed_string<260> *)(a2 + 72));
    v8 = *(vostok::vfs::base_node<1> **)(a2 + 1288);
    v13 = 47;
    vostok::vfs::get_node_physical_path<vostok::vfs::base_node,1>(v8, v9, &v11);
    v10 = vostok::fs_new::path_crc32(*(const char **)(a2 + 72), *(_DWORD *)(a2 + 76) - *(_DWORD *)(a2 + 72), 0);
    vostok::vfs::physical_path_mounter::mount_physical_folder(
      (vostok::vfs::physical_path_mounter *)a2,
      (vostok::fs_new::virtual_path_string *)(a2 + 72),
      v14,
      &v11,
      v10);
  }
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
    v7,
    (int *)(a2 + 64),
    *(vostok::vfs::vfs_mount **)(*(_DWORD *)(a2 + 1312) + 56));
}
