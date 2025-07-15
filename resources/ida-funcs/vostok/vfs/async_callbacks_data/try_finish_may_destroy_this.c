void __usercall vostok::vfs::async_callbacks_data::try_finish_may_destroy_this(
        vostok::vfs::async_callbacks_data *this@<ecx>,
        int a2@<esi>)
{
  vostok::vfs::base_node<1> *no_lock; // eax
  vostok::vfs::async_callbacks_data *v3; // ecx
  bool v4; // zf

  if ( *(_BYTE *)(a2 + 8) && *(_DWORD *)(a2 + 4) == *(_DWORD *)a2 )
  {
    no_lock = vostok::vfs::vfs_hashset::find_no_lock(
                (vostok::vfs::vfs_hashset *)this,
                (vostok::vfs::vfs_hashset *)(*(_DWORD *)(a2 + 84) + 24),
                *(char **)(a2 + 24),
                1);
    v4 = *(_DWORD *)(a2 + 132) == 0;
    *(_DWORD *)(a2 + 72) = no_lock;
    if ( v4 )
      vostok::vfs::async_callbacks_data::finish_branch_destroy_this(v3, a2);
    else
      vostok::vfs::async_callbacks_data::finish_tree_may_destroy_this(v3, a2);
  }
}
