void __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::SetLoadingInitActionFrame(
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
  if ( this->InitActionList.Data.Size > LoadingFrame )
  {
    this->InitActionList.Data.Data[LoadingFrame] = *frame;
    ++this->InitActionsCnt;
    LeaveCriticalSection(&p_PlaylistLock->cs);
  }
  else
  {
    if ( plog && (plog->pLog.pObject || Scaleform::Log::GetGlobalLog()) )
    {
      pObject = plog->pLog.pObject;
      Size = this->InitActionList.Data.Size;
      if ( !pObject )
        pObject = Scaleform::Log::GetGlobalLog();
      Scaleform::Log::LogError(
        pObject,
        "Invalid SWF file: failed to load init action frame #%d since total frames counter is %d",
        this->LoadingFrame + 1,
        Size);
    }
    LeaveCriticalSection(&p_PlaylistLock->cs);
  }
}
