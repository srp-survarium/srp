int __thiscall Scaleform::GFx::AMP::BroadcastSocket::Receive(
        Scaleform::GFx::AMP::BroadcastSocket *this,
        char *dataBuffer,
        int dataSize)
{
  int v3; // eax

  v3 = this->SocketImpl->ReceiveBroadcast(this->SocketImpl, dataBuffer, dataSize);
  return v3 < 0 ? 0 : v3;
}
