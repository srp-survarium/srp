BOOL __usercall vostok::resources::query_result::has_uncompressed_inline_data@<eax>(
        vostok::resources::query_result *this@<ecx>,
        vostok::vfs::vfs_iterator *a2@<eax>)
{
  vostok::vfs::vfs_iterator *v2; // esi
  vostok::vfs::base_node<1> *v3; // eax
  BOOL result; // eax

  result = 0;
  if ( a2[10].m_node )
  {
    v2 = a2 + 10;
    v3 = vostok::vfs::vfs_iterator::data_node(a2 + 10);
    if ( vostok::vfs::base_node<1>::is_inlined(v3) )
    {
      if ( !vostok::vfs::vfs_iterator::is_compressed(v2) )
        return 1;
    }
  }
  return result;
}
