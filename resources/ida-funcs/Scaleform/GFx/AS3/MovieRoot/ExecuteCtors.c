void __thiscall Scaleform::GFx::AS3::MovieRoot::ExecuteCtors(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::ASVM *pObject; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v4; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer _amp_timer_; // [esp+4h] [ebp-10h] BYREF

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_,
    this->pMovieImpl->AdvanceStats.pObject,
    "MovieRoot::ExecuteCtors",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  if ( this->ASFramesToExecute )
  {
    Scaleform::GFx::AS3::VM::ExecuteCode(this->pAVM.pObject, this->ASFramesToExecute);
    pObject = this->pAVM.pObject;
    if ( pObject->HandleException )
      pObject->HandleException = 0;
    this->ASFramesToExecute = 0;
  }
  Stats = _amp_timer_.Stats;
  if ( _amp_timer_.Stats )
  {
    v4 = _amp_timer_.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v4->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(_amp_timer_.StartTicks),
      (ProfileTicks - _amp_timer_.StartTicks) >> 32);
  }
}
