void __thiscall Scaleform::GFx::AMP::Server::SetSocketImplFactory(
        Scaleform::GFx::AMP::Server *this,
        Scaleform::GFx::AMP::SocketImplFactory *socketFactory)
{
  this->ConnectionWaitDelay = (unsigned int)socketFactory;
}
