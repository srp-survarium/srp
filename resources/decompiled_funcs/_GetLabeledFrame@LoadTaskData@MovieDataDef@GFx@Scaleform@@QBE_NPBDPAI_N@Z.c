char __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::GetLabeledFrame(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        char *label,
        unsigned int *frameNumber,
        bool translateNumbers)
{
  Scaleform::Lock *p_PlaylistLock; // esi
  char v7; // bl

  if ( this->LoadState >= LS_LoadFinished )
    return Scaleform::GFx::MovieDataDef::TranslateFrameString(&this->NamedFrames, label, frameNumber, translateNumbers);
  p_PlaylistLock = &this->PlaylistLock;
  EnterCriticalSection(&this->PlaylistLock.cs);
  v7 = Scaleform::GFx::MovieDataDef::TranslateFrameString(&this->NamedFrames, label, frameNumber, translateNumbers);
  LeaveCriticalSection(&p_PlaylistLock->cs);
  return v7;
}
