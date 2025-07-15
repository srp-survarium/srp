void __usercall Scaleform::GFx::AS3::MovieRoot::DoActions(Scaleform::GFx::AS3::MovieRoot *this@<ecx>, int a2@<ebp>)
{
  Scaleform::GFx::AS3::MovieRoot::ActionLevel i; // esi
  Scaleform::GFx::AS3::ASVM *pObject; // edi
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_DoActions; // [esp+8h] [ebp-10h] BYREF

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_DoActions,
    this->pMovieImpl->AdvanceStats.pObject,
    "MovieRoot::DoActions",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_DoActions);
  Scaleform::GFx::AS3::MovieRoot::ExecuteCtors(this);
  for ( i = AL_Highest; (unsigned int)i < AL_Count_; ++i )
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(this, a2, i);
  Scaleform::GFx::AS3::MovieRoot::CheckSocketMessages(this);
  pObject = this->pAVM.pObject;
  if ( pObject->HandleException )
    pObject->HandleException = 0;
  Stats = _amp_timer_Amp_Native_Function_Id_DoActions.Stats;
  if ( _amp_timer_Amp_Native_Function_Id_DoActions.Stats )
  {
    p_NativePopCallstack = &_amp_timer_Amp_Native_Function_Id_DoActions.Stats->NativePopCallstack;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_DoActions.StartTicks),
      (ProfileTicks - _amp_timer_Amp_Native_Function_Id_DoActions.StartTicks) >> 32);
  }
}
