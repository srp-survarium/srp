unsigned int __thiscall Scaleform::String::GetFirstCharAt(Scaleform::String *this, char *index, char **offset)
{
  unsigned int v3; // eax
  char *v4; // edi
  unsigned int v5; // esi
  unsigned int result; // eax

  v3 = this->HeapTypeBits & 0xFFFFFFFC;
  v4 = index;
  index = (char *)(v3 + 8);
  v5 = v3 + 8 + (*(_DWORD *)v3 & 0x7FFFFFFF);
  while ( 1 )
  {
    result = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&index);
    --v4;
    if ( (unsigned int)index >= v5 )
      break;
    if ( (int)v4 < 0 )
    {
      *offset = index;
      return result;
    }
  }
  return result;
}
