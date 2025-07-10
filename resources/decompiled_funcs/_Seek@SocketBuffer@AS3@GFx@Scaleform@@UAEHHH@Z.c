int __thiscall Scaleform::GFx::AS3::SocketBuffer::Seek(Scaleform::GFx::AS3::SocketBuffer *this, int offset, int origin)
{
  int result; // eax

  result = offset;
  this->readPosition = offset;
  return result;
}
