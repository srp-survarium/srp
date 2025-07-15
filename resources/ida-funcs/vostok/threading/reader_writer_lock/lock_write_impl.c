char __thiscall vostok::threading::reader_writer_lock::lock_write_impl(
        vostok::threading::reader_writer_lock *this,
        volatile signed __int64 *try_lock)
{
  int v2; // ebx
  int v3; // esi
  signed __int64 v5; // [esp+10h] [ebp-10h]
  signed __int64 v6; // [esp+18h] [ebp-8h]

  while ( 1 )
  {
    do
    {
      v2 = *(_DWORD *)try_lock;
      v3 = *((_DWORD *)try_lock + 1);
      LODWORD(v6) = *(_DWORD *)try_lock;
      HIDWORD(v6) = v3;
    }
    while ( (unsigned __int16)*(_DWORD *)try_lock );
    if ( v3 == GetCurrentThreadId() || !v3 )
    {
      LOWORD(v5) = 0;
      WORD1(v5) = HIWORD(v2) + 1;
      HIDWORD(v5) = GetCurrentThreadId();
      if ( _InterlockedCompareExchange64(try_lock, v5, v6) == v6 )
        break;
    }
  }
  return 1;
}
