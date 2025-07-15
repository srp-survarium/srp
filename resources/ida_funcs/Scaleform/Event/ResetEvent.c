void __thiscall Scaleform::Event::ResetEvent(Scaleform::Event *this)
{
  Scaleform::Mutex *p_StateMutex; // edi

  p_StateMutex = &this->StateMutex;
  Scaleform::Mutex::DoLock(&this->StateMutex);
  this->State = 0;
  this->Temporary = 0;
  Scaleform::Mutex::Unlock(p_StateMutex);
}
