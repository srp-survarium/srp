int __stdcall __CxxUnhandledExceptionFilter(_EXCEPTION_POINTERS *pPtrs)
{
  _EXCEPTION_RECORD *ExceptionRecord; // eax
  unsigned __int8 *v2; // eax

  ExceptionRecord = pPtrs->ExceptionRecord;
  if ( pPtrs->ExceptionRecord->ExceptionCode == -529697949 && ExceptionRecord->NumberParameters == 3 )
  {
    v2 = (unsigned __int8 *)ExceptionRecord->ExceptionInformation[0];
    if ( v2 == (unsigned __int8 *)429065504
      || v2 == (unsigned __int8 *)429065505
      || v2 == (unsigned __int8 *)429065506
      || v2 == &vostok::memory::s_CRT_arena[15617592] )
    {
      terminate();
    }
  }
  return 0;
}
