void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::readUnsignedInt(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        unsigned int *result)
{
  int readValue; // [esp+4h] [ebp-4h] BYREF

  if ( Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject) )
  {
    if ( Scaleform::GFx::AS3::SocketThreadMgr::ReadInt(this->SockMgr.pObject, &readValue) )
    {
      if ( (*((_DWORD *)this + 12) & 0x18) == 8 )
        *result = readValue;
      else
        *result = (((readValue << 16) | readValue & 0xFF00) << 8)
                | ((unsigned int)(HIWORD(readValue) | readValue & 0xFF0000) >> 8);
    }
    else
    {
      Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
        (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this,
        "AS3 Net Socket: Failed to read Unsigned Int");
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
