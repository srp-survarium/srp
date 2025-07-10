char __cdecl vostok::vfs::get_inline_data<1>(const vostok::vfs::base_node<1> *node, vostok::const_buffer *out_buffer)
{
  survarium::game_camera *v2; // ecx
  const vostok::vfs::archive_inline_compressed_file_node<1> *v4; // eax
  unsigned int m_inlined_size; // edx
  const vostok::vfs::archive_inline_file_node<1> *v6; // eax
  const char *pointer; // edx
  unsigned int v8; // eax

  survarium::weapon_user_dead_state::finalize(v2);
  if ( (node->m_flags & 0x40) != 0x40 )
    return 0;
  if ( (node->m_flags & 0x10) == 0x10 )
  {
    v4 = vostok::vfs::node_cast<vostok::vfs::archive_inline_compressed_file_node,vostok::vfs::base_node,1>(node);
    m_inlined_size = v4->m_inlined_size;
    out_buffer->m_data = v4->m_inlined_data.pointer;
    out_buffer->m_size = m_inlined_size;
  }
  else
  {
    v6 = vostok::vfs::node_cast<vostok::vfs::archive_inline_file_node,vostok::vfs::base_node,1>(node);
    pointer = v6->m_inlined_data.pointer;
    v8 = v6->m_inlined_size;
    out_buffer->m_data = pointer;
    out_buffer->m_size = v8;
  }
  return 1;
}
