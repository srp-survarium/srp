void __thiscall Scaleform::StringBuffer::AppendString(Scaleform::StringBuffer *this, const wchar_t *pstr, int len)
{
  int EncodeStringSize; // eax
  unsigned int Size; // edi

  if ( pstr )
  {
    EncodeStringSize = Scaleform::UTF8Util::GetEncodeStringSize(pstr, len);
    Size = this->Size;
    Scaleform::StringBuffer::Resize(this, Size + EncodeStringSize);
    Scaleform::UTF8Util::EncodeString(&this->pData[Size], pstr, len);
  }
}
