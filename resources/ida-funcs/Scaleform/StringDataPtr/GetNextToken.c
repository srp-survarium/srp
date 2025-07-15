Scaleform::StringDataPtr *__thiscall Scaleform::StringDataPtr::GetNextToken(
        Scaleform::StringDataPtr *this,
        Scaleform::StringDataPtr *result,
        char separator)
{
  const char *pStr; // esi
  unsigned int Size; // edi
  unsigned int i; // edx
  char v6; // al
  Scaleform::StringDataPtr *v7; // eax

  pStr = this->pStr;
  Size = this->Size;
  for ( i = 0; i < Size; ++i )
  {
    v6 = pStr[i];
    if ( !v6 )
      break;
    if ( v6 == separator )
      break;
  }
  v7 = result;
  result->pStr = pStr;
  result->Size = i;
  return v7;
}
