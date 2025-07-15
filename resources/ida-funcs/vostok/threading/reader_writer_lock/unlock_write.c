void __usercall vostok::threading::reader_writer_lock::unlock_write(
        vostok::threading::reader_writer_lock *this@<ecx>,
        volatile signed __int64 *a2@<edi>)
{
  signed __int64 v2; // [esp+8h] [ebp-10h]
  signed __int64 v3; // [esp+10h] [ebp-8h]

  while ( 1 )
  {
    v3 = *a2;
    if ( HIWORD(*(_DWORD *)a2) == 1 )
      HIDWORD(v3) = 0;
    WORD1(v3) = HIWORD(*(_DWORD *)a2) - 1;
    v2 = *a2;
    if ( _InterlockedCompareExchange64(a2, v3, v2) == v2 )
      break;
    vostok::threading::yield(0);
  }
}
