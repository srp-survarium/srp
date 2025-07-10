int __thiscall Scaleform::GFx::AMP::Socket::Receive(
        Scaleform::GFx::AMP::Socket *this,
        char *dataBuffer,
        int dataBufferSize)
{
  int v3; // eax

  v3 = this->SocketImpl->Receive(this->SocketImpl, dataBuffer, dataBufferSize);
  return v3 < 0 ? 0 : v3;
}
