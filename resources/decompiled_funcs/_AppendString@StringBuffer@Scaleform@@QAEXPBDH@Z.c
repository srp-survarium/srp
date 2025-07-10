void __thiscall Scaleform::StringBuffer::AppendString(
        Scaleform::StringBuffer *this,
        char *putf8str,
        unsigned int utf8StrSz)
{
  unsigned int v4; // esi
  unsigned int Size; // edi

  if ( putf8str )
  {
    v4 = utf8StrSz;
    if ( utf8StrSz )
    {
      if ( utf8StrSz == -1 )
        v4 = strlen(putf8str);
      Size = this->Size;
      Scaleform::StringBuffer::Resize(this, Size + v4);
      memcpy((unsigned __int8 *)&this->pData[Size], (unsigned __int8 *)putf8str, v4);
    }
  }
}
