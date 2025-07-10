void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::writeShort(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned __int16 value)
{
  __int16 v4; // cx

  if ( Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject) )
  {
    v4 = value;
    if ( (*((_DWORD *)this + 12) & 0x18) != 8 )
      v4 = (value << 8) | HIBYTE(value);
    Scaleform::GFx::AS3::SocketThreadMgr::SendShort(this->SockMgr.pObject, v4);
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this,
      "AS3 Net Socket: Attempting to write to closed socket");
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ThrowIOError(this);
  }
}
