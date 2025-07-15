const _s_TryBlockMapEntry *__cdecl _GetRangeOfTrysToCheck(
        const _s_FuncInfo *pFuncInfo,
        int CatchDepth,
        int curState,
        unsigned int *pStart,
        unsigned int *pEnd)
{
  unsigned int nTryBlocks; // esi
  unsigned int v7; // ebx
  const _s_TryBlockMapEntry *v8; // eax
  unsigned int v9; // esi
  const _s_TryBlockMapEntry *pEntry; // [esp+Ch] [ebp-4h]
  unsigned int end1; // [esp+18h] [ebp+8h]

  nTryBlocks = pFuncInfo->nTryBlocks;
  pEntry = pFuncInfo->pTryBlockMap;
  v7 = nTryBlocks;
LABEL_8:
  end1 = nTryBlocks;
  while ( CatchDepth >= 0 )
  {
    if ( nTryBlocks == -1 )
      _inconsistency();
    v8 = &pEntry[--nTryBlocks];
    if ( v8->tryHigh < curState && curState <= v8->catchHigh || nTryBlocks == -1 )
    {
      --CatchDepth;
      v7 = end1;
      goto LABEL_8;
    }
  }
  v9 = nTryBlocks + 1;
  *pStart = v9;
  *pEnd = v7;
  if ( v7 > pFuncInfo->nTryBlocks || v9 > v7 )
    _inconsistency();
  return &pEntry[v9];
}
