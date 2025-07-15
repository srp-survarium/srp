void __userpurge vostok::vfs::virtual_file_system::query_mount_impl(
        vostok::vfs::query_mount_arguments *args@<eax>,
        vostok::threading::mutex *a2@<ecx>,
        vostok::vfs::virtual_file_system *this)
{
  vostok::vfs::virtual_file_system *v3; // ebx
  vostok::vfs::vfs_mount *v4; // edi
  vostok::intrusive_double_linked_list<vostok::vfs::mounter_base,vostok::vfs::mounter *,0,4,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy> *v6; // ecx
  vostok::vfs::archive_mounter *v7; // ecx
  vostok::vfs::mount_result *v8; // ecx
  vostok::vfs::vfs_mount *v9; // ecx
  const vostok::vfs::mount_result *v10; // eax
  boost::function1<void,vostok::vfs::mount_result> *v11; // ecx
  vostok::memory::base_allocator *allocator; // edi
  char *v13; // eax
  int v14; // eax
  vostok::vfs::archive_mounter *v15; // ecx
  int v16; // eax
  vostok::vfs::vfs_mount *v17; // ecx
  vostok::vfs::mount_result *v18; // ecx
  vostok::vfs::vfs_mount *v19; // ecx
  const vostok::vfs::mount_result *v20; // eax
  boost::function1<void,vostok::vfs::mount_result> *v21; // ecx
  vostok::vfs::mount_result v22; // [esp-Ch] [ebp-570h] BYREF
  int m_object; // [esp-4h] [ebp-568h]
  vostok::vfs::lock_operation_enum v24; // [esp+0h] [ebp-564h]
  vostok::vfs::mounter v25; // [esp+10h] [ebp-554h] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v26; // [esp+550h] [ebp-14h] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v27; // [esp+558h] [ebp-Ch] BYREF

  v3 = this;
  v4 = (vostok::vfs::vfs_mount *)(&this->mount_history.gap0 + (_DWORD)&loc_2012E + 2);
  v27.m_object = (vostok::vfs::vfs_mount *)(&this->mount_history.gap0 + (_DWORD)&loc_2012E + 2);
  vostok::threading::mutex::lock(a2, (_RTL_CRITICAL_SECTION *)(&this->mount_history.gap0 + (_DWORD)&loc_2012E + 2));
  HIBYTE(this) = 0;
  if ( vostok::vfs::virtual_file_system::try_reference_to_pending_mount_unsafe(args, v6, v3, (bool *)&this + 3) )
    goto LABEL_2;
  if ( HIBYTE(this) )
  {
    m_object = 3;
LABEL_5:
    v22.result = (vostok::vfs::result_enum)v7;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v22.result,
      0);
    vostok::vfs::mount_result::mount_result(
      v8,
      &v27,
      (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)v22.result,
      (vostok::vfs::vfs_mount *)m_object);
    m_object = (int)v9;
    v22.result = (vostok::vfs::result_enum)v9;
    vostok::vfs::mount_result::mount_result((vostok::vfs::mount_result *)&v22.result, v10);
    v22.mount.m_object = (vostok::vfs::vfs_mount *)&args->callback;
    boost::function1<void,vostok::vfs::mount_result>::operator()(
      v11,
      v22,
      (boost::function1<void,vostok::vfs::mount_result> *)m_object);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v27);
LABEL_2:
    m_object = (int)v4;
    goto LABEL_18;
  }
  if ( !args->root_write_lock
    && !vostok::vfs::vfs_hashset::find_and_lock_branch(
          (char *)uri,
          &v3->hashset,
          &args->root_write_lock,
          (vostok::vfs::lock_type_enum)args->lock_operation,
          v24) )
  {
    m_object = 4;
    goto LABEL_5;
  }
  if ( args->type == mount_type_physical_path )
  {
    vostok::vfs::physical_path_mounter::physical_path_mounter(
      args,
      v7,
      (vostok::vfs::physical_path_mounter *)&v25.vostok::vfs::mounter_base,
      v3);
    vostok::vfs::mounter::~mounter((vostok::vfs::mounter *)&v25.vostok::vfs::mounter_base);
    goto LABEL_2;
  }
  if ( args->synchronous_device || args->submount_type != submount_type_subfat )
  {
    vostok::vfs::archive_mounter::archive_mounter(v7, (int)&v25, args, v3);
    vostok::vfs::mounter::~mounter(&v25);
  }
  else
  {
    allocator = args->allocator;
    v13 = type_info::raw_name(&vostok::vfs::archive_mounter `RTTI Type Descriptor');
    v14 = (int)allocator->call_malloc(
                 allocator,
                 1344u,
                 v13,
                 "vostok::vfs::virtual_file_system::query_mount_impl",
                 ".\\virtual_file_system.cpp",
                 114u);
    if ( !v14 || (vostok::vfs::archive_mounter::archive_mounter(v15, v14, args, v3), !v16) )
    {
      vostok::vfs::unlock_branch(args->root_write_lock, lock_type_write);
      v17 = (vostok::vfs::vfs_mount *)m_object;
      m_object = 3;
      v22.result = (vostok::vfs::result_enum)v17;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v22.result,
        0);
      vostok::vfs::mount_result::mount_result(
        v18,
        &v26,
        (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)v22.result,
        (vostok::vfs::vfs_mount *)m_object);
      m_object = (int)v19;
      v22.result = (vostok::vfs::result_enum)v19;
      vostok::vfs::mount_result::mount_result((vostok::vfs::mount_result *)&v22.result, v20);
      v22.mount.m_object = (vostok::vfs::vfs_mount *)&args->callback;
      boost::function1<void,vostok::vfs::mount_result>::operator()(
        v21,
        v22,
        (boost::function1<void,vostok::vfs::mount_result> *)m_object);
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v26);
    }
  }
  m_object = (int)v27.m_object;
LABEL_18:
  LeaveCriticalSection((LPCRITICAL_SECTION)m_object);
}
