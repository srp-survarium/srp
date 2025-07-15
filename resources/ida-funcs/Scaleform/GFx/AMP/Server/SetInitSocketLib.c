void __thiscall Scaleform::GFx::AMP::Server::SetInitSocketLib(Scaleform::GFx::AMP::Server *this, bool initSocketLib)
{
  LOBYTE(this->SendingEvent.StateWaitCondition.pImpl) = initSocketLib;
}
