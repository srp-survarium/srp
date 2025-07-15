int __thiscall Scaleform::GFx::AMP::BroadcastSocket::Broadcast(
        Scaleform::GFx::AMP::BroadcastSocket *this,
        const char *dataBuffer,
        unsigned int dataBufferSize)
{
  return this->SocketImpl->SendBroadcast(this->SocketImpl, dataBuffer, dataBufferSize);
}
