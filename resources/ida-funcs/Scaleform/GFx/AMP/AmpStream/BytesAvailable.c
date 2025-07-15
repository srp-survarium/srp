unsigned int __thiscall Scaleform::GFx::AMP::AmpStream::BytesAvailable(Scaleform::GFx::AS3::SocketBuffer *this)
{
  return this->Data.Data.Size - this->readPosition;
}
