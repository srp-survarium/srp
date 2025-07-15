void __userpurge Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(
        Scaleform::GFx::AS3::MovieRoot *this@<ecx>,
        int a2@<ebp>,
        Scaleform::GFx::AS3::MovieRoot::ActionLevel lvl)
{
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pActionRoot; // eax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *i; // eax
  Scaleform::AmpStats *Stats; // ebx
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer _amp_timer_; // [esp+8h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator iter; // [esp+18h] [ebp-18h] BYREF

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_,
    this->pMovieImpl->AdvanceStats.pObject,
    "MovieRoot::ExecuteActionQueue",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  iter.Level = lvl;
  pActionRoot = this->ActionQueue.Entries[lvl].pActionRoot;
  iter.pActionQueue = &this->ActionQueue;
  iter.ModId = 0;
  iter.pLastEntry = 0;
  iter.pRootEntry = 0;
  iter.pCurEntry = pActionRoot;
  for ( i = (Scaleform::GFx::AS3::MovieRoot::ActionEntry *)Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(&iter);
        i;
        i = (Scaleform::GFx::AS3::MovieRoot::ActionEntry *)Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(&iter) )
  {
    Scaleform::GFx::AS3::MovieRoot::ActionEntry::Execute(i, a2, this);
  }
  if ( iter.pLastEntry )
    Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(iter.pActionQueue, iter.pLastEntry);
  Stats = _amp_timer_.Stats;
  if ( _amp_timer_.Stats )
  {
    p_NativePopCallstack = &_amp_timer_.Stats->NativePopCallstack;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(_amp_timer_.StartTicks),
      (ProfileTicks - _amp_timer_.StartTicks) >> 32);
  }
}
