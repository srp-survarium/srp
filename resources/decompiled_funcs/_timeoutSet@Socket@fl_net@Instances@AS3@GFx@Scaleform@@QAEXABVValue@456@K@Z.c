void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::timeoutSet(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned int value)
{
  Scaleform::GFx::AS3::SocketThreadMgr::SetConnectTimeout(this->SockMgr.pObject, value);
}
