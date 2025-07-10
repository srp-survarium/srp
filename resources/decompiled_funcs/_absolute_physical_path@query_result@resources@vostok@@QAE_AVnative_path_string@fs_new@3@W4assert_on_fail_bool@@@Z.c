vostok::fs_new::native_path_string *__usercall vostok::resources::query_result::absolute_physical_path@<eax>(
        vostok::resources::query_result *this@<ecx>,
        const vostok::vfs::vfs_iterator *a2@<eax>,
        int a3@<esi>)
{
  vostok::vfs::vfs_hashset *m_hashset; // eax
  vostok::fs_new::virtual_path_string *v6; // eax
  char *m_end; // edi
  unsigned int v8; // edi
  unsigned __int8 *m_begin; // [esp-14h] [ebp-378h]
  const char *writer_thread_id; // [esp-4h] [ebp-368h]
  vostok::vfs::vfs_iterator it; // [esp+8h] [ebp-35Ch] BYREF
  vostok::fs_new::native_path_string physical_path; // [esp+18h] [ebp-34Ch] BYREF
  vostok::fs_new::native_path_string absolute_path; // [esp+130h] [ebp-234h] BYREF
  vostok::fs_new::native_path_string v14; // [esp+24Ch] [ebp-118h] BYREF

  physical_path.m_string.m_begin = physical_path.m_string.m_buffer;
  m_hashset = a2[43].m_hashset;
  physical_path.m_string.m_end = physical_path.m_string.m_buffer;
  physical_path.m_string.m_max_end = &physical_path.m_separator;
  physical_path.m_string.m_buffer[0] = 0;
  physical_path.m_separator = 92;
  if ( ((unsigned __int8)m_hashset & 8) != 0 )
  {
    writer_thread_id = (const char *)a2[14].m_hashset->m_hashlocks[1].m_readers_writers_counter.writer_thread_id;
    *(_DWORD *)a3 = a3 + 12;
    *(_DWORD *)(a3 + 4) = a3 + 12;
    *(_DWORD *)(a3 + 8) = a3 + 272;
    *(_BYTE *)(a3 + 12) = 0;
    vostok::buffer_string::operator+=((vostok::buffer_string *)a3, writer_thread_id);
    *(_BYTE *)(a3 + 272) = 92;
    return (vostok::fs_new::native_path_string *)a3;
  }
  else
  {
    vostok::vfs::vfs_iterator::vfs_iterator(&it, a2 + 10);
    v6 = (vostok::fs_new::virtual_path_string *)vostok::vfs::vfs_iterator::get_physical_path(&it, &v14);
    vostok::fs_new::virtual_path_string::operator=((vostok::fs_new::virtual_path_string *)&physical_path, v6);
    if ( physical_path.m_string.m_end == physical_path.m_string.m_begin )
    {
      *(_DWORD *)a3 = a3 + 12;
      *(_DWORD *)(a3 + 4) = a3 + 12;
      *(_DWORD *)(a3 + 8) = a3 + 272;
    }
    else
    {
      absolute_path.m_string.m_begin = absolute_path.m_string.m_buffer;
      absolute_path.m_string.m_end = absolute_path.m_string.m_buffer;
      absolute_path.m_string.m_max_end = &absolute_path.m_separator;
      absolute_path.m_string.m_buffer[0] = 0;
      absolute_path.m_separator = 92;
      vostok::fs_new::convert_to_absolute_path<vostok::fs_new::native_path_string>(
        (vostok::fixed_string<32> *)&absolute_path,
        &physical_path,
        assert_on_fail_true);
      m_end = absolute_path.m_string.m_end;
      *(_DWORD *)(a3 + 8) = a3 + 272;
      v8 = m_end - absolute_path.m_string.m_begin;
      m_begin = (unsigned __int8 *)absolute_path.m_string.m_begin;
      *(_DWORD *)a3 = a3 + 12;
      *(_DWORD *)(a3 + 4) = a3 + 12;
      memcpy((unsigned __int8 *)(a3 + 12), m_begin, v8);
      *(_DWORD *)(a3 + 4) += v8;
    }
    **(_BYTE **)(a3 + 4) = 0;
    *(_BYTE *)(a3 + 272) = 92;
    return (vostok::fs_new::native_path_string *)a3;
  }
}
