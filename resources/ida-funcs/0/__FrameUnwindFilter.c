int __cdecl __FrameUnwindFilter(_EXCEPTION_POINTERS *pExPtrs)
{
  unsigned int ExceptionCode; // eax
  _tiddata *v2; // eax

  ExceptionCode = pExPtrs->ExceptionRecord->ExceptionCode;
  if ( ExceptionCode == -532459699 )
  {
    if ( _getptd()->_ProcessingThrow > 0 )
    {
      v2 = _getptd();
      --v2->_ProcessingThrow;
    }
  }
  else if ( ExceptionCode == -529697949 )
  {
    _getptd()->_ProcessingThrow = 0;
    terminate();
  }
  return 0;
}
