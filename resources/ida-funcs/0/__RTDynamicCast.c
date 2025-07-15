char *__cdecl __RTDynamicCast(
        void **inptr,
        int VfDelta,
        TypeDescriptor *SrcType,
        TypeDescriptor *TargetType,
        int isReference)
{
  char *result; // eax
  char *CompleteObject; // edi
  const _s_RTTICompleteObjectLocator *v7; // eax
  char *v8; // esi
  unsigned int attributes; // ecx
  const _s_RTTIBaseClassDescriptor *VITargetTypeInstance; // eax
  std::bad_cast pExceptionObject; // [esp+10h] [ebp-28h] BYREF
  void *pResult; // [esp+1Ch] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+20h] [ebp-18h]

  if ( !inptr )
    return 0;
  ms_exc.registration.TryLevel = 0;
  CompleteObject = FindCompleteObject(inptr);
  v7 = (const _s_RTTICompleteObjectLocator *)*((_DWORD *)*inptr - 1);
  v8 = (char *)((char *)inptr - VfDelta - CompleteObject);
  attributes = v7->pClassDescriptor->attributes;
  if ( (attributes & 1) != 0 )
  {
    if ( (attributes & 2) != 0 )
      VITargetTypeInstance = FindVITargetTypeInstance(v7, CompleteObject, SrcType, (int)v8, TargetType);
    else
      VITargetTypeInstance = FindMITargetTypeInstance(v7, CompleteObject, SrcType, (int)v8, TargetType);
  }
  else
  {
    VITargetTypeInstance = FindSITargetTypeInstance(v7, SrcType, TargetType);
  }
  if ( VITargetTypeInstance )
  {
    result = &CompleteObject[PMDtoOffset(&VITargetTypeInstance->where, CompleteObject)];
    pResult = result;
  }
  else
  {
    result = 0;
    pResult = 0;
    if ( isReference )
    {
      std::bad_cast::bad_cast(&pExceptionObject, "Bad dynamic_cast!");
      _CxxThrowException(&pExceptionObject, &_TI2_AVbad_cast_std__);
    }
  }
  ms_exc.registration.TryLevel = -2;
  return result;
}
