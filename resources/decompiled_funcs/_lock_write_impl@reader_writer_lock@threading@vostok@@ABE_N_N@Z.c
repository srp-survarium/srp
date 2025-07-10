char __usercall vostok::threading::reader_writer_lock::lock_write_impl@<al>(
        vostok::threading::reader_writer_lock *this@<ecx>,
        volatile signed __int64 *a2@<edi>)
{
  int v2; // ebx
  int v3; // esi
  signed __int64 new_counter; // [esp+8h] [ebp-10h]
  signed __int64 previous_counters; // [esp+10h] [ebp-8h]

  while ( 1 )
  {
    do
    {
      v2 = *(_DWORD *)a2;
      v3 = *((_DWORD *)a2 + 1);
      LODWORD(previous_counters) = *(_DWORD *)a2;
      HIDWORD(previous_counters) = v3;
    }
    while ( (unsigned __int16)*(_DWORD *)a2 );
    if ( v3 == GetCurrentThreadId() || !v3 )
    {
      LOWORD(new_counter) = 0;
      WORD1(new_counter) = HIWORD(v2) + 1;
      HIDWORD(new_counter) = GetCurrentThreadId();
      if ( _InterlockedCompareExchange64(a2, new_counter, previous_counters) == previous_counters )
        break;
    }
  }
  return 1;
}
