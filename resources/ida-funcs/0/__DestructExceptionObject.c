void __cdecl __DestructExceptionObject(EHExceptionRecord *pExcept)
{
  const _s_ThrowInfo *pThrowInfo; // eax
  void (__cdecl *pmfnUnwind)(); // eax
  void *v3; // [esp+0h] [ebp-28h]
  int v4; // [esp+4h] [ebp-24h]

  if ( pExcept )
  {
    if ( pExcept->ExceptionCode == -529697949 )
    {
      pThrowInfo = pExcept->params.pThrowInfo;
      if ( pThrowInfo )
      {
        pmfnUnwind = pThrowInfo->pmfnUnwind;
        if ( pmfnUnwind )
          _CallMemberFunction1(pExcept->params.pExceptionObject, pmfnUnwind, v3, v4);
      }
    }
  }
}
