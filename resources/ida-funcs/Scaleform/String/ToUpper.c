Scaleform::String *__thiscall Scaleform::String::ToUpper(Scaleform::String *this, Scaleform::String *result)
{
  unsigned int v2; // eax
  unsigned int v3; // esi
  int Char_Advance0; // eax
  unsigned int v5; // eax
  char *putf8Buffer; // [esp+8h] [ebp-208h] BYREF
  int pindex; // [esp+Ch] [ebp-204h] BYREF
  __m128i pbuffer[32]; // [esp+10h] [ebp-200h] BYREF

  v2 = this->HeapTypeBits & 0xFFFFFFFC;
  putf8Buffer = (char *)(v2 + 8);
  v3 = v2 + 8 + (*(_DWORD *)v2 & 0x7FFFFFFF);
  result->HeapTypeBits = (unsigned int)&Scaleform::String::NullData;
  InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1);
  for ( pindex = 0; (unsigned int)putf8Buffer < v3; pindex = 0 )
  {
    do
    {
      Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
      v5 = Scaleform::SFtowupper(Char_Advance0);
      Scaleform::UTF8Util::EncodeChar(pbuffer[0].m128i_i8, &pindex, v5);
    }
    while ( (unsigned int)putf8Buffer < v3 && pindex < 504 );
    Scaleform::String::AppendString(result, pbuffer, pindex);
  }
  return result;
}
