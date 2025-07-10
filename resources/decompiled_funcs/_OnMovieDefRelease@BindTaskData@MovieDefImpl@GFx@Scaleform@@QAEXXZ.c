void __thiscall Scaleform::GFx::MovieDefImpl::BindTaskData::OnMovieDefRelease(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this)
{
  Scaleform::Lock *p_ResourceLock; // edi
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // esi
  Scaleform::GFx::LoadUpdateSync *v4; // eax
  Scaleform::Mutex *p_mMutex; // edi

  p_ResourceLock = &this->ResourceBinding.ResourceLock;
  EnterCriticalSection(&this->ResourceBinding.ResourceLock.cs);
  this->ResourceBinding.pOwnerDefRes = 0;
  LeaveCriticalSection(&p_ResourceLock->cs);
  EnterCriticalSection(&this->ImportSourceLock.cs);
  this->pDefImpl_Unsafe = 0;
  LeaveCriticalSection(&this->ImportSourceLock.cs);
  if ( (this->BindState & 0xF) <= 1 )
    this->BindingCanceled = 1;
  pObject = this->pDataDef.pObject->pData.pObject;
  v4 = pObject->pFrameUpdate.pObject;
  if ( v4 )
  {
    p_mMutex = &v4->mMutex;
    Scaleform::Mutex::DoLock(&v4->mMutex);
    Scaleform::WaitCondition::NotifyAll(&pObject->pFrameUpdate.pObject->WC);
    Scaleform::Mutex::Unlock(p_mMutex);
  }
}
