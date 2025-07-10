int __usercall TranslatorGuardHandler@<eax>(
        _EXCEPTION_REGISTRATION_RECORD **a1@<ebx>,
        EHExceptionRecord *pExcept,
        EHRegistrationNode *pRN,
        _CONTEXT *pContext)
{
  void *pContinue; // [esp+4h] [ebp-4h] BYREF

  if ( (pExcept->ExceptionFlags & 0x66) != 0 )
  {
    pRN[3].pNext = (EHRegistrationNode *)1;
    return 1;
  }
  else
  {
    __InternalCxxFrameHandler(
      pExcept,
      (EHRegistrationNode *)pRN[1].frameHandler,
      pContext,
      0,
      (const _s_FuncInfo *)pRN[1].pNext,
      pRN[1].state,
      pRN[2].pNext,
      1u);
    if ( !pRN[3].pNext )
      _UnwindNestedFrames(a1, pRN, (_EXCEPTION_RECORD *)pExcept);
    _CallSETranslator((EHExceptionRecord *)0x123, (EHRegistrationNode *)&pContinue, 0, 0, 0, 0, 0);
    return ((int (*)(void))pContinue)();
  }
}
