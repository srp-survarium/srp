char __cdecl vostok::vfs::lock_branch(
        vostok::vfs::base_node<1> *node,
        vostok::vfs::lock_type_enum lock_type,
        vostok::vfs::lock_operation_enum operation)
{
  vostok::vfs::base_folder_node<1> *pointer; // esi
  vostok::vfs::lock_type_enum v4; // ebx

  pointer = node->m_parent.pointer;
  v4 = vostok::vfs::soften_lock(lock_type);
  if ( pointer && !vostok::vfs::lock_branch(&pointer->base, v4, operation) )
    return 0;
  if ( !vostok::vfs::lock_node(node, lock_type, operation) )
  {
    if ( pointer )
      vostok::vfs::unlock_branch(&pointer->base, v4);
    return 0;
  }
  return 1;
}
