void __cdecl vostok::vfs::unlock_and_decref_recursively(
        vostok::vfs::base_node<1> *node,
        vostok::vfs::lock_type_enum branch_lock_type,
        vostok::vfs::find_enum find_flags,
        vostok::vfs::vfs_hashset *hashset,
        unsigned int mount_operation_id)
{
  vostok::vfs::decref_children(node, find_flags, hashset, mount_operation_id, 1);
  vostok::vfs::unlock_and_decref_branch(node, branch_lock_type, mount_operation_id);
}
