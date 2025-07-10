Scaleform::GFx::AS3::CheckResult *__cdecl Scaleform::GFx::AS3::IsNameStartChar(
        Scaleform::GFx::AS3::CheckResult *result,
        int c)
{
  Scaleform::GFx::AS3::CheckResult *v2; // eax

  if ( c == 58
    || c == 95
    || (unsigned int)(c - 65) <= 0x19
    || (unsigned int)(c - 97) <= 0x19
    || (unsigned int)(c - 192) <= 0x16
    || (unsigned int)(c - 216) <= 0x1E
    || (unsigned int)(c - 248) <= 0x207
    || (unsigned int)(c - 880) <= 0xD
    || (unsigned int)(c - 895) <= 0x1C80
    || (unsigned int)(c - 8204) <= 1
    || (unsigned int)(c - 8304) <= 0x11F
    || (unsigned int)(c - 11264) <= 0x3EF
    || (unsigned int)(c - 12289) <= 0xA7FE
    || (unsigned int)(c - 63744) <= 0x4CF
    || (unsigned int)(c - 65008) <= 0x20D )
  {
    v2 = result;
  }
  else
  {
    v2 = result;
    if ( (unsigned int)(c - 0x10000) > 0xDFFFF )
    {
      result->Result = 0;
      return v2;
    }
  }
  v2->Result = 1;
  return v2;
}
