int __cdecl CatchGuardHandler(EHExceptionRecord *pExcept, EHRegistrationNode *pRN, _CONTEXT *pContext)
{
  return __InternalCxxFrameHandler(
           pExcept,
           (EHRegistrationNode *)pRN[1].frameHandler,
           pContext,
           0,
           (const _s_FuncInfo *)pRN[1].pNext,
           pRN[1].state,
           pRN,
           0);
}
