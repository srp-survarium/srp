void __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::WaitForFrame(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        unsigned int frame)
{
  Scaleform::Mutex *p_mMutex; // edi

  if ( this->LoadState <= LS_LoadingFrames && this->LoadingFrame <= frame )
  {
    p_mMutex = &this->pFrameUpdate.pObject->mMutex;
    Scaleform::Mutex::DoLock(p_mMutex);
    while ( this->LoadState <= LS_LoadingFrames )
    {
      if ( this->LoadingFrame > frame )
        break;
      Scaleform::WaitCondition::Wait(&this->pFrameUpdate.pObject->WC, &this->pFrameUpdate.pObject->mMutex, 0xFFFFFFFF);
    }
    Scaleform::Mutex::Unlock(p_mMutex);
  }
}
