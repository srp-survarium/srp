void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::remoteAddressGet(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        Scaleform::GFx::ASString *result)
{
  const Scaleform::StringLH *Address; // eax

  Address = Scaleform::GFx::AS3::SocketThreadMgr::GetAddress(this->SockMgr.pObject);
  Scaleform::GFx::ASString::operator=(
    result,
    (Scaleform::GFx::ASStringNode *)((Address->HeapTypeBits & 0xFFFFFFFC) + 8));
}
