bool __thiscall vostok::vfs::mounter::try_mount_from_history(
        vostok::vfs::mounter *this,
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> a2)
{
  vostok::vfs::vfs_mount *m_object; // ebx
  int *p_next_in_children; // edi
  vostok::fs_new::native_path_string *physical_path; // eax
  vostok::fixed_string<260> *v6; // ecx
  vostok::fixed_string<260> *v7; // ecx
  vostok::intrusive_double_linked_list<vostok::vfs::vfs_mount,vostok::vfs::vfs_mount *,16,12,vostok::threading::simple_lock,vostok::no_size_policy,vostok::debug_policy> *v8; // eax
  vostok::vfs::vfs_mount *v9; // esi
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v10; // eax
  vostok::vfs::vfs_mount *v11; // ecx
  vostok::vfs::mount_result *v12; // ecx
  vostok::vfs::mounter *v13; // eax
  vostok::vfs::mounter *v14; // ecx
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v15; // [esp-Ch] [ebp-368h] BYREF
  vostok::vfs::vfs_mount *v16; // [esp-8h] [ebp-364h]
  int v17; // [esp-4h] [ebp-360h]
  vostok::fs_new::native_path_string v18; // [esp+10h] [ebp-34Ch] BYREF
  vostok::buffer_string v19[22]; // [esp+124h] [ebp-238h] BYREF
  char v20; // [esp+234h] [ebp-128h]
  vostok::buffer_string v21[22]; // [esp+238h] [ebp-124h] BYREF
  char v22; // [esp+348h] [ebp-14h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v23; // [esp+34Ch] [ebp-10h] BYREF

  m_object = a2.m_object;
  if ( a2.m_object[20].next_in_children.m_object )
    return 0;
  p_next_in_children = (int *)&a2.m_object[1].next_in_children;
  physical_path = vostok::vfs::query_mount_arguments::get_physical_path(
                    (vostok::vfs::query_mount_arguments *)this,
                    (int)&a2.m_object[1].next_in_children,
                    &v18);
  vostok::fixed_string<260>::fixed_string<260>(v6, v21, physical_path->m_string.m_begin);
  v17 = *p_next_in_children;
  v22 = 92;
  vostok::fixed_string<260>::fixed_string<260>(v7, v19, (char *)v17);
  v17 = (int)v21;
  v16 = (vostok::vfs::vfs_mount *)&a2;
  v8 = (vostok::intrusive_double_linked_list<vostok::vfs::vfs_mount,vostok::vfs::vfs_mount *,16,12,vostok::threading::simple_lock,vostok::no_size_policy,vostok::debug_policy> *)m_object[20].children.m_last.m_object;
  v20 = 47;
  v9 = m_object + 1;
  v10 = vostok::vfs::find_in_mount_history((vostok::threading::simple_lock *)v19, v8, &a2, (int)v21);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
    v10,
    (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&m_object[1]);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&a2);
  if ( m_object[1].m_reference_count )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v17 = 1;
      v16 = m_object[1].prev_in_children.m_object;
      v15.m_object = v11;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        &v15,
        (const vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&m_object[1]);
      vostok::vfs::mount_result::mount_result(v12, &v23, v15, v16);
      vostok::vfs::mounter::finish(v14, (vostok::vfs::mount_result *)m_object, v13, v17);
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v23);
      v9 = m_object + 1;
    }
  }
  return v9->m_reference_count != 0;
}
