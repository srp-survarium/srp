void __usercall CatchIt(
        EHRegistrationNode *pRN@<esi>,
        _s_HandlerType *pCatch@<ebx>,
        const _s_TryBlockMapEntry *pEntry@<edi>,
        EHExceptionRecord *pExcept,
        _CONTEXT *pContext,
        void *pDC,
        const _s_FuncInfo *pFuncInfo,
        const _s_CatchableType *pConv,
        int CatchDepth,
        EHRegistrationNode *pMarkerRN)
{
  void (__stdcall *v10)(_DWORD, EHRegistrationNode *); // eax

  if ( pConv )
    __BuildCatchObject(pExcept, (int (__stdcall *)())pRN, pCatch, pConv);
  if ( pMarkerRN )
    _UnwindNestedFrames((_EXCEPTION_REGISTRATION_RECORD **)pCatch, pMarkerRN, (_EXCEPTION_RECORD *)pExcept);
  else
    _UnwindNestedFrames((_EXCEPTION_REGISTRATION_RECORD **)pCatch, pRN, (_EXCEPTION_RECORD *)pExcept);
  __FrameUnwindToState(pRN, pDC, pFuncInfo, pEntry->tryLow);
  pRN->state = pEntry->tryHigh + 1;
  v10 = (void (__stdcall *)(_DWORD, EHRegistrationNode *))CallCatchBlock(
                                                            pExcept,
                                                            pRN,
                                                            pContext,
                                                            pFuncInfo,
                                                            CatchDepth,
                                                            0x100u);
  if ( v10 )
    _JumpToContinuation(v10, pRN);
}
