void __userpurge vostok::vfs::archive_mounter::archive_mounter(
        vostok::vfs::archive_mounter *this@<ecx>,
        int a2@<edi>,
        vostok::vfs::query_mount_arguments *args,
        vostok::vfs::virtual_file_system *vfs_data)
{
  vostok::vfs::query_mount_arguments *v4; // ecx
  vostok::vfs::mounter *v5; // ecx
  int v6; // esi
  char *v7; // eax
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v8; // eax
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v9; // ecx
  vostok::vfs::vfs_mount *v10; // eax
  vostok::vfs::archive_mounter *v11; // ecx
  vostok::vfs::base_node<1> *v12; // eax
  vostok::vfs::vfs_mount *v13; // eax
  int v14; // eax
  vostok::memory::base_allocator *v15; // [esp+0h] [ebp-8h]

  vostok::vfs::mounter::mounter(this, a2, args, vfs_data);
  *(_DWORD *)a2 = &vostok::vfs::archive_mounter::`vftable';
  *(_DWORD *)(a2 + 1328) = 0;
  *(_DWORD *)(a2 + 1332) = 0;
  *(_BYTE *)(a2 + 1336) = 0;
  *(_DWORD *)(a2 + 1340) = 0;
  vostok::vfs::query_mount_arguments::convert_pathes_to_absolute(v4, a2 + 72);
  if ( !vostok::vfs::mounter::try_mount_from_history(
          v5,
          (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)a2) )
  {
    v6 = *(_DWORD *)(a2 + 1216);
    v7 = type_info::raw_name(&vostok::vfs::vfs_mount `RTTI Type Descriptor');
    v8 = (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)(*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v6 + 16))(v6, 64, v7, "vostok::vfs::archive_mounter::archive_mounter", ".\\mount_archive.cpp", 33);
    if ( v8
      && (vostok::vfs::vfs_mount::vfs_mount(
            (vostok::vfs::vfs_mount *)v9,
            v8,
            *(vostok::vfs::vfs_mount **)(a2 + 1216),
            v15),
          v10) )
    {
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
        v9,
        (int *)(a2 + 64),
        v10);
      v12 = *(vostok::vfs::base_node<1> **)(a2 + 1288);
      if ( v12 )
      {
        v13 = vostok::vfs::mount_of_node<1>(v12);
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
          (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&vfs_data,
          v13);
        *(_DWORD *)(a2 + 1320) = *(_DWORD *)(vfs_data->hashset.m_hashlocks[3].m_readers_writers_counter.writer_thread_id
                                           + 80);
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&vfs_data);
      }
      if ( *(_DWORD *)(a2 + 1300) == 2 )
      {
        vostok::vfs::archive_mounter::mount_sub_fat(v11, (vostok::vfs::archive_mounter *)a2);
      }
      else
      {
        v14 = *(_DWORD *)(a2 + 1280);
        if ( v14 )
          *(_DWORD *)(a2 + 1320) = v14;
        if ( !*(_DWORD *)(a2 + 1320) )
        {
          v11 = (vostok::vfs::archive_mounter *)_InterlockedIncrement(&vostok::vfs::s_mount_id);
          *(_DWORD *)(a2 + 1320) = v11;
        }
        vostok::vfs::archive_mounter::mount_archive(v11, (vostok::vfs::mount_result *)a2);
      }
    }
    else
    {
      vostok::vfs::mounter::finish_with_out_of_memory((vostok::vfs::mounter *)v9, a2);
    }
  }
}
