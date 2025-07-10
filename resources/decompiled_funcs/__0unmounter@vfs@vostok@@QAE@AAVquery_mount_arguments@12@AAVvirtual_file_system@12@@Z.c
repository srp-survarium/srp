void __thiscall vostok::vfs::unmounter::unmounter(
        vostok::vfs::unmounter *this,
        vostok::vfs::query_mount_arguments *m_args,
        vostok::vfs::virtual_file_system *file_system)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  vostok::vfs::mount_result v7[2]; // [esp-8h] [ebp-280h] BYREF
  vostok::vfs::unmounter *thisa; // [esp+8h] [ebp-270h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v9; // [esp+144h] [ebp-134h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v10; // [esp+148h] [ebp-130h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> other; // [esp+14Ch] [ebp-12Ch] BYREF
  vostok::vfs::mount_root_node_base<1> *m_mount_root; // [esp+150h] [ebp-128h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v13; // [esp+268h] [ebp-10h] BYREF
  int v14; // [esp+26Ch] [ebp-Ch]
  char v15; // [esp+274h] [ebp-4h]
  char v16; // [esp+275h] [ebp-3h]
  char v17; // [esp+276h] [ebp-2h]
  char v18; // [esp+277h] [ebp-1h]

  thisa = this;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  thisa->m_args = m_args;
  thisa->m_hashset = &file_system->hashset;
  thisa->m_file_system = file_system;
  thisa->m_root_node_to_unmount = 0;
  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&dword_201A8 + (_DWORD)file_system))
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
    boost::function0<void>::operator()((boost::function0<void> *)((char *)&dword_201A8 + (_DWORD)file_system));
  vostok::vfs::query_mount_arguments::convert_pathes_to_absolute(m_args);
  v18 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  v17 = 0;
  survarium::weapon_user_dead_state::finalize(v4);
  m_mount_root = m_args->mount_ptr->m_mount_root;
  v5 = (survarium::game_camera *)thisa;
  thisa->m_root_node_to_unmount = m_mount_root;
  v16 = 0;
  survarium::weapon_user_dead_state::finalize(v5);
  v15 = 0;
  survarium::weapon_user_dead_state::finalize(v6);
  if ( m_args->submount_type == submount_type_hot_unmount )
    vostok::vfs::unmounter::hot_unmount(thisa);
  else
    vostok::vfs::unmounter::unmount(thisa);
  if ( m_args->unlock_after_mount )
    vostok::vfs::unlock_branch(m_args->root_write_lock, lock_type_write);
  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_args->callback)
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
  {
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &other,
      0);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &v13,
      &other);
    v14 = 1;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&other);
    v9 = &v13;
    v10 = (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v7;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &v7[0].mount,
      &v13);
    v10[1].m_object = v9[1].m_object;
    boost::function1<void,vostok::vfs::mount_result>::operator()(&m_args->callback, v7[0]);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v13);
  }
}
