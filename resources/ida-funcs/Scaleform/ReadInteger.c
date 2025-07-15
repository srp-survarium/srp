unsigned int __cdecl Scaleform::ReadInteger(Scaleform::StringDataPtr *str, int defaultValue, char separator)
{
  char *pStr; // ebx
  unsigned int i; // esi
  unsigned int Size; // eax
  unsigned int v6; // ecx
  Scaleform::StringDataPtr result; // [esp+8h] [ebp-8h] BYREF

  Scaleform::StringDataPtr::GetNextToken(str, &result, separator);
  pStr = (char *)result.pStr;
  if ( !result.Size || !result.pStr || !isdigit(*result.pStr) )
    return defaultValue;
  for ( i = 1; i < result.Size; ++i )
  {
    if ( !isdigit(pStr[i]) )
      break;
  }
  Size = str->Size;
  v6 = i;
  if ( Size < i )
    v6 = str->Size;
  str->pStr += v6;
  str->Size = Size - v6;
  return atoi((int)pStr, pStr);
}
