void __userpurge vostok::vfs::archive_mounter::mount_fat(
        vostok::vfs::archive_mounter *this@<ecx>,
        int a2@<edi>,
        vostok::vfs::archive_folder_mount_root_node<1> *mount_root,
        vostok::vfs::base_folder_node<1> *parent)
{
  unsigned int v4; // eax
  vostok::vfs::query_mount_arguments *v5; // ecx
  vostok::fs_new::native_path_string *physical_path; // eax
  int v7; // eax
  vostok::fs_new::device_file_system_interface *v8; // eax
  vostok::vfs::base_node<1> *v9; // ecx
  char *virtual_path_holder; // eax
  int v11; // eax
  vostok::vfs::base_node<1> *v12; // eax
  vostok::vfs::base_node<1> *v13; // [esp-4h] [ebp-124h]
  vostok::fs_new::native_path_string v14; // [esp+Ch] [ebp-114h] BYREF

  v4 = *(_DWORD *)(a2 + 1320);
  *(_DWORD *)(a2 + 1328) = mount_root;
  mount_root->mount_id = v4;
  *(_DWORD *)(*(_DWORD *)(a2 + 1328) + 84) = _InterlockedIncrement(&vostok::vfs::s_mount_operation_id);
  mount_root->nodes_buffer.pointer = *(const char **)(a2 + 1332);
  mount_root->attach_node.pointer = *(vostok::vfs::base_node<1> **)(a2 + 1288);
  vostok::vfs::archive_mounter::recursive_fixup_node(
    (vostok::vfs::archive_mounter *)a2,
    &mount_root->folder.base,
    (char *)mount_root);
  mount_root->attach_node.pointer = *(vostok::vfs::base_node<1> **)(a2 + 1288);
  mount_root->allocator.pointer = *(vostok::memory::base_allocator **)(a2 + 1216);
  mount_root->file_system.pointer = *(vostok::vfs::virtual_file_system **)(a2 + 1316);
  vostok::strings::copy<260>((char (*)[260])mount_root->virtual_path_holder, *(char **)(a2 + 72));
  vostok::strings::copy<260>((char (*)[260])mount_root->archive_path_holder, *(char **)(a2 + 624));
  vostok::strings::copy<32>((char (*)[32])mount_root->descriptor, *(char **)(a2 + 1236));
  physical_path = vostok::vfs::query_mount_arguments::get_physical_path(v5, a2 + 72, &v14);
  vostok::strings::copy<260>((char (*)[260])mount_root->fat_path_holder, physical_path->m_string.m_begin);
  v7 = *(_DWORD *)(a2 + 1212);
  if ( v7 )
    v8 = *(vostok::fs_new::device_file_system_interface **)(v7 + 4);
  else
    v8 = 0;
  mount_root->device.pointer = v8;
  mount_root->async_device.pointer = *(vostok::fs_new::asynchronous_device_interface **)(a2 + 1208);
  mount_root->watcher_enabled = *(_DWORD *)(a2 + 1224);
  *(_DWORD *)(*(_DWORD *)(a2 + 1328) + 32) = mount_root->virtual_path_holder;
  *(_DWORD *)(*(_DWORD *)(a2 + 1328) + 40) = mount_root->fat_path_holder;
  v9 = *(vostok::vfs::base_node<1> **)(a2 + 1300);
  if ( v9 == (vostok::vfs::base_node<1> *)3 )
  {
    virtual_path_holder = (char *)(*(_DWORD *)(a2 + 1288) + 51);
LABEL_10:
    vostok::vfs::base_node<1>::set_name(v9, (char *)mount_root->node.pointer, virtual_path_holder);
    goto LABEL_11;
  }
  if ( !v9 )
  {
    strrchr(mount_root->virtual_path_holder, 0x2Fu);
    v9 = v13;
    if ( v11 )
      virtual_path_holder = (char *)(v11 + 1);
    else
      virtual_path_holder = mount_root->virtual_path_holder;
    goto LABEL_10;
  }
LABEL_11:
  v12 = (vostok::vfs::base_node<1> *)vostok::fs_new::path_crc32(
                                       *(const char **)(a2 + 72),
                                       *(_DWORD *)(a2 + 76) - *(_DWORD *)(a2 + 72),
                                       0);
  vostok::vfs::archive_mounter::recursive_merge(
    (vostok::vfs::archive_mounter *)a2,
    (vostok::fs_new::virtual_path_string *)(a2 + 72),
    v12,
    (vostok::vfs::base_folder_node<1> *)&mount_root->folder.base,
    parent);
  *(_DWORD *)(*(_DWORD *)(a2 + 64) + 52) = mount_root;
  *(_DWORD *)(*(_DWORD *)(a2 + 1328) + 56) = *(_DWORD *)(a2 + 64);
}
