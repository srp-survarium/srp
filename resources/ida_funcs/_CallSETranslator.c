int __cdecl _CallSETranslator(
        EHExceptionRecord *pExcept,
        EHRegistrationNode *pRN,
        _CONTEXT *pContext,
        void *pDC,
        const _s_FuncInfo *pFuncInfo,
        int CatchDepth,
        EHRegistrationNode *pMarkerRN)
{
  int v8; // [esp+0h] [ebp-3Ch] BYREF
  int DidTranslate; // [esp+4h] [ebp-38h]
  _EXCEPTION_POINTERS pointers; // [esp+8h] [ebp-34h] BYREF
  void (__cdecl *pSETranslator)(unsigned int, _EXCEPTION_POINTERS *); // [esp+10h] [ebp-2Ch]
  TranslatorGuardRN TGRN; // [esp+14h] [ebp-28h]
  int savedregs; // [esp+3Ch] [ebp+0h] BYREF

  if ( pExcept == (EHExceptionRecord *)291 )
  {
    pRN->pNext = (EHRegistrationNode *)&ExceptionContinuation;
    return 1;
  }
  else
  {
    TGRN.pFrameHandler = TranslatorGuardHandler;
    TGRN.pFuncInfo = pFuncInfo;
    TGRN.pRN = pRN;
    TGRN.CatchDepth = CatchDepth;
    TGRN.pMarkerRN = pMarkerRN;
    TGRN.DidUnwind = 0;
    TGRN.ESP = &v8;
    TGRN.EBP = &savedregs;
    TGRN.pNext = (EHRegistrationNode *)NtCurrentTeb()->NtTib.ExceptionList;
    DidTranslate = 1;
    pointers.ExceptionRecord = (_EXCEPTION_RECORD *)pExcept;
    pointers.ContextRecord = pContext;
    pSETranslator = (void (__cdecl *)(unsigned int, _EXCEPTION_POINTERS *))_getptd()->_translator;
    pSETranslator(pExcept->ExceptionCode, &pointers);
    DidTranslate = 0;
    if ( TGRN.DidUnwind )
      TGRN.pNext->pNext = (EHRegistrationNode *)NtCurrentTeb()->NtTib.ExceptionList->Next;
    return DidTranslate;
  }
}
