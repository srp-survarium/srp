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
