void __usercall _CallCatchBlock2(
        int a1@<edi>,
        int a2@<esi>,
        EHRegistrationNode *pRN,
        const _s_FuncInfo *pFuncInfo,
        unsigned int handlerAddress,
        int CatchDepth,
        unsigned int NLGCode)
{
  _CallSettingFrame((int)pRN, a1, a2, handlerAddress, (unsigned int)pRN, NLGCode);
}
