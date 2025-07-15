void __thiscall vostok::vfs::archive_mounter::mount_archive_to_parent(
        vostok::vfs::archive_mounter *this,
        void **fat_file,
        vostok::vfs::base_folder_node<1> *parent_of_mount_root,
        vostok::vfs::base_folder_node<1> *device,
        int a5)
{
  bool v5; // zf
  void *v6; // eax
  vostok::fs_new::device_file_system_proxy_base *v7; // ecx
  vostok::fs_new::device_file_system_interface *m_device_file_system; // ecx
  vostok::threading::simple_lock *v9; // ecx
  vostok::fs_new::device_file_system_proxy_base *v10; // [esp-8h] [ebp-30h]
  vostok::fs_new::device_file_system_proxy_base v11[6]; // [esp+10h] [ebp-18h] BYREF
  char vars0; // [esp+28h] [ebp+0h] BYREF

  memset(v11, 0, sizeof(v11));
  vostok::fs_new::device_file_system_proxy_base::read(
    v11,
    (_DWORD *)(a5 + 4),
    (void **)&parent_of_mount_root->m_first_child.pointer,
    v11,
    0x18u);
  v5 = strcmp((const char *)v11, "big-endian") == 0;
  *((_BYTE *)fat_file + 1336) = v5;
  if ( v5 )
  {
    stlp_std::reverse<char *>((char *)&v11[4], (char *)&v11[5]);
    stlp_std::reverse<char *>((char *)&v11[5], &vars0);
  }
  v6 = (void *)(*(int (__thiscall **)(void *, char *, const char *, const char *, const char *, int))(*(_DWORD *)fat_file[304] + 16))(
                 fat_file[304],
                 (char *)&v11[5].m_device_file_system->__vftable + 1,
                 "archive nodes",
                 "vostok::vfs::archive_mounter::mount_archive_to_parent",
                 ".\\mount_archive.cpp",
                 137);
  fat_file[333] = v6;
  if ( v6 )
  {
    vostok::fs_new::device_file_system_proxy_base::read(
      v7,
      (_DWORD *)(a5 + 4),
      (void **)&parent_of_mount_root->m_first_child.pointer,
      v6,
      (unsigned int)v11[5].m_device_file_system);
    m_device_file_system = v11[5].m_device_file_system;
    v10 = (vostok::fs_new::device_file_system_proxy_base *)fat_file[333];
    v10[22].m_device_file_system = (vostok::fs_new::device_file_system_interface *)v11[5];
    vostok::vfs::archive_mounter::mount_fat(
      (vostok::vfs::archive_mounter *)m_device_file_system,
      (int)fat_file,
      (vostok::vfs::archive_folder_mount_root_node<1> *)v10,
      device);
    vostok::vfs::add_to_mount_history(
      (vostok::vfs::vfs_mount *)fat_file[16],
      (vostok::vfs::virtual_file_system *)fat_file[329],
      v9);
  }
  else
  {
    fat_file[17] = (void *)3;
  }
}
