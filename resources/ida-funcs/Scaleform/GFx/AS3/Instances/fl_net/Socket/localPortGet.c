void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::localPortGet(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        int *result)
{
  *result = Scaleform::GFx::AS3::SocketThreadMgr::GetPort(this->SockMgr.pObject);
}
