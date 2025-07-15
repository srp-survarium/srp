void __userpurge Scaleform::GFx::AS3::FrameCounter::AdvanceFrame(
        Scaleform::GFx::AS3::FrameCounter *this@<ecx>,
        int a2@<ebp>,
        bool nextFrame,
        float framePos)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::AS3::MovieRoot *pObject; // esi
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v8; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer _amp_timer_; // [esp+8h] [ebp-10h] BYREF

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_,
    this->pASRoot->pMovieImpl->AdvanceStats.pObject,
    "FrameCounter::AdvanceFrame",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  pMovieImpl = this->pASRoot->pMovieImpl;
  pObject = (Scaleform::GFx::AS3::MovieRoot *)pMovieImpl->pASMovieRoot.pObject;
  if ( nextFrame )
  {
    Scaleform::GFx::AS3::MovieRoot::ExecuteCtors((Scaleform::GFx::AS3::MovieRoot *)pMovieImpl->pASMovieRoot.pObject);
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, a2, AL_Highest);
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, a2, AL_High);
    Scaleform::GFx::AS3::FrameCounter::QueueFrameActions(this);
    Scaleform::GFx::AS3::MovieRoot::RequeueActionQueue(pObject, AL_Count_, AL_Frame);
  }
  Stats = _amp_timer_.Stats;
  if ( _amp_timer_.Stats )
  {
    v8 = _amp_timer_.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v8->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(_amp_timer_.StartTicks),
      (ProfileTicks - _amp_timer_.StartTicks) >> 32);
  }
}
