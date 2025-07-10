int __thiscall Scaleform::GFx::AS3::SocketBuffer::SkipBytes(Scaleform::GFx::AS3::SocketBuffer *this, int numBytes)
{
  int result; // eax

  result = numBytes;
  this->readPosition += numBytes;
  return result;
}
