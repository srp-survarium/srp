unsigned int __thiscall Scaleform::GFx::AMP::AmpStream::FirstMessageSize(Scaleform::GFx::AMP::AmpStream *this)
{
  int readPosition; // edi
  unsigned int result; // eax
  unsigned int v4; // [esp+8h] [ebp-4h] BYREF

  readPosition = this->readPosition;
  this->readPosition = 0;
  v4 = 0;
  this->Read(this, (unsigned __int8 *)&v4, 4);
  result = v4;
  this->readPosition = readPosition;
  return result;
}
