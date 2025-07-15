void __cdecl CallDestructExceptionObject(_EXCEPTION_RECORD *pExcept)
{
  if ( pExcept->ExceptionCode == -529697949 && _pDestructExceptionObject[0] )
  {
    if ( _IsNonwritableInCurrentImage((unsigned __int8 *)_pDestructExceptionObject) )
      ((void (__cdecl *)(EHExceptionRecord *))_pDestructExceptionObject[0])((EHExceptionRecord *)pExcept);
  }
}
