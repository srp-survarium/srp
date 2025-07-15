bool __thiscall Scaleform::GFx::Movie::GetVariable(
        Scaleform::GFx::Movie *this,
        Scaleform::GFx::Value *pval,
        const char *ppathToVar)
{
  bool v4; // al
  Scaleform::AmpStats *Stats; // esi
  bool v6; // bl
  Scaleform::AmpStats_vtbl *v7; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v10; // [esp+8h] [ebp-10h] BYREF

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v10,
    this->pASMovieRoot.pObject->pMovieImpl->AdvanceStats.pObject,
    "Movie::GetVariable",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_GetVariable);
  v4 = this->pASMovieRoot.pObject->GetVariable(this->pASMovieRoot.pObject, pval, ppathToVar);
  Stats = v10.Stats;
  v6 = v4;
  if ( v10.Stats )
  {
    v7 = v10.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v7->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v10.StartTicks),
      (ProfileTicks - v10.StartTicks) >> 32);
  }
  return v6;
}
