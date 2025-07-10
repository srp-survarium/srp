void __userpurge vostok::resources::managed_resource::late_set_fat_it(
        vostok::resources::managed_resource *this@<ecx>,
        const vostok::vfs::vfs_iterator *a2@<eax>,
        vostok::vfs::vfs_iterator new_it)
{
  vostok::vfs::vfs_iterator *v3; // esi

  v3 = (vostok::vfs::vfs_iterator *)&a2[10];
  if ( !vostok::vfs::vfs_iterator::operator==(&new_it, a2 + 10) )
    *v3 = new_it;
}
