void __cdecl vostok::vfs::make_iterator(
        vostok::vfs::vfs_locked_iterator *out_iterator,
        vostok::vfs::find_environment *env)
{
  vostok::vfs::vfs_locked_iterator::assign(
    out_iterator,
    env->node,
    &env->file_system->hashset,
    (vostok::vfs::vfs_iterator::type_enum)(2 - ((env->find_flags.m_flags & 1) != 0)),
    env->mount_operation_id);
}
