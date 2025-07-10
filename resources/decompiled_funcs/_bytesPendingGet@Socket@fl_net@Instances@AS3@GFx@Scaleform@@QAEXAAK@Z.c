void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::bytesPendingGet(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        unsigned int *result)
{
  *result = Scaleform::GFx::AS3::SocketThreadMgr::GetBytesPending(this->SockMgr.pObject);
}
