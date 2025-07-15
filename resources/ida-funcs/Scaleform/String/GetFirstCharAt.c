unsigned int __thiscall Scaleform::String::GetFirstCharAt(
        Scaleform::String *this,
        const char *index,
        const char **offset)
{
  _DWORD *v3; // eax
  const char *v4; // edi
  const char *v5; // esi
  unsigned int result; // eax

  v3 = (_DWORD *)(this->HeapTypeBits & 0xFFFFFFFC);
  v4 = index;
  index = (const char *)(v3 + 2);
  v5 = (char *)v3 + (*v3 & 0x7FFFFFFF) + 8;
  while ( 1 )
  {
    result = Scaleform::UTF8Util::DecodeNextChar_Advance0(&index);
    --v4;
    if ( index >= v5 )
      break;
    if ( (int)v4 < 0 )
    {
      *offset = index;
      return result;
    }
  }
  return result;
}
