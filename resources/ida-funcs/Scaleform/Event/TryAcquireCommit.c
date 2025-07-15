char __thiscall Scaleform::Event::TryAcquireCommit(Scaleform::Event *this)
{
  Scaleform::Waitable::HandlerArray **p_pHandlers; // edi

  p_pHandlers = &this->pHandlers;
  Scaleform::Mutex::DoLock((Scaleform::Mutex *)&this->pHandlers);
  if ( BYTE1(this->RefCount) )
  {
    BYTE1(this->RefCount) = 0;
    LOBYTE(this->RefCount) = 0;
  }
  Scaleform::Mutex::Unlock((Scaleform::Mutex *)p_pHandlers);
  return 1;
}
