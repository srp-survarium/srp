void __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::UpdateLoadState(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        unsigned int loadingFrame,
        Scaleform::GFx::MovieDataDef::MovieLoadState loadState)
{
  Scaleform::GFx::LoadUpdateSync *pObject; // eax
  Scaleform::Mutex *p_mMutex; // edi
  Scaleform::WaitCondition *p_WC; // ecx

  pObject = this->pFrameUpdate.pObject;
  if ( pObject )
  {
    p_mMutex = &pObject->mMutex;
    Scaleform::Mutex::DoLock(&pObject->mMutex);
    this->LoadState = loadState;
    p_WC = &this->pFrameUpdate.pObject->WC;
    this->LoadingFrame = loadingFrame;
    Scaleform::WaitCondition::NotifyAll(p_WC);
    Scaleform::Mutex::Unlock(p_mMutex);
  }
  else
  {
    this->LoadingFrame = loadingFrame;
    this->LoadState = loadState;
  }
}
