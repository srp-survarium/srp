bool __thiscall Scaleform::GFx::AMP::GFxSocketImpl::Listen(
        Scaleform::GFx::AMP::GFxSocketImpl *this,
        int numConnections)
{
  return listen(this->ListenSocket, numConnections) != -1;
}
