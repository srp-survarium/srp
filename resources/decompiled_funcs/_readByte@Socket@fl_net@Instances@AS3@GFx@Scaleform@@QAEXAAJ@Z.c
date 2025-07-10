void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::readByte(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        int *result)
{
  char readValue; // [esp+7h] [ebp-1h] BYREF

  if ( Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject) )
  {
    if ( Scaleform::GFx::AS3::SocketThreadMgr::ReadByte(this->SockMgr.pObject, &readValue) )
    {
      *result = readValue;
    }
    else
    {
      Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
        (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this,
        "AS3 Net Socket: Failed to read Byte");
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
