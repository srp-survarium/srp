void __userpurge vostok::vfs::physical_path_mounter::physical_path_mounter(
        vostok::vfs::query_mount_arguments *args@<eax>,
        vostok::vfs::mounter *a2@<ecx>,
        vostok::vfs::mount_result *this,
        vostok::vfs::virtual_file_system *vfs_data)
{
  vostok::vfs::query_mount_arguments *v5; // ecx
  vostok::vfs::mounter *v6; // ecx
  vostok::fs_new::synchronous_device_interface *v7; // ecx
  vostok::memory::base_allocator *m_object; // esi
  char *v9; // eax
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v10; // eax
  vostok::vfs::mounter *v11; // ecx
  vostok::vfs::vfs_mount *v12; // eax
  vostok::fs_new::asynchronous_device_query_vtbl *v13; // eax
  vostok::vfs::physical_path_mounter *v14; // ecx
  vostok::fs_new::synchronous_device_interface *v15; // ecx
  vostok::fs_new::synchronous_device_interface *v16; // ecx
  vostok::vfs::vfs_mount *v17; // ecx
  vostok::vfs::mount_result *v18; // ecx
  vostok::vfs::mounter *v19; // eax
  vostok::vfs::mounter *v20; // ecx
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v21; // [esp-Ch] [ebp-24h] BYREF
  vostok::vfs::vfs_mount *result; // [esp-8h] [ebp-20h]
  vostok::vfs::query_mount_arguments *v23; // [esp-4h] [ebp-1Ch]
  vostok::memory::base_allocator *v24; // [esp+0h] [ebp-18h]
  int v25; // [esp+Ch] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v26; // [esp+10h] [ebp-8h] BYREF
  char v27; // [esp+14h] [ebp-4h]

  vostok::vfs::mounter::mounter(a2, (int)this, args, vfs_data);
  this[166].mount.m_object = 0;
  v23 = (vostok::vfs::query_mount_arguments *)&this[9];
  this->mount.m_object = (vostok::vfs::vfs_mount *)&vostok::vfs::physical_path_mounter::`vftable';
  vostok::vfs::query_mount_arguments::convert_pathes_to_absolute(v5, (int)v23);
  if ( !vostok::vfs::mounter::try_mount_from_history(
          v6,
          (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)this) )
  {
    if ( !args->submount_node )
    {
      m_object = (vostok::memory::base_allocator *)this[152].mount.m_object;
      v9 = type_info::raw_name(&vostok::vfs::vfs_mount `RTTI Type Descriptor');
      v10 = (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)m_object->call_malloc(m_object, 64u, v9, "vostok::vfs::physical_path_mounter::physical_path_mounter", ".\\mount_physical_path.cpp", 36u);
      if ( !v10
        || (vostok::vfs::vfs_mount::vfs_mount((vostok::vfs::vfs_mount *)v11, v10, this[152].mount.m_object, v24), !v12) )
      {
        vostok::vfs::mounter::finish_with_out_of_memory(v11, (int)this);
        return;
      }
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
        (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v11,
        (int *)&this[8],
        v12);
    }
    v13 = (vostok::fs_new::asynchronous_device_query_vtbl *)this[151].mount.m_object;
    if ( v13 )
    {
      vostok::fs_new::synchronous_device_interface::synchronous_device_interface(
        v7,
        (int)&v25,
        v13,
        (vostok::memory::base_allocator *)this[152].mount.m_object);
      if ( v27 )
      {
        vostok::vfs::mounter::finish_with_out_of_memory(v14, (int)this);
        vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(v15, &v25);
        return;
      }
      this[166].mount.m_object = (vostok::vfs::vfs_mount *)&v25;
      vostok::vfs::physical_path_mounter::mount_impl(v14, (int)this);
      vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(v16, &v25);
    }
    else
    {
      this[166].mount.m_object = (vostok::vfs::vfs_mount *)this[151].result;
      vostok::vfs::physical_path_mounter::mount_impl((vostok::vfs::physical_path_mounter *)v7, (int)this);
    }
    v23 = 0;
    result = (vostok::vfs::vfs_mount *)this[8].result;
    v21.m_object = v17;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &v21,
      &this[8].mount);
    vostok::vfs::mount_result::mount_result(v18, &v26, v21, result);
    vostok::vfs::mounter::finish(v20, this, v19, (char)v23);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v26);
  }
}
