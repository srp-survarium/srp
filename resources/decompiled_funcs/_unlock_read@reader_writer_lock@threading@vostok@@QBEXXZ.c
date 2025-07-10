void __usercall vostok::threading::reader_writer_lock::unlock_read(
        vostok::threading::reader_writer_lock *this@<ecx>,
        vostok::threading::reader_writer_lock::counters_type *a2@<eax>)
{
  unsigned int new_counter; // [esp+14h] [ebp-10h]
  vostok::threading::reader_writer_lock::counters_type previous_counters; // [esp+1Ch] [ebp-8h]

  while ( 1 )
  {
    previous_counters = *a2;
    HIWORD(new_counter) = HIWORD(*(_DWORD *)&a2->readers_count);
    LOWORD(new_counter) = *(_DWORD *)&a2->readers_count - 1;
    if ( vostok::threading::interlocked_compare_exchange(
           (volatile __int64 *)a2,
           __SPAIR64__(a2->writer_thread_id, new_counter),
           a2->whole) == previous_counters.whole )
      break;
    if ( !SwitchToThread() )
      Sleep(0);
  }
}
