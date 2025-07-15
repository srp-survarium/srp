void __thiscall Scaleform::WStringBuffer::SetString(
        Scaleform::WStringBuffer *this,
        const char *putf8str,
        unsigned int utf8Sz)
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


void __thiscall Scaleform::WStringBuffer::SetString(Scaleform::WStringBuffer *this, wchar_t *pstr, unsigned int length)
{
  unsigned int v3; // esi

  v3 = length;
  if ( length == -1 )
    v3 = Scaleform::SFwcslen(pstr);
  if ( Scaleform::WStringBuffer::Resize(this, v3) )
  {
    if ( v3 )
      memcpy((unsigned __int8 *)this->pText, (unsigned __int8 *)pstr, 2 * v3 + 2);
  }
}
