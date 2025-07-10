char __thiscall vostok::vfs::query_notification_operation::try_write_lock(
        vostok::vfs::query_notification_operation *this)
{
  char *v1; // eax
  const char *v2; // eax
  vostok::vfs::mount_result v4[2]; // [esp-8h] [ebp-28Ch] BYREF
  vostok::vfs::query_notification_operation *thisa; // [esp+8h] [ebp-27Ch]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v6; // [esp+144h] [ebp-140h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v7; // [esp+148h] [ebp-13Ch]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> other; // [esp+14Ch] [ebp-138h] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v9; // [esp+15Ch] [ebp-128h] BYREF
  int v10; // [esp+160h] [ebp-124h]
  char v11; // [esp+16Ah] [ebp-11Ah]
  bool locked; // [esp+16Bh] [ebp-119h]
  vostok::fs_new::virtual_path_string write_lock_path; // [esp+16Ch] [ebp-118h] BYREF

  thisa = this;
  vostok::fs_new::virtual_path_string::virtual_path_string(&write_lock_path);
  v1 = (char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)thisa->m_virtual_path);
  vostok::fs_new::get_path_without_last_item<vostok::fs_new::virtual_path_string>(&write_lock_path, v1);
  thisa->m_lock_node = 0;
  while ( (vostok::fs_new::path_string_impl::length(&write_lock_path) != 0
         ? (unsigned int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
         : 0) != 0 )
  {
    v4[0].result = thisa->m_lock_operation;
    v2 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&write_lock_path);
    locked = vostok::vfs::vfs_hashset::find_and_lock_branch(
               &thisa->m_file_system->hashset,
               &thisa->m_lock_node,
               v2,
               lock_type_write,
               (vostok::vfs::lock_operation_enum)v4[0].result);
    if ( !locked && thisa->m_lock_operation == lock_operation_try_lock )
      break;
    if ( thisa->m_lock_node )
    {
      v11 = 0;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)locked);
      return 1;
    }
    vostok::fs_new::get_path_without_last_item_inplace<vostok::fs_new::virtual_path_string>(&write_lock_path);
  }
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &other,
    0);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &v9,
    &other);
  v10 = 4;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&other);
  v6 = &v9;
  v7 = (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v4;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &v4[0].mount,
    &v9);
  v7[1].m_object = v6[1].m_object;
  boost::function1<void,vostok::vfs::mount_result>::operator()(
    &thisa->m_callback->boost::function1<void,vostok::vfs::mount_result>,
    v4[0]);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v9);
  return 0;
}
