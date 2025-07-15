int __thiscall Scaleform::GFx::AS3::SocketBuffer::Write(
        Scaleform::GFx::AS3::SocketBuffer *this,
        unsigned __int8 *pbufer,
        int numBytes)
{
  memcpy(&this->Data.Data.Data[this->Data.Data.Size - numBytes], pbufer, numBytes);
  return numBytes;
}
