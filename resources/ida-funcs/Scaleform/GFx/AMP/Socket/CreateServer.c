char __thiscall Scaleform::GFx::AMP::Socket::CreateServer(
        Scaleform::GFx::AMP::Socket *this,
        unsigned int port,
        Scaleform::String *errorMsg)
{
  Scaleform::Lock *CreateLock; // ebx
  Scaleform::GFx::AMP::SocketInterface *SocketImpl; // ecx
  Scaleform::GFx::AMP::SocketInterface *v7; // ecx
  int v8; // eax
  Scaleform::Lock *v9; // edi
  Scaleform::GFx::AMP::SocketInterface *v10; // ecx
  int v11; // eax
  Scaleform::GFx::AMP::SocketInterface *v12; // ecx
  int v13; // eax
  Scaleform::MsgFormat::Sink result; // [esp+Ch] [ebp-Ch] BYREF

  CreateLock = this->CreateLock;
  if ( CreateLock )
    EnterCriticalSection(&this->CreateLock->cs);
  if ( this->SocketImpl->IsListening(this->SocketImpl) )
  {
    if ( CreateLock )
      LeaveCriticalSection(&CreateLock->cs);
    return 1;
  }
  SocketImpl = this->SocketImpl;
  this->IsServer = 1;
  if ( !SocketImpl->CreateStream(SocketImpl, 1) )
  {
    if ( errorMsg )
    {
      v7 = this->SocketImpl;
      result.Type = tStr;
      result.SinkData.pStr = errorMsg;
      v8 = v7->GetLastError(v7);
      Scaleform::SPrintF(&result, "Could not create listener socket. Error %d", v8);
    }
    v9 = this->CreateLock;
    if ( v9 )
      EnterCriticalSection(&this->CreateLock->cs);
    this->SocketImpl->Cleanup(this->SocketImpl);
    if ( v9 )
      LeaveCriticalSection(&v9->cs);
    if ( CreateLock )
    {
      LeaveCriticalSection(&CreateLock->cs);
      return 0;
    }
    return 0;
  }
  this->SocketImpl->SetListenPort(this->SocketImpl, port);
  if ( !this->SocketImpl->Bind(this->SocketImpl) )
  {
    if ( errorMsg )
    {
      v10 = this->SocketImpl;
      result.SinkData.pStr = errorMsg;
      result.Type = tStr;
      v11 = v10->GetLastError(v10);
      Scaleform::SPrintF(
        &result,
        "Could not associate local address (port %d) with listener socket. Error %d\n",
        port,
        v11);
    }
LABEL_22:
    Scaleform::GFx::AMP::Socket::Destroy(this);
    if ( CreateLock )
      LeaveCriticalSection(&CreateLock->cs);
    return 0;
  }
  if ( !this->SocketImpl->Listen(this->SocketImpl, 1) )
  {
    if ( errorMsg )
    {
      v12 = this->SocketImpl;
      result.SinkData.pStr = errorMsg;
      result.Type = tStr;
      v13 = v12->GetLastError(v12);
      Scaleform::SPrintF(&result, "Could not place socket in listening state. Error %d\n", v13);
    }
    goto LABEL_22;
  }
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
