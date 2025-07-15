char __usercall vostok::vfs::get_inline_data<1>@<al>(
        vostok::vfs::base_node<1> *node@<ecx>,
        vostok::const_buffer *out_buffer@<esi>)
{
  unsigned __int16 m_flags; // ax
  vostok::vfs::archive_inline_compressed_file_node<1> *v4; // eax
  const char *pointer; // ecx

  m_flags = node->m_flags;
  if ( (m_flags & 0x40) == 0 )
    return 0;
  if ( (m_flags & 0x10) != 0 )
    v4 = vostok::vfs::node_cast<vostok::vfs::archive_inline_compressed_file_node,vostok::vfs::base_node,1>(node);
  else
    v4 = (vostok::vfs::archive_inline_compressed_file_node<1> *)vostok::vfs::node_cast<vostok::vfs::archive_inline_file_node,vostok::vfs::base_node,1>(node);
  pointer = v4->m_inlined_data.pointer;
  out_buffer->m_size = v4->m_inlined_size;
  out_buffer->m_data = pointer;
  return 1;
}
