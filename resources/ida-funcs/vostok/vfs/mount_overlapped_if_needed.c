char __cdecl vostok::vfs::mount_overlapped_if_needed(vostok::vfs::find_environment *env)
{
  const char *partial_path; // ecx
  const char *path_to_find; // eax
  int v3; // eax
  vostok::vfs::vfs_locked_iterator *v4; // ecx
  vostok::vfs::async_callbacks_data *v6; // edi
  boost::function2<unsigned short,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &> *v7; // [esp-4h] [ebp-28h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> a0; // [esp+Ch] [ebp-18h] BYREF
  vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> list; // [esp+10h] [ebp-14h] BYREF

  partial_path = env->partial_path;
  path_to_find = env->path_to_find;
  list.m_size = 0;
  list.m_first = 0;
  list.m_last = 0;
  v3 = vostok::strings::compare(path_to_find, partial_path);
  if ( vostok::vfs::fill_nodes_to_expand_from_overlapped(
         env->node,
         &list,
         env->node_parent,
         env->allocator,
         (vostok::vfs::find_enum)env->find_flags.m_flags,
         (vostok::vfs::traverse_enum)(v3 == 0),
         1u) == 3 )
    goto LABEL_2;
  if ( !list.m_first )
    return 0;
  v6 = (vostok::vfs::async_callbacks_data *)env->allocator->call_malloc(
                                              env->allocator,
                                              strlen(env->partial_path) + strlen(env->path_to_find) + 138,
                                              "async_callbacks_data",
                                              "vostok::vfs::mount_overlapped_if_needed",
                                              ".\\find_async.cpp",
                                              52);
  if ( !v6 )
  {
LABEL_2:
    vostok::vfs::unlock_and_decref_branch(env->node, lock_type_read, env->mount_operation_id);
    a0.m_object = 0;
    memset(&list, 0, sizeof(list));
    boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::operator()(
      v7,
      &env->callback.vtable,
      &a0,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)3);
    vostok::vfs::vfs_locked_iterator::clear(v4, (int)&a0);
  }
  else
  {
    vostok::vfs::async_callbacks_data::async_callbacks_data(v6, env, type_branch);
    vostok::vfs::query_expand_nodes(&list, v6);
    vostok::vfs::free_nodes_to_expand(&list, env->allocator);
  }
  return 1;
}
