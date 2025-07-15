void __thiscall Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this,
        volatile unsigned int newState)
{
  Scaleform::GFx::LoadUpdateSync *pObject; // eax
  Scaleform::Mutex *p_mMutex; // edi
  Scaleform::WaitCondition *p_WC; // ecx

  pObject = this->pBindUpdate.pObject;
  if ( pObject )
  {
    p_mMutex = &pObject->mMutex;
    Scaleform::Mutex::DoLock(&pObject->mMutex);
    p_WC = &this->pBindUpdate.pObject->WC;
    this->BindState = newState;
    Scaleform::WaitCondition::NotifyAll(p_WC);
    Scaleform::Mutex::Unlock(p_mMutex);
  }
  else
  {
    this->BindState = newState;
  }
}
