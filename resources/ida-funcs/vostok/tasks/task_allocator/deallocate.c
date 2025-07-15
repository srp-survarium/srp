void __thiscall vostok::tasks::task_allocator::deallocate(
        vostok::tasks::task_allocator *this,
        vostok::tasks::task *freeing_task,
        unsigned int a3)
{
  unsigned int v3; // edi
  char *v4; // esi
  signed __int64 v5; // rax
  unsigned int v6; // ecx
  const char *v7; // [esp+0h] [ebp-28h]
  bool do_debug_break; // [esp+27h] [ebp-1h] BYREF

  v3 = a3;
  _InterlockedExchangeAdd(&s_counter, 0xFFFFFFFF);
  if ( *(_DWORD *)(a3 + 88) != 3 && !debug_macro_helper_ignore_always_35 )
  {
    do_debug_break = 0;
    vostok::debug::on_error(
      &do_debug_break,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      &stru_807510.m_buffer[56],
      &stru_807510.m_buffer[80],
      (const char *)0x43,
      (char *)&stru_807510.m_max_end,
      v7);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
  *(_DWORD *)(a3 + 88) = 0;
  v4 = (char *)&loc_60000 + (_DWORD)freeing_task;
  while ( 1 )
  {
    LODWORD(v5) = *(_DWORD *)v4;
    v6 = *((_DWORD *)v4 + 1);
    *(_DWORD *)(v3 + 4) = *(_DWORD *)v4;
    HIDWORD(v5) = v6;
    if ( _InterlockedCompareExchange64((volatile signed __int64 *)v4, __SPAIR64__(v6, a3), v5) == __PAIR64__(v6, v5) )
      break;
    v3 = a3;
  }
}
