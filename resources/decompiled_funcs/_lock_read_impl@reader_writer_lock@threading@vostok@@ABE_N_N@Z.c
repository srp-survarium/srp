char __usercall vostok::threading::reader_writer_lock::lock_read_impl@<al>(
        vostok::threading::reader_writer_lock *this@<ecx>,
        unsigned int *a2@<esi>)
{
  unsigned int new_counters; // [esp+8h] [ebp-10h]
  signed __int64 previous_counters; // [esp+10h] [ebp-8h]

  do
  {
    while ( HIWORD(*a2) )
      ;
    new_counters = *a2;
    LOWORD(new_counters) = *a2 + 1;
    previous_counters = *(_QWORD *)a2;
  }
  while ( _InterlockedCompareExchange64(
            (volatile signed __int64 *)a2,
            __SPAIR64__(a2[1], new_counters),
            previous_counters) != previous_counters );
  return 1;
}
