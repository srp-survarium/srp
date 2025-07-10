int __cdecl Scaleform::ReadInteger(Scaleform::StringDataPtr *str, int defaultValue, char separator)
{
  const char *pStr; // ebx
  unsigned int i; // esi
  unsigned int Size; // eax
  unsigned int v6; // ecx
  Scaleform::StringDataPtr token; // [esp+8h] [ebp-8h] BYREF

  Scaleform::StringDataPtr::GetNextToken(str, &token, separator);
  pStr = token.pStr;
  if ( !token.Size || !token.pStr || !isdigit(*token.pStr) )
    return defaultValue;
  for ( i = 1; i < token.Size; ++i )
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
  return atoi(pStr);
}
