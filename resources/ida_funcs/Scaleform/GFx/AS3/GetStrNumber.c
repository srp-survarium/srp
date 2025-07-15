Scaleform::GFx::AS3::CheckResult *__cdecl Scaleform::GFx::AS3::GetStrNumber(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::ASStringNode *sn,
        long double *resulta)
{
  Scaleform::GFx::AS3::CheckResult *v3; // eax
  unsigned int Size; // edi
  const char *pData; // esi
  int v6; // eax
  unsigned int v7; // eax
  long double v8; // st7

  if ( !sn )
  {
    v3 = result;
    result->Result = 0;
    return v3;
  }
  Size = sn->Size;
  if ( !Size )
    goto LABEL_14;
  pData = sn->pData;
  if ( (unsigned __int8)(*sn->pData - 48) > 9u )
    goto LABEL_14;
  v6 = 1;
  if ( Size <= 1 )
    goto LABEL_13;
  while ( (unsigned __int8)(pData[v6] - 48) <= 9u )
  {
    if ( ++v6 >= Size )
      goto LABEL_13;
  }
  if ( pData[v6] != 46 )
    goto LABEL_14;
  v7 = v6 + 1;
  if ( v7 >= Size )
  {
LABEL_13:
    v8 = strtod(pData, (char **)&sn);
    v3 = result;
    *resulta = v8;
    result->Result = 1;
    return v3;
  }
  while ( pData[v7] == 48 )
  {
    if ( ++v7 >= Size )
      goto LABEL_13;
  }
LABEL_14:
  v3 = result;
  result->Result = 0;
  return v3;
}
