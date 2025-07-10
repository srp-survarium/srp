void __cdecl FindHandlerForForeignException(
        EHExceptionRecord *pExcept,
        EHRegistrationNode *pRN,
        _CONTEXT *pContext,
        void *pDC,
        const _s_FuncInfo *pFuncInfo,
        int curState,
        int CatchDepth,
        EHRegistrationNode *pMarkerRN)
{
  void **p_translator; // edi
  int v9; // esi
  const _s_TryBlockMapEntry *i; // edi
  int v11; // eax
  int v12; // ecx
  unsigned int end; // [esp+4h] [ebp-8h] BYREF
  unsigned int curTry; // [esp+8h] [ebp-4h] BYREF

  if ( pExcept->ExceptionCode != -2147483645 )
  {
    if ( !_getptd()->_translator
      || (p_translator = &_getptd()->_translator, *p_translator == _encoded_null())
      || pExcept->ExceptionCode == -532459699
      || !_CallSETranslator(pExcept, pRN, pContext, pDC, pFuncInfo, CatchDepth, pMarkerRN) )
    {
      if ( !pFuncInfo->nTryBlocks )
        _inconsistency();
      v9 = curState;
      for ( i = _GetRangeOfTrysToCheck(pFuncInfo, CatchDepth, curState, &curTry, &end); curTry < end; ++i )
      {
        if ( v9 >= i->tryLow && v9 <= i->tryHigh )
        {
          v11 = (int)&i->pHandlerArray[i->nCatches];
          v12 = *(_DWORD *)(v11 - 12);
          if ( (!v12 || !*(_BYTE *)(v12 + 8)) && (*(_BYTE *)(v11 - 16) & 0x40) == 0 )
          {
            CatchIt(pRN, (_s_HandlerType *)(v11 - 16), i, pExcept, pContext, pDC, pFuncInfo, 0, CatchDepth, pMarkerRN);
            v9 = curState;
          }
        }
        ++curTry;
      }
    }
  }
}
