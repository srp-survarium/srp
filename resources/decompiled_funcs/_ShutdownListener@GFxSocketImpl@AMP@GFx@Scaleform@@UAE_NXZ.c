char __thiscall Scaleform::GFx::AMP::GFxSocketImpl::ShutdownListener(Scaleform::GFx::AMP::GFxSocketImpl *this)
{
  if ( this->IsListening(this) )
  {
    closesocket(this->ListenSocket);
    this->ListenSocket = -1;
  }
  return 1;
}
