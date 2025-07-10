void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::close(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        const Scaleform::GFx::AS3::Value *result)
{
  if ( Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject) )
    Scaleform::GFx::AS3::SocketThreadMgr::Uninit(this->SockMgr.pObject);
  else
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ThrowIOError(this);
}
