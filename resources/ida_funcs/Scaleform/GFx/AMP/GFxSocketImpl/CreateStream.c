bool __thiscall Scaleform::GFx::AMP::GFxSocketImpl::CreateStream(
        Scaleform::GFx::AMP::GFxSocketImpl *this,
        bool listener)
{
  SOCKET v3; // eax

  v3 = socket(2, 1, 6);
  if ( listener )
    this->ListenSocket = v3;
  else
    this->Socket = v3;
  return v3 != -1;
}
