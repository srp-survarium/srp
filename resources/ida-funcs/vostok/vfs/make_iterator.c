void __usercall vostok::vfs::make_iterator(
        vostok::vfs::find_environment *env@<eax>,
        vostok::vfs::vfs_locked_iterator *out_iterator)
{
  vostok::vfs::vfs_locked_iterator::assign(
    env->node,
    (vostok::vfs::vfs_locked_iterator *)&env->file_system->hashset,
    out_iterator,
    &env->file_system->hashset,
    (vostok::vfs::vfs_iterator::type_enum)(((env->find_flags.m_flags & 1) == 0) + 1),
    env->mount_operation_id);
}
