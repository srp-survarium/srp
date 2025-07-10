unsigned __int8 __usercall IsInExceptionSpec@<al>(const _s_ESTypeList *pESTypeList@<edi>, EHExceptionRecord *pExcept)
{
  const _s_CatchableTypeArray *pCatchableTypeArray; // eax
  int nCatchableTypes; // ebx
  const _s_CatchableType **arrayOfCatchableTypes; // esi
  int i; // [esp+4h] [ebp-8h]
  unsigned __int8 bFoundMatchingTypeInES; // [esp+Bh] [ebp-1h]

  if ( !pESTypeList )
    _inconsistency();
  i = 0;
  for ( bFoundMatchingTypeInES = 0; i < pESTypeList->nCount; ++i )
  {
    pCatchableTypeArray = pExcept->params.pThrowInfo->pCatchableTypeArray;
    nCatchableTypes = pCatchableTypeArray->nCatchableTypes;
    arrayOfCatchableTypes = pCatchableTypeArray->arrayOfCatchableTypes;
    if ( pCatchableTypeArray->nCatchableTypes > 0 )
    {
      while ( !__TypeMatch(&pESTypeList->pTypeArray[i], *arrayOfCatchableTypes, pExcept->params.pThrowInfo) )
      {
        --nCatchableTypes;
        ++arrayOfCatchableTypes;
        if ( nCatchableTypes <= 0 )
          goto LABEL_9;
      }
      bFoundMatchingTypeInES = 1;
    }
LABEL_9:
    ;
  }
  return bFoundMatchingTypeInES;
}
