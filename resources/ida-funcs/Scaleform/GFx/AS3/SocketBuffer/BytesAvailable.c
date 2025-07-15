unsigned int __thiscall Scaleform::GFx::AS3::SocketBuffer::BytesAvailable(Scaleform::GFx::AS3::SocketBuffer *this)
{
  return this->Data.Data.Size - this->readPosition;
}
