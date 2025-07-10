void __usercall vostok::threading::reader_writer_lock::unlock_write(
        vostok::threading::reader_writer_lock *this@<ecx>,
        volatile signed __int64 *a2@<esi>)
{
  signed __int64 new_counter; // [esp+8h] [ebp-10h]
  signed __int64 previous_counters; // [esp+10h] [ebp-8h]

  while ( 1 )
  {
    new_counter = *a2;
    if ( HIWORD(*(_DWORD *)a2) == 1 )
      HIDWORD(new_counter) = 0;
    WORD1(new_counter) = HIWORD(*(_DWORD *)a2) - 1;
    previous_counters = *a2;
    if ( _InterlockedCompareExchange64(a2, new_counter, previous_counters) == previous_counters )
      break;
    if ( !SwitchToThread() )
      Sleep(0);
  }
}
