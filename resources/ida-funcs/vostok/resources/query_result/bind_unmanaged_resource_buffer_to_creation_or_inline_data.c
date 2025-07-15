void __usercall vostok::resources::query_result::bind_unmanaged_resource_buffer_to_creation_or_inline_data(
        vostok::resources::query_result *this@<ecx>,
        int a2@<edi>)
{
  unsigned int m_size; // ecx
  int v3; // eax
  vostok::const_buffer v4; // [esp+8h] [ebp-8h] BYREF

  if ( vostok::resources::query_result::has_uncompressed_inline_data(this, (vostok::vfs::vfs_iterator *)a2) )
  {
    v4.m_data = 0;
    v4.m_size = 0;
    vostok::vfs::vfs_iterator::get_inline_data((vostok::vfs::vfs_iterator *)(a2 + 160), &v4);
    m_size = v4.m_size;
    *(_DWORD *)(a2 + 652) = v4.m_data;
    *(_DWORD *)(a2 + 656) = m_size;
  }
  else
  {
    v3 = *(_DWORD *)(a2 + 212);
    *(_DWORD *)(a2 + 652) = *(_DWORD *)(a2 + 208);
    *(_DWORD *)(a2 + 656) = v3;
  }
}
