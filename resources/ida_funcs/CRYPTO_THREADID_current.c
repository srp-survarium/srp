void __cdecl CRYPTO_THREADID_current(crypto_threadid_st *id)
{
  DWORD CurrentThreadId; // eax

  if ( threadid_callback )
  {
    threadid_callback(id);
  }
  else
  {
    if ( id_callback )
      CurrentThreadId = id_callback();
    else
      CurrentThreadId = GetCurrentThreadId();
    id->ptr = 0;
    id->val = CurrentThreadId;
  }
}
