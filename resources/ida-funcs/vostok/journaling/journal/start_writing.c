vostok::journaling::writer_ptr *__userpurge vostok::journaling::journal::start_writing@<eax>(
        vostok::journaling::journal *this@<ecx>,
        int a2@<eax>,
        _DWORD *a3@<edi>,
        vostok::journaling::writer_ptr *result,
        const vostok::journaling::data_chunk_type_enum data_type)
{
  HIBYTE(result) = (_BYTE)result;
  vostok::fs_new::device_file_system_no_watcher_proxy::write(
    (vostok::fs_new::device_file_system_no_watcher_proxy *)this,
    (_DWORD *)(a2 + 4),
    *(void ***)(a2 + 8),
    (char *)&result + 3,
    1u);
  *a3 = a2 + 20;
  return (vostok::journaling::writer_ptr *)a3;
}
