char __thiscall Scaleform::Semaphore::TryAcquire(Scaleform::Semaphore *this)
{
  Scaleform::AcquireInterface *v3; // ecx

  if ( this->RefCount < 1 )
    return 0;
  Scaleform::Mutex::DoLock((Scaleform::Mutex *)&this->Scaleform::AcquireInterface);
  v3 = &this->Scaleform::AcquireInterface;
  if ( (int)&this->pHandlers->Scaleform::Waitable::RefCount.Scaleform::Waitable::Value + 1 > this->RefCount )
  {
    Scaleform::Mutex::Unlock((Scaleform::Mutex *)v3);
    return 0;
  }
  else
  {
    ++this->pHandlers;
    Scaleform::Mutex::Unlock((Scaleform::Mutex *)v3);
    return 1;
  }
}
