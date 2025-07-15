void __usercall vostok::threading::reader_writer_lock::unlock_read(
        vostok::threading::reader_writer_lock *this@<ecx>,
        volatile signed __int64 *a2@<edi>)
{
  signed __int64 v2; // kr00_8
  signed __int64 v3; // [esp+10h] [ebp-8h]

  while ( 1 )
  {
    v3 = *a2;
    LOWORD(v3) = *a2 - 1;
    v2 = *a2;
    if ( _InterlockedCompareExchange64(a2, v3, *a2) == v2 )
      break;
    vostok::threading::yield(0);
  }
}
