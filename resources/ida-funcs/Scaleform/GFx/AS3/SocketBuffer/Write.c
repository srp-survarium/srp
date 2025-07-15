int __thiscall Scaleform::GFx::AS3::SocketBuffer::Write(
        Scaleform::GFx::AS3::SocketBuffer *this,
        const __m128i *pbufer,
        int numBytes)
{
  memcpy((int)&this->Data.Data.Data[this->Data.Data.Size - numBytes], pbufer, numBytes);
  return numBytes;
}
