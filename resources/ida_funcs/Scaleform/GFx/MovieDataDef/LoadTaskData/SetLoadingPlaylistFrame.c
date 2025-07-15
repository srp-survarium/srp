void __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::SetLoadingPlaylistFrame(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        const Scaleform::GFx::TimelineDef::Frame *frame,
        Scaleform::GFx::LogState *plog)
{
  Scaleform::Lock *p_PlaylistLock; // ebp
  unsigned int LoadingFrame; // eax
  Scaleform::Log *pObject; // eax
  unsigned int Size; // ebx

  p_PlaylistLock = &this->PlaylistLock;
  EnterCriticalSection(&this->PlaylistLock.cs);
  LoadingFrame = this->LoadingFrame;
  if ( this->Playlist.Data.Size > LoadingFrame )
  {
    this->Playlist.Data.Data[LoadingFrame] = *frame;
    LeaveCriticalSection(&p_PlaylistLock->cs);
  }
  else
  {
    if ( plog && (plog->pLog.pObject || Scaleform::Log::GetGlobalLog()) )
    {
      pObject = plog->pLog.pObject;
      Size = this->Playlist.Data.Size;
      if ( !pObject )
        pObject = Scaleform::Log::GetGlobalLog();
      Scaleform::Log::LogError(
        pObject,
        "Invalid SWF file: failed to load frame #%d since total frames counter is %d",
        this->LoadingFrame + 1,
        Size);
    }
    LeaveCriticalSection(&p_PlaylistLock->cs);
  }
}
