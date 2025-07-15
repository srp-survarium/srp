void __thiscall Scaleform::GFx::AMP::AmpStream::Write(Scaleform::GFx::AMP::AmpStream *this, Scaleform::File *str)
{
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int v4; // ebx
  unsigned int Size; // [esp+Ch] [ebp-4h] BYREF

  Write = str->Write;
  Size = this->Data.Data.Size;
  v4 = Size;
  Write(str, (const unsigned __int8 *)&Size, 4);
  if ( v4 )
    str->Write(str, this->Data.Data.Data, this->Data.Data.Size);
}


unsigned int __thiscall Scaleform::GFx::AMP::AmpStream::Write(
        Scaleform::GFx::AMP::AmpStream *this,
        const __m128i *pbufer,
        unsigned int numBytes)
{
  Scaleform::GFx::AMP::AmpStream::IncreaseMessageSize(this, numBytes);
  memcpy((int)&this->Data.Data.Data[this->Data.Data.Size - numBytes], pbufer, numBytes);
  return numBytes;
}
