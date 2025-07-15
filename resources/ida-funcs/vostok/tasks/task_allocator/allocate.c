vostok::tasks::task *__fastcall vostok::tasks::task_allocator::allocate(vostok::tasks::task_allocator *this, int a2)
{
  volatile signed __int64 *i; // edi
  int v3; // esi
  const char *v5; // [esp+0h] [ebp-28h]
  signed __int64 v6; // [esp+18h] [ebp-10h]
  bool do_debug_break; // [esp+27h] [ebp-1h] BYREF

  _InterlockedExchangeAdd(&s_counter, 1u);
  for ( i = (volatile signed __int64 *)((char *)&loc_60000 + a2); ; i = (volatile signed __int64 *)((char *)&loc_60000
                                                                                                  + a2) )
  {
    v3 = *(_DWORD *)i;
    if ( !*(_DWORD *)i )
      return 0;
    v6 = *i;
    if ( _InterlockedCompareExchange64(i, __SPAIR64__(*((_DWORD *)i + 1) + 1, *(_DWORD *)(v3 + 4)), v6) == v6 )
      break;
  }
  if ( *(_DWORD *)(v3 + 88) )
  {
    if ( !debug_macro_helper_ignore_always_34 )
    {
      do_debug_break = 0;
      vostok::debug::on_error(
        &do_debug_break,
        process_error_true,
        0,
        "assertion_failed",
        "fatal error",
        &stru_807510.m_buffer[56],
        &stru_807510.m_buffer[16],
        (const char *)0x38,
        (char *)&stru_807510.m_max_end,
        v5);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
  }
  return (vostok::tasks::task *)v3;
}
