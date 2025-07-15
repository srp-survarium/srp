int __cdecl _CallSETranslator(
        EHExceptionRecord *pExcept,
        EHRegistrationNode *pRN,
        void *pContext,
        void *pDC,
        const _s_FuncInfo *pFuncInfo,
        int CatchDepth,
        EHRegistrationNode *pMarkerRN)
{
  int v8; // [esp+0h] [ebp-3Ch] BYREF
  int v9; // [esp+4h] [ebp-38h]
  _DWORD v10[2]; // [esp+8h] [ebp-34h] BYREF
  void (__cdecl *translator)(unsigned int, _DWORD *); // [esp+10h] [ebp-2Ch]
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+14h] [ebp-28h]
  int (__usercall *v13)@<eax>(_EXCEPTION_REGISTRATION_RECORD **@<ebx>, EHExceptionRecord *, EHRegistrationNode *, _CONTEXT *); // [esp+18h] [ebp-24h]
  const _s_FuncInfo *v14; // [esp+20h] [ebp-1Ch]
  EHRegistrationNode *v15; // [esp+24h] [ebp-18h]
  int v16; // [esp+28h] [ebp-14h]
  EHRegistrationNode *v17; // [esp+2Ch] [ebp-10h]
  int *v18; // [esp+30h] [ebp-Ch]
  int *v19; // [esp+34h] [ebp-8h]
  int v20; // [esp+38h] [ebp-4h]
  int savedregs; // [esp+3Ch] [ebp+0h] BYREF

  if ( pExcept == (EHExceptionRecord *)291 )
  {
    pRN->pNext = (EHRegistrationNode *)&ExceptionContinuation;
    return 1;
  }
  else
  {
    v13 = TranslatorGuardHandler;
    v14 = pFuncInfo;
    v15 = pRN;
    v16 = CatchDepth;
    v17 = pMarkerRN;
    v20 = 0;
    v18 = &v8;
    v19 = &savedregs;
    ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
    v9 = 1;
    v10[0] = pExcept;
    v10[1] = pContext;
    translator = (void (__cdecl *)(unsigned int, _DWORD *))_getptd()->_translator;
    translator(pExcept->ExceptionCode, v10);
    v9 = 0;
    if ( v20 )
      ExceptionList->Next = NtCurrentTeb()->NtTib.ExceptionList->Next;
    return v9;
  }
}
