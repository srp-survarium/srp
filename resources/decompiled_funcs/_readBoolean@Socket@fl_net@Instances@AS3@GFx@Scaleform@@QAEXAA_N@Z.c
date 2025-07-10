void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::readBoolean(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        bool *result)
{
  if ( Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject) )
  {
    if ( !Scaleform::GFx::AS3::SocketThreadMgr::ReadBool(this->SockMgr.pObject, result) )
    {
      Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
        (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this,
        "AS3 Net Socket: Failed to read Boolean");
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
