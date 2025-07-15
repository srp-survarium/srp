Scaleform::GFx::AS3::CheckResult *__cdecl Scaleform::GFx::AS3::IsNameChar(
        Scaleform::GFx::AS3::CheckResult *result,
        int c)
{
  Scaleform::GFx::AS3::CheckResult *v2; // eax
  Scaleform::GFx::AS3::CheckResult v3; // [esp+7h] [ebp-1h] BYREF

  if ( Scaleform::GFx::AS3::IsNameStartChar(&v3, c)->Result
    || c == 45
    || c == 46
    || (unsigned int)(c - 48) <= 9
    || c == 183
    || (unsigned int)(c - 768) <= 0x6F )
  {
    v2 = result;
  }
  else
  {
    v2 = result;
    if ( (unsigned int)(c - 8255) > 1 )
    {
      result->Result = 0;
      return v2;
    }
  }
  v2->Result = 1;
  return v2;
}
