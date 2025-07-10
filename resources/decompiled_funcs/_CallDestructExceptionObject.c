void __cdecl CallDestructExceptionObject(_EXCEPTION_RECORD *pExcept, int fThrowNotAllowed)
{
  if ( pExcept->ExceptionCode == -529697949 && _pDestructExceptionObject )
  {
    if ( _IsNonwritableInCurrentImage((unsigned __int8 *)&_pDestructExceptionObject) )
      _pDestructExceptionObject(pExcept, fThrowNotAllowed);
  }
}
