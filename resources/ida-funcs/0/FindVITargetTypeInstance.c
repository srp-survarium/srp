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
  const _s_RTTIBaseClassDescriptor *v15; // [esp+10h] [ebp-20h]
  const _s_RTTIBaseClassDescriptor *v16; // [esp+14h] [ebp-1Ch]
  int v17; // [esp+18h] [ebp-18h]
  const _s_RTTIBaseClassDescriptor *v18; // [esp+1Ch] [ebp-14h]
  unsigned int numContainedBases; // [esp+20h] [ebp-10h]
  int v20; // [esp+24h] [ebp-Ch]
  unsigned int v21; // [esp+28h] [ebp-8h]
  char v22; // [esp+2Fh] [ebp-1h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  v20 = -1;
  v17 = -1;
  numBaseClasses = pClassDescriptor->numBaseClasses;
  v7 = 0;
  v18 = 0;
  v16 = 0;
  v15 = 0;
  pBaseClassArray = pClassDescriptor->pBaseClassArray;
  numContainedBases = 0;
  v22 = 1;
  v21 = 0;
  if ( !numBaseClasses )
    return 0;
  do
  {
    v8 = pBaseClassArray->arrayOfBaseClassDescriptors[v21];
    if ( v21 - v20 > numContainedBases )
    {
      if ( v8->pTypeDescriptor == pTargetTypeID
        || (strcmp((unsigned __int8 *)v8->pTypeDescriptor->name, (unsigned __int8 *)pTargetTypeID->name), !v9) )
      {
        if ( (v8->attributes & 3) == 0 )
          v15 = v8;
        v20 = v21;
        v7 = v8;
        numContainedBases = v8->numContainedBases;
      }
    }
    if ( v8->pTypeDescriptor == pSrcTypeID
      || (strcmp((unsigned __int8 *)v8->pTypeDescriptor->name, (unsigned __int8 *)pSrcTypeID->name), !v10) )
    {
      if ( PMDtoOffset(&v8->where, pCompleteObject) == SrcOffset )
      {
        if ( v21 - v20 > numContainedBases )
        {
          if ( (v8->attributes & 5) == 0 )
            v16 = v8;
        }
        else if ( v22 )
        {
          if ( (v7->attributes & 0x40) != 0 )
          {
            if ( (v7->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[v21 - v20]->attributes & 1) != 0 )
              v22 = 0;
            v11 = (v7->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[v21 - v20]->attributes & 4) == 0;
          }
          else
          {
            if ( !v20 && (v8->attributes & 1) != 0 )
              v22 = 0;
            v11 = 1;
          }
          if ( v22 && v11 )
          {
            v12 = PMDtoOffset(&v7->where, pCompleteObject);
            if ( v18 && v17 != v12 )
              return 0;
            v18 = v7;
            v17 = v12;
          }
        }
      }
    }
    ++v21;
  }
  while ( v21 < numBaseClasses );
  if ( !v22 || (result = v18) == 0 )
  {
    if ( !v16 )
      return 0;
    result = v15;
    if ( !v15 )
      return 0;
  }
  return result;
}
