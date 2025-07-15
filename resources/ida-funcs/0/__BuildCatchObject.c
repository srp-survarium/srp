void __cdecl __BuildCatchObject(
        EHExceptionRecord *pExcept,
        int (__stdcall *pRN)(),
        const _s_HandlerType *pCatch,
        const _s_CatchableType *pConv)
{
  int (__stdcall *v4)(); // ebx
  int v5; // eax
  char *v6; // eax
  char *v7; // eax
  int v8; // [esp+0h] [ebp-28h]

  if ( (pCatch->adjectives & 0x80000000) == 0 )
    v4 = (int (__stdcall *)())((char *)pRN + pCatch->dispCatchObj + 12);
  else
    v4 = pRN;
  v5 = __BuildCatchObjectHelper(pExcept, pRN, pCatch, pConv) - 1;
  if ( v5 )
  {
    if ( v5 == 1 )
    {
      v6 = __AdjustPointer((char *)pExcept->params.pExceptionObject, &pConv->thisDisplacement);
      _CallMemberFunction1(v4, pConv->copyFunction, v6, 1);
    }
  }
  else
  {
    v7 = __AdjustPointer((char *)pExcept->params.pExceptionObject, &pConv->thisDisplacement);
    _CallMemberFunction1(v4, pConv->copyFunction, v7, v8);
  }
}
