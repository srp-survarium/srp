void __usercall vostok::vfs::physical_path_mounter::mount_impl(
        vostok::vfs::physical_path_mounter *this@<ecx>,
        int a2@<eax>)
{
  if ( *(_DWORD *)(a2 + 1288) )
  {
    if ( *(_DWORD *)(a2 + 1300) == 1 )
      vostok::vfs::physical_path_mounter::mount_lazy(this, a2);
    else
      vostok::vfs::physical_path_mounter::mount_hot(this, a2);
  }
  else
  {
    vostok::vfs::physical_path_mounter::mount_root(this, (vostok::vfs::mounter *)a2);
  }
}
