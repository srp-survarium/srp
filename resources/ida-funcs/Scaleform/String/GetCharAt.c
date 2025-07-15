unsigned int __thiscall Scaleform::String::GetCharAt(Scaleform::String *this, int index)
{
  unsigned int v2; // eax
  char *v3; // ecx
  int v4; // eax
  char *putf8Buffer; // [esp+0h] [ebp-4h] BYREF

  putf8Buffer = (char *)this;
  v2 = this->HeapTypeBits & 0xFFFFFFFC;
  v3 = (char *)(v2 + 8);
  putf8Buffer = (char *)(v2 + 8);
  v4 = *(_DWORD *)v2;
  if ( v4 >= 0 )
    return Scaleform::UTF8Util::GetCharAt(index, v3, v4 & 0x7FFFFFFF);
  putf8Buffer = &v3[index];
  return Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
}
