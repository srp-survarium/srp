void __thiscall Scaleform::StringBuffer::AppendChar(Scaleform::StringBuffer *this, unsigned int ch)
{
  unsigned int Size; // edi
  int srcSize; // [esp+8h] [ebp-Ch] BYREF
  char buff[8]; // [esp+Ch] [ebp-8h] BYREF

  Size = this->Size;
  srcSize = 0;
  Scaleform::UTF8Util::EncodeChar(buff, &srcSize, ch);
  Scaleform::StringBuffer::Resize(this, Size + srcSize);
  memcpy((unsigned __int8 *)&this->pData[Size], (unsigned __int8 *)buff, srcSize);
}
