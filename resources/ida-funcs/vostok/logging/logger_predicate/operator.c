char __userpurge vostok::logging::logger_predicate::operator()@<al>(
        vostok::logging::logger_predicate *this@<ecx>,
        int a2@<edi>,
        const unsigned int index,
        char *string,
        const unsigned int length,
        const bool is_last)
{
  unsigned int v6; // ebx
  void *v7; // esp
  int v8; // esi
  vostok::logging::callback_flag v9; // ecx
  unsigned int v10; // edx
  int v11; // eax
  char v13[8]; // [esp+0h] [ebp-Ch] BYREF
  char *a6; // [esp+8h] [ebp-4h]

  v6 = strlen(*(const char **)(*(_DWORD *)(a2 + 4) + 568))
     + strlen(*(const char **)(*(_DWORD *)(a2 + 4) + 572))
     + strlen(*(const char **)(*(_DWORD *)(a2 + 4) + 564))
     + length
     + 129;
  v7 = alloca(v6);
  v8 = *(_DWORD *)(a2 + 4);
  a6 = v13;
  fill_log_string(
    (const vostok::logging::log_format *)v8,
    v13,
    v6,
    string,
    &string[length],
    *(vostok::logging::path_parts **)a2,
    *(vostok::logging::verbosity *)(v8 + 580));
  if ( (**(_DWORD **)(*(_DWORD *)(a2 + 4) + 552) != 0
      ? (unsigned int)vostok::memory::process_allocator::finalize_impl
      : 0) != 0 )
  {
    if ( index )
      v9 = is_last ? last : 0;
    else
      v9 = first;
    v10 = strlen(a6);
    v11 = *(_DWORD *)(a2 + 4);
    boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::operator()(
      (boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)v9,
      *(_DWORD **)(v11 + 552),
      *(void **)(v11 + 560),
      *(const char **)(v11 + 568),
      *(_DWORD *)(v11 + 576),
      *(const char **)(v11 + 572),
      *(const char **)(v11 + 564),
      *(vostok::logging::verbosity *)(v11 + 580),
      a6,
      v10,
      v9);
  }
  return 1;
}
