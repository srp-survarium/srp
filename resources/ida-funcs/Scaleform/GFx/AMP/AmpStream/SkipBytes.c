int __thiscall Scaleform::GFx::AMP::AmpStream::SkipBytes(Scaleform::GFx::AS3::SocketBuffer *this, int numBytes)
{
  int result; // eax

  result = numBytes;
  this->readPosition += numBytes;
  return result;
}
