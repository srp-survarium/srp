const _s_RTTIBaseClassDescriptor *__usercall FindMITargetTypeInstance@<eax>(
        const _s_RTTICompleteObjectLocator *pCOLocator@<eax>,
        char *pCompleteObject,
        TypeDescriptor *pSrcTypeID,
        int SrcOffset,
        TypeDescriptor *pTargetTypeID)
{
  const _s_RTTIClassHierarchyDescriptor *pClassDescriptor; // eax
  unsigned int numBaseClasses; // ebx
  const _s_RTTIBaseClassArray *pBaseClassArray; // edi
  const _s_RTTIBaseClassDescriptor *v8; // esi
  int v9; // eax
  int v10; // eax
  const _s_RTTIBaseClassDescriptor *pSourceBCD; // [esp+Ch] [ebp-14h]
  const _s_RTTIBaseClassDescriptor *pTargetBCD; // [esp+10h] [ebp-10h]
  unsigned int nTargetBases; // [esp+14h] [ebp-Ch]
  unsigned int iTarget; // [esp+18h] [ebp-8h]
  unsigned int i; // [esp+1Ch] [ebp-4h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  iTarget = -1;
  numBaseClasses = pClassDescriptor->numBaseClasses;
  pBaseClassArray = pClassDescriptor->pBaseClassArray;
  pTargetBCD = 0;
  pSourceBCD = 0;
  nTargetBases = 0;
  i = 0;
  if ( !numBaseClasses )
    return 0;
  while ( 1 )
  {
    v8 = pBaseClassArray->arrayOfBaseClassDescriptors[i];
    if ( i - iTarget > nTargetBases )
    {
      if ( v8->pTypeDescriptor == pTargetTypeID
        || (strcmp((unsigned __int8 *)v8->pTypeDescriptor->name, (unsigned __int8 *)pTargetTypeID->name), !v9) )
      {
        if ( pSourceBCD )
        {
          if ( (v8->attributes & 3) == 0 && (pSourceBCD->attributes & 1) == 0 )
            return v8;
          return 0;
        }
        iTarget = i;
        pTargetBCD = v8;
        nTargetBases = v8->numContainedBases;
      }
    }
    if ( v8->pTypeDescriptor == pSrcTypeID
      || (strcmp((unsigned __int8 *)v8->pTypeDescriptor->name, (unsigned __int8 *)pSrcTypeID->name), !v10) )
    {
      if ( PMDtoOffset(&v8->where, pCompleteObject) == SrcOffset )
        break;
    }
LABEL_12:
    if ( ++i >= numBaseClasses )
      return 0;
  }
  if ( !pTargetBCD )
  {
    pSourceBCD = v8;
    goto LABEL_12;
  }
  if ( i - iTarget > nTargetBases )
  {
    if ( (pTargetBCD->attributes & 3) == 0 )
      goto LABEL_20;
    return 0;
  }
  if ( (pTargetBCD->attributes & 0x40) == 0 )
  {
    if ( !iTarget )
    {
LABEL_20:
      if ( (v8->attributes & 1) != 0 )
        return 0;
    }
    return pTargetBCD;
  }
  return (pTargetBCD->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 1) == 0
       ? pTargetBCD
       : 0;
}
