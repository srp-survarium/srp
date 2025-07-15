void __usercall vostok::vfs::physical_path_mounter::mount_impl(
        vostok::vfs::physical_path_mounter *this@<ecx>,
        unsigned int a2@<ebx>)
{
  if ( this->m_args.submount_node )
  {
    if ( this->m_args.submount_type == submount_type_lazy )
      vostok::vfs::physical_path_mounter::mount_lazy(this);
    else
      vostok::vfs::physical_path_mounter::mount_hot(this);
  }
  else
  {
    vostok::vfs::physical_path_mounter::mount_root(this, a2);
  }
}
