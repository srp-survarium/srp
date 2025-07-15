void __cdecl _CallCatchBlock2(
        EHRegistrationNode *pRN,
        const _s_FuncInfo *pFuncInfo,
        void *handlerAddress,
        int CatchDepth,
        unsigned int NLGCode)
{
  _CallSettingFrame((unsigned int)handlerAddress, (unsigned int)pRN, NLGCode);
}
