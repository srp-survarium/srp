void __thiscall Scaleform::WStringBuffer::SetString(Scaleform::WStringBuffer *this, char *putf8str, int utf8Sz)
{
  int v3; // esi
  unsigned int Length; // eax

  v3 = utf8Sz;
  if ( utf8Sz == -1 )
    v3 = strlen(putf8str);
  Length = Scaleform::UTF8Util::GetLength(putf8str, v3);
  if ( Scaleform::WStringBuffer::Resize(this, Length) )
  {
    if ( v3 )
      Scaleform::UTF8Util::DecodeString(this->pText, putf8str, v3);
  }
}


void __thiscall Scaleform::WStringBuffer::SetString(
        Scaleform::WStringBuffer *this,
        const __m128i *pstr,
        unsigned int length)
{
  unsigned int v3; // esi

  v3 = length;
  if ( length == -1 )
    v3 = Scaleform::SFwcslen((const wchar_t *)pstr);
  if ( Scaleform::WStringBuffer::Resize(this, v3) )
  {
    if ( v3 )
      memcpy((int)this->pText, pstr, 2 * v3 + 2);
  }
}
