void __thiscall Scaleform::NumericBase::ReadWidth(Scaleform::NumericBase *this, Scaleform::StringDataPtr token)
{
  int v3; // eax
  int v4; // edi
  unsigned int Size; // edx
  unsigned int v6; // eax
  int v7; // ecx

  if ( token.Size )
  {
    v3 = 0;
    while ( token.pStr[v3] != 46 )
    {
      if ( ++v3 >= token.Size )
      {
        v4 = -1;
        goto LABEL_6;
      }
    }
    v4 = v3;
LABEL_6:
    *(_DWORD *)this ^= (*(_DWORD *)this
                      ^ (32 * Scaleform::ReadInteger(&token, (*(_DWORD *)this >> 5) & 0x1F, 58)))
                     & 0x3E0;
    if ( v4 >= 0 )
    {
      Size = token.Size;
      v6 = *(_DWORD *)this & 0xFFFFFFE0;
      *(_DWORD *)this = v6;
      v7 = Size != 0;
      token.pStr += v7;
      token.Size = Size - v7;
      *(_DWORD *)this ^= ((unsigned __int8)Scaleform::ReadInteger(&token, v6 & 0x1F, 58)
                        ^ (unsigned __int8)*(_DWORD *)this)
                       & 0x1F;
    }
  }
}
