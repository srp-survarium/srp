void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::writeFloat(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  float v; // [esp+14h] [ebp+8h]

  if ( Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject) )
  {
    v = value;
    if ( (*((_DWORD *)this + 12) & 0x18) != 8 )
      LODWORD(v) = (((LODWORD(v) << 16) | LOWORD(v) & 0xFF00) << 8)
                 | ((HIWORD(LODWORD(v)) | (unsigned int)&vostok::memory::s_CRT_arena[5508664] & LODWORD(v)) >> 8);
    Scaleform::GFx::AS3::SocketThreadMgr::SendFloat(this->SockMgr.pObject, v);
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this,
      "AS3 Net Socket: Attempting to write to closed socket");
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ThrowIOError(this);
  }
}
