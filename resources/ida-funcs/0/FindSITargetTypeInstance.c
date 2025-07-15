const _s_RTTIBaseClassDescriptor *__usercall FindSITargetTypeInstance@<eax>(
        const _s_RTTICompleteObjectLocator *pCOLocator@<eax>,
        TypeDescriptor *pSrcTypeID,
        TypeDescriptor *pTargetTypeID)
{
  const _s_RTTIClassHierarchyDescriptor *pClassDescriptor; // eax
  unsigned int numBaseClasses; // ebx
  int v5; // esi
  const _s_RTTIBaseClassArray *pBaseClassArray; // edi
  int v7; // eax
  const _s_RTTIBaseClassDescriptor *v9; // eax
  TypeDescriptor *pTypeDescriptor; // eax
  int v11; // eax
  const _s_RTTIBaseClassDescriptor *pBCD; // [esp+Ch] [ebp-4h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  numBaseClasses = pClassDescriptor->numBaseClasses;
  v5 = 0;
  pBaseClassArray = pClassDescriptor->pBaseClassArray;
  if ( numBaseClasses )
  {
    while ( 1 )
    {
      pBCD = pBaseClassArray->arrayOfBaseClassDescriptors[v5];
      if ( pBCD->pTypeDescriptor == pTargetTypeID )
        break;
      strcmp((unsigned __int8 *)pBCD->pTypeDescriptor->name, (unsigned __int8 *)pTargetTypeID->name);
      if ( !v7 )
        break;
      if ( ++v5 >= numBaseClasses )
        return 0;
    }
    while ( ++v5 < numBaseClasses )
    {
      v9 = pBaseClassArray->arrayOfBaseClassDescriptors[v5];
      if ( (v9->attributes & 4) != 0 )
        break;
      pTypeDescriptor = v9->pTypeDescriptor;
      if ( pTypeDescriptor != pSrcTypeID )
      {
        strcmp((unsigned __int8 *)pTypeDescriptor->name, (unsigned __int8 *)pSrcTypeID->name);
        if ( v11 )
          continue;
      }
      return pBCD;
    }
  }
  return 0;
}
