void __thiscall Scaleform::GFx::ASUtils::AS3::Formatter::WriteHexWord(
        Scaleform::GFx::ASUtils::AS3::Formatter *this,
        __int16 v)
{
  char v2; // al
  char v3; // al
  char v4; // al
  char v5; // al
  char v6; // al
  char v7; // al
  char v8; // al
  char v9; // al

  v2 = HIBYTE(v) >> 4;
  if ( (unsigned __int8)(HIBYTE(v) >> 4) >= 0xAu )
    v3 = v2 + 55;
  else
    v3 = v2 + 48;
  *this->pBuf++ = v3;
  v4 = HIBYTE(v) & 0xF;
  if ( (HIBYTE(v) & 0xFu) >= 0xA )
    v5 = v4 + 55;
  else
    v5 = v4 + 48;
  *this->pBuf++ = v5;
  v6 = (unsigned __int8)v >> 4;
  if ( (unsigned __int8)((unsigned __int8)v >> 4) >= 0xAu )
    v7 = v6 + 55;
  else
    v7 = v6 + 48;
  *this->pBuf++ = v7;
  v8 = v & 0xF;
  if ( (v & 0xFu) >= 0xA )
    v9 = v8 + 55;
  else
    v9 = v8 + 48;
  *this->pBuf++ = v9;
}
