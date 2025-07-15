char __usercall vostok::threading::reader_writer_lock::lock_read_impl@<al>(
        vostok::threading::reader_writer_lock *this@<ecx>,
        volatile signed __int64 *a2@<esi>)
{
  unsigned int v3; // [esp+8h] [ebp-10h]
  signed __int64 v4; // [esp+10h] [ebp-8h]

  do
  {
    while ( HIWORD(*(_DWORD *)a2) )
      ;
    v3 = *(_DWORD *)a2;
    LOWORD(v3) = *(_DWORD *)a2 + 1;
    v4 = *a2;
  }
  while ( _InterlockedCompareExchange64(a2, __SPAIR64__(*((_DWORD *)a2 + 1), v3), v4) != v4 );
  return 1;
}
