void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::readShort(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        int *result)
{
  __int16 v3; // ax
  int readData; // [esp+4h] [ebp-4h] BYREF

  if ( Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject) )
  {
    if ( Scaleform::GFx::AS3::SocketThreadMgr::ReadShort(this->SockMgr.pObject, (__int16 *)&readData) )
    {
      v3 = readData;
      if ( (*((_DWORD *)this + 12) & 0x18) != 8 )
        v3 = ((_WORD)readData << 8) | BYTE1(readData);
      *result = v3;
    }
    else
    {
      Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
        (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this,
        "AS3 Net Socket: Failed to read Short");
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
