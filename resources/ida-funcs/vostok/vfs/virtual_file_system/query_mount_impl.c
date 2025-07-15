void __thiscall vostok::vfs::virtual_file_system::query_mount_impl(
        vostok::vfs::virtual_file_system *this,
        vostok::vfs::query_mount_arguments *args)
{
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v2; // ecx
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v3; // ecx
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v4; // ecx
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v5; // ecx
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v6; // ecx
  vostok::memory::base_allocator *v7; // eax
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v8; // eax
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v9; // ecx
  vostok::vfs::mount_result v10[2]; // [esp-8h] [ebp-E44h] BYREF
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v11; // [esp+8h] [ebp-E34h]
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v12; // [esp+Ch] [ebp-E30h]
  vostok::vfs::virtual_file_system *thisa; // [esp+10h] [ebp-E2Ch]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v14; // [esp+12Ch] [ebp-D10h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v15; // [esp+130h] [ebp-D0Ch]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v16; // [esp+134h] [ebp-D08h] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v17; // [esp+250h] [ebp-BECh]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v18; // [esp+254h] [ebp-BE8h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v19; // [esp+258h] [ebp-BE4h] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v20; // [esp+374h] [ebp-AC8h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v21; // [esp+378h] [ebp-AC4h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> other; // [esp+37Ch] [ebp-AC0h] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v23; // [esp+384h] [ebp-AB8h] BYREF
  int v24; // [esp+388h] [ebp-AB4h]
  vostok::vfs::archive_mounter *v25; // [esp+390h] [ebp-AACh]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v26; // [esp+398h] [ebp-AA4h] BYREF
  int v27; // [esp+39Ch] [ebp-AA0h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v28; // [esp+3A8h] [ebp-A94h] BYREF
  int v29; // [esp+3ACh] [ebp-A90h]
  vostok::vfs::archive_mounter v30; // [esp+3B4h] [ebp-A88h] BYREF
  vostok::vfs::physical_path_mounter v31; // [esp+8F4h] [ebp-548h] BYREF
  bool out_of_memory; // [esp+E2Fh] [ebp-Dh] BYREF
  vostok::vfs::archive_mounter *mounter; // [esp+E30h] [ebp-Ch]
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+E34h] [ebp-8h] BYREF

  thisa = this;
  vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
    (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)(&this->mount_history.gap0 + (_DWORD)&loc_2012F + 1),
    (int)&raii);
  out_of_memory = 0;
  if ( vostok::vfs::virtual_file_system::try_reference_to_pending_mount_unsafe(thisa, args, &out_of_memory) )
    goto LABEL_20;
  if ( out_of_memory )
  {
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &other,
      0);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &v28,
      &other);
    v29 = 3;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&other);
    v20 = &v28;
    v21 = (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v10;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &v10[0].mount,
      &v28);
    v21[1].m_object = v20[1].m_object;
    boost::function1<void,vostok::vfs::mount_result>::operator()(&args->callback, v10[0]);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v28);
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      v3,
      (int)&raii);
    return;
  }
  if ( !args->root_write_lock
    && !vostok::vfs::vfs_hashset::find_and_lock_branch(
          &thisa->hashset,
          &args->root_write_lock,
          (const char *)&buf,
          lock_type_write,
          args->lock_operation) )
  {
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &v19,
      0);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &v26,
      &v19);
    v27 = 4;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v19);
    v17 = &v26;
    v18 = (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v10;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &v10[0].mount,
      &v26);
    v18[1].m_object = v17[1].m_object;
    boost::function1<void,vostok::vfs::mount_result>::operator()(&args->callback, v10[0]);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v26);
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      v4,
      (int)&raii);
    return;
  }
  if ( args->type == mount_type_physical_path )
  {
    vostok::vfs::physical_path_mounter::physical_path_mounter(&v31, args, thisa);
    vostok::vfs::mounter::~mounter(&v31);
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      v5,
      (int)&raii);
    return;
  }
  if ( args->synchronous_device || args->submount_type != submount_type_subfat )
  {
    vostok::vfs::archive_mounter::archive_mounter(&v30, args, thisa);
    vostok::vfs::mounter::~mounter(&v30);
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      v6,
      (int)&raii);
    return;
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v2);
  mounter = (vostok::vfs::archive_mounter *)vostok::memory::malloc_helper<vostok::memory::base_allocator>(v7, 0x540u);
  if ( mounter )
  {
    v25 = (vostok::vfs::archive_mounter *)operator new(0x540u, mounter);
    if ( v25 )
    {
      vostok::vfs::archive_mounter::archive_mounter(v25, args, thisa);
      v11 = v8;
    }
    else
    {
      v11 = 0;
    }
    v2 = v11;
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  mounter = (vostok::vfs::archive_mounter *)v12;
  if ( v12 )
  {
LABEL_20:
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      v2,
      (int)&raii);
  }
  else
  {
    vostok::vfs::unlock_branch(args->root_write_lock, lock_type_write);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &v16,
      0);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &v23,
      &v16);
    v24 = 3;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v16);
    v14 = &v23;
    v15 = (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v10;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &v10[0].mount,
      &v23);
    v15[1].m_object = v14[1].m_object;
    boost::function1<void,vostok::vfs::mount_result>::operator()(&args->callback, v10[0]);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v23);
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      v9,
      (int)&raii);
  }
}
