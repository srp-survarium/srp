vostok::journaling::reader_ptr *__userpurge vostok::journaling::journal::try_start_reading@<eax>(
        vostok::journaling::journal *this@<ecx>,
        int a2@<eax>,
        _DWORD *a3@<edi>,
        vostok::journaling::reader_ptr *result,
        const vostok::journaling::data_chunk_type_enum data_type)
{
  __int64 v6; // rax
  unsigned __int8 v8; // [esp+Fh] [ebp-1h] BYREF

  if ( !*(_DWORD *)(a2 + 28) )
  {
    LODWORD(v6) = vostok::fs_new::device_file_system_proxy_base::read(
                    (vostok::fs_new::device_file_system_proxy_base *)this,
                    (_DWORD *)(a2 + 4),
                    *(void ***)(a2 + 8),
                    &v8,
                    1u);
    if ( result == (vostok::journaling::reader_ptr *)1 || result == (vostok::journaling::reader_ptr *)2 )
    {
      if ( !v6 )
        vostok::debug::terminate("No more records in the journal");
    }
    else if ( !v6 )
    {
      goto LABEL_5;
    }
    *(_DWORD *)(a2 + 28) = v8;
  }
  if ( *(vostok::journaling::reader_ptr **)(a2 + 28) == result )
  {
    *(_DWORD *)(a2 + 28) = 0;
    *a3 = a2 + 12;
    return (vostok::journaling::reader_ptr *)a3;
  }
LABEL_5:
  *a3 = 0;
  return (vostok::journaling::reader_ptr *)a3;
}
