vostok::vfs::vfs_iterator *__usercall vostok::resources::query_result::get_fat_it_zero_if_physical_path_it@<eax>(
        vostok::resources::query_result *this@<ecx>,
        const vostok::vfs::vfs_iterator *a2@<eax>,
        vostok::vfs::vfs_iterator *a3@<esi>)
{
  if ( ((int)a2[43].m_hashset & 0x800) != 0 )
    vostok::vfs::vfs_iterator::end(a3);
  else
    vostok::vfs::vfs_iterator::vfs_iterator(a3, a2 + 10);
  return a3;
}
