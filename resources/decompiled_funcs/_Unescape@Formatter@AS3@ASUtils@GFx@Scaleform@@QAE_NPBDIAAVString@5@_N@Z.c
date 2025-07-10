char __thiscall Scaleform::GFx::ASUtils::AS3::Formatter::Unescape(
        Scaleform::GFx::ASUtils::AS3::Formatter *this,
        int psrc,
        const char *length,
        Scaleform::String *unescapedStr,
        bool useUtf8)
{
  const char *v5; // edi
  const char *v6; // eax
  char *pBuf; // eax
  int v9; // ebx
  Scaleform::String *v10; // ecx
  const char *v11; // ebp
  bool v12; // bl
  unsigned __int16 v13; // ax

  v5 = (const char *)psrc;
  length += psrc;
  v6 = length;
  this->pBuf = (char *)this;
  if ( v5 >= v6 )
  {
LABEL_19:
    *this->pBuf = 0;
    Scaleform::String::AppendString(unescapedStr, this->Buf, this->pBuf - (char *)this);
    return 1;
  }
  while ( 1 )
  {
    pBuf = this->pBuf;
    v9 = *v5++;
    psrc = (int)v5;
    if ( pBuf + 7 >= this->Endp )
    {
      v10 = unescapedStr;
      *pBuf = 0;
      Scaleform::String::AppendString(v10, this->Buf, 0xFFFFFFFF);
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
    v5 = (const char *)psrc;
    if ( (const char *)psrc == v11 )
      return 0;
    if ( v12 )
    {
      *this->pBuf = v13;
LABEL_17:
      ++this->pBuf;
      goto LABEL_18;
    }
    psrc = this->pBuf - (char *)this;
    Scaleform::UTF8Util::EncodeChar(this->Buf, &psrc, v13);
    this->pBuf = &this->Buf[psrc];
LABEL_18:
    if ( v5 >= length )
      goto LABEL_19;
  }
}
