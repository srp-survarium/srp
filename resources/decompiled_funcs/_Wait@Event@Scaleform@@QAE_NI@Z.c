bool __thiscall Scaleform::Event::Wait(Scaleform::Event *this, DWORD delay)
{
  Scaleform::Mutex *p_StateMutex; // edi
  volatile bool State; // bl

  p_StateMutex = &this->StateMutex;
  Scaleform::Mutex::DoLock(&this->StateMutex);
  if ( delay )
  {
    if ( delay == -1 )
    {
      while ( !this->State )
        Scaleform::WaitCondition::Wait(&this->StateWaitCondition, p_StateMutex, 0xFFFFFFFF);
    }
    else if ( !this->State )
    {
      Scaleform::WaitCondition::Wait(&this->StateWaitCondition, p_StateMutex, delay);
    }
  }
  State = this->State;
  if ( this->Temporary )
  {
    this->Temporary = 0;
    this->State = 0;
  }
  Scaleform::Mutex::Unlock(p_StateMutex);
  return State;
}
