void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::bytesAvailableGet(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        unsigned int *result)
{
  *result = Scaleform::GFx::AS3::SocketThreadMgr::GetBytesAvailable(this->SockMgr.pObject);
}
