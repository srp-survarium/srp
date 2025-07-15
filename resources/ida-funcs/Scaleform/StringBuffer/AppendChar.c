void __thiscall Scaleform::StringBuffer::AppendChar(Scaleform::StringBuffer *this, unsigned int ch)
{
  unsigned int Size; // edi
  int pindex; // [esp+8h] [ebp-Ch] BYREF
  char pbuffer[8]; // [esp+Ch] [ebp-8h] BYREF

  Size = this->Size;
  pindex = 0;
  Scaleform::UTF8Util::EncodeChar(pbuffer, &pindex, ch);
  Scaleform::StringBuffer::Resize(this, Size + pindex);
  memcpy((int)&this->pData[Size], (const __m128i *)pbuffer, pindex);
}
