bool __thiscall Scaleform::GFx::Movie::SetVariable(
        Scaleform::GFx::Movie *this,
        const char *ppathToVar,
        const Scaleform::GFx::Value *value,
        Scaleform::GFx::Movie::SetVarType setType)
{
  bool v5; // al
  Scaleform::AmpStats *Stats; // esi
  bool v7; // bl
  Scaleform::AmpStats_vtbl *v8; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v11; // [esp+Ch] [ebp-10h] BYREF

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v11,
    this->pASMovieRoot.pObject->pMovieImpl->AdvanceStats.pObject,
    "Movie::SetVariable",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_SetVariable);
  v5 = this->pASMovieRoot.pObject->SetVariable(this->pASMovieRoot.pObject, ppathToVar, value, setType);
  Stats = v11.Stats;
  v7 = v5;
  if ( v11.Stats )
  {
    v8 = v11.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v8->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v11.StartTicks),
      (ProfileTicks - v11.StartTicks) >> 32);
  }
  return v7;
}
