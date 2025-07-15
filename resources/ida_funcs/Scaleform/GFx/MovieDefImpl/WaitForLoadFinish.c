void __thiscall Scaleform::GFx::MovieDefImpl::WaitForLoadFinish(Scaleform::GFx::MovieDefImpl *this, bool cancel)
{
  Scaleform::GFx::MovieDataDef *pObject; // eax
  Scaleform::GFx::MovieDataDef::LoadTaskData *v4; // ecx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // eax
  Scaleform::GFx::LoadUpdateSync *v6; // esi

  pObject = this->pBindData.pObject->pDataDef.pObject;
  if ( cancel )
  {
    v4 = pObject->pData.pObject;
    if ( v4->LoadState <= LS_LoadingFrames )
      v4->LoadingCanceled = 1;
  }
  v5 = pObject->pData.pObject;
  if ( v5->LoadState <= LS_LoadingFrames )
    Scaleform::GFx::LoadUpdateSync::WaitForLoadFinished(v5->pFrameUpdate.pObject);
  v6 = this->pBindData.pObject->pBindUpdate.pObject;
  Scaleform::Mutex::DoLock(&v6->mMutex);
  while ( !v6->LoadFinished )
    Scaleform::WaitCondition::Wait(&v6->WC, &v6->mMutex, 0xFFFFFFFF);
  Scaleform::Mutex::Unlock(&v6->mMutex);
}
