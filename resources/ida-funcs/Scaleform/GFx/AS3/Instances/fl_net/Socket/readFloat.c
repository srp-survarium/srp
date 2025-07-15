void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::readFloat(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        long double *result)
{
  float valueRead; // [esp+4h] [ebp-4h] BYREF

  if ( Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject) )
  {
    if ( Scaleform::GFx::AS3::SocketThreadMgr::ReadFloat(this->SockMgr.pObject, &valueRead) )
    {
      Scaleform::GFx::AS3::Instances::fl_net::Socket::AdjustByteOrder<float>(this, &valueRead);
      *result = valueRead;
    }
    else
    {
      Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
        (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this,
        "AS3 Net Socket: Failed to read Float");
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
