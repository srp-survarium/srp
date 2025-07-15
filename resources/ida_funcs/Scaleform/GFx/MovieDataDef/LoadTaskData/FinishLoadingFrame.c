char __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::FinishLoadingFrame(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::GFx::LoadProcess *plp,
        bool finished)
{
  Scaleform::GFx::FrameBindData *FrameBindData; // eax
  Scaleform::GFx::FrameBindData *v6; // edi
  Scaleform::GFx::SWFProcessInfo *pAltStream; // eax
  Scaleform::Mutex *p_mMutex; // ebp
  char success; // [esp+14h] [ebp+4h]

  Scaleform::GFx::LoadProcess::CommitFrameTags(plp);
  success = 1;
  FrameBindData = Scaleform::GFx::LoadProcess::CreateFrameBindData(plp);
  v6 = FrameBindData;
  if ( FrameBindData )
  {
    FrameBindData->Frame = this->LoadingFrame;
    pAltStream = (Scaleform::GFx::SWFProcessInfo *)plp->pAltStream;
    if ( !pAltStream )
      pAltStream = &plp->ProcessInfo;
    v6->BytesLoaded = pAltStream->Stream.Pos
                    + pAltStream->Stream.FilePos
                    - pAltStream->Stream.DataSize
                    - plp->ProcessInfo.FileStartPos;
  }
  p_mMutex = &this->pFrameUpdate.pObject->mMutex;
  Scaleform::Mutex::DoLock(p_mMutex);
  if ( !v6 )
  {
    this->LoadState = LS_LoadError;
    success = 0;
    goto LABEL_12;
  }
  if ( this->BindData.pFrameData.Value )
    InterlockedExchange((volatile LONG *)&this->BindData.pFrameDataLast->pNextFrame, (LONG)v6);
  else
    InterlockedExchange((volatile LONG *)&this->BindData, (LONG)v6);
  ++this->LoadingFrame;
  this->BindData.pFrameDataLast = v6;
  if ( finished )
  {
    this->LoadState = LS_LoadFinished;
LABEL_12:
    if ( finished || !success )
      Scaleform::WaitCondition::NotifyAll(&this->pFrameUpdate.pObject->WC);
  }
  Scaleform::Mutex::Unlock(p_mMutex);
  return success;
}
