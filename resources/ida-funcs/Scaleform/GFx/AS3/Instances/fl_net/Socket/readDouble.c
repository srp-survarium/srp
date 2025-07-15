void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::readDouble(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        long double *result)
{
  if ( Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject) )
  {
    if ( Scaleform::GFx::AS3::SocketThreadMgr::ReadDouble(this->SockMgr.pObject, result) )
    {
      if ( (*((_DWORD *)this + 12) & 0x18) != 8 )
        *(_QWORD *)result = Scaleform::Alg::ByteUtil::SwapOrder(COERCE_UNSIGNED_INT64(*result));
    }
    else
    {
      Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
        (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this,
        "AS3 Net Socket: Failed to read Double");
      Scaleform::GFx::AS3::Instances::fl_net::Socket::ThrowEOFError(this);
    }
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this,
      "AS3 Net Socket: Attempting to read from closed socket");
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ThrowIOError(this);
  }
}
