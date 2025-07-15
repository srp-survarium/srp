void __usercall vostok::journaling::match_client::write_packet(
        vostok::network_core::buffer_reader *reader@<esi>,
        vostok::journaling::journal *a2@<ecx>,
        ...)
{
  const unsigned __int8 *v2; // edi
  vostok::fs_new::device_file_system_no_watcher_proxy *v3; // ecx
  vostok::fs_new::device_file_system_no_watcher_proxy *v4; // ecx
  vostok::journaling::data_chunk_type_enum v5; // [esp+0h] [ebp-Ch]
  const unsigned __int8 *v6; // [esp+8h] [ebp-4h] BYREF
  va_list va; // [esp+14h] [ebp+8h] BYREF

  va_start(va, a2);
  vostok::journaling::journal::start_writing(
    a2,
    (int)vostok::core::g_journal.m_variable,
    &v6,
    (vostok::journaling::writer_ptr *)6,
    v5);
  v2 = v6;
  vostok::fs_new::device_file_system_no_watcher_proxy::write(v3, *((_DWORD **)v6 + 1), *(void ***)v6, va, 1u);
  v6 = &reader->m_buffer[reader->m_buffer_size - (unsigned int)reader->m_pointer];
  vostok::fs_new::device_file_system_no_watcher_proxy::write(v4, *((_DWORD **)v2 + 1), *(void ***)v2, &v6, 4u);
  vostok::fs_new::device_file_system_no_watcher_proxy::write(
    (vostok::fs_new::device_file_system_no_watcher_proxy *)&reader->m_buffer[reader->m_buffer_size
                                                                           - (unsigned int)reader->m_pointer],
    *((_DWORD **)v2 + 1),
    *(void ***)v2,
    reader->m_pointer,
    (unsigned int)&reader->m_buffer[reader->m_buffer_size - (unsigned int)reader->m_pointer]);
}
