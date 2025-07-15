void __usercall vostok::vfs::vfs_locked_iterator::unlock_and_decref_if_needed(
        vostok::vfs::vfs_locked_iterator *this@<ecx>,
        int a2@<eax>)
{
  vostok::vfs::base_node<1> *v2; // ecx

  v2 = *(vostok::vfs::base_node<1> **)(a2 + 4);
  if ( v2 )
    vostok::vfs::unlock_and_decref_recursively(
      v2,
      lock_type_read,
      (vostok::vfs::find_enum)(*(_DWORD *)(a2 + 12) == 1),
      *(vostok::vfs::vfs_hashset **)a2,
      *(_DWORD *)(a2 + 16));
}
