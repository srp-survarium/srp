vostok::vfs::result_enum __cdecl vostok::vfs::try_find_sync_link(vostok::vfs::find_environment *env)
{
  unsigned int v1; // eax
  const char *v2; // eax
  vostok::vfs::vfs_locked_iterator *out_iterator; // [esp-10h] [ebp-14Ch]
  vostok::vfs::find_enum m_flags; // [esp-Ch] [ebp-148h]
  vostok::vfs::virtual_file_system *file_system; // [esp-8h] [ebp-144h]
  vostok::memory::base_allocator *allocator; // [esp-4h] [ebp-140h]
  vostok::fs_new::virtual_path_string path_across_link; // [esp+1Ch] [ebp-120h] BYREF

  vostok::fs_new::virtual_path_string::virtual_path_string(&path_across_link);
  vostok::vfs::find_link_target_path<1>(env->node, (vostok::fs_new::native_path_string *)&path_across_link);
  v1 = vostok::strings::length(env->partial_path);
  vostok::buffer_string::append(&path_across_link.m_string, (char *)&env->path_to_find[v1]);
  allocator = env->allocator;
  file_system = env->file_system;
  m_flags = env->find_flags.m_flags;
  out_iterator = env->out_iterator;
  v2 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&path_across_link);
  return vostok::vfs::try_find_sync(v2, out_iterator, m_flags, file_system, allocator);
}
