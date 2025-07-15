int __usercall ExFilterRethrow@<eax>(_EXCEPTION_POINTERS *pExPtrs@<eax>)
{
  _EXCEPTION_RECORD *ExceptionRecord; // eax
  unsigned int v2; // ecx

  ExceptionRecord = pExPtrs->ExceptionRecord;
  if ( ExceptionRecord->ExceptionCode != -529697949 )
    return 0;
  if ( ExceptionRecord->NumberParameters != 3 )
    return 0;
  v2 = ExceptionRecord->ExceptionInformation[0];
  if ( v2 != 429065504 && v2 != 429065505 && v2 != 429065506 )
    return 0;
  if ( ExceptionRecord->ExceptionInformation[2] )
    return 0;
  _getptd()->_cxxReThrow = 1;
  return 1;
}
