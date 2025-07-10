void __thiscall Scaleform::GFx::LoadUpdateSync::WaitForLoadFinished(Scaleform::GFx::LoadUpdateSync *this)
{
  Scaleform::Mutex *p_mMutex; // edi

  p_mMutex = &this->mMutex;
  Scaleform::Mutex::DoLock(&this->mMutex);
  while ( !this->LoadFinished )
    Scaleform::WaitCondition::Wait(&this->WC, p_mMutex, 0xFFFFFFFF);
  Scaleform::Mutex::Unlock(p_mMutex);
}
