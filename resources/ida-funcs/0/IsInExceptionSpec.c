char __usercall IsInExceptionSpec@<al>(const _s_ESTypeList *pESTypeList@<edi>, EHExceptionRecord *pExcept)
{
  const _s_CatchableTypeArray *pCatchableTypeArray; // eax
  int nCatchableTypes; // ebx
  const _s_CatchableType **arrayOfCatchableTypes; // esi
  int v6; // [esp+4h] [ebp-8h]
  char i; // [esp+Bh] [ebp-1h]

  if ( !pESTypeList )
    _inconsistency();
  v6 = 0;
  for ( i = 0; v6 < pESTypeList->nCount; ++v6 )
  {
    pCatchableTypeArray = pExcept->params.pThrowInfo->pCatchableTypeArray;
    nCatchableTypes = pCatchableTypeArray->nCatchableTypes;
    arrayOfCatchableTypes = pCatchableTypeArray->arrayOfCatchableTypes;
    if ( pCatchableTypeArray->nCatchableTypes > 0 )
    {
      while ( !__TypeMatch(&pESTypeList->pTypeArray[v6], *arrayOfCatchableTypes, pExcept->params.pThrowInfo) )
      {
        --nCatchableTypes;
        ++arrayOfCatchableTypes;
        if ( nCatchableTypes <= 0 )
          goto LABEL_9;
      }
      i = 1;
    }
LABEL_9:
    ;
  }
  return i;
}
