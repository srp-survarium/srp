void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::connectedGet(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        bool *result)
{
  *result = Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject);
}
