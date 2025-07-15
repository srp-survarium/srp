const _s_RTTIBaseClassDescriptor *__usercall FindVITargetTypeInstance@<eax>(
        const _s_RTTICompleteObjectLocator *pCOLocator@<eax>,
        char *pCompleteObject,
        TypeDescriptor *pSrcTypeID,
        int SrcOffset,
        TypeDescriptor *pTargetTypeID)
{
  const _s_RTTIClassHierarchyDescriptor *pClassDescriptor; // eax
  unsigned int numBaseClasses; // ebx
  const _s_RTTIBaseClassDescriptor *v7; // edi
  const _s_RTTIBaseClassDescriptor *v8; // esi
  int v9; // eax
  int v10; // eax
  bool v11; // al
  int v12; // eax
  const _s_RTTIBaseClassDescriptor *result; // eax
  const _s_RTTIBaseClassArray *pBaseClassArray; // [esp+Ch] [ebp-24h]
  const _s_RTTIBaseClassDescriptor *pCrossCastTargetBCD; // [esp+10h] [ebp-20h]
  const _s_RTTIBaseClassDescriptor *pCrossCastSourceBCD; // [esp+14h] [ebp-1Ch]
  int offsetDownCastResult; // [esp+18h] [ebp-18h]
  const _s_RTTIBaseClassDescriptor *pDownCastResultBCD; // [esp+1Ch] [ebp-14h]
  unsigned int nTargetBases; // [esp+20h] [ebp-10h]
  unsigned int iTarget; // [esp+24h] [ebp-Ch]
  unsigned int i; // [esp+28h] [ebp-8h]
  bool fDownCastAllowed; // [esp+2Fh] [ebp-1h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  iTarget = -1;
  offsetDownCastResult = -1;
  numBaseClasses = pClassDescriptor->numBaseClasses;
  v7 = 0;
  pDownCastResultBCD = 0;
  pCrossCastSourceBCD = 0;
  pCrossCastTargetBCD = 0;
  pBaseClassArray = pClassDescriptor->pBaseClassArray;
  nTargetBases = 0;
  fDownCastAllowed = 1;
  i = 0;
  if ( !numBaseClasses )
    return 0;
  do
  {
    v8 = pBaseClassArray->arrayOfBaseClassDescriptors[i];
    if ( i - iTarget > nTargetBases )
    {
      if ( v8->pTypeDescriptor == pTargetTypeID
        || (strcmp((unsigned __int8 *)v8->pTypeDescriptor->name, (unsigned __int8 *)pTargetTypeID->name), !v9) )
      {
        if ( (v8->attributes & 3) == 0 )
          pCrossCastTargetBCD = v8;
        iTarget = i;
        v7 = v8;
        nTargetBases = v8->numContainedBases;
      }
    }
    if ( v8->pTypeDescriptor == pSrcTypeID
      || (strcmp((unsigned __int8 *)v8->pTypeDescriptor->name, (unsigned __int8 *)pSrcTypeID->name), !v10) )
    {
      if ( PMDtoOffset(&v8->where, pCompleteObject) == SrcOffset )
      {
        if ( i - iTarget > nTargetBases )
        {
          if ( (v8->attributes & 5) == 0 )
            pCrossCastSourceBCD = v8;
        }
        else if ( fDownCastAllowed )
        {
          if ( (v7->attributes & 0x40) != 0 )
          {
            if ( (v7->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 1) != 0 )
              fDownCastAllowed = 0;
            v11 = (v7->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 4) == 0;
          }
          else
          {
            if ( !iTarget && (v8->attributes & 1) != 0 )
              fDownCastAllowed = 0;
            v11 = 1;
          }
          if ( fDownCastAllowed && v11 )
          {
            v12 = PMDtoOffset(&v7->where, pCompleteObject);
            if ( pDownCastResultBCD && offsetDownCastResult != v12 )
              return 0;
            pDownCastResultBCD = v7;
            offsetDownCastResult = v12;
          }
        }
      }
    }
    ++i;
  }
  while ( i < numBaseClasses );
  if ( !fDownCastAllowed || (result = pDownCastResultBCD) == 0 )
  {
    if ( !pCrossCastSourceBCD )
      return 0;
    result = pCrossCastTargetBCD;
    if ( !pCrossCastTargetBCD )
      return 0;
  }
  return result;
}
