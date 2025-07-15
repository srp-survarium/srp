char __thiscall Scaleform::GFx::ASUtils::AS3::Formatter::Unescape(
        Scaleform::GFx::ASUtils::AS3::Formatter *this,
        char *psrc,
        char *length,
        Scaleform::String *unescapedStr,
        bool useUtf8)
{
  char *v5; // edi
  char *v6; // eax
  char *pBuf; // eax
  int v9; // ebx
  Scaleform::String *v10; // ecx
  char *v11; // ebp
  bool v12; // bl
  unsigned __int16 v13; // ax

  v5 = psrc;
  length = &length[(_DWORD)psrc];
  v6 = length;
  this->pBuf = (char *)this;
  if ( v5 >= v6 )
  {
LABEL_19:
    *this->pBuf = 0;
    Scaleform::String::AppendString(unescapedStr, (const __m128i *)this, this->pBuf - (char *)this);
    return 1;
  }
  while ( 1 )
  {
    pBuf = this->pBuf;
    v9 = *v5++;
    psrc = v5;
    if ( pBuf + 7 >= this->Endp )
    {
      v10 = unescapedStr;
      *pBuf = 0;
      Scaleform::String::AppendString(v10, (const __m128i *)this, 0xFFFFFFFF);
      this->pBuf = (char *)this;
    }
    if ( v9 != 37 )
    {
      *this->pBuf = v9;
      goto LABEL_17;
    }
    v11 = v5;
    v12 = useUtf8 && *v5 != 117;
    v13 = *v5 == 117
        ? Scaleform::GFx::ASUtils::AS3::Formatter::ReadHex(this, (const char **)&psrc, length, 4u)
        : Scaleform::GFx::ASUtils::AS3::Formatter::ReadHex(this, (const char **)&psrc, length, 2u);
    v5 = psrc;
    if ( psrc == v11 )
      return 0;
    if ( v12 )
    {
      *this->pBuf = v13;
LABEL_17:
      ++this->pBuf;
      goto LABEL_18;
    }
    psrc = (char *)(this->pBuf - (char *)this);
    Scaleform::UTF8Util::EncodeChar(this->Buf, (int *)&psrc, v13);
    this->pBuf = &psrc[(_DWORD)this];
LABEL_18:
    if ( v5 >= length )
      goto LABEL_19;
  }
}
