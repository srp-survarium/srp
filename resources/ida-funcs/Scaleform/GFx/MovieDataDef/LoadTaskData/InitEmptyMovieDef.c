void __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::InitEmptyMovieDef(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this)
{
  Scaleform::Lock *p_PlaylistLock; // edi

  p_PlaylistLock = &this->PlaylistLock;
  EnterCriticalSection(&this->PlaylistLock.cs);
  Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Playlist.Data,
    this->Header.FrameCount);
  Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->InitActionList.Data,
    this->Header.FrameCount);
  this->InitActionsCnt = 0;
  LeaveCriticalSection(&p_PlaylistLock->cs);
  Scaleform::GFx::MovieDataDef::LoadTaskData::UpdateLoadState(this, this->Header.FrameCount, LS_LoadFinished);
}
