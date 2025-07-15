char __userpurge vostok::resources::device_manager::process_read_query@<al>(
        vostok::resources::query_result *query@<eax>,
        vostok::resources::device_manager *this,
        vostok::fs_new::synchronous_device_interface *file,
        const vostok::fs_new::synchronous_device_interface *device)
{
  vostok::vfs::vfs_iterator *p_m_fat_it; // eax
  char *m_link_target; // ecx
  unsigned __int64 file_offs; // kr00_8
  vostok::resources::query_result *v8; // ecx
  vostok::const_buffer *v9; // eax
  unsigned int m_size; // esi
  char result; // al
  unsigned __int64 v12; // [esp-4h] [ebp-2Ch]
  bool v13; // [esp+4h] [ebp-24h]
  _DWORD v14[2]; // [esp+10h] [ebp-18h] BYREF
  vostok::const_buffer v15; // [esp+18h] [ebp-10h] BYREF
  vostok::mutable_buffer out_data; // [esp+24h] [ebp-4h]

  p_m_fat_it = &query->m_fat_it;
  v14[0] = p_m_fat_it->m_hashset;
  v14[1] = p_m_fat_it->m_node;
  m_link_target = (char *)p_m_fat_it->m_link_target;
  v15.m_size = p_m_fat_it->m_type;
  v15.m_data = m_link_target;
  file_offs = vostok::vfs::vfs_iterator::get_file_offs((vostok::vfs::vfs_iterator *)m_link_target, (int)v14);
  out_data.m_data = (char *)HIDWORD(file_offs);
  v9 = vostok::resources::query_result::pin_compressed_or_raw_file(v8, query, &v15);
  m_size = v9->m_size;
  LODWORD(v12) = m_size;
  result = vostok::resources::device_manager::do_async_operation(
             query,
             file,
             (vostok::fs_new::device_file_system_proxy_base *)v9->m_data,
             this,
             (void **)file_offs,
             (vostok::mutable_buffer)__PAIR64__(v9->m_data, (unsigned int)out_data.m_data),
             v12,
             v13);
  if ( result )
    query->m_loaded_bytes += m_size;
  return result;
}
