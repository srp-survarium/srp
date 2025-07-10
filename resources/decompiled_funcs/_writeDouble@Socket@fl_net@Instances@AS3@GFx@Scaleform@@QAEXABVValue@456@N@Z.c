void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::writeDouble(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  if ( Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject) )
  {
    if ( (*((_DWORD *)this + 12) & 0x18) != 8 )
      value = COERCE_DOUBLE(Scaleform::Alg::ByteUtil::SwapOrder(*(unsigned __int64 *)&value));
    Scaleform::GFx::AS3::SocketThreadMgr::SendDouble(this->SockMgr.pObject, value);
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this,
      "AS3 Net Socket: Attempting to write to closed socket");
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ThrowIOError(this);
  }
}
