void __thiscall Scaleform::GFx::AMP::BroadcastSocket::GetName(
        Scaleform::GFx::AMP::BroadcastSocket *this,
        unsigned int *port,
        unsigned int *address,
        char *name,
        unsigned int nameSize)
{
  this->SocketImpl->GetName(this->SocketImpl, port, address, name, nameSize);
}
