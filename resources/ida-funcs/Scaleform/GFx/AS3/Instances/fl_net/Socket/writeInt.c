void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::writeInt(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned int value)
{
  if ( Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject) )
  {
    if ( (*((_DWORD *)this + 12) & 0x18) == 8 )
      Scaleform::GFx::AS3::SocketThreadMgr::SendInt(this->SockMgr.pObject, value);
    else
      Scaleform::GFx::AS3::SocketThreadMgr::SendInt(
        this->SockMgr.pObject,
        (((value << 16) | value & 0xFF00) << 8)
      | ((HIWORD(value) | (unsigned int)&vostok::memory::s_CRT_arena[5508664] & value) >> 8));
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this,
      "AS3 Net Socket: Attempting to write to closed socket");
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ThrowIOError(this);
  }
}
