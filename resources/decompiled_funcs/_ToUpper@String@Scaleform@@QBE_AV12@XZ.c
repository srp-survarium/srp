Scaleform::String *__thiscall Scaleform::String::ToUpper(Scaleform::String *this, Scaleform::String *result)
{
  unsigned int v2; // eax
  unsigned int v3; // esi
  wchar_t v4; // ax
  unsigned int v5; // eax
  const char *psource; // [esp+8h] [ebp-208h] BYREF
  int bufferOffset; // [esp+Ch] [ebp-204h] BYREF
  char buffer[512]; // [esp+10h] [ebp-200h] BYREF

  v2 = this->HeapTypeBits & 0xFFFFFFFC;
  psource = (const char *)(v2 + 8);
  v3 = v2 + 8 + (*(_DWORD *)v2 & 0x7FFFFFFF);
  result->HeapTypeBits = (unsigned int)&Scaleform::String::NullData;
  InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1);
  for ( bufferOffset = 0; (unsigned int)psource < v3; bufferOffset = 0 )
  {
    do
    {
      v4 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&psource);
      v5 = Scaleform::SFtowupper(v4);
      Scaleform::UTF8Util::EncodeChar(buffer, &bufferOffset, v5);
    }
    while ( (unsigned int)psource < v3 && bufferOffset < 504 );
    Scaleform::String::AppendString(result, buffer, bufferOffset);
  }
  return result;
}
