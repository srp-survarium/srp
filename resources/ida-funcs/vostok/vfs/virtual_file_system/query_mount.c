void __userpurge vostok::vfs::virtual_file_system::query_mount(
        vostok::vfs::query_mount_arguments *args@<eax>,
        vostok::threading::mutex *a2@<ecx>,
        vostok::vfs::virtual_file_system *this)
{
  vostok::vfs::base_node<1> **p_root_write_lock; // esi
  bool v4; // bl

  p_root_write_lock = &args->root_write_lock;
  v4 = args->root_write_lock == 0;
  vostok::vfs::virtual_file_system::query_mount_impl(args, a2, this);
  if ( v4 )
    *p_root_write_lock = 0;
}
