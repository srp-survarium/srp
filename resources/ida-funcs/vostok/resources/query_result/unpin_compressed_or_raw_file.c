void __fastcall vostok::resources::query_result::unpin_compressed_or_raw_file(
        vostok::resources::query_result *this,
        vostok::vfs::vfs_iterator *a2,
        vostok::const_buffer *pinned_file)
{
  vostok::resources::query_result *v3; // ecx

  if ( a2[10].m_node && vostok::vfs::vfs_iterator::is_compressed(a2 + 10) )
    vostok::resources::query_result::unpin_compressed_file(v3, pinned_file);
  else
    vostok::resources::query_result::unpin_raw_file((vostok::resources::query_result *)pinned_file, (int)a2);
}
