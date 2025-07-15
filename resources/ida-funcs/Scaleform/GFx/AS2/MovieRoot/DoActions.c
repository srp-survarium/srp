void __thiscall Scaleform::GFx::AS2::MovieRoot::DoActions(Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *i; // eax
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator v6; // [esp+8h] [ebp-20h] BYREF
  Scaleform::AmpFunctionTimer v7; // [esp+18h] [ebp-10h] BYREF

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v7,
    this->pMovieImpl->AdvanceStats.pObject,
    "MovieRoot::DoActions",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_DoActions);
  v6.pActionQueue = &this->ActionQueue;
  v6.ModId = 0;
  v6.CurrentPrio = 0;
  v6.pLastEntry = 0;
  for ( i = (Scaleform::GFx::AS2::MovieRoot::ActionEntry *)Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator::getNext(&v6);
        i;
        i = (Scaleform::GFx::AS2::MovieRoot::ActionEntry *)Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator::getNext(&v6) )
  {
    Scaleform::GFx::AS2::MovieRoot::ActionEntry::Execute(i, this);
  }
  if ( v6.pLastEntry )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(v6.pActionQueue, v6.pLastEntry);
  Stats = v7.Stats;
  if ( v7.Stats )
  {
    p_NativePopCallstack = &v7.Stats->NativePopCallstack;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v7.StartTicks),
      (ProfileTicks - v7.StartTicks) >> 32);
  }
}
