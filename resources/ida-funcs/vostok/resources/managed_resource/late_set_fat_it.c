void __userpurge vostok::resources::managed_resource::late_set_fat_it(
        vostok::resources::managed_resource *this@<ecx>,
        vostok::vfs::vfs_iterator *a2@<eax>,
        vostok::vfs::vfs_iterator new_it)
{
  if ( new_it.m_node != a2[10].m_node )
    a2[10] = new_it;
}
