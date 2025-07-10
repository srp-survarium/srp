Scaleform::GFx::AS3::CheckResult *__cdecl Scaleform::GFx::AS3::GetArrayInd(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::ASStringNode *sn,
        unsigned int *ind)
{
  unsigned int Size; // esi
  const char *pData; // edx
  char v5; // al
  Scaleform::GFx::AS3::CheckResult *v6; // eax
  int v7; // ecx
  long double v8; // st7
  unsigned int *v9; // edx

  Size = sn->Size;
  if ( Size )
  {
    pData = sn->pData;
    v5 = *sn->pData;
    if ( v5 == 48 )
    {
      *ind = 0;
      v6 = result;
      result->Result = Size == 1;
      return v6;
    }
    if ( (unsigned __int8)(v5 - 48) <= 9u )
    {
      v7 = 1;
      if ( Size <= 1 )
      {
LABEL_8:
        v8 = strtod(pData, (char **)&sn);
        if ( v8 <= 4294967295.0 )
        {
          v9 = ind;
          v6 = result;
          result->Result = 1;
          *v9 = (__int64)v8;
          return v6;
        }
      }
      else
      {
        while ( (unsigned __int8)(pData[v7] - 48) <= 9u )
        {
          if ( ++v7 >= Size )
            goto LABEL_8;
        }
      }
    }
  }
  v6 = result;
  result->Result = 0;
  return v6;
}
