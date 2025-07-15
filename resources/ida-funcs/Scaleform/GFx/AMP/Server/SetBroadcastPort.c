void __thiscall Scaleform::GFx::AMP::Server::SetBroadcastPort(Scaleform::GFx::AMP::Server *this, unsigned int port)
{
  this->ToggleStateLock.cs.SpinCount = port;
}
