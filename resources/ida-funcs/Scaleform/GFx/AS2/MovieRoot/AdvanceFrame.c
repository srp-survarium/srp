void __thiscall Scaleform::GFx::AS2::MovieRoot::AdvanceFrame(Scaleform::GFx::AS2::MovieRoot *this, bool nextFrame)
{
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v4; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v6; // [esp+4h] [ebp-10h] BYREF

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v6,
    this->pMovieImpl->AdvanceStats.pObject,
    "MovieRoot::AdvanceFrame",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_Invalid);
  if ( nextFrame )
    Scaleform::GFx::AS2::ASRefCountCollector::AdvanceFrame(
      this->MemContext.pObject->ASGC.pObject,
      &this->NumAdvancesSinceCollection,
      &this->LastCollectionFrame);
  Stats = v6.Stats;
  if ( v6.Stats )
  {
    v4 = v6.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v4->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v6.StartTicks),
      (ProfileTicks - v6.StartTicks) >> 32);
  }
}
