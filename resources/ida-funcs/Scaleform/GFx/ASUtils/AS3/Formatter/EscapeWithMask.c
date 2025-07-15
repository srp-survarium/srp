void __thiscall Scaleform::GFx::ASUtils::AS3::Formatter::EscapeWithMask(
        Scaleform::GFx::ASUtils::AS3::Formatter *this,
        char *psrc,
        int length,
        Scaleform::String *escapedStr,
        const unsigned int *escapeMask,
        bool useUtf8)
{
  char *v6; // ebp
  char *v7; // eax
  int Char_Advance0; // ebx
  char *pBuf; // eax
  Scaleform::String *v11; // ecx
  char v12; // cl
  unsigned __int8 v13; // al
  char v14; // al
  unsigned __int8 v15; // cl
  char v16; // al
  char v17; // al
  char v18; // al
  unsigned __int8 v19; // bl
  char v20; // al
  Scaleform::String *v21; // ecx
  char *v22; // [esp+8h] [ebp-4h]

  v6 = psrc;
  v7 = &psrc[length];
  v22 = &psrc[length];
  this->pBuf = (char *)this;
  if ( v6 < v7 )
  {
    do
    {
      Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&psrc);
      pBuf = this->pBuf;
      if ( pBuf + 7 >= this->Endp )
      {
        v11 = escapedStr;
        *pBuf = 0;
        Scaleform::String::AppendString(v11, (const __m128i *)this, 0xFFFFFFFF);
        this->pBuf = (char *)this;
      }
      if ( Char_Advance0 < 128 && (length = 1 << (Char_Advance0 % 32), (length & escapeMask[Char_Advance0 / 32]) != 0) )
      {
        *this->pBuf = Char_Advance0;
      }
      else
      {
        if ( (Char_Advance0 & 0xFF00) != 0 )
        {
          if ( useUtf8 )
          {
            for ( ; v6 < psrc; ++v6 )
            {
              *this->pBuf++ = 37;
              v12 = *v6;
              v13 = (unsigned __int8)*v6 >> 4;
              if ( v13 >= 0xAu )
                v14 = v13 + 55;
              else
                v14 = v13 + 48;
              *this->pBuf++ = v14;
              v15 = v12 & 0xF;
              if ( v15 >= 0xAu )
                v16 = v15 + 55;
              else
                v16 = v15 + 48;
              *this->pBuf++ = v16;
            }
          }
          else
          {
            *this->pBuf++ = 37;
            *this->pBuf++ = 117;
            Scaleform::GFx::ASUtils::AS3::Formatter::WriteHexWord(this, Char_Advance0);
          }
          goto LABEL_27;
        }
        *this->pBuf++ = 37;
        v17 = (unsigned __int8)Char_Advance0 >> 4;
        if ( (unsigned __int8)((unsigned __int8)Char_Advance0 >> 4) >= 0xAu )
          v18 = v17 + 55;
        else
          v18 = v17 + 48;
        *this->pBuf++ = v18;
        v19 = Char_Advance0 & 0xF;
        if ( v19 >= 0xAu )
          v20 = v19 + 55;
        else
          v20 = v19 + 48;
        *this->pBuf = v20;
      }
      ++this->pBuf;
LABEL_27:
      v6 = psrc;
    }
    while ( psrc < v22 );
  }
  v21 = escapedStr;
  *this->pBuf = 0;
  Scaleform::String::AppendString(v21, (const __m128i *)this, 0xFFFFFFFF);
}
