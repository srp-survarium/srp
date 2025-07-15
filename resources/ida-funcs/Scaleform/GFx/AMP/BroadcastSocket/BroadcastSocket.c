void __thiscall Scaleform::GFx::AMP::BroadcastSocket::BroadcastSocket(
        Scaleform::GFx::AMP::BroadcastSocket *this,
        bool initLib,
        Scaleform::GFx::AMP::SocketImplFactory *socketImplFactory)
{
  Scaleform::GFx::AMP::SocketInterface *v4; // eax
  bool v5; // zf

  this->SocketFactory = socketImplFactory;
  this->InitLib = initLib;
  if ( !socketImplFactory )
    this->SocketFactory = Scaleform::GFx::AMP::GlobalDefaultSocketFactory;
  v4 = this->SocketFactory->Create(this->SocketFactory);
  v5 = !this->InitLib;
  this->SocketImpl = v4;
  if ( !v5 )
    v4->Startup(v4);
}
