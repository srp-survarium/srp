BOOL __thiscall Scaleform::GFx::MovieDefImpl::BindTaskData::WaitForBindStateFlags(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this,
        unsigned int flags)
{
  Scaleform::GFx::LoadUpdateSync *pObject; // eax
  Scaleform::Mutex *p_mMutex; // edi

  pObject = this->pBindUpdate.pObject;
  if ( pObject )
  {
    p_mMutex = &pObject->mMutex;
    Scaleform::Mutex::DoLock(&pObject->mMutex);
    while ( (this->BindState & 0xF) < 3 )
    {
      if ( (this->BindState & flags) != 0 )
        break;
      Scaleform::WaitCondition::Wait(&this->pBindUpdate.pObject->WC, &this->pBindUpdate.pObject->mMutex, 0xFFFFFFFF);
    }
    Scaleform::Mutex::Unlock(p_mMutex);
  }
  return (flags & this->BindState) != 0;
}
