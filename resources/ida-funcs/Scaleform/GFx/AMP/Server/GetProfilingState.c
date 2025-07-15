bool __thiscall Scaleform::GFx::AMP::Server::GetProfilingState(Scaleform::GFx::AMP::Server *this)
{
  Scaleform::AmpServer *v3; // esi

  if ( this->RecordingState )
    return 1;
  v3 = &this->Scaleform::AmpServer;
  return this->IsEnabled(&this->Scaleform::AmpServer)
      && !v3->IsPaused(&this->Scaleform::AmpServer)
      && Scaleform::GFx::AMP::ThreadMgr::IsValidSocket(this->SocketThreadMgr.pObject)
      && v3->IsValidConnection(&this->Scaleform::AmpServer);
}
