char __thiscall Scaleform::GFx::AMP::Socket::CreateClient(
        Scaleform::GFx::AMP::Socket *this,
        const char *ipAddress,
        unsigned int port,
        Scaleform::String *errorMsg)
{
  Scaleform::Lock *CreateLock; // ebp
  Scaleform::GFx::AMP::SocketInterface *SocketImpl; // ecx
  Scaleform::GFx::AMP::SocketInterface *v7; // ecx
  int v8; // eax
  Scaleform::Lock *v9; // edi
  Scaleform::GFx::AMP::SocketInterface *v11; // ecx
  int v12; // eax
  Scaleform::MsgFormat::Sink result; // [esp+10h] [ebp-Ch] BYREF

  CreateLock = this->CreateLock;
  if ( CreateLock )
    EnterCriticalSection(&this->CreateLock->cs);
  SocketImpl = this->SocketImpl;
  this->IsServer = 0;
  if ( SocketImpl->CreateStream(SocketImpl, 0) )
  {
    this->SocketImpl->SetAddress(this->SocketImpl, port, ipAddress);
    if ( this->SocketImpl->Connect(this->SocketImpl) )
    {
      if ( errorMsg )
      {
        result.Type = tStr;
        result.SinkData.pStr = errorMsg;
        Scaleform::SPrintF(&result, "Socket connection established on port %d\n", port);
      }
      if ( CreateLock )
        LeaveCriticalSection(&CreateLock->cs);
      return 1;
    }
    else
    {
      if ( errorMsg )
      {
        v11 = this->SocketImpl;
        result.Type = tStr;
        result.SinkData.pStr = errorMsg;
        v12 = v11->GetLastError(v11);
        Scaleform::SPrintF(&result, "Could not connect to server. Error %d\n", v12);
      }
      Scaleform::GFx::AMP::Socket::Destroy(this);
      if ( CreateLock )
        LeaveCriticalSection(&CreateLock->cs);
      return 0;
    }
  }
  else
  {
    if ( errorMsg )
    {
      v7 = this->SocketImpl;
      result.Type = tStr;
      result.SinkData.pStr = errorMsg;
      v8 = v7->GetLastError(v7);
      Scaleform::SPrintF(&result, "Could not create socket. Error %d", v8);
    }
    v9 = this->CreateLock;
    if ( v9 )
      EnterCriticalSection(&this->CreateLock->cs);
    this->SocketImpl->Cleanup(this->SocketImpl);
    if ( v9 )
      LeaveCriticalSection(&v9->cs);
    if ( CreateLock )
      LeaveCriticalSection(&CreateLock->cs);
    return 0;
  }
}
