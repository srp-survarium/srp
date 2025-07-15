char __thiscall Scaleform::GFx::AMP::GFxSocketImpl::Shutdown(Scaleform::GFx::AMP::GFxSocketImpl *this)
{
  if ( this->Socket != -1 )
  {
    closesocket(this->Socket);
    this->Socket = -1;
  }
  return 1;
}
