Scaleform::GFx::AS3::CheckResult *__cdecl Scaleform::GFx::AS3::GetArrayInd(
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value::V1U *ind)
{
  unsigned int v3; // eax
  Scaleform::GFx::AS3::CheckResult *v4; // eax

  v3 = prop_name->Name.Flags & 0x1F;
  if ( v3 == 10 )
  {
    result->Result = Scaleform::GFx::AS3::GetArrayInd(
                       (Scaleform::GFx::AS3::CheckResult *)&prop_name,
                       prop_name->Name.value.VS._1.VStr,
                       (unsigned int *)ind)->Result;
    return result;
  }
  else if ( v3 - 2 > 2 )
  {
    v4 = result;
    result->Result = 0;
  }
  else
  {
    result->Result = Scaleform::GFx::AS3::Value::Convert2UInt32(
                       &prop_name->Name,
                       (Scaleform::GFx::AS3::CheckResult *)&prop_name,
                       ind)->Result;
    return result;
  }
  return v4;
}


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
