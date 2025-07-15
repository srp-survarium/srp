const char *__usercall Scaleform::GFx::FontFlagsToString@<eax>(unsigned int matchFontFlags@<eax>)
{
  const char *result; // eax
  bool v2; // zf

  if ( !matchFontFlags )
    return StrFlags[0];
  if ( (matchFontFlags & 0x10) != 0 )
  {
    if ( (matchFontFlags & 3) == 3 )
      return StrFlags[7];
    if ( (matchFontFlags & 2) != 0 )
      return StrFlags[5];
    if ( (matchFontFlags & 1) != 0 )
      return StrFlags[6];
    return StrFlags[4];
  }
  if ( (matchFontFlags & 3) == 3 )
    return StrFlags[3];
  if ( (matchFontFlags & 2) != 0 )
    return StrFlags[1];
  v2 = (matchFontFlags & 1) == 0;
  result = StrFlags[2];
  if ( v2 )
    return StrFlags[0];
  return result;
}
