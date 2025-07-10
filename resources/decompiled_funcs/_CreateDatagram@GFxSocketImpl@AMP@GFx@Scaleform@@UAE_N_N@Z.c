bool __thiscall Scaleform::GFx::AMP::GFxSocketImpl::CreateDatagram(
        Scaleform::GFx::AMP::GFxSocketImpl *this,
        bool broadcast)
{
  SOCKET v3; // eax

  v3 = socket(2, 2, 17);
  this->Socket = v3;
  if ( !broadcast )
    this->ListenSocket = v3;
  return v3 != -1;
}
