int __cdecl __InternalCxxFrameHandler(
        EHExceptionRecord *pExcept,
        EHRegistrationNode *pRN,
        _CONTEXT *pContext,
        void *pDC,
        const _s_FuncInfo *pFuncInfo,
        int CatchDepth,
        EHRegistrationNode *pMarkerRN,
        unsigned __int8 recursive)
{
  int (*pForwardCompat)(...); // edx

  if ( _getptd()->_cxxReThrow
    || pExcept->ExceptionCode == -529697949
    || pExcept->ExceptionCode == -2147483610
    || (*(_DWORD *)pFuncInfo & 0x1FFFFFFFu) < 0x19930522
    || (pFuncInfo->EHFlags & 1) == 0 )
  {
    if ( (pExcept->ExceptionFlags & 0x66) != 0 )
    {
      if ( pFuncInfo->maxState )
      {
        if ( !CatchDepth )
          __FrameUnwindToState(pRN, pDC, pFuncInfo, -1);
      }
    }
    else if ( pFuncInfo->nTryBlocks || (*(_DWORD *)pFuncInfo & 0x1FFFFFFFu) >= 0x19930521 && pFuncInfo->pESTypeList )
    {
      if ( pExcept->ExceptionCode == -529697949
        && pExcept->NumberParameters >= 3
        && pExcept->params.magicNumber > 0x19930522 )
      {
        pForwardCompat = pExcept->params.pThrowInfo->pForwardCompat;
        if ( pForwardCompat )
          return pForwardCompat(pExcept, pRN, pContext, pDC, pFuncInfo, CatchDepth, pMarkerRN, recursive);
      }
      FindHandler(pExcept, pRN, pContext, pDC, pFuncInfo, recursive, CatchDepth, pMarkerRN);
    }
  }
  return 1;
}
