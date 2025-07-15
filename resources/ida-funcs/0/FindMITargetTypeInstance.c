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
  const _s_RTTIBaseClassDescriptor *v12; // [esp+Ch] [ebp-14h]
  const _s_RTTIBaseClassDescriptor *v13; // [esp+10h] [ebp-10h]
  unsigned int numContainedBases; // [esp+14h] [ebp-Ch]
  int v15; // [esp+18h] [ebp-8h]
  int v16; // [esp+1Ch] [ebp-4h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  v15 = -1;
  numBaseClasses = pClassDescriptor->numBaseClasses;
  pBaseClassArray = pClassDescriptor->pBaseClassArray;
  v13 = 0;
  v12 = 0;
  numContainedBases = 0;
  v16 = 0;
  if ( !numBaseClasses )
    return 0;
  while ( 1 )
  {
    v8 = pBaseClassArray->arrayOfBaseClassDescriptors[v16];
    if ( v16 - v15 > numContainedBases )
    {
      if ( v8->pTypeDescriptor == pTargetTypeID
        || (strcmp((unsigned __int8 *)v8->pTypeDescriptor->name, (unsigned __int8 *)pTargetTypeID->name), !v9) )
      {
        if ( v12 )
        {
          if ( (v8->attributes & 3) == 0 && (v12->attributes & 1) == 0 )
            return v8;
          return 0;
        }
        v15 = v16;
        v13 = v8;
        numContainedBases = v8->numContainedBases;
      }
    }
    if ( v8->pTypeDescriptor == pSrcTypeID
      || (strcmp((unsigned __int8 *)v8->pTypeDescriptor->name, (unsigned __int8 *)pSrcTypeID->name), !v10) )
    {
      if ( PMDtoOffset(&v8->where, pCompleteObject) == SrcOffset )
        break;
    }
LABEL_12:
    if ( ++v16 >= numBaseClasses )
      return 0;
  }
  if ( !v13 )
  {
    v12 = v8;
    goto LABEL_12;
  }
  if ( v16 - v15 > numContainedBases )
  {
    if ( (v13->attributes & 3) == 0 )
      goto LABEL_20;
    return 0;
  }
  if ( (v13->attributes & 0x40) == 0 )
  {
    if ( !v15 )
    {
LABEL_20:
      if ( (v8->attributes & 1) != 0 )
        return 0;
    }
    return v13;
  }
  return (v13->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[v16 - v15]->attributes & 1) == 0 ? v13 : 0;
}
