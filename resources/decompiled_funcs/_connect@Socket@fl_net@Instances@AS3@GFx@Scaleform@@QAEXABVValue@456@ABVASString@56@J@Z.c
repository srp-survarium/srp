void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::connect(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *host,
        int port)
{
  Scaleform::GFx::AS3::SocketThreadMgr::Init(this->SockMgr.pObject, host->pNode->pData, port);
}
