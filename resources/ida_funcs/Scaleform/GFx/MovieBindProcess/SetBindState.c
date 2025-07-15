void __thiscall Scaleform::GFx::MovieBindProcess::SetBindState(
        Scaleform::GFx::MovieBindProcess *this,
        volatile unsigned int newState)
{
  Scaleform::GFx::MovieDefImpl::BindTaskData *pObject; // esi
  Scaleform::GFx::LoadUpdateSync *v3; // eax
  Scaleform::Mutex *p_mMutex; // edi
  Scaleform::WaitCondition *p_WC; // ecx

  pObject = this->pBindData.pObject;
  if ( pObject )
  {
    v3 = pObject->pBindUpdate.pObject;
    if ( v3 )
    {
      p_mMutex = &v3->mMutex;
      Scaleform::Mutex::DoLock(&v3->mMutex);
      p_WC = &pObject->pBindUpdate.pObject->WC;
      pObject->BindState = newState;
      Scaleform::WaitCondition::NotifyAll(p_WC);
      Scaleform::Mutex::Unlock(p_mMutex);
    }
    else
    {
      pObject->BindState = newState;
    }
  }
}
