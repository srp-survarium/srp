void __usercall vostok::memory::doug_lea_allocator::user_current_thread_id(
        vostok::memory::doug_lea_allocator *this@<ecx>,
        int a2@<esi>)
{
  DWORD CurrentThreadId; // eax
  const char *Value; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( *(_DWORD *)(a2 + 36) != CurrentThreadId )
  {
    _InterlockedExchange((volatile __int32 *)(a2 + 36), CurrentThreadId);
    if ( *(_DWORD *)(a2 + 28) )
      *(_BYTE *)(a2 + 32) = 1;
  }
  Value = (const char *)TlsGetValue(s_thread_logging_name_tls_key);
  if ( !Value )
    Value = "undefined";
  *(_DWORD *)(a2 + 24) = Value;
}
