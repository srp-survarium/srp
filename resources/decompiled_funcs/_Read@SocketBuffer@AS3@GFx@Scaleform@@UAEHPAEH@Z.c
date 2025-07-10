unsigned int __thiscall Scaleform::GFx::AS3::SocketBuffer::Read(
        Scaleform::GFx::AS3::SocketBuffer *this,
        unsigned __int8 *pbufer,
        unsigned int numBytes)
{
  memcpy(pbufer, &this->Data.Data.Data[this->readPosition], numBytes);
  this->readPosition += numBytes;
  return numBytes;
}
